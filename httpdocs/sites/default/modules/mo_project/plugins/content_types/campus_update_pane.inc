<?php
/**
 *  @file campus_update_pane.inc
 *  @brief  Code for the 'Campus Leaderboard' Panels Pane showing the last updated date.
 *
 *  @details
 */
 
 
$plugin = array(
  'single' => TRUE,
  'title' => t('Campus Last Updated'),
  'description' => t('Panel pane for campus last updated display'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_miles_leaderboard_leaderboard_c_pane_render2',
  'admin info' => 'mo_miles_leaderboard_leaderboard_c_pane_admin_info2',
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
 *  @details  2014-08-22 
 */
function mo_miles_leaderboard_leaderboard_c_pane_render2($subtype, $conf, $args, $contexts) {
  $path = request_path();
  $path_pieces = explode('/', $path);
  $year = array_pop($path_pieces);
  
  $pane = new stdClass();
  $content = array();
  if (is_numeric($year)) {
    $updated = mo_miles_leaderboard_get_cc_updated($year);
  } else {
    $updated = mo_miles_leaderboard_get_cc_updated();
  }
  $content[] = $updated;
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
 *  @details  2014-08-22 
 */
function mo_miles_leaderboard_leaderboard_c_pane_admin_info2($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Campus Last Updated');
    }
    $block->content = '';
    return $block;
  }
}