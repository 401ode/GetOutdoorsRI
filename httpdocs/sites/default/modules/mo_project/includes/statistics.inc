<?php
/**
 *  @file statistics.inc
 *  @brief  Functions for generating Challenge statistics
 *
 *  @details 
 *  mo_project_stats_overview = Gets display data for /stats main page
 *  mo_project_count_users = Gets count of users by register date or last access date
 *  mo_project_stats_activities = Gets display data for miles logged by county and activity
 *  mo_project_stats_badges = Gets display data for number of users earning general mileage or activity mileage badges
 *  mo_project_stats_count_badgeholders = Gets count of users logging the passed-in threshold and optional passed-in activity
 *  mo_project_stats_counties = Gets display data for users registered, new users registered with the last ten days, and verified miles logged - by county
 *  mo_project_stats_counties_csv = Provides the same data as mo_project_stats_counties in downloadable csv format
 *  mo_project_stats_demographics = 'Users' Tab - Count of Users and Sub-users by Gender, Age Bracket, and Region
 *  mo_project_stats_groups = Gets display data for counts of user groups and umbrella groups
 *  mo_project_count_groups = Gets count of groups open to join, hidden, owner-approval, and closed
 *  mo_project_stats_leaders = Gets display data for Top 5 participants by activity, shows name, gender, county, and distance
 *  mo_project_stats_trends = Gets display data for Number of Users registered and Miles logged per week and month
 *  mo_project_stats_milestones = Gets display data for Number of Users achieving specific mileage thresholds
 */


/**
 *  @brief  'Overview' Tab - Functions to populate the /stats page and it's tabs
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_overview() {
  
  $now = time();
  $week_ago = date_modify(date_create(), '-7 days');
  $month_ago = date_modify(date_create(), '-30 days');
  $end_date = date('Y-m-d H:i:s', $now);
  $challenge_dates = mo_project_get_challenge_dates_by_year(2013);

  // Verified users with at least one mileage record
  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');
  
  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');    
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->fields('n', array('uid'));
  $query->distinct();
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');  
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $query->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
  $query->condition('t.field_mileage_date_value', $end_date, '<'); 
  $users_with_a_mileage_record = $query->execute()->rowCount();

  $new_years_day = date("Y-m-d H:i:s", strtotime('first day of January' . date("Y"))); 
  // Number of Main User miles in $year
  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');  
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('subuser', 'su', 's.field_mileage_subuser_value = su.suid');
  $query->join('taxonomy_term_data', 'x', 'su.type_tid = x.tid');  
  $query->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');  
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $query->condition('x.name', 'Me', '=');
  $query->condition('t.field_mileage_date_value', $new_years_day, '>=');
  $query->condition('t.field_mileage_date_value', $end_date, '<'); 
  $miles_users = $query->execute()->fetchField();
  
  // Number of Buddy miles in $year
  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');  
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('subuser', 'su', 's.field_mileage_subuser_value = su.suid');
  $query->join('taxonomy_term_data', 'x', 'su.type_tid = x.tid');  
  $query->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');  
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $query->condition('x.name', 'Me', '<>');
  $query->condition('t.field_mileage_date_value', $new_years_day, '>=');
  $query->condition('t.field_mileage_date_value', $end_date, '<'); 
  $miles_buddy = $query->execute()->fetchField();
  
  // Number of miles logged within the last 7 days
  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');  
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 'dt', 'd.entity_id = dt.entity_id AND (dt.entity_type = :type AND dt.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');  
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $query->condition('dt.field_mileage_date_value', date_format($week_ago, 'Y-m-d H:i:s'), '>=');
  $query->condition('dt.field_mileage_date_value', $end_date, '<');
  $miles_week = $query->execute()->fetchField();

  // Number of miles logged within the last 30 days
  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');  
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 'dt', 'd.entity_id = dt.entity_id AND (dt.entity_type = :type AND dt.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');  
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $query->condition('dt.field_mileage_date_value', date_format($month_ago, 'Y-m-d H:i:s'), '>=');
  $query->condition('dt.field_mileage_date_value', $end_date, '<');
  $miles_month = $query->execute()->fetchField();
  
  // Users who have matched or exceeded 100 miles
  $challenge_met = mo_project_stats_count_badgeholders();

/*  // Medals requested 
  $query2 = db_select('field_data_field_user_medal', 'fc');
  $query2->join('field_data_field_user_medal_date_requested', 'r', 'fc.field_user_medal_value = r.entity_id AND (r.entity_type = :type1 AND r.deleted = :deleted1)', array(':type1' => 'field_collection_item', ':deleted1' => 0));
  $query2->addExpression('COUNT(r.entity_id)', 'users');
  $query2->condition('fc.entity_type', 'user');
  $query2->condition('fc.deleted', 0, '=');
  $medal_requests = $query2->execute()->fetchField(); 
  
  // Medals mailed
  $query3 = db_select('field_data_field_user_medal_date_mailed', 'm');
  $query3->addExpression('COUNT(DISTINCT m.entity_id)', 'users');
  $query3->condition('m.entity_type', 'field_collection_item');
  $query3->condition('m.deleted', 0, '=');
  $query3->isNotNull('m.field_user_medal_date_mailed_value');
  $medal_mailed = $query3->execute()->fetchField(); 
*/
  
  $container = array(); 

  $output = array(
    'header' => array(
      t('Informational Tidbit'),
        array(
          'data' => t('Total'),
          'class' => array('align-right'),
        ),
    ),
    'rows' => array(
      array(
        t('Total Verified users'),
        array(
          'data' => number_format(mo_project_count_users()),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Users with at least one mileage record'),
        array(
          'data' => number_format($users_with_a_mileage_record),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Miles logged by Main Users in ' . date("Y")),
        array(
          'data' => number_format($miles_users, 2),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Miles logged by Buddies in ' . date("Y")),
        array(
          'data' => number_format($miles_buddy, 2),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Users that have completed 100 Miles or more'),
        array(
          'data' => number_format($challenge_met),
          'class' => array('align-right'),
        ),
      ),      
      array(
        t('New users in the past 30 days'),
        array(
          'data' => number_format(mo_project_count_users($month_ago->getTimestamp())),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('New users in the past 7 days'),
        array(
          'data' => number_format(mo_project_count_users($week_ago->getTimestamp())),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Users on site in the past 30 days'),
        array(
          'data' => number_format(mo_project_count_users(FALSE, $month_ago->getTimestamp())),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Users on site in the past 7 days'),
        array(
          'data' => number_format(mo_project_count_users(FALSE, $week_ago->getTimestamp())),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Miles logged in the past 30 days'),
        array(
          'data' => number_format($miles_month, 2),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Miles logged in the past 7 days'),
        array(
          'data' => number_format($miles_week, 2),
          'class' => array('align-right'),
        ),
      ),

    ),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  
  $container[] = array(
    '#type' => 'markup',
    '#markup' => theme_table($output),
  );
  
/*  $rows = array();
  $rows[] = array(
    t('Users that have completed 100 Miles or more'),
    array(
      'data' => number_format($challenge_met),
      'class' => array('align-right'),
    ),
  );
  $rows[] = array(
    t('Users that have requested medals'),
    array(
      'data' => number_format($medal_requests),
      'class' => array('align-right'),
    ),
  );
  $rows[] = array(
    t('Users that have had medals mailed to them'),
    array(
      'data' => number_format($medal_mailed),
      'class' => array('align-right'),
    ),
  );

  $output = array(
  'header' => array(
    t('Medal Status'),
    array(
      'data' => t('Users'),
      'class' => array('align-right'),
    ),
  ),
  'rows' => $rows,
  'attributes' => array(),
  'caption' => NULL,
  'colgroups' => array(),
  'sticky' => TRUE,
  'empty' => NULL,
  );

  $container[] = array(
    '#type' => 'markup',
    '#markup' => theme_table($output),
  );
*/ 

  return $container;
}

 
/**
 *  @brief  Gets count of users by register date or last access date
 *  
 *  @param [in] $registered_since MySQL Date parameter
 *  @param [in] $accessed_since   MySQL Date parameter
 *  @return  count of users
 *  
 *  @details 2013
 */
function mo_project_count_users($registered_since=FALSE, $accessed_since=FALSE) {
  $query = db_select('users', 'u');
  $query->addField('u', 'uid');
  $query->condition('u.status', 0, '>');
  if ($registered_since) {
    $query->condition('u.created', $registered_since, '>=');
  }
  if ($accessed_since) {
    $query->condition('u.access', $accessed_since, '>=');
  }
  $result = $query->execute();
  return $result->rowCount();
}


/**
 *  @brief  'Activities' Tab - Miles logged by county and activity
 *   
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_activities () {
  $output = array();
  $headers = array(t('County'));
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $challenge_dates['end'];
  }

  // Begin writing SQL for pivot table
  // http://www.artfulsoftware.com/infotree/qrytip.php?id=78
  // http://www.artfulsoftware.com/infotree/qrytip.php?id=523
  $sql = "SELECT IFNULL(county, 'Statewide') AS County, ";
  
  $a_vocab = taxonomy_vocabulary_machine_name_load('activities');
  $activities = taxonomy_get_tree($a_vocab->vid, 0, 1);
  foreach ($activities as $activity) {    
    $headers[] = array(
      'data' => '<span class="activity-icon ir align-right ' . drupal_clean_css_identifier(strtolower($activity->name)) . '">' . $activity->name . '</span>',
      'class' => array('align-right'),
    );
    
    $sql .= "SUM( CASE aid WHEN " . $activity->tid . " THEN mile ELSE 0 END ) AS '" . $activity->name . "', ";
  }

  // Strip off last comma
  $sql = substr($sql, 0, -2);
  $sql .= " FROM ( " .
      "SELECT x.name AS county, a.field_mileage_activity_tid AS aid, " .
      "ROUND(SUM(d.field_mileage_distance_value), 2) as mile " . 
      "FROM node n " .
      "INNER JOIN users_roles r ON n.uid = r.uid " .      
      "INNER JOIN field_data_field_mileage_distance d ON n.nid = d.entity_id AND (d.entity_type = :type2 AND d.deleted = :deleted) " .
      "INNER JOIN field_data_field_mileage_date t ON n.nid = t.entity_id AND (t.entity_type = :type2 AND t.deleted = :deleted) " . 
      "INNER JOIN field_data_field_mileage_activity a ON n.nid = a.entity_id AND (a.entity_type = :type2 AND a.deleted = :deleted) " .
      "LEFT JOIN field_data_field_user_county c ON n.uid = c.entity_id AND (c.entity_type = :type3 AND c.deleted = :deleted) " .
      "INNER JOIN taxonomy_term_data x ON c.field_user_county_tid = x.tid " .
      "WHERE (n.type = :type) " .
      "AND (n.status <> :status) " .
      "AND (n.uid <> :deleted) " .
      "AND (r.rid IN (:roles)) " .  
      "AND (c.field_user_county_tid <> '') " .
      "AND (t.field_mileage_date_value >= :start) " .
      "AND (t.field_mileage_date_value < :end) " .
      "GROUP BY c.field_user_county_tid, a.field_mileage_activity_tid " .
    ") AS derived_1 " .
    "GROUP BY county WITH ROLLUP";
    
  $results = db_query($sql, array(
      ':type' => 'mileage',
      ':type2' => 'node',
      ':type3' => 'user',
      ':status' => 0, 
      ':deleted' => 0,
      ':roles' => array('14', '3'),
      ':start' => $challenge_dates['start'],
      ':end' => $end_date,
    )
  );   

  $rows = array();
  foreach ($results as $record) {
    $rows[] = (array)$record;
  }
  // Right-align each number value
  foreach ($rows as &$row) {
    foreach ($row as $key => &$cell_value) {
      if($key != 'County') {
        $value = (double)$cell_value;
        $cell_value = array(
          'data' => number_format($value, 2),
          'class' => array('align-right'),
        );
      }
    }
  }

  // Add a pager, even though we are not using db_select
  // http://knackforge.com/blog/sabareesh/creating-pager-drupal-without-dbselect-and-pagerdefault
  $per_page = 15;
  // Initialize the pager
  $current_page = pager_default_initialize(count($rows), $per_page);
  // Split your list into page sized chunks
  $chunks = array_chunk($rows, $per_page, TRUE);
  // Show the appropriate items from the list
  $output = theme('table', array(
    'header' => $headers,
    'rows' => $chunks[$current_page],
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  ));
  
  // Show the pager
  $output .= theme('pager', array('quantity',count($rows)));

  return $output;
}


/**
 *  @brief  'Badges' Tab - User totals for each achievement
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_badges() {
  if( (isset($_GET['sort'])) && (isset($_GET['order'])) ) {
    switch($_GET['order']){
      case 'Challenge':
        $order = 'year';
        break;
      case 'Badge':
        $order = 'title';
        break;
      case 'Badges Awarded':
        $order = 'awarded';
        break;
      default:
        $order = 'year';
    }
    
    if($_GET['sort'] == 'asc') {
      $sort = 'ASC';
    } else {
      $sort = 'DESC';
    }
  
  } else {
    // Default sort
    $order = 'year';
    $sort = 'DESC';
  }
 
  $query = db_select('node', 'n');
  $query->join('badges_earned', 'b', 'n.nid = b.field_badges_entity_id');
  $query->fields('n', array('title'));
  $query->addExpression('YEAR(FROM_UNIXTIME(b.field_badges_date))', 'year');
  $query->addExpression('COUNT(b.field_badges_entity_id)', 'awarded');
  $query->condition('n.type', 'achievement', '=');
  $query->condition('n.status', 0, '<>');
  $query->condition('b.field_badges_uid', 0, '<>');
  $query->groupBy('title');
  $query->groupBy('year');
  $query->orderBy($order, $sort);
  if ($order <> 'title') {  
    $query->orderBy('title', 'ASC');
  }
  $query = $query->extend('TableSort')->extend('PagerDefault')->limit(15); 
  $badgecounts = $query->execute()->fetchAll();
  
  $headers = array(
    array(
      'data' => t('Challenge'),
      'field' => 'year',
    ),
    array(
      'data' => t('Badge'),
      'field' => 'title',
    ),
    array(
      'data' => t('Badges Awarded'),
      'field' => 'awarded',
      'class' => array('align-right'),
    ),
  );
  $rows = array(); 

  foreach ($badgecounts as $badgecount) {  
    $rows[] = array(
        $badgecount->year,
        $badgecount->title,
        array(
          'data' => number_format($badgecount->awarded),
          'class' => array('align-right'),
        ),            
    );
  }

  $output = theme_table(
    array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => NULL,
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    )
  ).theme('pager');
  
  return $output;

}


/**
 *  @brief  'Distances' Tab - Number of Users achieving specific mileage thresholds
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_milestones() {
 
  $milestones = array(25, 50, 75, 100, 250, 500, 750, 1000);
  $headers = array(t('Users with:'));
  foreach($milestones AS $col) {
    $headers[] = array(
      'data' => t($col . '+ Miles'),
      'class' => array('align-right'),
    );
  }

  $rows = array();
  $newrow = array();
  $newrow[] = array(
    'data' => 'Any Activity'
  );
  foreach($milestones AS $amt) {
    $newrow[] = array(
      'data' => number_format(mo_project_stats_count_badgeholders($amt)),     
      'class' => array('align-right'),  
    );
  }
  $rows[] = $newrow;
 
  $a_vocab = taxonomy_vocabulary_machine_name_load('activities');
  $activities = taxonomy_get_tree($a_vocab->vid, 0, 1);
  foreach ($activities as $activity) {    
    $newrow = array();
    $newrow[] = array(
      'data' => $activity->name . '&nbsp;<span class="activity-icon ' . drupal_clean_css_identifier(strtolower($activity->name)) . ' ir">' . $activity->name . '</span>',
    );
    foreach($milestones AS $amt) {
      $newrow[] = array(
        'data' => number_format(mo_project_stats_count_badgeholders($amt, $activity->tid)),     
        'class' => array('align-right'),  
      );
    }
    $rows[] = $newrow;
  }

  $output = theme_table(
  array(
    'header' => $headers,
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
    )
  );

  $miles[] = array(
    '#type' => 'markup',
    '#markup' => $output,
  );
  return render($miles);  
}


/**
 *  @brief  'Distances' Tab helper
 *  
 *  @param [in] $threshold     Optional. Number of miles the user is required to log to be counted
 *  @param [in] $activity_tid  Optional. Activity tid the miles must be logged to
 *  @return  Count of users who meet the criteria
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 *  Gets count of users logging the passed-in threshold and optional passed-in activity
 */
function mo_project_stats_count_badgeholders($threshold = 100.00, $activity_tid = FALSE) {
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $challenge_dates['end'];
  }
  
  // Verified users
  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');

  $subqry = db_select('node', 'n');
  $subqry->join('users_roles', 'r', 'n.uid = r.uid');
  $subqry->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $subqry->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $subqry->fields('n', array('uid'));
  $subqry->addExpression('SUM(d.field_mileage_distance_value)', 'miles');
  $subqry->condition('n.type', 'mileage', '=');
  $subqry->condition('n.status', 0, '<>');
  $subqry->condition('n.uid', 0, '<>');  
  $subqry->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
  $subqry->condition('t.field_mileage_date_value', $end_date, '<');
  $subqry->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  if($activity_tid != FALSE) {
    $subqry->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $subqry->condition('a.field_mileage_activity_tid', $activity_tid, '=');
  }
  $subqry->groupBy('n.uid');

  $query = db_select($subqry, 's');
  $query->addExpression('COUNT(s.uid)', 'users');
  $query->condition('s.miles', $threshold, '>=');
  return $query->execute()->fetchField();
}

 
/**
 *  @brief  'Counties' Tab - Users and Mileage by County
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 *  References: http://w3shaman.com/article/working-table-and-pagination-drupal-7
 */
function mo_project_stats_counties() {
  if( (isset($_GET['sort'])) && (isset($_GET['order'])) ) {
    if($_GET['sort'] == 'asc') {
      $sort = 'ASC';
    } else {
      $sort = 'DESC';
    }
  
    switch($_GET['order']){
      case 'County':
        $order = 'County';
        break;
      case 'Participants':
        $order = 'Participants';
        break;
      case 'New Participants*':
        $order = 'New_Participants';
        break;
      case 'Miles':
        $order = 'Miles';
        break;
      default:
        $order = 'County';
    }
  } else {
    // Default sort
    $sort = 'ASC';
    $order = 'County';
  }

  $button = array(
    '#type' => 'markup',
    '#markup' => l('Export', 'stats/county/export', array(
        'attributes' => array(
            'id' => 'exp-county', 
            'class' => array('exp-county btn'),
        )
    ))
  );        
  $output = render($button);

  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');
  
  $subquery1 = db_select('field_data_field_user_county', 'c');
  $subquery1->addField('c', 'field_user_county_tid', 'cid');
  $subquery1->addExpression('COUNT(c.entity_id)', 'users');
  $subquery1->groupBy('cid');
  
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $challenge_dates['end'];
  }  
  
  $subquery2 = db_select('node', 'n');
  $subquery2->join('users_roles', 'r', 'n.uid = r.uid');  
  $subquery2->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $subquery2->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $subquery2->join('field_data_field_user_county', 'c', 'n.uid = c.entity_id AND (c.entity_type = :type2 AND c.deleted = :deleted2)', array(':type2' => 'user', ':deleted2' => 0));
  $subquery2->addField('c', 'field_user_county_tid', 'cid');
  $subquery2->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $subquery2->condition('n.type', 'mileage');
  $subquery2->condition('n.status', 0, '<>');
  $subquery2->condition('n.uid', 0, '<>');
  $subquery2->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $subquery2->condition('c.field_user_county_tid', '', '<>');
  $subquery2->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
  $subquery2->condition('t.field_mileage_date_value', $end_date, '<');
  $subquery2->groupBy('cid');

  $tendays_ago = strtotime('-10 days');
  $subquery3 = db_select('users', 'u');
  $subquery3->join('field_data_field_user_county', 'c', 'u.uid = c.entity_id AND (c.entity_type = :type3 AND c.deleted = :deleted3)', array(':type3' => 'user', ':deleted3' => 0));
  $subquery3->addField('c', 'field_user_county_tid', 'cid');
  $subquery3->addExpression('COUNT(u.uid)', 'new_users');
  $subquery3->condition('u.created', $tendays_ago, '>=');
  $subquery3->condition('u.status', 0, '<>');
  $subquery3->condition('c.field_user_county_tid', '', '<>');
  $subquery3->groupBy('cid');
  
  $query = db_select('taxonomy_term_data', 't');
  $query->join('taxonomy_vocabulary', 'tv', 't.vid = tv.vid');  
  $query->leftJoin($subquery1, 's1', 't.tid = s1.cid');
  $query->leftJoin($subquery2, 's2', 't.tid = s2.cid');
  $query->leftJoin($subquery3, 's3', 't.tid = s3.cid');  
  $query->addField('t', 'name', 'County');
  $query->addField('s1', 'users', 'Participants');
  $query->addField('s3', 'new_users', 'New_Participants');
  $query->addField('s2', 'distance', 'Miles');
  $query->condition('tv.name', 'MO.gov Counties', '=');
  $query->orderBy($order, $sort);
  $query->orderBy('County', 'ASC');
  $query = $query->extend('TableSort')->extend('PagerDefault')->limit(15); 
  $counties = $query->execute()->fetchAll();
  
  $header = array(
    array(
      'data' => t('County'),
      'field' => 'County',
    ),
    array(
      'data' => t('Participants'),
      'field' => 'Participants',
      'class' => array('align-right'),
    ),
    array(
      'data' => t('New Participants*'),
      'field' => 'New_Participants',
      'class' => array('align-right'),
    ),    
    array(
      'data' => t('Miles'),
      'field' => 'Miles',
      'class' => array('align-right'),
    ),
  );
  $rows = array(); 

  foreach ($counties as $county) {  
      $p = 0;
      $np = 0;
      $m = 0.00;
      if(!empty($county->Participants)) {
        $p = $county->Participants;
      }
      if(!empty($county->New_Participants)) {
        $np = $county->New_Participants;
      }      
      if(!empty($county->Miles)) {
        $m = $county->Miles;
      } 
      $rows[] = array(
          $county->County,
          array(
            'data' => number_format($p),
            'class' => array('align-right'),
          ),            
          array(
            'data' => number_format($np),
            'class' => array('align-right'),
          ),            
          array(
            'data' => number_format($m, 2),
            'class' => array('align-right'),
          ),            
      );
  }

  // Output of table with the paging
  $output .= theme_table(
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => '* New Participants have registered within the last ten days.',
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    )
  ).theme('pager');

  return $output;
}


/**
 *  @brief  'Users' Tab - Count of Users by Gender, Age Bracket, and Region
 *  
 *  @return  Render array
 *  
 *  @details  2015-01-29 
 */
function mo_project_stats_demographics() {
  $container = array();
  $q_tot = db_select('users', 'u');
  $q_tot->addExpression('COUNT(u.uid)');
  $total_users = $q_tot->execute()->fetchField();
  unset($q_tot);

  $query_all = db_select('users', 'u');
  $query_all->fields('u', array('status')); 
  $query_all->addExpression('COUNT(u.uid)', 'count');
  $query_all->groupBy('u.status');
  $result_all = $query_all->execute()->fetchAllKeyed();
  unset($query_all);
  
  if(!empty($result_all)) {
    $rows = array();
    foreach($result_all AS $key => $value) {
      if ($key == 0) {
        $label = 'Deleted';
      } else {
        $label = 'Active';
        $total_active_users = $value;
      }
      $percent = $value * 100 / $total_users;
      $rows[] = array(
        t($label),
        array (
          'data' => number_format($value, 0),
          'class' => array('align-right'),
        ),
        array (
          'data' => number_format($percent, 1) . '%',
          'class' => array('align-right'),
        ),            
      );
    }
  }
  unset($result_all);  
  
  $output = array(
    'header' => array(
      t('User Accounts'),
      array (
        'data' => t('Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  unset($rows); 

  $container[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>User Accounts</h3>',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );
  unset($output);
  
  // Sub-Users
  $query_users_w_subs = db_select('subuser', 's');
  $query_users_w_subs->fields('s', array('uid'));
  $query_users_w_subs->groupBy('s.uid');
  // Add the COUNT expression
  $query_users_w_subs->addExpression('COUNT(s.suid)', 'suidcount');
  // Add the HAVING condition
  $query_users_w_subs->havingCondition('suidcount', 1, '>');  
  $users_w_subs = $query_users_w_subs->execute()->rowCount();
  
  $query_all_sub = db_select('subuser', 's');
  $query_all_sub->join('taxonomy_term_data', 'x', 's.type_tid = x.tid');
  $query_all_sub->join('users', 'u', 's.uid = u.uid');
  $query_all_sub->addExpression('COUNT(s.suid)', 'count');
  $query_all_sub->condition('u.status', 1, '=');  
  $query_all_sub->condition('x.name', 'Me', '<>');   
  $total_sub_users = array_shift( $query_all_sub->execute()->fetchCol() );

  $average_subs = ($total_sub_users / $users_w_subs);
  
  $query_sub = db_select('subuser', 's');
  $query_sub->join('taxonomy_term_data', 'x', 's.type_tid = x.tid');
  $query_sub->join('users', 'u', 's.uid = u.uid');
  $query_sub->addField('x', 'name', 'type');
  $query_sub->addExpression('COUNT(s.suid)', 'count');
  $query_sub->condition('u.status', 1, '=');
  $query_sub->condition('x.name', 'Me', '<>');  
  $query_sub->groupBy('x.name'); 
  $query_sub->orderBy('count', 'DESC');  
  $result_sub = $query_sub->execute()->fetchAllKeyed();  
  
  $total_value = 0;
  if(!empty($result_sub)) {
    $rows = array();
    
    foreach($result_sub AS $key => $value) {
      if ($key != NULL) {
        $label = ucfirst($key);
      }
      $percent = $value * 100 / $total_sub_users;
      $rows[] = array(
        t($label),
        array (
          'data' => number_format($value, 0),
          'class' => array('align-right'),
        ),
        array (
          'data' => number_format($percent, 1) . '%',
          'class' => array('align-right'),
        ),            
      );
      $total_value = $total_value + $value;
    }
    $rows[] = array(
      t('All'),
      array (
        'data' => number_format($total_value, 0),
        'class' => array('align-right'),
      ),
      array (
        'data' => number_format(100, 1) . '%',
        'class' => array('align-right'),
      ),            
    );
  }
  unset($result_sub);  
  unset($total_sub_users);
  
  $output1 = array(
    'header' => array(
      t('Users With Buddies'),
        array(
          'data' => t('Total'),
          'class' => array('align-right'),
        ),
    ),
    'rows' => array(
      array(
        t('Users that have created a Buddy'),
        array(
          'data' => number_format($users_w_subs),
          'class' => array('align-right'),
        ),
      ),
      array(
        t('Average Buddies per User'),
        array(
          'data' => number_format($average_subs, 2),
          'class' => array('align-right'),
        ),
      ),
    ),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );

  $container[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Buddy Accounts (Sub-Users)</h3>',
    '#markup' => theme_table($output1),
    '#suffix' => '<br>',
  );
  unset($output1);
  
  $output2 = array(
    'header' => array(
      t('Buddy Types'),
      array (
        'data' => t('Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  unset($rows); 

  $container[] = array(
    '#type' => 'markup',
    '#markup' => theme_table($output2),
    '#suffix' => '<br>',
  );
  unset($output2);  
  
  // Users by Gender
  $query_gen = db_select('users', 'u');
  $query_gen->leftJoin('field_data_field_user_gender', 'g', 'u.uid = g.entity_id AND (g.entity_type = :type AND g.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_gen->addField('g', 'field_user_gender_value', 'gender');
  $query_gen->addExpression('COUNT(u.uid)', 'count');
  $query_gen->condition('u.status', 1, '=');
  $query_gen->groupBy('g.field_user_gender_value');
  $result_gen = $query_gen->execute()->fetchAllKeyed();

  if(!empty($result_gen)) {
    $rows = array();
    
    // Add the NULL values to the Undisclosed ones
    $no_ans = $result_gen[NULL];
    unset($result_gen[NULL]);
    
    foreach($result_gen AS $key => $value) {
      if ($key != NULL) {
        $label = ucfirst($key);
      }
      if ($label == 'Undisclosed') {
        $value = $value + $no_ans;
      }
      $percent = $value * 100 / $total_active_users;
      $rows[] = array(
        t($label),
        array (
          'data' => number_format($value, 0),
          'class' => array('align-right'),
        ),
        array (
          'data' => number_format($percent, 1) . '%',
          'class' => array('align-right'),
        ),            
      );
    }
  }
  unset($result_gen);  
  
  $output = array(
    'header' => array(
      t('Gender'),
      array (
        'data' => t('Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  unset($rows); 

  $container[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Active Users by Gender</h3>',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );
  unset($output);
  
  // Users by Age Bracket
  $query_age = db_select('users', 'u');
  $query_age->leftJoin('field_data_field_user_age', 'a', 'u.uid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_age->leftJoin('taxonomy_term_data', 'x', 'a.field_user_age_tid = x.tid');
  $query_age->addField('x', 'name', 'age bracket');
  $query_age->addExpression('COUNT(u.uid)', 'count');
  $query_age->condition('u.status', 1, '=');
  $query_age->groupBy('x.name');
  $result_age = $query_age->execute()->fetchAllKeyed();
  
  $query_agegen = db_select('users', 'u');
  $query_agegen->leftJoin('field_data_field_user_gender', 'g', 'u.uid = g.entity_id AND (g.entity_type = :type AND g.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_agegen->leftJoin('field_data_field_user_age', 'a', 'u.uid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_agegen->leftJoin('taxonomy_term_data', 'x', 'a.field_user_age_tid = x.tid');
  $query_agegen->addField('g', 'field_user_gender_value', 'gender');
  $query_agegen->addField('x', 'name', 'agebracket');
  $query_agegen->addExpression('COUNT(u.uid)', 'count');
  $query_agegen->condition('u.status', 1, '=');
  $query_agegen->groupBy('g.field_user_gender_value, x.name');
  $query_agegen->orderBy('g.field_user_gender_value, x.name');
  $result_agegen = $query_agegen->execute()->fetchAll();

  if(!empty($result_age)) {
    $rows = array();
    
    foreach($result_age AS $key => $value) {
      if ($key != NULL) {
        $label = ucfirst($key);
      }
      // Add label for NULL values
      if ($key == NULL) {
        $label = 'Not Available';
      }
      $percent = $value * 100 / $total_active_users;
      $rows[] = array(
        t($label),
        array (
          'data' => number_format($value, 0),
          'class' => array('align-right'),
        ),
        array (
          'data' => number_format($percent, 1) . '%',
          'class' => array('align-right'),
        ),            
      );
    }

    $end = count($result_agegen);
    foreach($result_agegen AS $obj) {
      if ( ($obj->gender <> 'undisclosed') AND ($obj->gender <> NULL) ) {
        if ($obj->agebracket == NULL) {
          $labelgen = 'Not Available';
        } else {
          $labelgen = $obj->agebracket;
        }
        $percentgen = $obj->count * 100 / $total_active_users;
        
        for($i=0; $i<$end; $i++) {
          if ($rows[$i][0] == $labelgen) {
              $rows[$i][] = array(
                'data' => number_format($obj->count, 0),
                'class' => array('align-right'),
              );
              $rows[$i][] = array (
                'data' => number_format($percentgen, 1) . '%',
                'class' => array('align-right'),        
              );
              break;
          }
        }      
      }
    }  
  }

  unset($result_age);  
  unset($result_agegen);
  
  $output = array(
    'header' => array(
      t('Age Bracket'),
      array (
        'data' => t('All: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Female: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Male: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  unset($rows); 

  $container[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Active Users by Age</h3>',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );
  unset($output);
  
  // Users by Region
  $query_reg = db_select('users', 'u');
  $query_reg->leftJoin('field_data_field_user_county', 'c', 'u.uid = c.entity_id AND (c.entity_type = :type AND c.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_reg->leftJoin('taxonomy_term_data', 'x', 'c.field_user_county_tid = x.tid');
  $query_reg->addField('x', 'description', 'region');
  $query_reg->addExpression('COUNT(u.uid)', 'count');
  $query_reg->condition('u.status', 1, '=');
  $query_reg->groupBy('x.description');
  $result_reg = $query_reg->execute()->fetchAllKeyed();
  
  $query_reggen = db_select('users', 'u');
  $query_reggen->leftJoin('field_data_field_user_gender', 'g', 'u.uid = g.entity_id AND (g.entity_type = :type AND g.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_reggen->leftJoin('field_data_field_user_county', 'c', 'u.uid = c.entity_id AND (c.entity_type = :type AND c.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query_reggen->leftJoin('taxonomy_term_data', 'x', 'c.field_user_county_tid = x.tid');
  $query_reggen->addField('g', 'field_user_gender_value', 'gender');
  $query_reggen->addField('x', 'description', 'region1');
  $query_reggen->addExpression('COUNT(u.uid)', 'count');
  $query_reggen->condition('u.status', 1, '=');
  $query_reggen->groupBy('g.field_user_gender_value, x.description');
  $query_reggen->orderBy('g.field_user_gender_value, x.description');
  $result_reggen = $query_reggen->execute()->fetchAll();
  

  if(!empty($result_reg)) {
    $rows = array();
    
    foreach($result_reg AS $key => $value) {
      if ($key != NULL) {
        switch($key) {
          case 'KC':
            $label = 'Kansas City';
            break;
          case 'NE':
            $label = 'Northeast';
            break;
          case 'CEN':
            $label = 'Central';
            break;
          case 'STL':
            $label = 'St. Louis';
            break;
          case 'LAK':
            $label = 'Lake';
            break;
          case 'SE':
            $label = 'Southeast';
            break;
        }
        $label .= ' Region';
      }
      // Add label for NULL values
      if ($key == NULL) {
        $label = 'Not Available';
      }
      $percent = $value * 100 / $total_active_users;
      $rows[] = array(
        t($label),
        array (
          'data' => number_format($value, 0),
          'class' => array('align-right'),
        ),
        array (
          'data' => number_format($percent, 1) . '%',
          'class' => array('align-right'),
        ),            
      );
    }
    
    $end = count($result_reggen);
    foreach($result_reggen AS $obj) {
      if ( ($obj->gender <> 'undisclosed') AND ($obj->gender <> NULL) ) {
        if ($obj->region1 != NULL) {
          switch($obj->region1) {
            case 'KC':
              $labelgen = 'Kansas City';
              break;
            case 'NE':
              $labelgen = 'Northeast';
              break;
            case 'CEN':
              $labelgen = 'Central';
              break;
            case 'STL':
              $labelgen = 'St. Louis';
              break;
            case 'LAK':
              $labelgen = 'Lake';
              break;
            case 'SE':
              $labelgen = 'Southeast';
              break;
          }
          $labelgen .= ' Region';
        }
        // Add label for NULL values
        if ($obj->region1 == NULL) {
          $labelgen = 'Not Available';
        }          
        
        $percentgen = $obj->count * 100 / $total_active_users;
        
        for($i=0; $i<$end; $i++) {
          if ($rows[$i][0] == $labelgen) {
              $rows[$i][] = array(
                'data' => number_format($obj->count, 0),
                'class' => array('align-right'),
              );
              $rows[$i][] = array (
                'data' => number_format($percentgen, 1) . '%',
                'class' => array('align-right'),        
              );
              break;
          }
        }      
      }
    }    
  }
  unset($result_reg);  
  unset($result_reggen);
  
  $output = array(
    'header' => array(
      t('Region'),
      array (
        'data' => t('All: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Female: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Male: Count'),
        'class' => array('align-right'),
      ),            
      array (
        'data' => t('Percent'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  unset($rows); 

  $container[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Active Users by Region</h3>',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );
  unset($output);
  
  
  
//  $content = theme('chart', array('chart' => $chart));
//  $content = mo_project_blank_page();
  return render($container);
}


/**
 *  @brief  'Groups' Tab - Count of groups by type of group, Mileage and Membership stats per group
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 *  updated 2015-01-28 
 */
function mo_project_stats_groups() {
  $groups = array();
  $query = db_select('node', 'n');
  $query->addExpression('COUNT(n.nid)', 'groups');
  $query->condition('n.type', 'mo_cms_user_group');
  $query->condition('n.status', 0, '<>');
  $total_groups = $query->execute()->fetchField();

/*  $query = db_select('node', 'n');
  $query->addExpression('COUNT(n.nid)', 'groups');
  $query->condition('n.type', 'mo_cms_umbrella_group');
  $query->condition('n.status', 0, '<>');
  $umb_groups = $query->execute()->fetchField();
*/
  $output = array(
    'header' => array(
      t('Group Type'),
      array (
        'data' => t('Total Groups'),
        'class' => array('align-right'),
      ),            
    ),
    'rows' => array(
      array(
        t('All User Groups'),
        array (
          'data' => number_format($total_groups),
          'class' => array('align-right'),
        ),            
      ),
    ),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  
  $query = db_select('field_data_field_mo_cms_user_group_type', 't');
  $query->addField('t', 'field_mo_cms_user_group_type_value', 'name');
  $query->addExpression('COUNT(t.entity_id)', 'groups');
  $query->condition('t.deleted', 0, '=');
  $query->groupBy('name');
  $group_types = $query->execute()->fetchAllKeyed();
  
  foreach($group_types AS $group_name => $group_count) {
    
    $group_name = ucfirst($group_name);
  
    // Write the table rows
    $output['rows'][] = array(
        $group_name,
        array (
          'data' => number_format($group_count),
          'class' => array('align-right'),
        ),
    );
  }
  
  $groups[] = array(
    '#type' => 'markup',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );

 
  $output = array();
  $headers = array(t('Group'));

  // Begin writing SQL for pivot table
  // http://www.artfulsoftware.com/infotree/qrytip.php?id=78
  // http://www.artfulsoftware.com/infotree/qrytip.php?id=523
  $sql = "SELECT IFNULL(grp,'Totals') AS 'Group', ";
  $sql_sel = "";
  
  $c_query = db_select('node', 'n');
  $c_query->addExpression('LEFT(n.title, 4)', 'year');
  $c_query->condition('n.type', 'challenge', '=');
  $c_results = $c_query->execute()->fetchCol();

  foreach ($c_results as $yr) {    
    $headers[] = array(
      'data' => t($yr . ': Miles'),
      'class' => array('align-right'),
    );    
    $headers[] = array(
      'data' => t('Members'),
      'class' => array('align-right'),
    );
    
    $sql .= "mil" . $yr . ", mem" . $yr . ", ";
    $sql_sel .= "SUM(IF(m.challenge_year = " . $yr . ", m.grp_distance, 0)) AS 'mil" . $yr . "', ";
    $sql_sel .= "SUM(IF(m.challenge_year = " . $yr . ", m.grp_member_total, 0)) AS 'mem" . $yr . "', ";

  }

  // Strip off last comma
  $sql = substr($sql, 0, -2);
  $sql_sel = substr($sql_sel, 0, -2);
  
  $sql .= " FROM ( " .
      "SELECT n.title AS 'grp', " . $sql_sel .
      " FROM mo_cms_user_groups_snapshot m " .
      "LEFT JOIN node n ON m.grp_id = n.nid " .      
      "GROUP BY grp WITH ROLLUP" .
    ") AS derived_1";

  $results = db_query($sql);   

  $rows = array();
  foreach ($results as $record) {
    $rows[] = (array)$record;
  }
  
  // Remove the final row (Totals -- useless in this instance)
  $index = count($rows) - 1;
  unset($rows[$index]);
  
  // Right-align each number value
  foreach ($rows as &$row) {
    foreach ($row as $key => &$cell_value) {
      $label = substr($key, 0, 3);
      switch($label) {
        case 'mil':
          $value = (double)$cell_value;
          $cell_value = array(
            'data' => number_format($value, 2),
            'class' => array('align-right'),
          );
          break;
        case 'mem':
          $value = $cell_value;
          $cell_value = array(
            'data' => number_format($value, 0),
            'class' => array('align-right'),
          );
          break;
        default:
          break;        
      }
    }
  }

  // Add a pager, even though we are not using db_select
  // http://knackforge.com/blog/sabareesh/creating-pager-drupal-without-dbselect-and-pagerdefault
  $per_page = 15;
  // Initialize the pager
  $current_page = pager_default_initialize(count($rows), $per_page);
  // Split your list into page sized chunks
  $chunks = array_chunk($rows, $per_page, TRUE);
  // Show the appropriate items from the list
  $output = theme('table', array(
    'header' => $headers,
    'rows' => $chunks[$current_page],
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  ));
  
  // Show the pager
  $output .= theme('pager', array('quantity',count($rows)));

  $groups[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Group Info</h3>',
    '#markup' => $output,
  );
  
  return $groups; 
}


/**
 *  @brief  'Groups' Tab helper - Gets count of groups meeting the passed-in criteria 
 *  
 *  @param [in] $join     Optional. Requirement to join. ('open' or 'closed')
 *  @param [in] $visible  Optional. Membership roster displayed to nonmembers. ('visible' or 'invisible') 
 *  @return  Integer count of groups that meet the criteria
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_count_groups($join = 'open', $visible = 'visible') {
  $query = db_select('node', 'n');
  $query->join('field_data_field_mo_cms_user_groups_join', 'j', 'n.nid = j.entity_id AND (j.entity_type = :type AND j.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mo_cms_user_groups_vis', 'v', 'n.nid = v.entity_id AND (v.entity_type = :type1 AND v.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $query->addExpression('COUNT(j.entity_id)');
  $query->condition('n.type', 'mo_cms_user_group');
  $query->condition('n.status', 0, '<>');
  $query->condition('j.field_mo_cms_user_groups_join_value', $join, '=');
  $query->condition('v.field_mo_cms_user_groups_vis_value', $visible, '=');

  return $query->execute()->fetchField();
}


/**
 *  @brief  'Leaders' Tab - Top 5 participants by activity, shows name, gender, county, and distance
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_leaders () {
  $output = array();
  $leads = array();
  
  $query1 = db_select('taxonomy_term_data', 't');
  $query1->join('taxonomy_vocabulary', 'tv', 't.vid = tv.vid');
  $query1->join('taxonomy_term_hierarchy', 'th', 't.tid = th.tid');
  $query1->fields('t', array('tid', 'name'));
  $query1->condition('tv.name', 'Activities', '=');
  $query1->condition('th.parent', 0, '=');
  $results = $query1->execute();

  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');
  
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $challenge_dates['end'];
  }  

  foreach ($results as $row) {  
    $activity = $row->name;

    $output = array(
      'header' => array(
        t($activity),
        t('Gender'),
        t('County'),
        array (
          'data' => t('Miles'),          
          'class' => array('align-right'),
        ),
      ),
      'rows' => array(),
      'attributes' => array(),
      'caption' => NULL,
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    );
    
    $query2 = db_select('node', 'n');
    $query2->join('users_roles', 'r', 'n.uid = r.uid');
    $query2->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query2->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
    $query2->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type2 AND a.deleted = :deleted2)', array(':type2' => 'node', ':deleted2' => 0));
    $query2->leftJoin('realname', 'rn', 'n.uid = rn.uid');
    $query2->leftJoin('field_data_field_user_gender', 'g', 'n.uid = g.entity_id AND (g.entity_type = :type3 AND g.deleted = :deleted3)', array(':type3' => 'user', ':deleted3' => 0));
    $query2->leftJoin('field_data_field_user_county', 'c', 'n.uid = c.entity_id AND (c.entity_type = :type4 AND c.deleted = :deleted4)', array(':type4' => 'user', ':deleted4' => 0));
    $query2->leftJoin('taxonomy_term_data', 'x', 'c.field_user_county_tid = x.tid');
    $query2->fields('n', array('uid'));
    $query2->fields('rn', array('realname'));
    $query2->addField('g', 'field_user_gender_value', 'gender');
    $query2->addField('x', 'name', 'county');
    $query2->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
    $query2->condition('n.type', 'mileage');
    $query2->condition('n.status', 0, '<>');
    $query2->condition('n.uid', 0, '<>');
    $query2->condition('r.rid', array($verified_role->rid, $admin_role->rid));
    $query2->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
    $query2->condition('t.field_mileage_date_value', $end_date, '<');
    $query2->condition('a.field_mileage_activity_tid', $row->tid, '=');
    $query2->groupBy('rn.realname, g.field_user_gender_value, x.name');
    $query2->orderBy('distance', 'DESC');
    $query2->range(0,5);
    $act_leaders = $query2->execute()->fetchAll();
      
    foreach ($act_leaders as $leader) { 
        // If no realname, try to get user_first and user_last
        if (empty($leader->realname)) {
          $leader_user_obj = user_load($leader->uid);
          $fieldinfo = field_get_items('user', $leader_user_obj, 'field_user_first_name');
          if ($fieldinfo) {
            $leader_name = check_plain($fieldinfo[0]['value']) . ' ';
          }
          else {
            $leader_name = '';
          }
          $fieldinfo = field_get_items('user', $leader_user_obj, 'field_user_last_name');
          if ($fieldinfo) {
            $leader_name .= check_plain($fieldinfo[0]['value']);
          }
          else {
            $leader_name .= 'User ' . $leader->uid;
          }
        } else {
          $leader_name = $leader->realname;
        }
        // If logged in user has administrator or editor role, show realname, 
        // Else show initials
        global $user;       
        if( (in_array('administrator', $user->roles)) OR 
            (in_array('editor', $user->roles)) ) {
            $leader_name = $leader_name;
        } elseif (substr($leader_name, 0, 4) == 'User') {
            $leader_name = 'Anon';
        } else {
            // For security's sake, get initials
            $namestring = $leader_name;
            $first = strtok($namestring, ' ');
            $second = strtok(' ');
            $leader_name = strtoupper(substr($first, 0, 1)) . '. ' . strtoupper(substr($second, 0, 1)) . '.';
        }
        
        if (empty($leader->gender)) {
          $leader_gender = 'Undisclosed';
        } else {
          $leader_gender = ucfirst($leader->gender);
        }
        
        // Write the table rows
        $output['rows'][] = array(
            $leader_name,
            $leader_gender,
            $leader->county,
            array (
              'data' => number_format($leader->distance, 2),
              'class' => array('align-right'),
            ),
        );
    }
  
    $leads[] = array(
      '#type' => 'markup',
      '#markup' => theme_table($output),
      '#suffix' => '<br><br>',
    );
  
  }
  return render($leads);
}


/**
 *  @brief  'Trends' Tab - Number of Users registered and Miles logged per week and month
 *  
 *  @return  Render array
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_trends() {
  $first_chal_dates = mo_project_get_challenge_dates_by_year(2013);
  $current_chal_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $first_chal_dates['start']) AND (date('Y-m-d H:i:s') <= $current_chal_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $current_chal_dates['end'];
  }  
  
  // Verified users with at least one mileage record
  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');

  // Users Registered by month
  $q_mo_users = db_select('users', 'u');
  $q_mo_users->addExpression('YEAR(FROM_UNIXTIME(u.created))', 'annum');
  $q_mo_users->addExpression('MONTH(FROM_UNIXTIME(u.created))', 'mnth');
  $q_mo_users->addExpression('COUNT(u.uid)', 'total_users');
  $q_mo_users->condition('u.created', $first_chal_dates['start_sse'], '>=');  
  $q_mo_users->groupBy('annum');
  $q_mo_users->groupBy('mnth');

  // Verified mileage logged by month
  $q_mo_miles = db_select('node', 'n');  
  $q_mo_miles->join('users_roles', 'r', 'n.uid = r.uid');
  $q_mo_miles->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $q_mo_miles->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0)); 
  $q_mo_miles->addExpression('YEAR(t.field_mileage_date_value)', 'annum');
  $q_mo_miles->addExpression('MONTH(t.field_mileage_date_value)', 'mnth'); 
  $q_mo_miles->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $q_mo_miles->condition('n.type', 'mileage');
  $q_mo_miles->condition('n.status', 0, '<>');
  $q_mo_miles->condition('n.uid', 0, '<>');
  $q_mo_miles->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $q_mo_miles->condition('t.field_mileage_date_value', $first_chal_dates['start'], '>=');
  $q_mo_miles->condition('t.field_mileage_date_value', $end_date, '<');
  $q_mo_miles->groupBy('annum');
  $q_mo_miles->groupBy('mnth');

  // Get data for table
  $query = db_select($q_mo_miles, 'qm');
  $query->leftJoin($q_mo_users, 'qu', 'qm.annum = qu.annum AND qm.mnth = qu.mnth');
  $query->addField('qm', 'mnth', 'Month');
  $query->addField('qm', 'annum', 'Year');  
  $query->addField('qu', 'total_users', 'Participants');
  $query->addField('qm', 'distance', 'Miles');
  $query->orderBy('qm.annum', 'ASC');
  $query->orderBy('qm.mnth', 'ASC');  
  $monthly = $query->execute()->fetchAll();

  // Users Registered by Week
  $q_wk_users = db_select('users', 'u');
  $q_wk_users->addExpression('YEARWEEK(FROM_UNIXTIME(u.created), 3)', 'yrweeknum');
  $q_wk_users->addExpression('COUNT(u.uid)', 'total_users');
  $q_wk_users->condition('u.created', $first_chal_dates['start_sse'], '>=');
  $q_wk_users->groupBy('yrweeknum');
  
  // Verified miles logged by Week
  $q_wk_miles = db_select('node', 'n');  
  $q_wk_miles->join('users_roles', 'r', 'n.uid = r.uid');
  $q_wk_miles->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $q_wk_miles->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $q_wk_miles->addExpression('YEARWEEK(t.field_mileage_date_value, 3)', 'yrweeknum');
  $q_wk_miles->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
  $q_wk_miles->condition('n.type', 'mileage');
  $q_wk_miles->condition('n.status', 0, '<>');
  $q_wk_miles->condition('n.uid', 0, '<>');
  $q_wk_miles->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  $q_wk_miles->condition('t.field_mileage_date_value', $first_chal_dates['start'], '>=');
  $q_wk_miles->condition('t.field_mileage_date_value', $end_date, '<');
  $q_wk_miles->groupBy('yrweeknum');
  
  // Get data for table  
  $query2 = db_select($q_wk_miles, 'qm');
  $query2->leftJoin($q_wk_users, 'qu', 'qm.yrweeknum = qu.yrweeknum');
  $query2->addExpression('LEFT(qm.yrweeknum, 4)', 'Year');
  $query2->addExpression('MID(qm.yrweeknum, 5, 2)', 'Week');  
  $query2->addField('qu', 'total_users', 'Participants');
  $query2->addField('qm', 'distance', 'Miles');
  $query2->orderBy('qm.yrweeknum', 'DESC');
  $query2 = $query2->extend('TableSort')->extend('PagerDefault')->limit(10); 
  $weekly = $query2->execute()->fetchAll();
 
 
  // Get month names
  $m_names = array(1=>'January', 2=>'February', 3=>'March', 4=>'April', 
      5=>'May', 6=>'June', 7=>'July', 8=>'August', 9=>'September', 
      10=>'October', 11=>'November', 12=>'December', 
  );
 
  $trend = array();
  $output = array(
    'header' => array(
      t('Month'),
      array(
        'data' => t('New Participants'),
        'class' => array('align-right'),
      ),
      array(
        'data' => t('Miles'),          
        'class' => array('align-right'),
      ),
    ),
    'rows' => array(),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  foreach ($monthly as $mon) {  
      $p = 0;
      $m = 0.00;
      if(!empty($mon->Participants)) {
        $p = $mon->Participants;
      }
      if(!empty($mon->Miles)) {
        $m = $mon->Miles;
      } 

      $output['rows'][] = array(
          t($m_names[$mon->Month] . ' ' . $mon->Year),
          array(
            'data' => number_format($p),
            'class' => array('align-right'),
          ),
          array(
            'data' => number_format($m, 2),
            'class' => array('align-right'),
          ),
      );
  }

  $trend[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Monthly Trends</h3>',
    '#markup' => theme_table($output),
    '#suffix' => '<br>',
  );
  

  //Weekly Trends
  $output = ""; 
//  $rows = array_fill(1, 53, array());
  $header = array(
      t('Week'),
      array(
        'data' => t('New Participants'),
        'class' => array('align-right'),
      ),
      array(
        'data' => t('Miles'),          
        'class' => array('align-right'),
      ),
  );
  
  foreach ($weekly as $week) {
      if ($week->Year == 2013) { 
        // June 1, 2013 falls in the 22nd week of the year, it needs to display as week 1
        $weeknum = $week->Week -21;
      } elseif (($week->Year == 2014) AND ($week->Week < 12)) {
        // March 19, 2014 falls in the 12th week of the year, it needs to display as week 1
        // and Weeks 1-11 need to display as part of the 2013 challenge year
        $weeknum = $week->Week +52-21;
      } elseif (($week->Year == 2014) AND ($week->Week >= 12)) {
        $weeknum = $week->Week -11;      
      }
      
      if (($week->Year == 2013) AND ($weeknum == 1)) {
        $weeklbl = t('Week ' . $weeknum . ' (Jun 1, 2013)');
      } elseif (($week->Year == 2014) AND ($weeknum == 1)) {
        $weeklbl = t('Week ' . $weeknum . ' (Mar 20 to Mar 22, 2014)');      
      } else {
        //Returns the date of Sunday in Week
        $from = date('M j', strtotime($week->Year . 'W' . $week->Week . '+1')); 
        //Returns the date of Saturday in Week
        $to = date('M j', strtotime($week->Year . 'W' .  $week->Week . '-6'));  
        $weeklbl = t('Week ' . $weeknum . ' (' . $from . ' to ' . $to . ', ' . $week->Year . ')');
      }
      
      $p = 0;
      $m = 0.00;
      if(!empty($week->Participants)) {
        $p = $week->Participants;
      }
      if(!empty($week->Miles)) {
        $m = $week->Miles;
      } 
      $rows[$weeknum] = array(
          $weeklbl,
          array(
            'data' => number_format($p),
            'class' => array('align-right'),
          ),
          array(
            'data' => number_format($m, 2),
            'class' => array('align-right'),
          ),
      );
  }
  
  $output = theme_table(
  array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
    )
  ).theme("pager");

  $trend[] = array(
    '#type' => 'markup',
    '#prefix' => '<h3>Weekly Trends</h3>',
    '#markup' => $output,
  );
  
  return render($trend);
}


/**
 *  @brief  Creates csv output of users registered, new users registered with the last ten days, and verified miles logged - by county
 *  
 *  @return  void
 *  
 *  @details  2013-07-26 by B. Dickson and D. Trussell
 */
function mo_project_stats_counties_csv() {
  // send response headers to the browser
  drupal_add_http_header('Content-Type', 'text/csv');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=csvfile.csv');  

  // get the data
    $verified_role = user_role_load_by_name('verified user');
    $admin_role = user_role_load_by_name('administrator');
    
    $subquery1 = db_select('field_data_field_user_county', 'c');
    $subquery1->addField('c', 'field_user_county_tid', 'cid');
    $subquery1->addExpression('COUNT(c.entity_id)', 'users');
    $subquery1->groupBy('cid');
    
    $challenge_dates = mo_project_get_challenge_dates_by_year();
    if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
      $end_date = date('Y-m-d H:i:s');
    } else {
      $end_date = $challenge_dates['end'];
    }  

    $subquery2 = db_select('node', 'n');
    $subquery2->join('users_roles', 'r', 'n.uid = r.uid');  
    $subquery2->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $subquery2->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
    $subquery2->join('field_data_field_user_county', 'c', 'n.uid = c.entity_id AND (c.entity_type = :type2 AND c.deleted = :deleted2)', array(':type2' => 'user', ':deleted2' => 0));
    $subquery2->addField('c', 'field_user_county_tid', 'cid');
    $subquery2->addExpression('ROUND(SUM(d.field_mileage_distance_value), 2)', 'distance');
    $subquery2->condition('n.type', 'mileage');
    $subquery2->condition('n.status', 0, '<>');
    $subquery2->condition('n.uid', 0, '<>');
    $subquery2->condition('r.rid', array($verified_role->rid, $admin_role->rid));
    $subquery2->condition('c.field_user_county_tid', '', '<>');
    $subquery2->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
    $subquery2->condition('t.field_mileage_date_value', $end_date, '<');
    $subquery2->groupBy('cid');
    
    $tendays_ago = strtotime('-10 days');
    $subquery3 = db_select('users', 'u');
    $subquery3->join('field_data_field_user_county', 'c', 'u.uid = c.entity_id AND (c.entity_type = :type3 AND c.deleted = :deleted3)', array(':type3' => 'user', ':deleted3' => 0));
    $subquery3->addField('c', 'field_user_county_tid', 'cid');
    $subquery3->addExpression('COUNT(u.uid)', 'new_users');
    $subquery3->condition('u.created', $tendays_ago, '>=');
    $subquery3->condition('u.status', 0, '<>');
    $subquery3->condition('c.field_user_county_tid', '', '<>');
    $subquery3->groupBy('cid');

    
    $query = db_select('taxonomy_term_data', 't');
    $query->join('taxonomy_vocabulary', 'tv', 't.vid = tv.vid');  
    $query->leftJoin($subquery1, 's1', 't.tid = s1.cid');
    $query->leftJoin($subquery2, 's2', 't.tid = s2.cid');
    $query->leftJoin($subquery3, 's3', 't.tid = s3.cid');  
    $query->addField('t', 'name', 'County');
    $query->addField('s1', 'users', 'Participants');
    $query->addField('s3', 'new_users', 'New');
    $query->addField('s2', 'distance', 'Miles');
    $query->condition('tv.name', 'MO.gov Counties', '=');
    $query->orderBy('County', 'ASC');
  $csv_array = $query->execute()->fetchAll();
  
  // write the csv file
  $header = array('County', 'Participants', 'New Participants', 'Miles');  
  $fpointer = fopen('php://output', 'w');
  fputcsv($fpointer, $header);
  
  foreach($csv_array as $row){ 
    $line = (array)$row;
    if( (is_null($line['Participants'])) OR ($line['Participants'] == '') ) {
      $line['Participants'] = 0;
    }
    if( (is_null($line['New'])) OR ($line['New'] == '') ) {
      $line['New'] = 0;
    }
    if( (is_null($line['Miles'])) OR ($line['Miles'] == '') ) {
      $line['Miles'] = 0.00;
    } 
    fputcsv($fpointer, $line);
  }
  fclose($fpointer);
  drupal_exit();  
}