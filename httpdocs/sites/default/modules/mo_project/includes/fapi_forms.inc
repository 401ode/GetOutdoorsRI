<?php
/**
 *  @file fapi_forms.inc
 *  @brief  Various FAPI forms used on the site, usually with ajax processing
 *
 *  @details
 *  mo_project_add_mileage_form = creates the add mileage form
 *  mo_project_add_mileage_form_mobile = creates the add mileage form
 *  mo_project_add_subuser_form = creates the add subuser form
 *  mo_project_add_subuser_form_submit = Adds the sub-user record to table subuser
 *  mo_project_activity_converter_form = creates the activity converter form
 *  mo_project_km_to_miles_converter_form = creates the kilometers to miles conversion form
 *  mo_project_calories_calculator_form = creates the calorie counter form
 *  mo_project_activity_log_export_form = creates the activity log export form
 *  mo_project_activity_log_export_form_submit = Creates the csv file upon clicking submit on the Activity Log Export Form  
 */


/**
 *  @brief  creates the add mileage form
 *  
 *  @return  new form
 *  
 *  @details  2013
 */
function mo_project_add_mileage_form() {
  global $user;
  $date = date('Y-m-d 00:00:00');
  $format = 'Y-m-d';

  $form = array();
  $form[0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'date' => array(
      '#type' => 'date_popup',
      '#id' => 'edit-date',
      '#title' => t('Date'),
      '#size' => 10,
      '#default_value' => $date,
      '#date_format' => $format,
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-1:0',
      '#datepicker_options' => array(
        'maxDate' => 0,
      ),
    ),
  );
  $field = field_info_field('field_mileage_activity');
  $allowed_values = mo_project_get_allowed_term_reference_values($field);
  $form[1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'activity' => array(
      '#type' => 'select',
      '#title' => t('Activity'),
      '#options' => $allowed_values,
    ),
  );
  $form[2] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'location' => array(
      '#type' => 'textfield',
      '#id' => 'mileage-location',
      '#title' => t('Location or Event Code'),
      '#autocomplete_path' => 'ajax/mileage_location_autocomplete',
    ),
  );
  $all_subusers = mo_project_get_subusers($user->uid);
  foreach ($all_subusers as $row) {
    $key = $row->suid . '|' . $row->type_name;
    $allowed_subusers[$key] = t($row->name);
    if ($row->type_name == "Me") {
      $me_default = $key; 
    }
  }

  $form[3] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'subuser' => array(
      '#type' => 'select',
      '#id' => 'edit-subuser',
      '#title' => t('Log miles for:'),
      '#options' => $allowed_subusers,
      '#default' => $me_default,
    ),
  );
  $form[4] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'distance' => array(
      '#type' => 'textfield',
      '#title' => t('Distance'),
      '#size' => 6,
    ),
    'units' => array(
      '#type' => 'select',
      '#title' => 'units',
      '#title_display' => 'invisible',
      '#options' => array(
        'miles' => t('Mi'),
        'kilometers' => t('Km'),
      ),
      '#default_value' => 'miles',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add Miles'),
    '#attributes' => array(
      'id' => 'submit-mileage',
    ),
  );
  return $form;
}


/**
 *  @brief  creates the add mileage form
 *  
 *  @return  new form
 *  
 *  @details  2013
 */
function mo_project_add_mileage_form_mobile() {
  global $user;
  $date = date('Y-m-d 00:00:00');
  $format = 'Y-m-d';

  $form = array();
  $form[0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'date' => array(
      '#type' => 'date_popup',
      '#id' => 'edit-date-mobile',
      '#title' => t('Date'),
      '#size' => 10,
      '#default_value' => $date,
      '#date_format' => $format,
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-1:0',
      '#datepicker_options' => array(
        'maxDate' => 0,
      ),
    ),
  );
  $field = field_info_field('field_mileage_activity');
  $allowed_values = mo_project_get_allowed_term_reference_values($field);
  $form[1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'activity' => array(
      '#type' => 'select',
      '#id' => 'edit-activity-mobile',
      '#title' => t('Activity'),
      '#options' => $allowed_values,
    ),
  );
  $form[2] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'location' => array(
      '#type' => 'textfield',
      '#id' => 'mileage-location-mobile',
      '#title' => t('Location or Event Code'),
      '#autocomplete_path' => 'ajax/mileage_location_autocomplete',
    ),
  );
  $all_subusers = mo_project_get_subusers($user->uid);
  foreach ($all_subusers as $row) {
    $key = $row->suid;
    $allowed_subusers[$key] = t($row->name);
    if ($row->type_name == "Me") {
      $me_default = $key; 
    }
  }
  
  $form[3] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'subuser' => array(
      '#type' => 'select',
      '#id' => 'edit-subuser-mobile',
      '#title' => t('Log miles for:'),
      '#options' => $allowed_subusers,
      '#default' => $me_default,
    ),
  );
  $form[4] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'distance' => array(
      '#type' => 'textfield',
      '#id' => 'edit-distance-mobile',
      '#title' => t('Distance'),
      '#size' => 6,
    ),
    'units' => array(
      '#type' => 'select',
      '#id' => 'edit-units-mobile',
      '#title' => 'units',
      '#title_display' => 'invisible',
      '#options' => array(
        'miles' => t('Mi'),
        'kilometers' => t('Km'),
      ),
      '#default_value' => 'miles',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add Miles'),
    '#attributes' => array(
      'id' => 'submit-mileage-mobile',
    ),
  );
  return $form;
}


/**
 *  @brief  creates the add subuser form
 *  
 *  @return  new form
 *  
 *  @details  2015-03-16 
 */
function mo_project_add_subuser_form() {
  $form = array();
  $form['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('container-inline'),
    ),
  );
  $form['container'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'name' => array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#size' => 12,
    ),
  );
  
  $vid = taxonomy_vocabulary_machine_name_load("sub_user")->vid;
  $terms = taxonomy_get_tree($vid);
  foreach ($terms AS $term) {
    // Do not allow User to add himself as a buddy
    if ($term->name != "Me") {
      $allowed_values[$term->tid] = $term->name;
    }
  }
  $form['container'][1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'type' => array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#options' => $allowed_values,
    ),
  );
  
  $form['container']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
    '#attributes' => array(
      'id' => 'submit-subuser',
    ),
  );

  return $form;
}


/**
 *  @brief Adds the sub-user record to table subuser
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  nothing
 *  
 *  @details Details
 */
function mo_project_add_subuser_form_submit($form, &$form_state) {
  // get the data
  global $user;
  if (!empty($_POST['name'])) {
    $name = $_POST['name'];
  } else {
    $name = 'Buddy';
  }
  
  if (!empty($_POST['type'])) {
    $type = $_POST['type'];
  } else {
    $term = taxonomy_get_term_by_name('Other', 'sub_user');
    $term = array_keys($term);
    $type = array_pop($term);
  }
  
  $suid = db_insert('subuser')
  ->fields(array(
    'uid' => $user->uid,
    'name' => $name,
    'type_tid' => $type,
    'created' => REQUEST_TIME,
  ))
  ->execute();
  
  if(is_numeric($suid)) {
    drupal_set_message('You’ve successfully added ' . $name . ' as a buddy – now hit the trail and log your 100 Missouri Miles together!');
  }
  
  return TRUE;
}

  
/**
 *  @brief creates the activity converter form
 *  
 *  @return  new form
 *  
 *  @details  2013
 */
function mo_project_activity_converter_form() {
  $form = array();
  $field = field_info_field('field_mileage_activity');
  $v = taxonomy_vocabulary_machine_name_load('activities');
  $v_tree = taxonomy_get_tree($v->vid);
  $tids = array();
  foreach ($v_tree as $term) {
    $tids[] = $term->tid;
  }
  $terms = taxonomy_term_load_multiple($tids);
  $allowed_values = array();
  foreach ($terms as $tid=>$term) {
    $field = field_get_items('taxonomy_term', $term, 'field_activity_conversion_coef');
    if (!empty($field[0]['value'])) {
      $allowed_values[$tid] = $term->name;
    }
  }
  asort($allowed_values);
  
  $form['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('container-inline'),
    ),
  );
  $form['container'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'activity' => array(
      '#type' => 'select',
      '#title' => t('Activity'),
      '#options' => $allowed_values,
    ),
  );
  $form['container'][1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'time' => array(
      '#type' => 'textfield',
      '#title' => t('Time'),
      '#size' => 8,
      '#attributes' => array(
        'placeholder' => t('in minutes')
      ),
    ),
  );
  $form[2] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'activity-converter-results',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Convert'),
    '#attributes' => array(
      'id' => 'convert-activity',
    ),
  );
  return $form;
}


/**
 *  @brief  creates the kilometers to miles conversion form
 *  
 *  @return  new form
 *  
 *  @details  2013
 */
function mo_project_km_to_miles_converter_form() {
  $form = array();
  $form['km'] = array(
    '#type' => 'textfield',
    '#title' => t('Kilometers'),
    '#size' => 8,
    '#attributes' => array(),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Convert to Miles'),
    '#attributes' => array(
      'id' => 'convert-km',
    ),
  );
  $form[] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'km-converter-results',
    ),
  );
  return $form;
}


/**
 *  @brief  creates the calorie counter form
 *  
 *  @return  new form
 *  
 *  @details  2013
 */
function mo_project_calories_calculator_form() {
  $form = array();
  $field = field_info_field('field_mileage_activity');
  $v = taxonomy_vocabulary_machine_name_load('activities');
  $v_tree = taxonomy_get_tree($v->vid);
  $tids = array();
  foreach ($v_tree as $term) {
    $tids[] = $term->tid;
  }
  $terms = taxonomy_term_load_multiple($tids);
  $allowed_values = array();
  foreach ($terms as $tid=>$term) {
    $field = field_get_items('taxonomy_term', $term, 'field_metabolic_equivalent_coef');
    if (!empty($field[0]['value'])) {
      $allowed_values[$tid] = $term->name;
    }
  }
  asort($allowed_values);
  $form['activity'] = array(
    '#type' => 'select',
    '#title' => t('Activity'),
    '#options' => $allowed_values,
  );
  $form['time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time'),
    '#size' => 8,
    '#attributes' => array(
      'placeholder' => t('in minutes')
    ),
  );
  $form['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Weight'),
    '#size' => 8,
    '#attributes' => array(
      'placeholder' => t('in pounds')
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Calculate Calories'),
    '#attributes' => array(
      'id' => 'calculate-calories',
    ),
  );
  $form[] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'calorie-calculator-results',
    ),
  );
  return $form;
}


/**
 *  @brief  creates the activity log export form
 *  
 *  @return  new form
 *  
 *  @details  2015-02-06 
 *  updated 2015-04-20  - add sub-user selection
 */
function mo_project_activity_log_export_form() {
  global $user;
  $date1 = date('Y-m-d 00:00:00', strtotime("first day of January this year"));
  $date2 = date('Y-m-d 00:00:00');
  $format = 'Y-m-d';
  $form = array();
  $form['instructions'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
  );
  $form['instructions'][0] = array(
    '#type' => 'markup',
    '#markup' => t('<p>Want a record of your 100 Missouri Miles activity? Just pick a start and end date, then click the "Export" button to download a spreadsheet of your activity.</p>'),
  );  
  $form['range'] = array(
    '#type' => 'fieldset',
    '#title' => t('Date Range'),
  );
  $form['range'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'date_from' => array(
      '#type' => 'date_popup',
      '#title' => t('From'),
      '#description' => NULL,
      '#size' => 10,
      '#default_value' => $date1,
      '#date_format' => $format,
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-4:0',
      '#datepicker_options' => array(
        'maxDate' => 0,
      ),
    ),
  );
  $form['range'][1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'date_to' => array(
      '#type' => 'date_popup',
      '#title' => t('To'),
      '#description' => NULL,
      '#size' => 10,
      '#default_value' => $date2,
      '#date_format' => $format,
      '#date_label_position' => 'within',
      '#date_timezone' => 'America/Chicago',
      '#date_year_range' => '-4:0',
      '#datepicker_options' => array(
        'maxDate' => 0,
      ),
    ),
  );
  $all_subusers = mo_project_get_subusers($user->uid);
  foreach ($all_subusers as $row) {
    $key = $row->suid;
    $allowed_subusers[$key] = t($row->name);
    if ($row->type_name == "Me") {
      $me_default = $key; 
    }
  }
  $form['subuser'] = array(
    '#type' => 'fieldset',
    '#title' => t(''),
  );
  $form['subuser'][0] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'subuser' => array(
      '#type' => 'select',
      '#id' => 'edit-subuser',
      '#title' => t('Logged By:'),
      '#options' => $allowed_subusers,
      '#default' => $me_default,
    ),
  );
    
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
    '#attributes' => array(
      'id' => 'export-activity-log',
    ),
  );
  return $form;
}


/**
 *  @brief Creates the csv file upon clicking submit on the Activity Log Export Form
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  nothing
 *  
 *  @details 2015-02-06 
 *  updated 2015-04-20  - add sub-user selection
 */
function mo_project_activity_log_export_form_submit($form, &$form_state) {
  // begin sending response headers to the browser
  drupal_add_http_header('Content-Type', 'text/csv');

  // get the data
//  global $user;
  $suid = $form_state['values']['subuser'];
  if (!empty($_POST['date_from'])) {
    $begin_date = $_POST['date_from']['date'];
  } else {
    $challenge_dates = mo_project_get_challenge_dates_by_year(2013);    
    $begin_date = $challenge_dates['start'];
  }
  if (!empty($_POST['date_to'])) {
    $end_date = $_POST['date_to']['date'];
  } else {
    $end_date = date('Y-m-d H:i:s');
  }

  // complete sending response headers to the browser
  $filename = 'attachment;filename=100momiles_' . $begin_date . '-' . $end_date . '.csv';
  drupal_add_http_header('Content-Disposition', $filename);  
  
  $query = db_select('node', 'n');
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type1 AND t.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $query->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type2 AND s.deleted = :deleted2)', array(':type2' => 'node', ':deleted2' => 0));
  $query->join('subuser', 'su', 's.field_mileage_subuser_value = su.suid');
  $query->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type3 AND a.deleted = :deleted3)', array(':type3' => 'node', ':deleted3' => 0));
  $query->join('taxonomy_term_data', 'x', 'a.field_mileage_activity_tid = x.tid');
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type4 AND d.deleted = :deleted4)', array(':type4' => 'node', ':deleted4' => 0));
  $query->leftJoin('field_data_field_mileage_facility', 'f', 'n.nid = f.entity_id AND (f.entity_type = :type5 AND f.deleted = :deleted5)', array(':type5' => 'node', ':deleted5' => 0));
  $query->addField('t', 'field_mileage_date_value', 'date');
  $query->addField('su', 'name', 'logged by');
  $query->addField('f', 'field_mileage_facility_value', 'location');
  $query->addField('x', 'name', 'activity');
  $query->addExpression('ROUND(d.field_mileage_distance_value, 2)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
//  $query->condition('n.uid', $user->uid, '=');
  $query->condition('s.field_mileage_subuser_value', $suid, '=');
  $query->condition('t.field_mileage_date_value', $begin_date, '>=');
  $query->condition('t.field_mileage_date_value', $end_date, '<');
  $query->orderBy('date', 'ASC');
  $csv_array = $query->execute()->fetchAll();

  // write the csv file
  $header = array('Date', 'Logged By', 'Location', 'Activity', 'Distance');  
  $fpointer = fopen('php://output', 'w');
  fputcsv($fpointer, $header);
  
  foreach($csv_array as $row){ 
    $line = (array)$row;
    $date_mysql = strtotime($line['date']);
    $line['date'] = date('Y-m-d', $date_mysql);
    fputcsv($fpointer, $line);
  }
  fclose($fpointer);
  drupal_exit();  
}
