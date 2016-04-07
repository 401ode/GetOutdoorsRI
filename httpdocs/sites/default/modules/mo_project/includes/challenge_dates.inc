<?php
/**
 *  @file  challenge_dates.inc
 *  @brief  Code to manage the start and end date of each year's 100 Missouri Miles Challenge
 *
 *  @details
 *  mo_project_100_missouri_miles_config = Create configuration form to set the current challenge start and end dates
 *  mo_project_100_missouri_miles_config_submit = Process submissions to the challenge date configuration form
 *  mo_project_get_challenge_nodes = Gets the challenge date nodes
 *  mo_project_get_challenge_dates_by_year = Gets the start and end dates for each year's challenge
 *  mo_project_get_challenge_dates = Redundancy to catch obsolete function calls
 *  mo_project_get_current_challenge_dates = Redundancy to catch obsolete function calls
 */

 
/**
 *  @brief  Create configuration form to set the current challenge start and end dates
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  new form
 *  
 *  @details  2014-03-17
 */ 
function mo_project_100_missouri_miles_config($form, &$form_state) {
  $date = format_date(REQUEST_TIME, 'custom', 'Y-m-d H:i:s');
  $format = 'Y-m-d';
  $form['date_start'] = array(
    '#type' => 'date_popup',
    '#title' => t('Select start date'),
    '#default_value' => variable_get_value('current_challenge_start_date') ? variable_get_value('current_challenge_start_date') : $date,
    '#date_format' => $format,
    '#date_label_position' => 'within',
  );
  $form['date_end'] = array(
    '#type' => 'date_popup',
    '#title' => t('Select end date'),
    '#default_value' => variable_get_value('current_challenge_end_date') ? variable_get_value('current_challenge_end_date') : $date,
    '#date_format' => $format,
    '#date_label_position' => 'within',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Set dates'),
    '#attributes' => array(
      'id' => 'set-challenge-dates',
    ),
  );
  return $form;
}


/**
 *  @brief  Process submissions to the challenge date configuration form
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  void
 *  
 *  @details  2014-03-17
 */
function mo_project_100_missouri_miles_config_submit($form, &$form_state) {
  if (!empty($form_state['input']['date_start']['date'])) {
    variable_set_value('current_challenge_start_date', $form_state['input']['date_start']['date'] . ' 00:00:00');
  }
  if (!empty($form_state['input']['date_end']['date'])) {
    variable_set_value('current_challenge_end_date', $form_state['input']['date_end']['date'] . ' 23:59:59');
  }
}


/**
 *  @brief  Gets the challenge date nodes
 *  
 *  @return  array of challenge date nodes
 *  
 *  @details  2014-03-17
 */
function mo_project_get_challenge_nodes() {
  $challenge_nodes = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'challenge');
  $query->propertyCondition('status', 1);
  $query->fieldOrderBy('field_challenge_dates', 'value', 'ASC');
  $result = $query->execute();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    foreach ($nodes as $nid=>$node) {
      $date_field = field_get_items('node', $node, 'field_challenge_dates');
      if (!empty($date_field[0]['value']) and !empty($date_field[0]['value2'])) {
        $year = date('Y', strtotime($date_field[0]['value']));
        $challenge_nodes[$year] = $node;
      }
    }
  }
  return $challenge_nodes;
}


/**
 *  @brief  Gets the start and end dates for each year's challenge
 *  
 *  @param [in] $year  Optional.  Four digit year of the challenge
 *  @return  array of challenge start and end dates in MySQL format and Unix Timestamp format
 *  
 *  @details  2014-03-10 
 *            Edit 2014-03-18
 */
function mo_project_get_challenge_dates_by_year($year=FALSE) {
  if (!$year) {
    $year = date('Y');
  }
  $challenges = mo_project_get_challenge_nodes();
  $node = $challenges[$year];
  $date_field = field_get_items('node', $node, 'field_challenge_dates');
  if (!empty($date_field[0]['value']) and !empty($date_field[0]['value2'])) {
    $start = $date_field[0]['value'];
    $end = $date_field[0]['value2'];
    return array(
      'start' => $start,
      'start_sse' => strtotime($start),
      'end' => $end,
      'end_sse' => strtotime($end),
    );
  }
  return FALSE;
}


/**
 *  @brief  Redundancy to catch obsolete function calls
 *  
 *  @param [in] $node  node entity?
 *  @return  FALSE
 *  
 *  @details  2014-03-18
 */
function mo_project_get_challenge_dates($node) {
  return FALSE;
}


/**
 *  @brief  Redundancy to catch obsolete function calls
 *  
 *  @return  array of challenge start and end dates in MySQL format and Unix Timestamp format
 *  
 *  @details  2014-03-18
 */
function mo_project_get_current_challenge_dates() {
  return mo_project_get_challenge_dates_by_year();
}

