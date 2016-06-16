<?php
/**
 *  @file campus_leaderboard_pane.inc
 *  @brief  Code for the 'Campus Leaderboard' Panels Pane.
 *
 *  @details
 */
 
 
$plugin = array(
  'single' => TRUE,
  'title' => t('Campus Leaderboard'),
  'description' => t('Leaderboard pane for campus display'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_miles_leaderboard_leaderboard_c_pane_render',
  'admin info' => 'mo_miles_leaderboard_leaderboard_c_pane_admin_info',
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
 *  @details  2014-03-19
 */
function mo_miles_leaderboard_leaderboard_c_pane_render($subtype, $conf, $args, $contexts) {
  $path = request_path();
  $path_pieces = explode('/', $path);
  $year = array_pop($path_pieces);
  
  $pane = new stdClass();

  // Get max division
  $query = db_select('field_data_field_campus_division', 'd');
  $query->addExpression('MAX(d.field_campus_division_value)', 'max_div');
  $query->condition('d.field_campus_division_value', 9, '<');  
  $results = $query->execute()->fetchCol();
  
  $content = array();
  
  for ($div = 1; $div <= $results[0]; $div++) {
    if (is_numeric($year)) {
      $lboard = mo_miles_leaderboard_build_cc_leaderboard($div, $year);
    } else {
      $lboard = mo_miles_leaderboard_build_cc_leaderboard($div);
    }
    $content['leaderboard'][$div] = $lboard;
    $content['leaderboard'][$div]['attributes']['id'] = 'division-' . $div . '-leaderboard';
  }
  $pane->title = t('<none>');
  $pane->content = render($content);
 
  return $pane;
}


/**
 *  @brief  'admin info' callback for panel pane.
 *  
 *  @param [in] $subtype  
 *  @param [in] $conf     
 *  @param [in] $contexts 
 *  @return  block
 *  
 *  @details  2014-03-19
 */
function mo_miles_leaderboard_leaderboard_c_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Campus Leaderboard');
    }
    $block->content = '';
    return $block;
  }
}