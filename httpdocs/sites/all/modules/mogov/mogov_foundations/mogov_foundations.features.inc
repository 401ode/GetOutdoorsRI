<?php
/**
 * @file
 * mogov_foundations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mogov_foundations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function mogov_foundations_node_info() {
  $items = array(
    'mogov_contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('Contact information for an individual or an organization.'),
      'has_title' => '1',
      'title_label' => t('Name (for normal display, e.g. "Jane Q. Smythe")'),
      'help' => '',
    ),
    'mogov_page' => array(
      'name' => t('Basic Page'),
      'base' => 'node_content',
      'description' => t('Use for basic content. Offers easy in-place WYSIWYG editing, but is limited to the standard site layout.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mogov_page_panelized' => array(
      'name' => t('Basic Page, with layout options'),
      'base' => 'node_content',
      'description' => t('Use for basic content. While this version loses the easy in-place WYSIWYG editing, it gains increased layout flexibility.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
