<?php

/**
 * Implements hook_menu()
 */
function mogov_sliders_menu() {
  $items = array();
  
  $items['admin/structure/mogov-sliders'] = array(
    'title' => t('Sliders'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mogov_slider_overview_form', 'mogov_slider'),
    'description' => 'Manage sliders.',
    'access callback' => 'mogov_sliders_access_callback',
  );
  
  $items['slider/%'] = array(
    'title' => 'Slider',
    'page callback' => 'mogov_sliders_view_slider',
    'page arguments' => array(1),
    'access arguments' => array('administer sliders'),
  );
  
  return $items;
}