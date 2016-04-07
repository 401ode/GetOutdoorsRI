<?php
/**
 * @file
 * mo_cms_user_groups.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mo_cms_user_groups_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_privacy|node|mo_cms_user_group|default';
  $field_group->group_name = 'group_privacy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_user_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Privacy Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_mo_cms_user_groups_join',
      1 => 'field_mo_cms_user_groups_stats',
      2 => 'field_mo_cms_user_groups_vis',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Privacy Settings',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_privacy|node|mo_cms_user_group|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_conversion|taxonomy_term|activities|form';
  $field_group->group_name = 'group_tab_conversion';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'activities';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Conversion',
    'weight' => '10',
    'children' => array(
      0 => 'field_activity_conversion_coef',
      1 => 'field_metabolic_equivalent_coef',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_conversion|taxonomy_term|activities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mo_cms_user_group|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_user_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Group Information',
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'field_url',
      2 => 'field_mo_cms_postal_address',
      3 => 'field_trail_activity',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_main|node|mo_cms_user_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|taxonomy_term|activities|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'activities';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Term',
    'weight' => '9',
    'children' => array(
      0 => 'field_activity_past_tense',
      1 => 'name',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_main|taxonomy_term|activities|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_options|node|mo_cms_user_group|form';
  $field_group->group_name = 'group_tab_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_user_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '9',
    'children' => array(
      0 => 'field_mo_cms_user_groups_join',
      1 => 'field_mo_cms_user_groups_stats',
      2 => 'field_mo_cms_user_groups_vis',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_options|node|mo_cms_user_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_owners|node|mo_cms_user_group|form';
  $field_group->group_name = 'group_tab_owners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_user_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Owners',
    'weight' => '8',
    'children' => array(
      0 => 'field_mo_cms_user_groups_owners',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_owners|node|mo_cms_user_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mo_cms_user_group|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_user_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_owners',
      2 => 'group_tab_options',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs_main|node|mo_cms_user_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|taxonomy_term|activities|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'activities';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_conversion',
      2 => 'group_tab_description',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs_main|taxonomy_term|activities|form'] = $field_group;

  return $export;
}
