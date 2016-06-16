<?php
/**
 * @file
 * mo_cms_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mo_cms_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mo_cms_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mo_cms_events_node_info() {
  $items = array(
    'mo_cms_event' => array(
      'name' => t('MO CMS: Event'),
      'base' => 'node_content',
      'description' => t('A standard event used by various sites.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
