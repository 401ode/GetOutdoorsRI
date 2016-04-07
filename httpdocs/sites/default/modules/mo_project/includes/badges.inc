<?php
/**
 *  @file badges.inc
 *  @brief  Functions for calculating and displaying badges earned by users
 *
 *  @details
 *  mo_project_get_earned_badges = Gets user's earned achievement nids
 *  mo_project_get_unearned_badges = Gets user's UNearned achievement nids
 *  mo_project_write_new_badges = Writes the uid, nid, and date_earned to the badges_earned table
 *  mo_project_delete_badges = Deletes the uid, nid, and date_earned from the badges_earned table
 *  mo_project_get_user_badge_list = Gets theme_item_list of badges
 *  mo_project_get_badge_image = Gets formatted image of badge
 *  mo_project_build_badge_gallery = Gets display data for Trophy Room
 *  mo_project_build_badge_gallery_subuser = Gets display data for Trophy Room for each sub-user
 *  mo_project_build_upcoming_gallery = Gets display data for Upcoming Trophy Room
 *  mo_project_build_badge_archive = Gets display data for Trophy Archive
 *  mo_project_build_badge_archive_helper = Builds the dynamic query for each Achievement Category
 *  mo_project_get_archive_badge_list = Gets render array of badges, ready for theme_item_list
 *  mo_project_badge_gallery_sort = Sorts badge nids by Achievement Category
 *  mo_project_build_trophy_sidebar = Gets display content for the Trophy Room block on the Dashboard 
 *  mo_project_build_upcoming_trophy_block = Gets display content for the Upcoming Badges block on the Dashboard
 *  mo_project_build_profile_badge_accordian = Displays a listing of badges earned on the user profile
 *  mo_project_clone_core_achievements = Selects all of supplied year's "Standard Core" achievements (badges), updates the dates to year+1, and creates new achievement nodes
 *  mo_project_populate_badges_earned = Populates badges_earned table with initial values from 2013
 *  mo_project_get_affected_badges = Gets achievements that might have been affected by a new or changed mileage node
 *  mo_project_evaluate_badges = Checks for new badges earned or unearned after each add, edit or delete mileage
 *  mo_project_badge_recheck = Re-checks all badges for current challenge year for the supplied user
 *  mo_project_evaluate_sub_badges = Calls mo_project_evaluate_badges with the array of sub-badges
 *  mo_project_get_overall_badges = Gets achievements that have another badge as one criteria
 */

 
/**
 *  @brief  Gets user's earned achievement nids
 *  
 *  @param [in] $uid   User id of user
 *  @param [in] $suid  Sub-User id of user or sub-user
 *  @param [in] $yr    Optional. The Challenge year
 *  @return  Array of achievement nids earned by the user sorted by date earned
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-24  to add sub-user
 */
function mo_project_get_earned_badges($uid, $suid=NULL, $yr=NULL) {

  if (is_null($suid)) {
    // Get the suid of the "Me" sub-user
    $me_sub = mo_project_get_subusers($uid, array('Me'));
    $suid = $me_sub[0]->suid;
  }

  $query_ern = db_select('badges_earned', 'b');
  $query_ern->fields('b', array('field_badges_entity_id'));
  $query_ern->condition('b.field_badges_uid', $uid);
  $query_ern->condition('b.field_badges_suid', $suid);
  if (!is_null($yr)) {
      $challenge_dates = mo_project_get_challenge_dates_by_year($yr);
      $query_ern->condition('b.field_badges_date', $challenge_dates['start_sse'], '>=');
      $query_ern->condition('b.field_badges_date', $challenge_dates['end_sse'], '<=');
  }
  $query_ern->orderBy('b.field_badges_date'); 
  $earned_badges = $query_ern->execute()->fetchCol();

  if ( ($yr == 2014) OR ($yr == 2015) ) {
    $node_title = 'Early Bird (' . $yr . ')';
    $query_nid = db_select('node', 'n');
    $query_nid->fields('n', array('nid'));
    $query_nid->condition('n.title', $node_title, '=');
    $query_nid->condition('n.type', 'achievement', '=');    
    $badge_nid = $query_nid->execute()->fetchCol();
    
    // Earned Early Bird badge?
    $query_all = db_select('badges_earned', 'b');
    $query_all->fields('b', array('field_badges_entity_id'));
    $query_all->condition('b.field_badges_uid', $uid);
    $query_all->condition('b.field_badges_suid', $suid);
    $all_earned_badges = $query_all->execute()->fetchCol();

    if (in_array($badge_nid, $all_earned_badges)) {      
      $earned_badges = array_merge(array($badge_nid), $earned_badges);
    }
  }
  
  return $earned_badges;
}


/**
 *  @brief  Gets user's UNearned achievement nids
 *  
 *  @param [in] $uid  User id of user
 *  @param [in] $suid  Sub-User id of user or sub-user
 *  @return  Array of achievement nids NOT YET earned by the user, not expired, 
 *  sorted by sticky then weight
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-24  to add sub-user
 */
function mo_project_get_unearned_badges($uid, $suid=NULL) {
  
  if (is_null($suid)) {
    // Get the suid of the "Me" sub-user
    $me_sub = mo_project_get_subusers($uid, array('Me'));
    $suid = $me_sub[0]->suid;
  }
  
  // Get the earned badges
  $earned_badges = mo_project_get_earned_badges($uid, $suid);

  $challenge_dates = mo_project_get_challenge_dates_by_year();

  // Load IDs of all badges that have not been earned and are not expired into array $badge_nids
  // Sort by sticky and weight
  $query_all = db_select('node', 'n');
  $query_all->join('field_data_field_achievement_dates', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type1 AND d.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $query_all->join('field_data_field_achievement_sticky', 's', 'n.nid = s.entity_id AND (s.entity_type = :type2 AND s.deleted = :deleted2)', array(':type2' => 'node', ':deleted2' => 0));
  $query_all->join('field_data_field_achievement_weight', 'w', 'n.nid = w.entity_id AND (w.entity_type = :type3 AND w.deleted = :deleted3)', array(':type3' => 'node', ':deleted3' => 0)); 
  $query_all->fields('n', array('nid'));
  $query_all->condition('n.type', 'achievement', '=');
  $query_all->condition('n.status', 0, '<>');
  // Exclude already earned badges
  if (!empty($earned_badges)) {
    $query_all->condition('n.nid', $earned_badges, 'NOT IN');
  }
  // Must be achievable within the current Challenge
  $query_all->condition('d.field_achievement_dates_value', $challenge_dates['end'], '<');
  // Must not have already expired
  $query_all->condition('d.field_achievement_dates_value2', date('Y-m-d H:i:s'), '>');
  $query_all->orderBy('s.field_achievement_sticky_value', 'DESC');
  $query_all->orderBy('d.field_achievement_dates_value2', 'ASC');
  $query_all->orderBy('w.field_achievement_weight_value', 'ASC');
  $query_all->orderBy('n.title', 'ASC');

  $badge_nids = $query_all->execute()->fetchCol();  
 
  return $badge_nids;
}


/**
 *  @brief  Writes the uid, nid, and date_earned to the badges_earned table
 *  
 *  @param [in] $uid       User id of user
 *  @param [in] $suid      Sub-User id of user or sub-user  
 *  @param [in] $badge_id  Achievement nid
 *  @param [in] $earned    Optional. Timestamp of Max(Date) of qualifying mileage
 *  @return  The badge nid of the row inserted or FALSE on failure
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_write_new_badges($uid, $suid, $badge_id, $earned=NULL) {

  if (is_null($suid)) {
    // Get the suid of the "Me" sub-user
    $me_sub = mo_project_get_subusers($uid, array('Me'));
    $suid = $me_sub[0]->suid;
  }
  
  // Get count of records before insert query
  $c_query = db_select('badges_earned', 'b');
  $c_query->fields('b', array('field_badges_row_id'));
  $c_query->condition('b.field_badges_uid', $uid, '=');
  $c_query->condition('b.field_badges_suid', $suid, '=');  
  $c_query->condition('b.field_badges_entity_id', $badge_id, '=');
  $start_results = $c_query->execute()->rowCount();
  
  if ($start_results == 0) {
  
    if ( is_null($earned) ) {
      $earned = $_SERVER['REQUEST_TIME'];
    }
   
    // Write new record
    $i_query = db_insert('badges_earned');
    $i_query->fields(array(
        'field_badges_uid' => $uid,
        'field_badges_suid' => $suid,        
        'field_badges_entity_id' => $badge_id,
        'field_badges_date' => $earned,
      ));
    $i_query->execute();
    
    // Get count of records after insert query
    $c_query2 = db_select('badges_earned', 'b');
    $c_query2->fields('b', array('field_badges_row_id'));
    $c_query2->condition('b.field_badges_uid', $uid, '=');
    $c_query2->condition('b.field_badges_suid', $suid, '=');
    $c_query2->condition('b.field_badges_entity_id', $badge_id, '=');
    $end_results = $c_query2->execute()->rowCount();
  
    $rows_inserted = $end_results - $start_results;
    if ($rows_inserted > 0) {
      return $badge_id;
    }
  } else {
    return FALSE;
  }
}


/**
 *  @brief  Deletes the uid, nid, and date_earned from the badges_earned table
 *  
 *  @param [in] $uid       User id of user
 *  @param [in] $suid      Sub-User id of user or sub-user
 *  @param [in] $badge_id  Achievement nid
 *  @return  The nid of the achievement deleted, 'check' is something weird happened, OR 
 *  FALSE on failure
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_delete_badges($uid, $suid, $badge_id) {

  // Get count of records before delete query
  $c_query = db_select('badges_earned', 'b');
  $c_query->fields('b', array('field_badges_row_id'));
  $c_query->condition('b.field_badges_uid', $uid, '=');
  $c_query->condition('b.field_badges_suid', $suid, '=');
  $c_query->condition('b.field_badges_entity_id', $badge_id, '=');
  $start_results = $c_query->execute()->rowCount();

  if ($start_results > 0) {
    // Delete row from table `badges_earned`
    $d_query = db_delete('badges_earned');
    $d_query->condition('field_badges_uid', $uid);
    $d_query->condition('field_badges_suid', $suid);
    $d_query->condition('field_badges_entity_id', $badge_id);
    $d_query->execute();
    
    // Get count of records after delete query
    $c_query2 = db_select('badges_earned', 'b');
    $c_query2->fields('b', array('field_badges_row_id'));
    $c_query2->condition('b.field_badges_uid', $uid, '=');
    $c_query2->condition('b.field_badges_suid', $suid, '=');
    $c_query2->condition('b.field_badges_entity_id', $badge_id, '=');
    $end_results = $c_query2->execute()->rowCount();
  
    $rows_deleted = $start_results - $end_results;
    if ($rows_deleted > 0) {
      return $badge_id;
    } else {
      return 'check';
    }
  } else {
    return FALSE;
  }
}

 
/**
 *  @brief Gets theme_item_list of badges
 *  
 *  @param [in] $nids Array of achievement nids
 *  @return rendered list of badges
 *  
 *  @details  2014-03-14 
 */ 
function mo_project_get_user_badge_list($nids) {
  $badges_earned = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'class' => array(
        'badges',
      ),
    ),
    'items' => array(),
  );
  
  $nodes = entity_load('node', $nids);
  foreach ($nodes as $node) {
    $badge_field = field_get_items('node', $node, 'field_achievement_badge');
    if ($badge_image = mo_project_get_badge_image($badge_field, 'sm')) {
    
      $badge = array(
        '#type'    => 'link',
        '#title'   => $badge_image,
        '#href'    => 'ajax/badge_detail/' . $node->nid,
        '#options' => array(
            'html' => TRUE, 
            'title' => $node->title,
            'attributes' => array(
                'class' => array('colorbox'), 
                'id' => 'badge-detail',
            ),
        ),
        '#suffix' => t('<h4>' . $node->title . '</h4>'),
      );    
      $badges_earned['items'][] = array(
        'class' => array(
          'badge',
          'badge-' . $node->nid,
        ),
        'data' => render($badge),
      );
    }
  }

  if (!empty($badges_earned['items'])) {
    return theme_item_list($badges_earned);
  }
  return NULL;
}
 

/**
 *  @brief  Gets formatted image of badge
 *  
 *  @param [in] $badge_field field_achievement_badge from the achievement node
 *  @param [in] $size        text representation of badge size 
 *  @return  renderable array
 *  
 *  @details  2014-03-14 
 */
function mo_project_get_badge_image($badge_field, $size) {
  if (!empty($badge_field[0]['fid'])) {
    $img = file_load($badge_field[0]['fid']);
    $width = '';
    $height = '';
    if (!empty($img->metadata['width'])) {
      $width = $img->metadata['width'];
    }
    if (!empty($img->metadata['height'])) {
      $height = $img->metadata['height'];
    }
 
    $img_vars = array(
      'style_name' => 'badge_' . $size,
      'path' => $img->uri,
      'width' => $width,
      'height' => $height,
      'alt' => NULL,
      'title' => NULL,
      'attributes' => array(
        'class' => array(
          'badge',
        ),
      ),
    );
    $field = field_get_items('file', $img, 'field_file_image_alt_text');
    if (!empty($field[0]['value'])) {
      $img_vars['alt'] = t($field[0]['value']);
    }
    $field = field_get_items('file', $img, 'field_file_image_alt_text');
    if (!empty($field[0]['value'])) {
      $img_vars['title'] = t($field[0]['value']);
    }
    return theme_image_style($img_vars);
  }
  return NULL;
}


/**
 *  @brief Gets display data for Trophy Room
 *  
 *  @param [in] $yr The year of the challenge (2013, 2014, etc.)
 *  @return Render Array to build trophy room page
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_build_badge_gallery($yr) {
  global $user;
  $uid = $user->uid;

  $all_subusers = mo_project_get_subusers($uid);
  foreach ($all_subusers as $row) {
    $key = $row->suid;
    $allowed_subusers[$key] = t($row->name);
    if ($row->type_name == "Me") {
      $me_default = $key; 
    }
  } 
  $earned_badge_nids = mo_project_get_earned_badges($uid, $me_default, $yr);
  
  if (!empty($earned_badge_nids)) {
    // Sort badges
    $unsorted_badge_nids = $earned_badge_nids;
    unset($earned_badge_nids);
    $earned_badge_nids = mo_project_badge_gallery_sort($unsorted_badge_nids);

    $message1 = "Take a look at all the beautiful ";
  } else {
    $message1 = "In your Trophy Room, you can see any ";
  }
  $message1 .= "badges you earned with <strong>100 Missouri Miles</strong> in the <strong>" . $yr . " Challenge!</strong><br>Select another tab to see what you achieved in ";
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ($yr == date("Y", $challenge_dates['start_sse'])) {
    $message1 .= "previous years, or <em>Upcoming Badges</em> to see all the badges you can still unlock! ";
  } else {
    $message1 .= "other Challenges, or <em>Upcoming Badges</em> to see all the badges you can unlock this year! ";
  }
  $message1 .= "Want to see ALL the badges we've ever offered? Browse through our new <a href=\"/archive/trophy\">Trophy Archive</a>.";

  $content = array(
    'trophies' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'user-trophies',
      ),
    ),
  );
  $content['trophies'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'overall-badges',
      'class' => 'overall-badges clearfix',
    ),
  );

  // Get theme_item_list of badges
  $overall = mo_project_get_user_badge_list($earned_badge_nids);
  $overall = str_replace('h4>', 'p>', $overall);  
  
  if (!empty($earned_badge_nids)) {
    $content['trophies'][0][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<h3><span class="Me"></span>'),
      '#markup' => t('My Badges'),
      '#suffix' => t('</h3>'),
    );
    $content['trophies'][0][1] = array(
      '#type' => 'markup',
      '#prefix' => t('<p>'),
      '#markup' => t($message1),
      '#suffix' => t('</p>'),
    );  
    $content['trophies'][0][2] = array(    
      '#type' => 'markup', 
      '#markup' => $overall,
    );      
  } else {
    $challenge_dates = mo_project_get_challenge_dates_by_year();
    if ($yr == date("Y", $challenge_dates['start_sse'])) {
      $message = "Log some miles in Missouri's beautiful outdoors to earn badges!";
    } else {
      $message = "You earned no badges for 100 Missouri Miles in " . $yr . ".";  
    }
    $content['trophies'][0][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<p>'),
      '#markup' => t($message),
      '#suffix' => t('</p>'),
    );  
  }
 
  if( (count($all_subusers) > 1) AND ($yr >= '2015') ) {
    $index = 1;
    foreach($all_subusers AS $row) {
      if($row->type_name != 'Me') {
        $earned_badge_nids = mo_project_get_earned_badges($uid, $row->suid, $yr);        
        $subcontent = mo_project_build_badge_gallery_subuser($earned_badge_nids, $index, $row->name, $row->type_name, $yr);
        $index++;
        $count = array_push($content, $subcontent);
      }
    }
  }
  return $content;  
}


/**
 *  @brief Gets display data for Trophy Room for each sub-user
 *  
 *  @param [in] $earned_badge_nids  array badge nids to be displayed
 *  @param [in] $index              index number for the array
 *  @param [in] $name               sub-user name
 *  @param [in] $class              sub-user type
 *  @param [in] $yr                 challenge year
 *  
 *  @return Render Array to build trophy room page
 *  
 *  @details  2014-04-27 
 */
function mo_project_build_badge_gallery_subuser($earned_badge_nids, $index, $name, $class, $yr) {
  // Format $name and add possessive to name for header: $name's Badges
  $name = ucwords(strtolower(trim($name)));
  if( substr($name, -1) == 's' ) {
    $name = $name ."'";
  } else {
    $name = $name ."'s";
  }
  
  if (!empty($earned_badge_nids)) {
    // Sort badges
    $unsorted_badge_nids = $earned_badge_nids;
    unset($earned_badge_nids);
    $earned_badge_nids = mo_project_badge_gallery_sort($unsorted_badge_nids);
  }
  
  // Get theme_item_list of badges
  $overall = mo_project_get_user_badge_list($earned_badge_nids);
  $overall = str_replace('h4>', 'p>', $overall);  

  $content['trophies'][$index] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'overall-badges',
      'class' => 'overall-badges clearfix',
    ),
  );
  
  if (!empty($earned_badge_nids)) {
    $content['trophies'][$index][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<span class="' . $class . '"></span><h3>'),
      '#markup' => t($name . ' Badges'),
      '#suffix' => t('</h3>'),
    );
    $content['trophies'][$index][1] = array(  
      '#type' => 'markup', 
      '#markup' => $overall,
    );      
  } else {
    $challenge_dates = mo_project_get_challenge_dates_by_year();
    if ($yr == date("Y", $challenge_dates['start_sse'])) {
      $message = "Log some miles in Missouri's beautiful outdoors to earn badges!";
    } else {
      $message = "You earned no badges for 100 Missouri Miles in " . $yr . ".";  
    }
    $content['trophies'][$index][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<span class="' . $class . '"></span><h3>'),
      '#markup' => t($name . ' Badges'),
      '#suffix' => t('</h3>'),
    );
    $content['trophies'][$index][1] = array(
      '#type' => 'markup',
      '#prefix' => t('<p>'),
      '#markup' => t($message),
      '#suffix' => t('</p>'),
    );  
  }
 
  return $content;
}


/**
 *  @brief  Gets display data for Upcoming Trophy Room
 *  
 *  @return  Render Array to build trophy room page
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_build_upcoming_gallery() {
  global $user;
  $uid = $user->uid;
  $unsorted_badge_nids = array();
  $unearned_badge_nids = array();
  
  // Get the suid of the "Me" sub-user
  $me_sub = mo_project_get_subusers($uid, array('Me'));
  $suid = $me_sub[0]->suid;

  $unsorted_badge_nids = mo_project_get_unearned_badges($uid, $suid);
  if (!empty($unsorted_badge_nids)) {  
    $unearned_badge_nids = mo_project_badge_gallery_sort($unsorted_badge_nids);
  }
  
  if (!empty($unearned_badge_nids)) {
    $yr = date("Y");
    $message = "Need some inspiration? These are all the badges you can still unlock with <strong>100 Missouri Miles</strong> in the <strong>" . $yr . " Challenge!</strong> Try an event, set a goal to go farther than before, or check out a new activity like Paddling or Swimming! <br>Build up your confidence by selecting the " . $yr . " tab to see what you've already earned this year, or any of the other tabs for previous years.<br>Want to know what you might have missed? Browse through our new <a href=\"/archive/trophy\">Trophy Archive</a>.";
  } else {
    $message = "WOW! What an overachiever! You've already earned all the badges available to you right now. Check back soon because we are adding new badges all the time.<br>Want to know what you might have missed? Browse through our new <a href=\"/archive/trophy\">Trophy Archive</a>.";
  }
  
  $content = array(
    'trophies' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'user-trophies',
      ),
    ),
  );
  $content['trophies'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'overall-badges',
      'class' => 'overall-badges clearfix',
    ),
  );

  // Get theme_item_list of badges
  $overall = mo_project_get_user_badge_list($unearned_badge_nids);
  $overall = str_replace('h4>', 'p>', $overall); 
  
  if (!empty($unearned_badge_nids)) {
    $content['trophies'][0][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<h3>'),
      '#markup' => t('My Upcoming Badges'),
      '#suffix' => t('</h3>'),
    );
    $content['trophies'][0][1] = array(
      '#type' => 'markup',
      '#prefix' => t('<p>'),
      '#markup' => t($message),
      '#suffix' => t('</p>'),
    );      
    $content['trophies'][0][2] = array(    
      '#type' => 'markup', 
      '#markup' => $overall,
    );
  } else {
    $content['trophies'][0][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<p>'),
      '#markup' => t($message),
      '#suffix' => t('</p>'),
    );  
  }
  
  return $content;
} 


/**
 *  @brief Gets display data for Trophy Archive
 *  
 *  @return Render Array to build trophy archive page
 *  
 *  @details  2015-02-02 
 */
function mo_project_build_badge_archive() {
  // Get ALL badge nids
  $q_all = db_select('node', 'n');
  $q_all->join('field_data_field_achievement_dates', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $q_all->fields('n', array('nid', 'title', 'status'));
  $q_all->fields('t', array('field_achievement_dates_value2'));  
  $q_all->condition('n.type', 'achievement', '=');
  $q_all->orderBy('n.nid', 'ASC');
  $all = $q_all->execute()->fetchAllAssoc('nid');
  
  // Get Sponsored Event badges
  $term_id = taxonomy_get_term_by_name('100MoMiles Events');
  $q_event = mo_project_build_badge_archive_helper(key($term_id));
  $event = $q_event->execute()->fetchCol();
  $b_event = mo_project_get_archive_badge_list($event, $all);

  // Get Featured Water Trail badges
  $term_id = taxonomy_get_term_by_name('Featured Water Trails');
  $q_water = mo_project_build_badge_archive_helper(key($term_id));
  $water = $q_water->execute()->fetchCol();
  $b_water = mo_project_get_archive_badge_list($water, $all);

  // Get State Park badges
  $term_id = taxonomy_get_term_by_name('State Parks');
  $q_park = mo_project_build_badge_archive_helper(key($term_id));
  $park = $q_park->execute()->fetchCol();
  $b_park = mo_project_get_archive_badge_list($park, $all);
 
  // Get Healthy Month badges
  $term_id = taxonomy_get_term_by_name('Healthy Months');  
  $q_month = mo_project_build_badge_archive_helper(key($term_id));
  $month = $q_month->execute()->fetchCol();
  $b_month = mo_project_get_archive_badge_list($month, $all);
  
  // Get Calendar Holiday badges
  $term_id = taxonomy_get_term_by_name('Calendar Holidays'); 
  $q_days = mo_project_build_badge_archive_helper(key($term_id));
  $days = $q_days->execute()->fetchCol();
  $b_days = mo_project_get_archive_badge_list($days, $all);
  
  // Get Other badges
  $term_id = taxonomy_get_term_by_name('Other Achievements');
  $q_other = mo_project_build_badge_archive_helper(key($term_id));
  $other = $q_other->execute()->fetchCol();
  $b_other = mo_project_get_archive_badge_list($other, $all);

  // Get Total Miles badges
  $term_id = taxonomy_get_term_by_name('Mileage Milestones');
  $q_miles = mo_project_build_badge_archive_helper(key($term_id));
  $miles = $q_miles->execute()->fetchCol();
  $b_miles = mo_project_get_archive_badge_list($miles, $all);
 
   // Get Miles by Activity badges
  $term_id = taxonomy_get_term_by_name('Activity Miles');
  $q_walk = mo_project_build_badge_archive_helper(key($term_id));
  $q_walk->condition('n.title', '%Walk%', 'LIKE');
  $walk = $q_walk->execute()->fetchCol(); 
  $b_walk = mo_project_get_archive_badge_list($walk, $all);

  $q_run = mo_project_build_badge_archive_helper(key($term_id));
  $q_run->condition('n.title', '%Run%', 'LIKE');
  $run = $q_run->execute()->fetchCol(); 
  $b_run = mo_project_get_archive_badge_list($run, $all);

  $q_cycl = mo_project_build_badge_archive_helper(key($term_id));
  $q_cycl->condition('n.title', '%Cycl%', 'LIKE');
  $cycl = $q_cycl->execute()->fetchCol();
  $b_cycl = mo_project_get_archive_badge_list($cycl, $all);

  $q_hik = mo_project_build_badge_archive_helper(key($term_id));
  $q_hik->condition('n.title', '%Hik%', 'LIKE');
  $hik = $q_hik->execute()->fetchCol();
  $b_hik = mo_project_get_archive_badge_list($hik, $all);
  
  $q_swim = mo_project_build_badge_archive_helper(key($term_id));
  $q_swim->condition('n.title', '%Swim%', 'LIKE');
  $swim = $q_swim->execute()->fetchCol();
  $b_swim = mo_project_get_archive_badge_list($swim, $all);

  $q_paddl = mo_project_build_badge_archive_helper(key($term_id));
  $q_paddl->condition('n.title', '%Paddl%', 'LIKE');
  $paddl = $q_paddl->execute()->fetchCol();  
  $b_paddl = mo_project_get_archive_badge_list($paddl, $all);

  $q_rid = mo_project_build_badge_archive_helper(key($term_id));
  $q_rid->condition('n.title', '%Rid%', 'LIKE');
  $rid = $q_rid->execute()->fetchCol();  
  $b_rid = mo_project_get_archive_badge_list($rid, $all);

  $q_geo = mo_project_build_badge_archive_helper(key($term_id));
  $q_geo->condition('n.title', '%Geocach%', 'LIKE');
  $geo = $q_geo->execute()->fetchCol();  
  $b_geo = mo_project_get_archive_badge_list($geo, $all);

  $q_skat = mo_project_build_badge_archive_helper(key($term_id));
  $q_skat->condition('n.title', '%Skat%', 'LIKE');
  $skat = $q_skat->execute()->fetchCol();  
  $b_skat = mo_project_get_archive_badge_list($skat, $all);
  
  $q_roll = mo_project_build_badge_archive_helper(key($term_id));
  $q_roll->condition('n.title', '%Roll%', 'LIKE');
  $roll = $q_roll->execute()->fetchCol(); 
  $b_roll = mo_project_get_archive_badge_list($roll, $all);
  
  $h3_array = array(
    '100MoMiles Events' => $b_event,
    'Featured Water Trails' => $b_water,
    'State Park Attendance' => $b_park,
    'Mileage Milestones' => $b_miles,
    'Healthy Months' => $b_month,
    'Active Holidays' => $b_days,
    'Other Achievements' => $b_other,
    'Walking Miles' => $b_walk,
    'Running Miles' => $b_run,
    'Cycling Miles' => $b_cycl,
    'Hiking Miles' => $b_hik,
    'Swimming Miles' => $b_swim,
    'Paddling Miles' => $b_paddl,
    'Riding Miles' => $b_rid,
    'Geocaching Miles' => $b_geo,
    'Skating Miles' => $b_skat,
    'Rolling Miles' => $b_roll,    
  );
  
  $message = "<p>How many badges can you unlock? Here's a list of all the badges you can earn with 100 Missouri Miles (as well as a few we've archived and are no longer available).</p><p>Keep track of your progress in your <a href=\"/trophy\">Trophy Room</a> and if you have an idea for a badge you'd like to see, <a href=\"/content/connect-us\">we'd love to hear it</a>.</p>";
  
  $content = array(
    'archive' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'trophy-archive',
      ),
    ),
  );
  
  $content['archive'][0] = array(
    '#type' => 'markup',
    '#markup' => t($message),
  );
  
  $i = 1;
  foreach ($h3_array AS $title => $b_list) {
    $content['archive'][$i] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'archive-badges',
        'class' => 'archive-badges clearfix',
      ),
    );
    $content['archive'][$i][0] = array(
      '#type' => 'markup',
      '#prefix' => t('<h3>'),
      '#markup' => t($title),
      '#suffix' => t('</h3>'),
    );
    $content['archive'][$i][1] = array(    
      '#type' => 'markup', 
      '#markup' => theme_item_list($b_list),
    );
    $i = $i +1;
  }

  return $content;  
}


/**
 *  @brief Builds the dynamic query for each Achievement Category
 *  
 *  @return Render SelectQuery Object
 *  
 *  @details  2015-02-02 
 */
function mo_project_build_badge_archive_helper($condition=NULL) {
  $query = db_select('node', 'n');
  $query->join('field_data_field_achievement_dates', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_achievement_weight', 'w', 'n.nid = w.entity_id AND (w.entity_type = :type AND w.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
  $query->join('field_data_field_achievement_category', 'c', 'n.nid = c.entity_id AND (c.entity_type = :type AND c.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
  $query->fields('n', array('nid'));
  $query->condition('n.type', 'achievement', '=');
  if ($condition != NULL) {
    $query->condition('c.field_achievement_category_tid', $condition, '=');
  }
  $query->orderBy('t.field_achievement_dates_value2', 'DESC');
  $query->orderBy('w.field_achievement_weight_value', 'ASC');
  $term = taxonomy_term_load($condition);
  if ($term->name != 'Mileage Milestones') {   
    $query->orderBy('n.nid', 'DESC');
  }

  return $query;
}

/**
 *  @brief Sorts badge nids by Achievement Category
 *  
 *  @param [in] $nids Array of achievement nids
 *  @return  sorted array of achievement nids
 *  
 *  @details  2015-04-30 
 */
function mo_project_badge_gallery_sort($unsorted_nids) {
  $sorted_nids = array();
  
  // Get Sponsored Event badges
  $term_id = taxonomy_get_term_by_name('100MoMiles Events');
  $q_event = mo_project_build_badge_archive_helper(key($term_id));
  $q_event->condition('n.nid', $unsorted_nids, 'IN');
  $event = $q_event->execute()->fetchCol();
  foreach($event AS $v) {
    $sorted_nids[] = $v;
  }

  // Get Featured Water Trail badges
  $term_id = taxonomy_get_term_by_name('Featured Water Trails');
  $q_water = mo_project_build_badge_archive_helper(key($term_id));
  $q_water->condition('n.nid', $unsorted_nids, 'IN');
  $water = $q_water->execute()->fetchCol();
  foreach($water AS $v) {
    $sorted_nids[] = $v;
  }
  
  // Get State Park badges
  $term_id = taxonomy_get_term_by_name('State Parks');
  $q_park = mo_project_build_badge_archive_helper(key($term_id));
  $q_park->condition('n.nid', $unsorted_nids, 'IN');
  $park = $q_park->execute()->fetchCol();
  foreach($park AS $v) {
    $sorted_nids[] = $v;
  }
 
  // Get Healthy Month badges
  $term_id = taxonomy_get_term_by_name('Healthy Months');  
  $q_month = mo_project_build_badge_archive_helper(key($term_id));
  $q_month->condition('n.nid', $unsorted_nids, 'IN');
  $month = $q_month->execute()->fetchCol();
  foreach($month AS $v) {
    $sorted_nids[] = $v;
  }
  
  // Get Calendar Holiday badges
  $term_id = taxonomy_get_term_by_name('Calendar Holidays'); 
  $q_days = mo_project_build_badge_archive_helper(key($term_id));
  $q_days->condition('n.nid', $unsorted_nids, 'IN');
  $days = $q_days->execute()->fetchCol();
  foreach($days AS $v) {
    $sorted_nids[] = $v;
  }
  
  // Get Other badges
  $term_id = taxonomy_get_term_by_name('Other Achievements');
  $q_other = mo_project_build_badge_archive_helper(key($term_id));
  $q_other->condition('n.nid', $unsorted_nids, 'IN');
  $other = $q_other->execute()->fetchCol();
  foreach($other AS $v) {
    $sorted_nids[] = $v;
  }

  // Get Total Miles badges
  $term_id = taxonomy_get_term_by_name('Mileage Milestones');
  $q_miles = mo_project_build_badge_archive_helper(key($term_id));
  $q_miles->condition('n.nid', $unsorted_nids, 'IN');
  $miles = $q_miles->execute()->fetchCol();
  foreach($miles AS $v) {
    $sorted_nids[] = $v;
  }
   
   // Get Miles by Activity badges
  $term_id = taxonomy_get_term_by_name('Activity Miles');
  $q_walk = mo_project_build_badge_archive_helper(key($term_id));
  $q_walk->condition('n.title', '%Walk%', 'LIKE');
  $q_walk->condition('n.nid', $unsorted_nids, 'IN');
  $walk = $q_walk->execute()->fetchCol(); 
  foreach($walk AS $v) {
    $sorted_nids[] = $v;
  }

  $q_run = mo_project_build_badge_archive_helper(key($term_id));
  $q_run->condition('n.title', '%Run%', 'LIKE');
  $q_run->condition('n.nid', $unsorted_nids, 'IN');
  $run = $q_run->execute()->fetchCol(); 
  foreach($run AS $v) {
    $sorted_nids[] = $v;
  }

  $q_cycl = mo_project_build_badge_archive_helper(key($term_id));
  $q_cycl->condition('n.title', '%Cycl%', 'LIKE');
  $q_cycl->condition('n.nid', $unsorted_nids, 'IN');
  $cycl = $q_cycl->execute()->fetchCol();
  foreach($cycl AS $v) {
    $sorted_nids[] = $v;
  }

  $q_hik = mo_project_build_badge_archive_helper(key($term_id));
  $q_hik->condition('n.title', '%Hik%', 'LIKE');
  $q_hik->condition('n.nid', $unsorted_nids, 'IN');
  $hik = $q_hik->execute()->fetchCol();
  foreach($hik AS $v) {
    $sorted_nids[] = $v;
  }
  
  $q_swim = mo_project_build_badge_archive_helper(key($term_id));
  $q_swim->condition('n.title', '%Swim%', 'LIKE');
  $q_swim->condition('n.nid', $unsorted_nids, 'IN');
  $swim = $q_swim->execute()->fetchCol();
  foreach($swim AS $v) {
    $sorted_nids[] = $v;
  }

  $q_paddl = mo_project_build_badge_archive_helper(key($term_id));
  $q_paddl->condition('n.title', '%Paddl%', 'LIKE');
  $q_paddl->condition('n.nid', $unsorted_nids, 'IN');
  $paddl = $q_paddl->execute()->fetchCol();  
  foreach($paddl AS $v) {
    $sorted_nids[] = $v;
  }

  $q_rid = mo_project_build_badge_archive_helper(key($term_id));
  $q_rid->condition('n.title', '%Rid%', 'LIKE');
  $q_rid->condition('n.nid', $unsorted_nids, 'IN');
  $rid = $q_rid->execute()->fetchCol();  
  foreach($rid AS $v) {
    $sorted_nids[] = $v;
  }

  $q_geo = mo_project_build_badge_archive_helper(key($term_id));
  $q_geo->condition('n.title', '%Geocach%', 'LIKE');
  $q_geo->condition('n.nid', $unsorted_nids, 'IN');
  $geo = $q_geo->execute()->fetchCol();  
  foreach($geo AS $v) {
    $sorted_nids[] = $v;
  }

  $q_skat = mo_project_build_badge_archive_helper(key($term_id));
  $q_skat->condition('n.title', '%Skat%', 'LIKE');
  $q_skat->condition('n.nid', $unsorted_nids, 'IN');
  $skat = $q_skat->execute()->fetchCol();  
  foreach($skat AS $v) {
    $sorted_nids[] = $v;
  }
  
  $q_roll = mo_project_build_badge_archive_helper(key($term_id));
  $q_roll->condition('n.title', '%Roll%', 'LIKE');
  $q_roll->condition('n.nid', $unsorted_nids, 'IN');
  $roll = $q_roll->execute()->fetchCol(); 
  foreach($roll AS $v) {
    $sorted_nids[] = $v;
  }
  
  return $sorted_nids;
} 


/**
 *  @brief Gets render array of badges, ready for theme_item_list
 *  
 *  @param [in] $nids Array of achievement nids
 *  @return render array of badges
 *  
 *  @details  2015-02-02 
 */ 
function mo_project_get_archive_badge_list($nids, $all) {
  $badges_earned = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'class' => array(
        'badges',
      ),
    ),
    'items' => array(),
  );
  
  $nodes = entity_load('node', $nids);
  foreach ($nodes as $node) {
    $badge_field = field_get_items('node', $node, 'field_achievement_badge');
    if ($badge_image = mo_project_get_badge_image($badge_field, 'sm')) {
    
      $badge = array(
        '#type'    => 'link',
        '#title'   => $badge_image,
        '#href'    => 'ajax/badge_detail/' . $node->nid,
        '#options' => array(
            'html' => TRUE, 
            'title' => $node->title,
            'attributes' => array(
                'class' => array('colorbox'), 
                'id' => 'badge-detail',
            ),
        ),
        '#suffix' => t('<h4>' . $node->title . '</h4>'),
      );    
      $badges_earned['items'][] = array(
        'class' => array(
          'badge',
          'badge-' . $node->nid,
        ),
        'data' => render($badge),
      );
    }    
  }

  foreach($nids AS $nid) {
    if (array_key_exists($nid, $all)) {
      if ( ($all[$nid]->status == 0) OR ($all[$nid]->field_achievement_dates_value2 < date('Y-m-d H:i:s')) ) {
        $find = 'badge-' . $nid;
        for($i=0; $i < count($badges_earned['items']); $i++) {
          if ($badges_earned['items'][$i]['class'][1] == $find) {
            $badges_earned['items'][$i]['class'][] = 'archived';
            break;
          }
        }
      }
    }
  }
  
  if (!empty($badges_earned['items'])) {
    return $badges_earned;
  }
  return NULL;
}
 

/**
 *  @brief  Gets display content for the Trophy Room block on the Dashboard
 *  
 *  @return  render array including the three most recently earned badges
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_build_trophy_sidebar() {
  global $user;
  // Get the suid of the "Me" sub-user
  $me_sub = mo_project_get_subusers($user->uid, array('Me'));
  $suid = $me_sub[0]->suid;

  
  $content = array(
    'trophies' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'trophy-sidebar',
        'class' => array(
          'trophy-sidebar',
        ),
      ),
    ),
  );
  $content['trophies'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'badge-images',
      ),
    ),
  );
 
  $achievement_nids = mo_project_get_earned_badges($user->uid, $suid, date("Y"));
//  For Testing Only
//  $achievement_nids = mo_project_get_earned_badges(237, date("Y"));  
 
  if (!empty($achievement_nids)) {
    // Reverse the array to get the most-recently earned at front
    $achievement_nids = array_reverse($achievement_nids);
    // Break off the first three achievements
    if (count($achievement_nids) > 3) {
      $chunks = array_chunk($achievement_nids, 3);
      $achievement_nids = $chunks[0];
    }
    $badge_list = mo_project_get_user_badge_list($achievement_nids);

    $content['trophies'][0][0] = array(   
      '#type' => 'markup',
      '#markup' => $badge_list, 
    );      
  } else {
    $content['trophies'][0][0] = array(
      '#type' => 'markup',
      '#markup' => t("<p>You can do it! Log some more miles to earn your first badge.</p>"),
    );
  }
  $content['trophies'][1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'clearfix',
      ),
    ),
  );
  $content['trophies'][2] = array(
    '#type' => 'markup',
    '#markup' => l('Trophy Room', 'trophy', array(
        'attributes' => array(
            'id' => 'go-trophy', 
            'class' => array('go-trophy'),
        )
    ))
  );       
  
  return $content;
}


/**
 *  @brief  Gets display content for the Upcoming Badges block on the Dashboard
 *  
 *  @return  Render array of five UNearned badges, ordered by sticky, then weight, then title; where the date criteria is not in the past
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_build_upcoming_trophy_block() {
  global $user;
  
  $content = array(
    'trophies' => array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'upcoming-trophy',
        'class' => array(
          'upcoming-trophy',
        ),
      ),
    ),
  );
  $content['trophies'][0] = array(
    '#type' => 'markup',
    '#markup' => l('View All Upcoming', 'trophy/upcoming', array(
        'attributes' => array(
            'id' => 'go-trophy', 
            'class' => array('go-trophy'),
        )
    ))
  );       
  $content['trophies'][1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'badge-images',
      ),
    ),
  );

  $unearned_badge_nids = array();
  
  // Get sub-users
  $query = db_select('subuser', 's');
  $query->fields('s', array('suid'));
  $query->condition('s.uid', $user->uid, '=');
  $subs = $query->execute()->fetchCol();
  foreach($subs AS $suid) {
    $ubn = mo_project_get_unearned_badges($user->uid, $suid);
    $unearned_badge_nids = array_merge($unearned_badge_nids, $ubn);
  }
  $achievement_nids = array_unique($unearned_badge_nids);
  //For Testing Only
  //  $achievement_nids = mo_project_get_unearned_badges(237);  

  if (!empty($achievement_nids)) {
    if (count($achievement_nids) > 5) {
      $chunks = array_chunk($achievement_nids, 5);
      $achievement_nids = $chunks[0];
    }
    $badge_list = mo_project_get_user_badge_list($achievement_nids);

    $content['trophies'][1][0] = array(   
      '#type' => 'markup',
      '#markup' => $badge_list, 
    );      
  } else {
    $content['trophies'][1][0] = array(  
      '#type' => 'markup',
      '#markup' => t("<p>WOW! What an overachiever! You've already earned all the badges available to you right now. Check back soon because we are adding new badges all the time.</p>"),
    );
  }
  $content['trophies'][2] = array(  
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'clearfix',
      ),
    ),
  );
  
  return $content;
}


/**
 *  @brief  Display a listing of badges earned on the user profile
 *  
 *  @return  Render array for unordered list <ul> of earned badges, sorted by most recent earned
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-27  to add sub-user
 */
function mo_project_build_profile_badge_accordian() { 
  $account = menu_get_object('user');

  // Query badges_earned table (joined with achievement nodes to get the human-readable titles)
  $b_query = db_select('node', 'n');
  $b_query->join('badges_earned', 'b', 'n.nid = b.field_badges_entity_id');
  $b_query->join('subuser', 's', 'b.field_badges_suid = s.suid');
  $b_query->fields('s', array('name'));
  $b_query->fields('n', array('title'));
  $b_query->fields('b', array('field_badges_date'));
  $b_query->condition('n.type', 'achievement', '=');
  $b_query->condition('n.status', 0, '<>');
  $b_query->condition('b.field_badges_uid', $account->uid, '=');
  $b_query->orderBy('b.field_badges_date', 'DESC');
  $badges = $b_query->execute()->fetchAll();

  // Theme as unordered list
  $badges_earned = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'class' => array(
        'user-profile-badges',
      ),
    ),
    'items' => array(),
  );
  
  foreach ($badges as $b) {
    $badges_earned['items'][] = ucwords(trim($b->name)) . ' earned <strong>' . $b->title . '</strong> on ' . date('M j, Y', $b->field_badges_date);
  }

  if (!empty($badges_earned['items'])) {
    return theme_item_list($badges_earned);
  }
  return NULL;
}


/**
 *  @brief Selects all of one year's "Standard Core" achievements (badges), updates the dates to year+1, and creates the new achievement nodes
 *  
 *  @param [in] $yr Optional.  Four digit year of the challenge achievements to clone
 *  @return none
 *  
 *  @details 2015-01-05 
 */
function mo_project_clone_core_achievements($year=FALSE) {
  if (!$year) {
    $year = date('Y');
  }
  $clone_year = $year + 1;
  $start_date = $year . '-01-01 00:00:00';
  $end_date = $clone_year . '-01-01 00:00:00';

  // Get challenge dates for $year and $clone_year
  $old_challenge = mo_project_get_challenge_dates_by_year($year);
  $new_challenge = mo_project_get_challenge_dates_by_year($clone_year);
  
  // Get all the year's achievement nodes where "Standard Core" has been selected
  $query = db_select('node', 'n');
  $query->join('field_data_field_achievement_dates', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_achievement_core', 'c', 'n.nid = c.entity_id AND (c.entity_type = :type AND c.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->fields('n', array('nid'));
  $query->condition('n.type', 'achievement', '=');
  $query->condition('n.status', 0, '<>');
  $query->condition('c.field_achievement_core_value', 1, '=');
  $query->condition('t.field_achievement_dates_value', $start_date, '>=');  
  $query->condition('t.field_achievement_dates_value2', $end_date, '<');
  $query->orderBy('n.nid', 'ASC');
  $achv_nids = $query->execute()->fetchCol();

  // Load the nodes for all $achv_nids
  $achievements = node_load_multiple($achv_nids);
//*******************
drupal_set_message('<pre>Achievements found: ' . print_r(count($achievements), TRUE) . '</pre>');
  
  $i = 0;
  foreach($achievements AS $achievement) {
    $new_title = '';
    $new_body = '';    
    $new_start = '';
    $new_end = '';
    
    // If title does not end with 'miles' or 'park', 
    // Add or change '(year)'
    $title_field = trim($achievement->title);
    if ( (strtolower(substr($title_field, -5)) != 'miles') AND
         (strtolower(substr($title_field, -5)) != ' park') ) {
         
        if (substr($title_field, -1) == ')') {
          $new_title = str_replace($year, $clone_year, $title_field);
        } else {
          $new_title = $title_field . ' (' . $clone_year . ')';
        }
         
    } else {
      $new_title = $title_field;
    }

    // If body (description) field contains $year, replace with $clone_year
    $new_body = $achievement->body;
    $body_field = trim($new_body[$achievement->language][0]['value']);
    $pos = strpos($body_field, $year);
    if ($pos !== FALSE) {
      $body_field = str_replace($year, $clone_year, $body_field);
      $new_body[$achievement->language][0]['value'] = $body_field;
      $new_body[$achievement->language][0]['safe_value'] = check_markup($body_field, $new_body[$achievement->language][0]['format']);
    }

    // Change the field_achievement_dates_value Year
    // Change the field_achievement_dates_value2 Year
    $date_field = field_get_items('node', $achievement, 'field_achievement_dates');
    
    // If the achievement runs the entire challenge year,
    // compare and change the start and end dates as necessary
    if ( ($date_field[0]['value'] == $old_challenge['start']) AND
        ( substr($date_field[0]['value2'], 0, 10) == substr($old_challenge['end'], 0, 10)) ) {
      $new_start = $new_challenge['start'];
      $new_end = substr($new_challenge['end'], 0, 10) . substr($date_field[0]['value2'], 10); 
    } else {
      $new_start = $clone_year . substr($date_field[0]['value'], 4);
      $new_end = $clone_year . substr($date_field[0]['value2'], 4);
    }

    // Create the new node
    $node = new stdClass();
    $node->title = $new_title;
    $node->status = 0;
    $node->promote = 0;
    $node->sticky = 0;
    $node->type = $achievement->type;
    $node->language = $achievement->language;
    $node->revision = 0;
    node_object_prepare($node);

    $node->uid = $achievement->uid;    
    $node->body = $new_body;
    $node->field_achievement_badge = $achievement->field_achievement_badge;
    $node->field_achievement_activity = $achievement->field_achievement_activity;
    $node->field_achievement_admin = $achievement->field_achievement_admin;
    $node->field_achievement_core = $achievement->field_achievement_core;
    $node->field_achievement_sticky = $achievement->field_achievement_sticky;
    $node->field_achievement_weight = $achievement->field_achievement_weight;
    $node->field_achievement_progressive = $achievement->field_achievement_progressive;
    $node->field_achievement_category = $achievement->field_achievement_category;    
    $node->field_achievement_activity_all = $achievement->field_achievement_activity_all;
    $node->field_achievement_facility = $achievement->field_achievement_facility;
    $node->field_achievement_facility_all = $achievement->field_achievement_facility_all;
    $node->field_achievement_group = $achievement->field_achievement_group;
    $node->field_achievement_group_all = $achievement->field_achievement_group_all;
    $node->field_achievement_threshold = $achievement->field_achievement_threshold;
    $node->field_achievement_threshold_1log = $achievement->field_achievement_threshold_1log;
    $node->field_achievement_threshold_equl = $achievement->field_achievement_threshold_equl;
    $node->field_achievement_subbadge = $achievement->field_achievement_subbadge;
    $node->field_achievement_subbadge_all = $achievement->field_achievement_subbadge_all;
    
    $node->field_achievement_dates[$node->language][0]['value'] = $new_start;
    $node->field_achievement_dates[$node->language][0]['value2'] = $new_end;
    $node->field_achievement_dates[$node->language][0]['timezone'] = $achievement->field_achievement_dates[$node->language][0]['timezone'];
    $node->field_achievement_dates[$node->language][0]['timezone_db'] = $achievement->field_achievement_dates[$node->language][0]['timezone_db'];
    $node->field_achievement_dates[$node->language][0]['date_type'] = $achievement->field_achievement_dates[$node->language][0]['date_type'];
  
    // Save the new node
    node_submit($node);
    node_save($node);

    $i = $i +1;
  }
//*******************
drupal_set_message('<pre>Achievements cloned: ' . print_r($i, TRUE) . '</pre>');

  return('');
  
}


/**
 *  @brief  Initial populate of the badges_earned table
 *  
 *  @return  User uid of the updated user
 *  
 *  @details  2014-03-14 
 */ 
function mo_project_populate_badges_earned() {

  // Get all the 2013 badges to test
  $bnid_query = db_select('node', 'n');
  $bnid_query->join('field_data_field_achievement_dates', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $bnid_query->fields('n', array('nid'));
  $bnid_query->condition('n.type', 'achievement', '=');
  $bnid_query->condition('n.status', 0, '<>');
  $bnid_query->condition('t.field_achievement_dates_value2', '2014-01-01 00:00:00', '<');
  $bnid_query->orderBy('n.nid', 'ASC');
  $badge_nids = $bnid_query->execute()->fetchCol();

  //Load the nodes for all $badge_nids to be tested
  $achievements = node_load_multiple($badge_nids);
  
  // Get the users
  $uid_query = db_select('users', 'u');
  $uid_query->fields('u', array('uid'));
  $uid_query->condition('u.uid', 0, '<>');
  $uid_query->condition('u.uid', 13022, '>=');  
//  $uid_query->condition('u.uid', 13041, '<');
  $uid_query->orderBy('u.uid', 'ASC');  
  $uid_result = $uid_query->execute()->fetchCol();
   
  foreach ($uid_result AS $uid) {
    foreach ($achievements as $achievement) {
    
      $query1 = db_select('node', 'n');
      $query1->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
      $query1->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0)); 
      $query1->fields('d', array('field_mileage_distance_value'));
      $query1->fields('t', array('field_mileage_date_value'));
      $query1->condition('n.type', 'mileage');
      $query1->condition('n.status', 0, '<>');
      $query1->condition('n.uid', $uid);
      if (!empty($achievement->field_achievement_activity)) {
        $query1->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
        $query1->condition('a.field_mileage_activity_tid', $achievement->field_achievement_activity['und'][0]['tid'], '=');
      }
      
      $challenge_dates = mo_project_get_challenge_dates_by_year(2013);
      $query1->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
      $query1->condition('t.field_mileage_date_value', $challenge_dates['end'], '<=');
      $query1->orderBy('t.field_mileage_date_value');
      $result1 = $query1->execute()->fetchAll();  

      $threshold_item = field_get_items('node', $achievement, 'field_achievement_threshold');
      $threshold = $threshold_item[0]['value'];
      if ($threshold > 0) {
        $total_mileage = 0;      
        foreach ($result1 as $row) {   
          $total_mileage += $row->field_mileage_distance_value;
          if ($total_mileage >= $threshold) {
            $timestamp = strtotime($row->field_mileage_date_value);
            $written_id = mo_project_write_new_badges($uid, $suid, $achievement->nid, $timestamp);
            break;
          }
        }
      }
      
    }  // next achievement
  }  // next user
return $uid; 
}


/**
 *  @brief  Gets achievements that might have been affected by a new or changed mileage node
 *  
 *  @param [in] $mileage_node  the mileage node that was added or changed
 *  @return  Array of achievement nids possibly affected by the new or changed mileage
 *  
 *  @details  2014-03-14 
 *  updated 2014-04-28  to add sub-user
 */
function mo_project_get_affected_badges($mileage_node=FALSE) {
$DEBUG = FALSE;

if ($DEBUG) {
  $message = '';
  $module_path = drupal_get_path('module', 'mo_project');
  $fileLocation = $module_path . "/includes/badge_get_log" . date('Y_m_d_H_i') . ".txt";
  $file = fopen($fileLocation, "wb");
  $message .= 'BEGIN EXECUTION OF FUNCTION mo_project_get_affected_badges.' . chr(10);
  if ($mileage_node === FALSE) {
    $message .= 'No mileage log entry was passed in.  Get all badges.' . chr(10);
  } else {
    $message .= 'Affected mileage log entry ($mileage_node object) is: ' . print_r($mileage_node, TRUE) . chr(10);
  }
  fwrite($file, $message);
  $message = '';
}
  $badge_nids = array();

  // Load IDs of all badges into array $badge_nids
  $query_all = db_select('node', 'n');
  $query_all->fields('n', array('nid'));
  $query_all->condition('n.type', 'achievement', '=');
  $query_all->condition('n.status', 0, '<>');  
  $badge_nids = $query_all->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'IDs of all badges: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}

  // Remove any Administratively Awarded badges
  $query_adm = db_select('field_data_field_achievement_admin', 'f');
  $query_adm->fields('f', array('entity_id'));
  $query_adm->condition('f.deleted', 0, '=');
  $query_adm->condition('f.field_achievement_admin_value', 1, '=');  
  $adm_nids = $query_adm->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'Administratively Awarded badges should be removed from the $badge_nids array: ' . print_r($adm_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
  if (!empty($adm_nids)) {
    $badge_nids = array_diff($badge_nids, $adm_nids);
    sort($badge_nids);
  }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
  
  if ($mileage_node !== FALSE) {
    $suid_item = field_get_items('node', $mileage_node, 'field_mileage_subuser');
    $suid = $suid_item[0]['value'];
    // Load IDs of earned badges for current user into array $earned_badges 
    $earned_badges = mo_project_get_earned_badges($mileage_node->uid, $suid);
if ($DEBUG) {
  $message .= '$suid is ' . print_r($suid, TRUE) . chr(10);
  $message .= 'Already Earned badges should be removed from the $badge_nids array: ' . print_r($earned_badges, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}

    // If the current user has earned at least one badge already, 
    // remove any earned badges from the $badge_nids array
    if (!empty($earned_badges)) {
      $badge_nids = array_diff($badge_nids, $earned_badges);
      sort($badge_nids);
    }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}

    // Check the data provided by the mileage_node
    $mileage_date = field_get_items('node', $mileage_node, 'field_mileage_date');  
    $mileage_year = strtotime($mileage_date[0]['value']); 
    $mileage_year = date("Y", $mileage_year);
    $activity_item = field_get_items('node', $mileage_node, 'field_mileage_activity');
    $facility_item = field_get_items('node', $mileage_node, 'field_mileage_facility');
    $activity_tid = $activity_item[0]['tid'];
    
    if (!empty($facility_item[0]['value'])) {
      $facility_name = $facility_item[0]['value'];
      // Get facility tid from facility name
      $f_query = new EntityFieldQuery;
      $f_query->entityCondition('entity_type', 'taxonomy_term');
      $f_query->propertyCondition('name', $facility_name);
      $f_query->propertyCondition('vid', 11);
      $result = $f_query->execute();
      if (!($result)) {
        $facility_tid = NULL;
      } else {
        $facility_tid = array_shift($result['taxonomy_term'])->tid;  
      }
    } else {
      $facility_tid = NULL;
    }    
if ($DEBUG) {
  $message .= 'Data provided by the mileage_node:' . chr(10);
  $message .= '$mileage_date is: ' . print_r($mileage_date, TRUE) . chr(10);
  $message .= '$mileage_year is: ' . $mileage_year . chr(10);
  $message .= '$activity_item is: ' . print_r($activity_item, TRUE) . chr(10);
  $message .= '$activity_tid is: ' . $activity_tid . chr(10);
  $message .= '$facility_item is: ' . print_r($facility_item, TRUE) . chr(10);
  $message .= '$facility_tid is: ' . $facility_tid . chr(10);
  $message .= '$facility_name is: ' . $facility_name . chr(10) . chr(10);
  
  fwrite($file, $message);
  $message = '';
}
    
    
    // Eliminate badges that would NOT be affected by the changed data
    
    // Other years
    $query_yer = db_select('field_data_field_achievement_dates', 'd');
    $query_yer->fields('d', array('entity_id'));
    $query_yer->distinct();
    $query_yer->where('YEAR(d.field_achievement_dates_value) <> ' . $mileage_year);  
    $elim_yer_badges = $query_yer->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'Badges from Other Years should be removed from the $badge_nids array: ' . print_r($elim_yer_badges, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}

    if (!empty($elim_yer_badges)) {
      $badge_nids = array_diff($badge_nids, $elim_yer_badges);
      sort($badge_nids);
    }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
   
    // Other activities
    // Get all badges requiring one or more activities
    $query_act = db_select('field_data_field_achievement_activity', 'a1');
    $query_act->fields('a1', array('entity_id'));
    $query_act->distinct();
    $all_act_badges = $query_act->execute()->fetchCol();
    
    // Get all badges that could be earned with this mileage log's activity 
    $query_act2 = db_select('field_data_field_achievement_activity', 'a2');
    $query_act2->fields('a2', array('entity_id'));
    $query_act2->distinct(); 
    $query_act2->condition('a2.field_achievement_activity_tid', $activity_tid, '=');  
    $this_act_badges = $query_act2->execute()->fetchCol();

    // Remove the badges that could be earned with this activity, 
    // leaving the badges that could NOT be earned to be REMOVED from the badges to evaluate
    if (!empty($this_act_badges)) {
      $elim_act_badges = array_diff($all_act_badges, $this_act_badges);
    }
    
if ($DEBUG) {
  $message .= 'Badges requiring Other Activities should be removed from the $badge_nids array: ' . print_r($elim_act_badges, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
    if (!empty($elim_act_badges)) {
      $badge_nids = array_diff($badge_nids, $elim_act_badges);
      sort($badge_nids);
    }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
    
    // Other facilities
    // Get all badges requiring one or more facilities
    $query_fac = db_select('field_data_field_achievement_facility', 'f1');      
    $query_fac->fields('f1', array('entity_id'));
    $query_fac->distinct();
    $all_fac_badges = $query_fac->execute()->fetchCol();

    if ($facility_tid != NULL) {
      // If this mileage is for a particular facility, get all badges that could be earned with this facility
      $query_fac2 = db_select('field_data_field_achievement_facility', 'f2');
      $query_fac2->fields('f2', array('entity_id'));
      $query_fac2->distinct();
      $query_fac2->condition('f2.field_achievement_facility_tid', $facility_tid, '=');  
      $this_fac_badges = $query_fac2->execute()->fetchCol();
      
      // Remove the badges that could be earned with this facility, 
      // leaving the badges that could NOT be earned to be REMOVED from the badges to evaluate
      if (!empty($this_fac_badges)) {
        $elim_fac_badges = array_diff($all_fac_badges, $this_fac_badges);
      }

    } else {
      $elim_fac_badges = $all_fac_badges;
    }
if ($DEBUG) {
  $message .= 'Badges requiring Other Facilities should be removed from the $badge_nids array: ' . print_r($elim_fac_badges, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}    
    if (!empty($elim_fac_badges)) {
      $badge_nids = array_diff($badge_nids, $elim_fac_badges);
      sort($badge_nids);
    }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
   
    // Groups: is the user a member of at least one group?
    $subqy_grp = db_select('mo_cms_user_groups_membership', 'm');
    $subqy_grp->fields('m', array('entity_id'));
    $subqy_grp->distinct();
    $subqy_grp->condition('m.approved', 1, '=');
    $subqy_grp->condition('m.deleted', 0, '=');  
    $subqy_grp->condition('m.blocked', 0, '=');
    $subqy_grp->condition('m.uid', $mileage_node->uid, '=');
    $member_groups = $subqy_grp->execute();
    $num_of_results = $member_groups->rowCount();
    
    // if not, eliminate all badges that require group membership
    if ( (empty($num_of_results)) OR ($num_of_results < 1) ) { 
      $query_grp = db_select('field_data_field_achievement_group', 'g');
      $query_grp->fields('g', array('entity_id'));
      $query_grp->distinct();
      $elim_grp_badges = $query_grp->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'This user is not a member of any Groups.' . chr(10) . 'Badges requiring Group Membership should be removed from the $badge_nids array: ' . print_r($elim_grp_badges, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}
      if (!empty($elim_grp_badges)) {
        $badge_nids = array_diff($badge_nids, $elim_grp_badges);
        sort($badge_nids);
      }
if ($DEBUG) {
  $message .= 'Remaining badges to be evaluated: ' . print_r($badge_nids, TRUE) . chr(10);
  fwrite($file, $message);
  $message = '';
}      
    }
    
/*    // Add back in any badges that have sub-badges
    $add_overall_badges = mo_project_get_overall_badges();
    $badge_nids = array_merge($badge_nids, $add_overall_badges);
    $badge_nids = array_unique($badge_nids);
*/    
  }
if ($DEBUG) {
  $message .= 'END EXECUTION OF FUNCTION mo_project_get_affected_badges' . chr(10) . chr(10);
  fclose($file);
}  
  return $badge_nids;
  
}


/**
 *  @brief  Check for new badges earned or unearned after each add, edit or delete mileage
 *  
 *  @param [in] $uid         User id of user
 *  @param [in] $suid        Sub-User id of user or sub-user
 *  @param [in] $badge_nids  Array of achievement nids to test
 *  @param [in] $yr          The Challenge year
 *  @param [in] $action      Optional. ('write' to evaluate new badges earned, 
 *                            'delete' to evaluate already earned badges,
 *                            'none' to simply return TRUE or FALSE)
 *  @return  Array of changed achievement nids, or FALSE
 *  
 *  @details  2014-03-14 
 *  updated 2015-04-28  to add sub-user
 *  
 *  If a new badge is earned, writes the uid, nid, and date_earned to the badges_earned table.
 *  If a badge becomes unearned, delete the uid, nid, and date_earned from badges_earned.
 *  edited 2014-06-09 
 *  Added evaluation code for sub-badge criteria
 *  Added evaluation code for distance in a single mileage log entry
 */
function mo_project_evaluate_badges($uid, $suid, $badge_nids, $yr, $action='write') {
$DEBUG = FALSE;

if ($DEBUG) {
  $message = '';
  $module_path = drupal_get_path('module', 'mo_project');
  $fileLocation = $module_path . "/includes/badge_log" . date('Y_m_d_H_i') . ".txt";
  $file = fopen($fileLocation, "wb");
  $message .= 'BEGIN EXECUTION OF FUNCTION mo_project_evaluate_badges.' . chr(10) . 'Passed in variables are:' . chr(10);
  $message .= 'User ID ($uid) is: ' . $uid . chr(10);
  $message .= 'Sub-User ID ($suid) is: ' . $suid . chr(10);
  $message .= 'Badges to test ($badge_nids array) is: ' . print_r($badge_nids, TRUE) . chr(10);
  $message .= 'Challenge year ($yr) is: ' . $yr . chr(10);
  $message .= 'The action to take ($action) is: ' . $action . chr(10);
  fwrite($file, $message);
  $message = '';
}

  // Initialize starting values
  $changed_badges = array();
  $previous_query = "";
  $previous_distance = 0;
  $previous_earned = '1980-01-01 00:00:00';
/*  $subbadge_count = 0;
  
  // Get nids of all published badges with sub-badge criteria into an array 
  $all_bs_with_subs = mo_project_get_overall_badges();  
*/
  
  // Load the full nodes for all $badge_nids to be tested
  $achievements = node_load_multiple($badge_nids);
  
  // Loop: Evaluate each badge
  foreach ($achievements as $achievement) {
if ($DEBUG) {
  $message .= chr(10) . '=-=-=-=-=-=-=-=-=-=' . chr(10);
  $message .= 'Evaluating badge: ' . $achievement->nid . ' - ' . $achievement->title . chr(10);
  fwrite($file, $message);
  $message = '';
}  
    $continue = TRUE;
    $activities_array = array();
    $facilities_array = array();
    $usergroups_array = array();

    // Begin building dynamic queries
    // $query1 finds the total distance logged for all criteria and the date it was earned
    // $query2 finds all activities logged for all other criteria 
    // (used to check when an achievement requires ALL of a set of multiple activities)
    // $query3 finds all facilities logged for all other criteria 
    // (used to check when an achievement requires ALL of a set of multiple facilities)
    $query1 = db_select('node', 'n');
    $query2 = db_select('node', 'n');
    $query3 = db_select('node', 'n');
    $query1->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query2->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query3->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query1->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
    $query2->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
    $query3->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query1->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
    $query2->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
    $query3->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));

    if ( (!empty($achievement->field_achievement_threshold_equl)) AND ($achievement->field_achievement_threshold_equl['und'][0]['value'] <> 0) ){
      // Single mileage entry
      $query1->addField('d', 'field_mileage_distance_value', 'distance');
      $query1->addField('t', 'field_mileage_date_value', 'earned');
    } else {
      // Cumulative mileage
      $query1->addExpression('SUM(d.field_mileage_distance_value)', 'distance');
      $query1->addExpression('MAX(t.field_mileage_date_value)', 'earned');
    }

    $query1->condition('n.type', 'mileage');
    $query2->condition('n.type', 'mileage');
    $query3->condition('n.type', 'mileage');
    $query1->condition('n.status', 0, '<>');
    $query2->condition('n.status', 0, '<>');
    $query3->condition('n.status', 0, '<>');
    $query1->condition('n.uid', $uid);
    $query2->condition('n.uid', $uid);
    $query3->condition('n.uid', $uid);
    $query1->condition('s.field_mileage_subuser_value', $suid);
    $query2->condition('s.field_mileage_subuser_value', $suid);
    $query3->condition('s.field_mileage_subuser_value', $suid);
    
        /*
        SELECT SUM(d.field_mileage_distance_value) AS distance
        FROM {node} n
        INNER JOIN {field_data_field_mileage_distance} d ON n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)
        INNER JOIN {field_data_field_mileage_date} t ON n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)
        WHERE  (n.type = :db_condition_placeholder_0) 
        AND (n.status <> :db_condition_placeholder_1) 
        AND (n.uid = :db_condition_placeholder_2) 
        AND (s.field_mileage_subuser_value = :db_condition_placeholder_3) 
        */

    // Get activity criteria
    if (!empty($achievement->field_achievement_activity)) {
      $query1->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
      $query2->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
      $query3->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));

      if (count($achievement->field_achievement_activity['und']) == 1 ) {
        foreach ($achievement->field_achievement_activity['und'] as $activity) {
          $query1->condition('a.field_mileage_activity_tid', $activity['tid'], '=');  
          $query3->condition('a.field_mileage_activity_tid', $activity['tid'], '=');  
if ($DEBUG) {
  $message .= 'Required achievement tid is: ' . $activity['tid'] . chr(10);
  fwrite($file, $message);
  $message = '';
}  
        }
      } else {   
        $activity_or = db_or(); 
if ($DEBUG) {
  $message .= 'Required achievement tids are:' . chr(10);
}        
        foreach ($achievement->field_achievement_activity['und'] as $activity) {
          $activity_or->condition('a.field_mileage_activity_tid', $activity['tid'], '=');          
          if ($achievement->field_achievement_activity_all['und'][0]['value'] == 1) {
            $activities_array[] = $activity['tid'];
          }
if ($DEBUG) {
  $message .= '  ' . $activity['tid'] . chr(10);
}  
        }
if ($DEBUG) {
  if(!empty($activities_array)) {
    $message .= 'ALL activities are required' . chr(10);
  }
  fwrite($file, $message);
  $message = '';
}        
        $query1->condition($activity_or); 
        $query3->condition($activity_or); 
      }
    }
        /*
        INNER JOIN {field_data_field_mileage_activity} a ON n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)        
        AND (a.field_mileage_activity_tid = :db_condition_placeholder_3)
        */

        /*
        INNER JOIN {field_data_field_mileage_activity} a ON n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)        
        AND( (a.field_mileage_activity_tid = :db_condition_placeholder_3) OR (a.field_mileage_activity_tid = :db_condition_placeholder_4) OR (a.field_mileage_activity_tid = :db_condition_placeholder_5) )
        */

    // Get location criteria
    if (!empty($achievement->field_achievement_facility)) {
      $query1->join('field_data_field_mileage_facility', 'f', 'n.nid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
      $query2->join('field_data_field_mileage_facility', 'f', 'n.nid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
      $query3->join('field_data_field_mileage_facility', 'f', 'n.nid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));

      if (count($achievement->field_achievement_facility['und']) == 1 ) {
        foreach ($achievement->field_achievement_facility['und'] as $facility) {
          $facility_term = taxonomy_term_load($facility['tid']);
          $query1->condition('f.field_mileage_facility_value', $facility_term->name, '=');  
          $query2->condition('f.field_mileage_facility_value', $facility_term->name, '=');    
if ($DEBUG) {
  $message .= 'Required facility is: ' . $facility_term->name . chr(10);
  fwrite($file, $message);
  $message = '';
}  
        }
      } else {
        $facility_or = db_or();
if ($DEBUG) {
  $message .= 'Required facilities are:' . chr(10);
}        
        foreach ($achievement->field_achievement_facility['und'] as $facility) {
          $facility_term = taxonomy_term_load($facility['tid']);
          $facility_or->condition('f.field_mileage_facility_value', $facility_term->name, '=');  
          if ($achievement->field_achievement_facility_all['und'][0]['value'] == 1) {
            $facilities_array[] = $facility['tid'];
          }
if ($DEBUG) {
  $message .= '  ' . $facility_term->name . chr(10);
}
        }
if ($DEBUG) {
  if(!empty($facilities_array)) {
    $message .= 'ALL facilities are required' . chr(10);
  }
  fwrite($file, $message);
  $message = '';
}
        $query1->condition($facility_or);        
        $query2->condition($facility_or);            
      }
    }
        /*
        INNER JOIN {field_data_field_mileage_facility} f ON n.nid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)        
        AND (f.field_mileage_facility_value = :db_condition_placeholder_4)
        */

        /*
        INNER JOIN {field_data_field_mileage_facility} f ON n.nid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)        
        AND( (f.field_mileage_facility_value = :db_condition_placeholder_4) OR (f.field_mileage_facility_value = :db_condition_placeholder_5) OR (f.field_mileage_facility_value = :db_condition_placeholder_6) )
        */

        
    // Get group membership criteria
    if (!empty($achievement->field_achievement_group)) {
      $query1->join('mo_cms_user_groups_membership', 'm', 'n.uid = m.uid AND (m.approved = :approved AND m.deleted = :deleted AND m.blocked = :blocked)', array(':approved' => 1, ':deleted' => 0, ':blocked' => 0));
      $query2->join('mo_cms_user_groups_membership', 'm', 'n.uid = m.uid AND (m.approved = :approved AND m.deleted = :deleted AND m.blocked = :blocked)', array(':approved' => 1, ':deleted' => 0, ':blocked' => 0));
      $query3->join('mo_cms_user_groups_membership', 'm', 'n.uid = m.uid AND (m.approved = :approved AND m.deleted = :deleted AND m.blocked = :blocked)', array(':approved' => 1, ':deleted' => 0, ':blocked' => 0));


      if (count($achievement->field_achievement_group['und']) == 1 ) {
        foreach ($achievement->field_achievement_group['und'] as $usergroup) {
          $query1->condition('m.entity_id', $usergroup['target_id'], '=');  
          $query2->condition('m.entity_id', $usergroup['target_id'], '=');  
          $query3->condition('m.entity_id', $usergroup['target_id'], '=');  
if ($DEBUG) {
  $message .= 'Required group id is: ' . $usergroup['target_id'] . chr(10);
  fwrite($file, $message);
  $message = '';
}
        }
      } else {
        $usergroup_or = db_or();
if ($DEBUG) {
  $message .= 'Required group ids are:' . chr(10);
}        
        foreach ($achievement->field_achievement_group['und'] as $usergroup) {
          $usergroup_or->condition('m.entity_id', $usergroup['target_id'], '=');  
          if ($achievement->field_achievement_group_all['und'][0]['value'] == 1) {
            $usergroups_array[] = $usergroup['target_id'];
          }
if ($DEBUG) {
  $message .= '  ' . $usergroup['target_id'] . chr(10);
}
        }
if ($DEBUG) {
  if(!empty($usergroups_array)) {
    $message .= 'ALL groups are required' . chr(10);
  }
  fwrite($file, $message);
  $message = '';
}         
        $query1->condition($usergroup_or);        
        $query2->condition($usergroup_or); 
        $query3->condition($usergroup_or);         
      }
    }
   
        /*
        INNER JOIN {mo_cms_user_groups_membership} m ON n.uid = m.uid AND (m.approved = :approved AND m.deleted = :deleted AND m.blocked = :blocked)        
        AND (m.entity_id = :db_condition_placeholder_5)
        */

        /*
        INNER JOIN {mo_cms_user_groups_membership} m ON n.uid = m.uid AND (m.approved = :approved AND m.deleted = :deleted AND m.blocked = :blocked)        
        AND( ((m.entity_id = :db_condition_placeholder_5) OR ((m.entity_id = :db_condition_placeholder_6) OR ((m.entity_id = :db_condition_placeholder_7) )
        */

        
    // Get date criteria
    if (!empty($achievement->field_achievement_dates)) {
if ($DEBUG) {
  $message .= 'Dates provided are:' . chr(10);
}
      foreach ($achievement->field_achievement_dates['und'] as $badge_date) {
        $start_date = date_parse($badge_date['value']); 
        $min_date = date("Y-m-d H:i:s", mktime($start_date['hour'], $start_date['minute'], $start_date['second'], $start_date['month'], $start_date['day'], $start_date['year']));
      
        if (!empty($badge_date['value2'])) {       
          $end_date = date_parse($badge_date['value2']);
          $max_date = date("Y-m-d H:i:s", mktime($end_date['hour'], $end_date['minute'], $end_date['second'], $end_date['month'], $end_date['day'], $end_date['year']));         
        } else {
          $max_date = date("Y-m-d H:i:s", mktime(23, 59, 59, $start_date['month'], $start_date['day'], $start_date['year']));
        } 
        
        $query1->condition('t.field_mileage_date_value', $min_date, '>=');
        $query2->condition('t.field_mileage_date_value', $min_date, '>=');
        $query3->condition('t.field_mileage_date_value', $min_date, '>=');
        $query1->condition('t.field_mileage_date_value', $max_date, '<=');
        $query2->condition('t.field_mileage_date_value', $max_date, '<=');
        $query3->condition('t.field_mileage_date_value', $max_date, '<=');
if ($DEBUG) {
  $message .= '  greater than or equal to ' . $min_date . chr(10);
  $message .= '  less than or equal to ' . $max_date . chr(10);
}
      }
if ($DEBUG) {      
  fwrite($file, $message);
  $message = '';
}               
    }  else {    
      $challenge_dates = mo_project_get_challenge_dates_by_year($yr);
      $query1->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
      $query2->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
      $query3->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
      $query1->condition('t.field_mileage_date_value', $challenge_dates['end'], '<=');
      $query2->condition('t.field_mileage_date_value', $challenge_dates['end'], '<=');
      $query3->condition('t.field_mileage_date_value', $challenge_dates['end'], '<=');
if ($DEBUG) {
  $message .= 'No dates were provided.  Challenge dates for ' . $yr . ' are:' . chr(10);
  $message .= '  greater than or equal to ' . $challenge_dates['start'] . chr(10);
  $message .= '  less than or equal to ' . $challenge_dates['end'] . chr(10);
  fwrite($file, $message);
  $message = '';
}
    }
        /*       
        AND (t.field_mileage_date_value >= :db_condition_placeholder_5) AND (t.field_mileage_date_value <= :db_condition_placeholder_6)
        */


if ($DEBUG) {
  $q = mo_project_get_query_string($query1);
  $message .= chr(10) . '$query1 finds the total distance logged for all criteria and the date it was earned' . chr(10) . chr(10);
  $message .= print_r($q, TRUE) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
  
  
//--------------------------------------------------------------------------
    // Query build is complete, compare to previous_query
    if ($previous_query === mo_project_get_query_string($query1)) {
      // Same query, no need to execute again, use previous results to save time and resources.
      $result1 = array();
      $obj = new stdClass();
      $obj->distance = $previous_distance;
      $obj->earned = $previous_earned;      
      $result1[] = $obj;
if ($DEBUG) {
  $message .= 'Same query, no need to execute again, use previous results to save time and resources' . chr(10);
  $message .= 'previous_distance is ' . $previous_distance . chr(10);
  $message .= 'previous_earned is ' . $previous_earned . chr(10);
  $message .= 'total_mileage is ' . $total_mileage . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
    } else {
      // New query, execute for results.
      $previous_distance = 0;
      $previous_earned = '1980-01-01 00:00:00';
      unset($total_mileage);
      $result1 = $query1->execute()->fetchAll();    
if ($DEBUG) {
  $message .= 'New query, execute for results' . chr(10);   
  fwrite($file, $message);
  $message = '';
}
    }

    if (!empty($result1)) {     // Query executed successfully
if ($DEBUG) {
  $message .= 'Query executed successfully' . chr(10);    
  fwrite($file, $message);
  $message = '';
}    
      if ( (empty($result1[0]->distance)) AND (empty($result1[0]->field_mileage_distance_value)) ) {
        // No rows found
        
/*        // Could still be a valid earned badge - Is this a badge with sub-badges?
        if (in_array($achievement->nid, $all_bs_with_subs)) {

          // Are the sub-badge requirements met?
          $continue = mo_project_evaluate_sub_badges($uid, $yr, $achievement);
          
          if ( ($continue == FALSE) AND ($action == 'delete') ) {
            // Badge not earned
            $deleted_id = mo_project_delete_badges($uid, $achievement->nid);
            $changed_badges[$achievement->nid] = $achievement->title;
          }
        } else {
*/        
if ($DEBUG) {
  $message .= 'No rows found' . chr(10) . 'Badge NOT earned' . chr(10);
  fwrite($file, $message);
  $message = '';
}
          // Badge not earned
          if ($action == 'delete') {
            $deleted_id = mo_project_delete_badges($uid, $suid, $achievement->nid);
            if (is_numeric($deleted_id)) {
              $changed_badges[$achievement->nid] = $achievement->title;
            }
if ($DEBUG) {
  $message .= '$action is ' . $action . '.' . chr(10) . 'Call mo_project_delete_badges.' . chr(10);
  if ($deleted_id === FALSE) {
    $message .= 'mo_project_delete_badges DID NOT delete a row from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . chr(10) . chr(10);
  } else if (is_numeric($deleted_id)) {
    $message .= 'mo_project_delete_badges deleted all rows from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $deleted_id . chr(10) . chr(10);
  } else {
    $message .= 'CHECK TABLE badges_earned MANUALLY.' . chr(10);
    $message .= 'Function mo_project_delete_badges returned: ' . print_r($deleted_id, TRUE) . ' when asked to delete rows from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . chr(10) . chr(10);
  }
  $message .= '$changed_badges array is ' . print_r($changed_badges, TRUE);
  $message .= chr(10) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
          }
//        }

      } else {
if ($DEBUG) {
  $message .= 'At least one record meets the activity, location, group and date criteria' . chr(10);
  if ($continue) {
    $message .= '$continue is TRUE' . chr(10);
  } else {
    $message .= '$continue is FALSE' . chr(10);
  }
  fwrite($file, $message);
  $message = '';
}      
        // At least one record meets the activity, location, group and date criteria

/*        // Is this a badge with sub-badges?
        if (in_array($achievement->nid, $all_bs_with_subs)) {

          // Are the sub-badge requirements met?
          $continue = mo_project_evaluate_sub_badges($uid, $yr, $achievement);
        }
*/        
        // When multiple activities are selected as a condition, the condition can require either:
        // ANY of the selected activities, or
        // ALL of the selected activities.
        // We already know at least one of the activities are met, or the query would not have returned results
        // Does the badge require a set of ALL of the selected activities?
        if ( ($continue) AND (!empty($activities_array)) ) {
          // Set query2 to return activity tids for all logged miles that meet other criteria
          $query2->addField('a', 'field_mileage_activity_tid', 'activity');   
          $activities_result = $query2->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'ALL of the selected activities are required' . chr(10);
  $q = mo_project_get_query_string($query2);
  $message .= chr(10) . '$query2 finds all activities logged for all other criteria. (used to check when an achievement requires ALL of a set of multiple activities)' . chr(10) . chr(10);
  $message .= print_r($q, TRUE) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
          // Compare the activities the user logged to the activities required for the badge
          foreach ($activities_array AS $activity) {
            if ($continue) {        
              $continue = in_array($activity, $activities_result);
if ($DEBUG) {
  if ($continue) {
    $message .= 'Required activity ' . $activity . ' found' . chr(10);
  }
}  
            } else {
              // ALL-selected-activities condition NOT met, Badge not earned
              // break loop to save time and resources
              break;
if ($DEBUG) {
  $message .= 'Required activity ' . $activity . ' NOT found' . chr(10) . 'Badge NOT earned' . chr(10) . chr(10);
}               
            }
          }
        }
if ($DEBUG) {  
  fwrite($file, $message);
  $message = '';
}
      
        // Same logic as activities above
        // Does the badge require a set of ALL of the selected facilities?
        if ( ($continue) AND (!empty($facilities_array)) ) {

          // Set query3 to return facility tids for all logged miles that meet other criteria
          $query3->join('taxonomy_term_data', 'x', 'f.field_mileage_facility_value = x.name AND (x.vid = 11)');
          $query3->addField('x', 'tid', 'facility');    
          $facilities_result = $query3->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'ALL of the selected facilities are required' . chr(10);
  $q = mo_project_get_query_string($query3);
  $message .= chr(10) . '$query3 finds all facilities logged for all other criteria. (used to check when an achievement requires ALL of a set of multiple facilities)' . chr(10) . chr(10);
  $message .= print_r($q, TRUE) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}          
          // Compare the facilities the user logged to the facilities required for the badge
          foreach ($facilities_array AS $facility) {
            if ($continue) {            
              $continue = in_array($facility, $facilities_result);
if ($DEBUG) {
  if ($continue) {
    $message .= 'Required facility ' . $facility . ' found' . chr(10);
  }
}              
            } else {
              // ALL-selected-facilities condition NOT met, Badge not earned
              // break loop to save time and resources
              break;
if ($DEBUG) {
  $message .= 'Required facility ' . $facility . ' NOT found' . chr(10) . 'Badge NOT earned' . chr(10) . chr(10);
}               
              
            }            
          }
        }
if ($DEBUG) {  
  fwrite($file, $message);
  $message = '';
}
        
        // Same logic as activities above
        // Does the badge require a set of ALL of the selected groups?
        if ( ($continue) AND (!empty($usergroups_array)) ) {
        
          // Set query4 to return all groups which the user is a member of
          $query4 = db_select('mo_cms_user_groups_membership', 'm');
          $query4->fields('m', array('entity_id'));
          $query4->condition('m.uid', $uid, '=');
          $query4->condition('m.approved', 1, '=');
          $query4->condition('m.deleted', 0, '=');
          $query4->condition('m.blocked', 0, '=');    
          $groups_result = $query4->execute()->fetchCol();
if ($DEBUG) {
  $message .= 'ALL of the selected groups are required' . chr(10);
  $q = mo_project_get_query_string($query4);
  $message .= chr(10) . '$query4 finds all groups logged for all other criteria. (used to check when an achievement requires ALL of a set of multiple groups)' . chr(10) . chr(10);
  $message .= print_r($q, TRUE) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
} 
          // Compare the groups the user is a member of to the groups required for the badge
          foreach ($usergroups_array AS $ugroup) {
            if ($continue) {            
              $continue = in_array($ugroup, $groups_result);
if ($DEBUG) {
  if ($continue) {
    $message .= 'Required group ' . $ugroup . ' found' . chr(10);
  }
}              
            } else {
              // ALL-selected-usergroups condition NOT met, Badge not earned
              // break loop to save time and resources
              break;
if ($DEBUG) {
  $message .= 'Required group ' . $ugroup . ' NOT found' . chr(10) . 'Badge NOT earned' . chr(10) . chr(10);
}               
            }
          }
        }
if ($DEBUG) {  
  fwrite($file, $message);
  $message = '';
}

        // Does the badge require a mileage threshold?
        if ( ($continue) AND (!empty($achievement->field_achievement_threshold)) ) {

          // Get threshold value
          $threshold_item = field_get_items('node', $achievement, 'field_achievement_threshold');
          $threshold = $threshold_item[0]['value'];
          if ($threshold > 0) {
if ($DEBUG) {
  $message .= 'The badge $threshold value is ' . $threshold . chr(10);
}          
            // Does the threshold have to be met in one single mileage log entry?
            if ( (!empty($achievement->field_achievement_threshold_1log)) AND ($achievement->field_achievement_threshold_1log['und'][0]['value'] <> 0) ) {
      
if ($DEBUG) {
  $message .= 'Threshold must be met in one single mileage log entry.' . chr(10);
}
              foreach ($result1 as $row) {   // Should only be one row, but just in case  
                $total_mileage = $row->distance;

                // Because Mileage Distance datatype is float, and Achievement Threshold datatype is decimal,
                // sometimes strange things happen with the values 
                // EXAMPLE: ($total_mileage is 6.1999998092651. $threshold is 6.200. $continue is FALSE)
                // Explicitly cast both variables to float, and round to three places
                $new_total_mileage = round((float)$total_mileage, 3);
                $new_threshold = round((float)$threshold, 3);
                
                // Meet mileage threshold?
                if ($new_total_mileage < $new_threshold) {
                  $continue = FALSE;
if ($DEBUG) {
  $message .= '$total_mileage for this row is ' . $total_mileage . chr(10);
  $message .= 'After casting both variables to float, and rounding to three places:' . chr(10);
  $message .= '$new_total_mileage ' . $new_total_mileage . ' is LESS THAN $new_threshold ' . $new_threshold . chr(10);
  if ($continue) {
    $message .= '$continue is TRUE' . chr(10);
  } else {
    $message .= '$continue is FALSE' . chr(10);
  }
  $message .= 'Badge NOT earned.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}                  
                } else if ( (!empty($achievement->field_achievement_threshold_equl)) AND ($achievement->field_achievement_threshold_equl['und'][0]['value'] <> 0) AND ($new_total_mileage > (ceil($new_threshold))) ) {
                  // Exact Value threshold (as opposed to cumulative)
                  $continue = FALSE;  
if ($DEBUG) {
  $message .= 'Mileage logged must be an "Exact" match (the value or up to the next integer).' . chr(10);
  $message .= '$total_mileage for this row is ' . $total_mileage . chr(10);
  $message .= 'After casting both variables to float, and rounding to three places:' . chr(10);
  $message .= '$new_total_mileage ' . $new_total_mileage . ' is GREATER THAN $new_threshold ' . $new_threshold . chr(10) . 'AND $new_total_mileage ' . $new_total_mileage . ' is GREATER THAN the next integer ' . (ceil($new_threshold)) . chr(10);
  if ($continue) {
    $message .= '$continue is TRUE' . chr(10);
  } else {
    $message .= '$continue is FALSE' . chr(10);
  }
  $message .= 'Badge NOT earned.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}                  
                } else {
                  $continue = TRUE;
                  break;
                }
              }              
              
            } else {       
if ($DEBUG) {
  $message .= 'Threshold may be met with cumulative mileage log entries.' . chr(10);
}         
              $total_mileage = 0;      
if ($DEBUG) {
  $i = 0;
}
              foreach ($result1 as $row) {   // Should only be one row, but just in case              
if ($DEBUG) {
  $i++;
  $message .= '$total_mileage ' . $total_mileage;
}
                $total_mileage += $row->distance;
if ($DEBUG) {
  $message .= ' plus row ' . $i . ' mileage (' . $row->distance . ') equals ' . $total_mileage . chr(10);
}
              }
          
              // Because Mileage Distance datatype is float, and Achievement Threshold datatype is decimal,
              // sometimes strange things happen with the values 
              // EXAMPLE: ($total_mileage is 6.1999998092651. $threshold is 6.200. $continue is FALSE)
              // Explicitly cast both variables to float, and round to three places
              $new_total_mileage = round((float)$total_mileage, 3);
              $new_threshold = round((float)$threshold, 3);
             
              // Meet mileage threshold?
              if ($new_total_mileage < $new_threshold) {
                $continue = FALSE;
if ($DEBUG) { 
  $message .= 'After casting both variables to float, and rounding to three places:' . chr(10);
  $message .= '$new_total_mileage ' . $new_total_mileage . ' is LESS THAN $new_threshold ' . $new_threshold . chr(10);
  if ($continue) {
    $message .= '$continue is TRUE' . chr(10);
  } else {
    $message .= '$continue is FALSE' . chr(10);
  }
  $message .= 'Badge NOT earned.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}                
              } else if ( (!empty($achievement->field_achievement_threshold_equl)) AND ($achievement->field_achievement_threshold_equl['und'][0]['value'] <> 0) AND ($new_total_mileage > (ceil($new_threshold))) ) {
                // Exact Value threshold (as opposed to cumulative)
                $continue = FALSE; 
if ($DEBUG) {
  $message .= 'Mileage logged must be an "Exact" match (the value or up to the next integer).' . chr(10);
  $message .= 'After casting both variables to float, and rounding to three places:' . chr(10);
  $message .= '$new_total_mileage ' . $new_total_mileage . ' is GREATER THAN $new_threshold ' . $new_threshold . chr(10) . 'AND $new_total_mileage ' . $new_total_mileage . ' is GREATER THAN the next integer ' . (ceil($new_threshold)) . chr(10);
  if ($continue) {
    $message .= '$continue is TRUE' . chr(10);
  } else {
    $message .= '$continue is FALSE' . chr(10);
  }
  $message .= 'Badge NOT earned.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
              }   // end if meet mileage threshold
            }   // end if single entry vs. cumulative
          }   // end if threshold greater than zero
        }

        // Badge earned   
        if ($continue) {
if ($DEBUG) {
  $message .= 'FINAL EVALUATION:' . chr(10);
  if ($continue) {
    $message .= '  $continue is TRUE' . chr(10);
  } else {
    $message .= '  $continue is FALSE' . chr(10);
  }
  $message .= '  Badge has been EARNED.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}

          if ($action == 'write') {

            // Convert the date earned to a timestamp
            if (!empty($result1[0]->earned)) {
              $timestamp = strtotime($result1[0]->earned);
            } else {
              $timestamp = NULL;
            }
            
            // Must return the written_id
            $written_id = mo_project_write_new_badges($uid, $suid, $achievement->nid, $timestamp);
            if (is_numeric($written_id)) {
              $changed_badges[$achievement->nid] = $achievement->title;
            }
if ($DEBUG) {
  $message .= '$action is ' . $action . '.' . chr(10) . 'Call mo_project_write_new_badges.' . chr(10);
  if ($written_id === FALSE) {
    $message .= 'mo_project_write_new_badges DID NOT insert a new row in table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . chr(10) . chr(10);
  } else {
    $message .= 'mo_project_write_new_badges inserted a new row in table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $written_id . chr(10) . chr(10);
  }
  $message .= '$changed_badges array is ' . print_r($changed_badges, TRUE); 
  fwrite($file, $message);
  $message = '';
}
            }
/*          // Increment the sub-badge counter
          } else if ($action == 'none') {
            $subbadge_count++;
          }
*/          
        } else {     // $continue = FALSE;
if ($DEBUG) {
  $message .= 'FINAL EVALUATION:' . chr(10);
  if ($continue) {
    $message .= '  $continue is TRUE' . chr(10);
  } else {
    $message .= '  $continue is FALSE' . chr(10);  
  }
  $message .= '  Badge NOT earned.' . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
          // Badge not earned
          if ($action == 'delete') {
            $deleted_id = mo_project_delete_badges($uid, $suid, $achievement->nid);
            if (is_numeric($deleted_id)) {
              $changed_badges[$achievement->nid] = $achievement->title;
            }
if ($DEBUG) {
  $message .= '$action is ' . $action . '.' . chr(10) . 'Call mo_project_delete_badges.' . chr(10);
  if ($deleted_id === FALSE) {
    $message .= 'mo_project_delete_badges DID NOT delete a row from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . chr(10) . chr(10);
  } else if (is_numeric($deleted_id)) {
    $message .= 'mo_project_delete_badges deleted all rows from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . chr(10) . chr(10);
  } else {
    $message .= 'CHECK TABLE badges_earned MANUALLY.' . chr(10);
    $message .= 'Function mo_project_delete_badges returned: ' . print_r($deleted_id, TRUE) . ' when asked to delete rows from table badges_earned for user ' . $uid . ', sub-user ' . $suid . ' and badge ' . $achievement->nid . '.' . chr(10) . chr(10); 
  }
  $message .= '$changed_badges array is ' . print_r($changed_badges, TRUE);
  $message .= chr(10) . chr(10) . chr(10);
  fwrite($file, $message);
  $message = '';
}
          }
        } 
        
      }  // end if (results of query1)
    }  // end if (query1 executed successfully)

    // Set 'previous' values
    $previous_query = mo_project_get_query_string($query1);
    if ( !empty($result1[0]->earned) ) {
      $previous_earned = $result1[0]->earned;
    } else {
      $previous_earned = '1980-01-01 00:00:00';    
    }
    if (isset($total_mileage)) {
      $previous_distance = $total_mileage;
    } else {
      $previous_distance = 0;    
    }
    
  }  // end loop (evaluate each badge
  
  if (!empty($changed_badges)) {
if ($DEBUG) {
  $message .= 'END EXECUTION OF FUNCTION mo_project_evaluate_badges FOR USER ' . $uid . ', SUB-USER ' . $suid . chr(10) . chr(10);
  fclose($file);
}  
    // Names and ids of badges written or deleted
    return $changed_badges;
/*  } else if ($action == 'none') {
    // Count of sub-badges earned
    return $subbadge_count;
*/
  } else {
    return FALSE;
if ($DEBUG) {
  $message .= 'END EXECUTION OF FUNCTION mo_project_evaluate_badges FOR USER ' . $uid . ', SUB-USER ' . $suid . chr(10);
  $message .= 'ZERO BADGES ADDED OR DELETED' . chr(10) . chr(10);
  fclose($file);
}
  }
}


/**
 *  @brief  Re-checks all badges for current challenge year for the supplied user
 *  
 *  @param [in] $uid         User id of user
 *  @return  nothing.
 *  
 *  @details  2015-04-28 
 */ 
function mo_project_badge_recheck($uid) {
 
  // Load IDs of all badges into array $badge_nids
  $query_all = db_select('node', 'n');
  $query_all->fields('n', array('nid'));
  $query_all->condition('n.type', 'achievement', '=');
  $query_all->condition('n.status', 0, '<>');  
  $badge_nids = $query_all->execute()->fetchCol();

  // Remove any Administratively Awarded badges
  $query_adm = db_select('field_data_field_achievement_admin', 'f');
  $query_adm->fields('f', array('entity_id'));
  $query_adm->condition('f.deleted', 0, '=');
  $query_adm->condition('f.field_achievement_admin_value', 1, '=');  
  $adm_nids = $query_adm->execute()->fetchCol();

  if (!empty($adm_nids)) {
    $badge_nids = array_diff($badge_nids, $adm_nids);
    sort($badge_nids);
  }
  
  // Remove any badges from Other years
  $query_yer = db_select('field_data_field_achievement_dates', 'd');
  $query_yer->fields('d', array('entity_id'));
  $query_yer->distinct();
  $query_yer->where('YEAR(d.field_achievement_dates_value) <> ' . date("Y"));  
  $elim_yer_badges = $query_yer->execute()->fetchCol();

  if (!empty($elim_yer_badges)) {
    $badge_nids = array_diff($badge_nids, $elim_yer_badges);
    sort($badge_nids);
  }
  
  // Get Sub-Users
  $subuser_array = mo_project_get_subusers($uid);

  $all_deleted_badges = array();
  $all_added_badges = array();
  
  foreach($subuser_array AS $row) {
      // Check for badges that SHOULD NOT have been earned
      $deleted_badges = mo_project_evaluate_badges($uid, $row->suid, $badge_nids, date("Y"), 'delete');
      $d = array_push($all_deleted_badges, $deleted_badges);
      
      // Remove any deleted badges from badge_nids
      if ( !empty($deleted_badges) AND $deleted_badges !== FALSE ) {
        $deleted_badge_nids = array_keys($deleted_badges);
        $badge_nids = array_diff($badge_nids, $deleted_badge_nids);
        sort($badge_nids);
      }

      // Check for badges that SHOULD have been awarded
      $added_badges = mo_project_evaluate_badges($uid, $row->suid, $badge_nids, date("Y"), 'write');
      $a = array_push($all_added_badges, $added_badges);
  }
  
  // Inform the user
  $account = user_load($uid);
  $fname_item = field_get_items('user', $account, 'field_user_first_name');
  $fname = ucwords(strtolower(trim($fname_item[0]['value'])));
  $lname_item = field_get_items('user', $account, 'field_user_last_name');
  $lname = ucwords(strtolower(trim($lname_item[0]['value'])));
  
  $message = '<pre>Badge Re-recheck complete for user ' . $fname . ' ' . $lname . '.<br><br>';
  $i=0;
  foreach($subuser_array AS $row) {
    if(!empty($all_added_badges[$i])) {
      $message .= 'Badges added for sub-user ' . $row->name . ' (' . $row->suid. '):<br>';
      foreach($all_added_badges[$i] AS $nid => $title) {
        $message .= '&nbsp;&#149;&nbsp;&nbsp;' . $title . '<br>';
      }
    } else {
      $message .= 'No badges needed to be added for sub-user ' .$row->name . ' (' . $row->suid. ').<br>';
    }
    if(!empty($all_deleted_badges[$i])) {
      $message .= 'Badges deleted for sub-user ' . $row->name . ' (' . $row->suid. '):<br>';
      foreach($all_deleted_badges[$i] AS $nid => $title) {
        $message .= '&nbsp;&#149;&nbsp;&nbsp;' . $title . '<br><br>';
      }
    } else {
      $message .= 'No badges needed to be deleted for sub-user ' . $row->name . ' (' . $row->suid. ').<br><br>';
    }
    $i++;
  }
  $message .= '</pre>';
 
  drupal_set_message($message);
  $content = mo_project_blank_page();
  return $content;
}


/**
 *  @brief  Calls mo_project_evaluate_badges with the array of sub-badges
 *  
 *  @param [in] $uid         User id of user
 *  @param [in] $yr          The Challenge year
 *  @param [in] $achievement Full node of the main badge (the one with the sub-badges to be evaluated)
 *  
 *  @return  TRUE if the sub-badge requirements are met.
 *  
 *  @details  2014-06-06 
 */
/*
function mo_project_evaluate_sub_badges($uid, $yr, $achievement) {
  // Loop: create array of nids of sub-badges selected for this badge
  foreach ($achievement->field_achievement_subbadge['und'] as $subbadge_criteria) {
    $subbadge_array[] = $subbadge_criteria['target_id'];
  }
          
  // Call mo_project_evaluate_badges, passing in the sub-badge array and
  // action 'none', which returns a count of the badges that were earned
  $sub_count = mo_project_evaluate_badges($uid, $subbadge_array, $yr, 'none');
  
  // Are the sub-badge requirements met?
  if ( ($achievement->field_achievement_subbadge_all['und'][0]['value'] == 1) AND 
    (count($subbadge_array) != $sub_count) ) {
    // ALL-selected-sub-badges condition NOT met, Badge not earned
    $continue = FALSE;

  } else if ($sub_count == 0) {
    // Sub-badge conditions were NOT met, Badge not earned
    $continue = FALSE;

  } else {
    // Badge earned
    $continue = TRUE;
  }

  return $continue;
}
*/

/**
 *  @brief  Gets achievement nids that have another badge as one criteria
 *  
 *  @return  Array of achievement nids
 *  
 *  @details 2014-06-09 
 */
/*
function mo_project_get_overall_badges() {

  $query = db_select('node', 'n');
  $query->join('field_data_field_achievement_subbadge', 's', 'n.nid = s.entity_id AND (s.entity_type = :b_type AND s.deleted = :b_deleted)', array(':b_type' => 'node', ':b_deleted' => 0));
  $query->fields('n', array('nid'));
  $query->distinct();  
  $query->condition('n.type', 'achievement');
  $query->condition('n.status', 0, '<>');
  $results = $query->execute()->fetchCol(); 

  return $results;
}
*/

