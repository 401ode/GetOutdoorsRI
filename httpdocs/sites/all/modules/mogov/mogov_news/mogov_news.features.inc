<?php
/**
 * @file
 * mogov_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mogov_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mogov_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mogov_news_node_info() {
  $items = array(
    'mogov_news_release' => array(
      'name' => t('News Release'),
      'base' => 'node_content',
      'description' => t('A standard news release suitable for display on mo.gov and other state websites.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'mogov_news_release_link' => array(
      'name' => t('News Release Link'),
      'base' => 'node_content',
      'description' => t('Like a regular news release, but instead of containing content locally, simply links to a release on another site.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
