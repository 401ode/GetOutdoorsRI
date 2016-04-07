<?php
/**
 * @file
 * mo_cms_user_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mo_cms_user_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mo_cms_user_groups_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mo_cms_user_groups_node_info() {
  $items = array(
    'mo_cms_umbrella_group' => array(
      'name' => t('MO CMS: Umbrella Group'),
      'base' => 'node_content',
      'description' => t('A group of related user groups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'mo_cms_user_group' => array(
      'name' => t('MO CMS: User Group'),
      'base' => 'node_content',
      'description' => t('Groups of users.'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  return $items;
}
