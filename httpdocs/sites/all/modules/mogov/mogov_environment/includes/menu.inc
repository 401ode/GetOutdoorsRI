<?php

/**
 * Implements hook_menu().
 */
function mogov_environment_menu() {

  $items = array();
  
  $items['admin/config/mogov/environment'] = array(
    'title' => 'Hosting Environment',
    'description' => 'Environmental configuration options',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('variable_group_form', 'mogov_environment_settings'),
    'access arguments' => array('access administration pages'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['nscache_inval'] = array(
    'title' => t('Clear the NetScaler cache'),
    'description' => 'NetScaler will intercept this path and invalidate its cache.',
    'page callback' => 'mogov_foundations_blank_page',
    'access arguments' => array('access content'),
    'type' => MENU_NORMAL_ITEM,
  );

  return $items;

}
