<?php

/**
 * Implements hook_menu().
 */
function mogov_foundations_menu() {

  global $base_url;
  $items = array();

  $items['admin/config/mogov'] = array(
    'title'            => 'MO.gov Site Configuration',
    'description'      => 'Configuration options common to most MO.gov websites.',
    'page callback'    => 'system_admin_menu_block_page',
    'access arguments' => array('access administration pages'),
    'file'             => 'system.admin.inc',
    'file path'        => drupal_get_path('module', 'system'),
    'position'         => 'left',
    'weight'           => -100,
  );

  $items['admin/config/mogov/agency'] = array(
    'title' => 'Agency leadership information',
    'description' => 'Basic configuration including Governor\'s and agency head\'s names, agency name, etc.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('variable_group_form', 'mogov_agency_info'),
    'access arguments' => array('administer mogov site configuration'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/mogov/social'] = array(
    'title' => 'Social media accounts',
    'description' => 'Configure social media URLs and accounts; may be used to generate various links.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('variable_group_form', 'mogov_social_info'),
    'access arguments' => array('administer social media accounts'),
    'type' => MENU_NORMAL_ITEM,
  );

  return $items;
}
