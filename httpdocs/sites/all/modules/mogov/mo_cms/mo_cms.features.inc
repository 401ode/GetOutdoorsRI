<?php
/**
 * @file
 * mo_cms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mo_cms_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function mo_cms_node_info() {
  $items = array(
    'mo_cms_contact' => array(
      'name' => t('MO CMS: Contact'),
      'base' => 'node_content',
      'description' => t('A state agency contact.'),
      'has_title' => '1',
      'title_label' => t('Name (first last)'),
      'help' => '',
    ),
    'mo_cms_location' => array(
      'name' => t('MO CMS: Location'),
      'base' => 'node_content',
      'description' => t('A location (state-owned or otherwise) that may be referenced in meeting notices, building closures, etc.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
