<?php
/**
 *  @file blue_leaderboard_pane.inc
 *  @brief  Code for the 'Blue Miles Leaderboard' Panels Pane.
 *
 *  @details
 */
 
 
$plugin = array(
  'single' => TRUE,
  'title' => t('Blue Miles Leaderboard'),
  'description' => t('Leaderboard pane for Blue Miles display'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_project_blue_leaderboard_pane_render',
  'admin info' => 'mo_project_blue_leaderboard_pane_admin_info',
  'all contexts' => TRUE,
);


/**
 *  @brief  Creates custom panels pane
 *  
 *  @param [in] $subtype  
 *  @param [in] $conf     
 *  @param [in] $args     
 *  @param [in] $contexts 
 *  @return  pane
 *  
 *  @details  2015-02-05 
 */
function mo_project_blue_leaderboard_pane_render($subtype, $conf, $args, $contexts) {
  $pane = new stdClass();

  $q_all = mo_project_build_bluemiles_leaderboard_query();
  $top_all = $q_all->execute()->fetchAll();

  $q_fem = mo_project_build_bluemiles_leaderboard_query('female');
  $top_fem = $q_fem->execute()->fetchAll();

  $q_mal = mo_project_build_bluemiles_leaderboard_query('male');
  $top_mal = $q_mal->execute()->fetchAll();
  
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'bluemiles-leaderboard',
      'class' => array('no-style'),       
    ),
  );

  $content[] = array(
      '#type' => 'markup',
      '#markup' => t('<h2>GoRI Leaderboard</h2>'),
  );
  
  $headers = array(
    array(
      'data' => t('Overall'),
      'field' => 'name_all',
    ),
    array(
      'data' => t('Blue Miles'),
      'field' => 'miles_all',
      'class' => array(
        'blue-miles-column',
      ),
    ),
    array(
      'data' => t('Top Females'),
      'field' => 'name_fem',
    ),
    array(
      'data' => t('Blue Miles'),
      'field' => 'miles_fem',
      'class' => array(
        'blue-miles-column',
      ),
    ),
    array(
      'data' => t('Top Males'),
      'field' => 'name_mal',
    ),
    array(
      'data' => t('Blue Miles'),
      'field' => 'miles_mal',
      'class' => array(
        'blue-miles-column',
      ),
    ),  
  );  
  
  $rows = array();  
 
  $len_all = count($top_all);
  $len_fem = count($top_fem);
  $len_mal = count($top_mal);

  for ($i=0; $i < 5; $i++) {
    if ($i < $len_all) {
      $name_all = ucfirst($top_all[$i]->firstname . ' ' . substr($top_all[$i]->lastname, 0, 1));
      $miles_all = number_format($top_all[$i]->miles);
    } else {
      $name_all = '<em>None</em>';
      $miles_all = 0;
    }
    $name_all = $i+1 . '. ' . $name_all . '.';
    
    if ($i < $len_fem) {
      $name_fem = ucfirst($top_fem[$i]->firstname . ' ' . substr($top_fem[$i]->lastname, 0, 1));
      $miles_fem = number_format($top_fem[$i]->miles);
    } else {
      $name_fem = '<em>None</em>';
      $miles_fem = 0;
    }
    $name_fem = $i+1 . '. ' . $name_fem . '.';

    if ($i < $len_mal) {
      $name_mal = ucfirst($top_mal[$i]->firstname . ' ' . substr($top_mal[$i]->lastname, 0, 1));
      $miles_mal = number_format($top_mal[$i]->miles);
    } else {
      $name_mal = '<em>None</em>';
      $miles_mal = 0;
    }
    $name_mal = $i+1 . '. ' . $name_mal . '.';
    
    $rows[] = array(
      $name_all,
      array(
        'data' => $miles_all,
        'class' => array('blue-miles-column'),
      ),            
      $name_fem,
      array(
        'data' => $miles_fem,
        'class' => array('blue-miles-column'),
      ),            
      $name_mal,
      array(
        'data' => $miles_mal,
        'class' => array('blue-miles-column'),
      ),            
    );  
  }

  $output = theme_table(
    array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array(
        'id' => 'bluemiles-leaderboard-rows',     
      ),
      'caption' => NULL,
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    )
  );
  
  $content[] = array(
    '#type' => 'markup',
    '#markup' => $output,
  );
  
  $pane->title = t('<none>');
  $pane->content = render($content);
 
  return $pane;
}   
 
 
 /**
 *  @brief  Blue Miles Leaderboard Query Helper
 *  
 *  @param [in] $gender  Optional. Conditional query argument, ('male', 'female')
 *  @return  SelectQuery Object
 *  
 *  @details  2015-02-06 
 */
function mo_project_build_bluemiles_leaderboard_query($gender=NULL) {
  $challenge_dates = mo_project_get_challenge_dates_by_year();
  if ( (date('Y-m-d H:i:s') > $challenge_dates['start']) AND (date('Y-m-d H:i:s') <= $challenge_dates['end']) ) {
    $end_date = date('Y-m-d H:i:s');
  } else {
    $end_date = $challenge_dates['end'];
  }

  // Verified users with at least one mileage record
  $verified_role = user_role_load_by_name('verified user');
  $admin_role = user_role_load_by_name('administrator');

  $query = db_select('node', 'n');
  $query->join('users_roles', 'r', 'n.uid = r.uid');
  $query->join('field_data_field_user_first_name', 'f', 'n.uid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query->join('field_data_field_user_last_name', 'l', 'n.uid = l.entity_id AND (l.entity_type = :type AND l.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type2 AND d.deleted = :deleted)', array(':type2' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type2 AND t.deleted = :deleted)', array(':type2' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type2 AND a.deleted = :deleted)', array(':type2' => 'node', ':deleted' => 0));
  if ($gender != NULL) {
    $query->join('field_data_field_user_gender', 'g', 'n.uid = g.entity_id AND (g.entity_type = :type AND g.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  }
  $query->addField('f', 'field_user_first_name_value', 'firstname');
  $query->addField('l', 'field_user_last_name_value', 'lastname');
  $query->addExpression('ROUND(SUM(d.field_mileage_distance_value))', 'miles');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', 0, '<>');
  $query->condition('r.rid', array($verified_role->rid, $admin_role->rid));
  if ($gender != NULL) {
    $query->condition('g.field_user_gender_value', $gender);
  }
  $query->condition('t.field_mileage_date_value', $challenge_dates['start'], '>=');
  $query->condition('t.field_mileage_date_value', $end_date, '<');
  $query->groupBy('n.uid');
  $query->orderBy('miles', 'DESC');
  $query->orderBy('lastname', 'ASC');  
  $query->range(0,5);

  return $query;
}


/**
 *  @brief  'admin info' callback for panel pane.
 *  
 *  @param [in] $subtype  
 *  @param [in] $conf     
 *  @param [in] $contexts 
 *  @return  block
 *  
 *  @details  2015-02-05 
 */
function mo_project_blue_leaderboard_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Blue Miles Leaderboard');
    }
    $block->content = '';
    return $block;
  }
}
