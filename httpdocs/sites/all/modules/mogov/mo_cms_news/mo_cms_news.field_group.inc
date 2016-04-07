<?php
/**
 * @file
 * mo_cms_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mo_cms_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '26',
    'children' => array(
      0 => 'field_mo_cms_categories',
      1 => 'field_mo_cms_related_agencies',
      2 => 'field_tags',
      3 => 'field_mo_cms_related_locations',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-categorization field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_categorization|node|mo_cms_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_content|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tab_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '24',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_content|node|mo_cms_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Headlines',
    'weight' => '23',
    'children' => array(
      0 => 'field_mo_cms_news_deck_copy',
      1 => 'field_mo_cms_news_short_headline',
      2 => 'field_mo_cms_county_muni',
      3 => 'field_mo_cms_news_date',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Headlines',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-tab-main field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_tab_main|node|mo_cms_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_media|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tab_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '25',
    'children' => array(
      0 => 'field_mo_cms_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_media|node|mo_cms_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_settings|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tab_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '22',
    'children' => array(
      0 => 'field_mo_cms_contact',
      1 => 'field_mo_cms_news_type',
      2 => 'field_mo_cms_local_only',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_settings|node|mo_cms_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mo_cms_news_release|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_content',
      2 => 'group_tab_main',
      3 => 'group_tab_media',
      4 => 'group_tab_settings',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mo_cms_news_release|form'] = $field_group;

  return $export;
}
