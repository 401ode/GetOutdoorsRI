<?php
/**
 * @file
 * mo_cms_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mo_cms_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial|node|mo_cms_event|form';
  $field_group->group_name = 'group_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_mo_cms_editorial_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-editorial field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial|node|mo_cms_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_datetime|node|mo_cms_event|form';
  $field_group->group_name = 'group_tab_datetime';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Dates & Times',
    'weight' => '6',
    'children' => array(
      0 => 'field_mo_cms_event_dates',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-datetime field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_datetime|node|mo_cms_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_location|node|mo_cms_event|form';
  $field_group->group_name = 'group_tab_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '7',
    'children' => array(
      0 => 'field_mo_cms_postal_address',
      1 => 'field_mo_cms_map_coords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_location|node|mo_cms_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mo_cms_event|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Name & Description',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_mo_cms_event_type',
      2 => 'field_mo_cms_event_website',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_main|node|mo_cms_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mo_cms_event|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_datetime',
      2 => 'group_tab_location',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mo_cms_event|form'] = $field_group;

  return $export;
}
