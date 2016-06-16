<?php
/**
 * @file
 * mogov_foundations.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mogov_foundations_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fieldset_internet|field_collection_item|field_mogov_contact_information|form';
  $field_group->group_name = 'group_fieldset_internet';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_mogov_contact_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Internet',
    'weight' => '2',
    'children' => array(
      0 => 'field_mogov_email',
      1 => 'field_mogov_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fieldset-internet field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_fieldset_internet|field_collection_item|field_mogov_contact_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fieldset_phones|field_collection_item|field_mogov_contact_information|form';
  $field_group->group_name = 'group_fieldset_phones';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_mogov_contact_information';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Phone Numbers',
    'weight' => '1',
    'children' => array(
      0 => 'field_mogov_phone',
      1 => 'field_mogov_phone_mobile',
      2 => 'field_mogov_phone_tdd',
      3 => 'field_mogov_phone_fax',
      4 => 'field_mogov_phone_toll_free',
      5 => 'field_mogov_phone_hotline',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Phone Numbers',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-fieldset-phones field-group-fieldset',
        'description' => 'Leave blank any numbers that aren\'t applicable to this contact.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_fieldset_phones|field_collection_item|field_mogov_contact_information|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|default';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_real_name',
      1 => 'field_user_org',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'user_user_full_group_personal',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_alt_title|file|image|form';
  $field_group->group_name = 'group_tab_alt_title';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Alt and Title Tags',
    'weight' => '16',
    'children' => array(
      0 => 'field_file_image_alt_text',
      1 => 'field_file_image_title_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-alt-title field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_alt_title|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|file|audio|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '5',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_mogov_categories',
      2 => 'field_mogov_agencies',
      3 => 'field_mogov_state_locations',
      4 => 'field_mogov_tags',
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
  $export['group_tab_categorization|file|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|file|document|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '14',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_mogov_categories',
      2 => 'field_mogov_agencies',
      3 => 'field_mogov_state_locations',
      4 => 'field_mogov_tags',
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
  $export['group_tab_categorization|file|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|file|image|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '17',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_mogov_categories',
      2 => 'field_mogov_agencies',
      3 => 'field_mogov_state_locations',
      4 => 'field_mogov_tags',
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
  $export['group_tab_categorization|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|file|video|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '4',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_mogov_categories',
      2 => 'field_mogov_agencies',
      3 => 'field_mogov_state_locations',
      4 => 'field_mogov_tags',
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
  $export['group_tab_categorization|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|mogov_page_panelized|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page_panelized';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '9',
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
  $export['group_tab_categorization|node|mogov_page_panelized|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|mogov_page|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '7',
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
  $export['group_tab_categorization|node|mogov_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_contact_info|node|mogov_contact|form';
  $field_group->group_name = 'group_tab_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '12',
    'children' => array(
      0 => 'field_mogov_contact_information',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-contact-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_contact_info|node|mogov_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_contact_lists|node|mogov_contact|form';
  $field_group->group_name = 'group_tab_contact_lists';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Contact Lists',
    'weight' => '13',
    'children' => array(
      0 => 'field_mogov_contact_lists',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-contact-lists field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_contact_lists|node|mogov_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_description|file|audio|form';
  $field_group->group_name = 'group_tab_description';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '4',
    'children' => array(
      0 => 'media_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_description|file|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_description|file|document|form';
  $field_group->group_name = 'group_tab_description';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '13',
    'children' => array(
      0 => 'media_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_description|file|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_description|file|image|form';
  $field_group->group_name = 'group_tab_description';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '15',
    'children' => array(
      0 => 'media_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_description|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_description|file|video|form';
  $field_group->group_name = 'group_tab_description';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '3',
    'children' => array(
      0 => 'media_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_description|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|file|audio|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Recording Info',
    'weight' => '3',
    'children' => array(
      0 => 'media_title',
      1 => 'field_license',
      2 => 'field_mo_cms_date',
      3 => 'filename',
      4 => 'preview',
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
  $export['group_tab_main|file|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|file|document|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Document Info',
    'weight' => '12',
    'children' => array(
      0 => 'media_title',
      1 => 'field_license',
      2 => 'filename',
      3 => 'preview',
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
  $export['group_tab_main|file|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|file|image|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Image Info',
    'weight' => '14',
    'children' => array(
      0 => 'media_title',
      1 => 'field_license',
      2 => 'filename',
      3 => 'preview',
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
  $export['group_tab_main|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|file|video|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Video Info',
    'weight' => '2',
    'children' => array(
      0 => 'media_title',
      1 => 'field_license',
      2 => 'filename',
      3 => 'preview',
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
  $export['group_tab_main|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mogov_contact|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Name & Affiliation',
    'weight' => '10',
    'children' => array(
      0 => 'field_mogov_name_alpha',
      1 => 'field_mogov_agency',
      2 => 'field_mogov_create_block',
      3 => 'field_mogov_position_title',
      4 => 'field_mogov_contact_division',
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
  $export['group_tab_main|node|mogov_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mogov_page_panelized|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page_panelized';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'field_mogov_body',
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
  $export['group_tab_main|node|mogov_page_panelized|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mogov_page|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '6',
    'children' => array(
      0 => 'field_mogov_body',
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
  $export['group_tab_main|node|mogov_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_style_sections|taxonomy_term|mo_cms_out_of_state_locations|form';
  $field_group->group_name = 'group_tab_style_sections';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'mogov_out_of_state_locations';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Style Sections',
    'weight' => '1',
    'children' => array(
      0 => 'field_mo_cms_location_lists_sec',
      1 => 'field_mogov_location_lists_pri',
      2 => 'field_mogov_location_lists_sec',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-style-sections field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_style_sections|taxonomy_term|mo_cms_out_of_state_locations|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|file|audio|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'audio';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_description',
      2 => 'group_tab_main',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|file|audio|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|file|document|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_description',
      2 => 'group_tab_main',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|file|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|file|image|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_alt_title',
      1 => 'group_tab_categorization',
      2 => 'group_tab_description',
      3 => 'group_tab_main',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|file|video|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_description',
      2 => 'group_tab_main',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mogov_contact|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_contact_info',
      2 => 'group_tab_contact_lists',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mogov_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mogov_page_panelized|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page_panelized';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_categorization',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mogov_page_panelized|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mogov_page|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mogov_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_categorization',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mogov_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_account|user|user|form';
  $field_group->group_name = 'group_user_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '1',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_personal|user|user|form';
  $field_group->group_name = 'group_user_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_user_org',
      1 => 'field_mogov_real_name',
      2 => 'field_mogov_agency',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_personal|user|user|form'] = $field_group;

  return $export;
}
