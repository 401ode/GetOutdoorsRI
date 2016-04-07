<?php
/**
 * Implements hook_menu().
 */
function mogov_news_menu() {

  $items = array();

  $items['admin/config/mogov/mogov-news/config'] = array(
    'title' => 'News',
    'description' => 'Options for the News module',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('variable_module_form', 'mogov_news'),
    'access arguments' => array('access administration pages'),
    'type' => MENU_NORMAL_ITEM,
  );

  return $items;
}
