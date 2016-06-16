<?php
/**
 * @file
 * mo_cms_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mo_cms_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function mo_cms_news_node_info() {
  $items = array(
    'mo_cms_news_release' => array(
      'name' => t('MO CMS: News Release'),
      'base' => 'node_content',
      'description' => t('A standard news release suitable for display on mo.gov and other state websites.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => t('Enter the full headline, for use on a full view of the news release and wherever else there is sufficient space.'),
    ),
  );
  return $items;
}
