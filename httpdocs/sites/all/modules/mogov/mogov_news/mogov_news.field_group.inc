<?php
/**
 * @file
 * mogov_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mogov_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|mogov_news_release_link|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release_link';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '11',
    'children' => array(
      0 => 'field_mogov_agencies',
      1 => 'field_mogov_categories',
      2 => 'field_mogov_state_locations',
      3 => 'field_mogov_tags',
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
  $export['group_tab_categorization|node|mogov_news_release_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|mogov_news_release|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '12',
    'children' => array(
      0 => 'field_mogov_categories',
      1 => 'field_mogov_agencies',
      2 => 'field_mogov_state_locations',
      3 => 'field_mogov_tags',
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
  $export['group_tab_categorization|node|mogov_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_content|node|mogov_news_release|form';
  $field_group->group_name = 'group_tab_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '10',
    'children' => array(
      0 => 'body',
      1 => 'field_mogov_body',
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
  $export['group_tab_content|node|mogov_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mogov_news_release_link|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release_link';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Headlines',
    'weight' => '8',
    'children' => array(
      0 => 'field_mogov_news_short_headline',
      1 => 'field_mogov_news_deck_copy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_main|node|mogov_news_release_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mogov_news_release|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Headlines',
    'weight' => '8',
    'children' => array(
      0 => 'field_mogov_news_short_headline',
      1 => 'field_mogov_news_deck_copy',
      2 => 'field_mogov_news_dateline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_main|node|mogov_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_media|node|mogov_news_release|form';
  $field_group->group_name = 'group_tab_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '11',
    'children' => array(
      0 => 'field_mogov_news_media',
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
  $export['group_tab_media|node|mogov_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_settings|node|mogov_news_release_link|form';
  $field_group->group_name = 'group_tab_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release_link';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_mogov_news_date',
      1 => 'field_mogov_news_local_only',
      2 => 'field_mogov_news_remote_source',
      3 => 'field_mogov_news_remote_url',
      4 => 'field_mogov_news_type',
      5 => 'field_mogov_news_source',
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
  $export['group_tab_settings|node|mogov_news_release_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_settings|node|mogov_news_release|form';
  $field_group->group_name = 'group_tab_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_mogov_news_date',
      1 => 'field_mogov_news_source',
      2 => 'field_mogov_news_contact',
      3 => 'field_mogov_news_type',
      4 => 'field_mogov_news_local_only',
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
  $export['group_tab_settings|node|mogov_news_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mogov_news_release_link|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release_link';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_main',
      2 => 'group_tab_settings',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mogov_news_release_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mogov_news_release|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_news_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_settings',
      2 => 'group_tab_content',
      3 => 'group_tab_media',
      4 => 'group_tab_categorization',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mogov_news_release|form'] = $field_group;

  return $export;
}
