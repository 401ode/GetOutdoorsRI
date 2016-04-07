<?php
/**
 * @file
 * mo_cms.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mo_cms_field_group_info() {
  $export = array();

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
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_address|node|mo_cms_location|form';
  $field_group->group_name = 'group_tab_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_location';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '7',
    'children' => array(
      0 => 'field_mo_cms_address',
      1 => 'field_mo_cms_contact_info_std',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-address field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_address|node|mo_cms_location|form'] = $field_group;

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
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
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
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
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
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
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
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
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
  $export['group_tab_categorization|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|page|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '9',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
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
  $export['group_tab_categorization|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_categorization|node|panel|form';
  $field_group->group_name = 'group_tab_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'panel';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '9',
    'children' => array(
      0 => 'field_mo_cms_related_locations',
      1 => 'field_mo_cms_categories',
      2 => 'field_mo_cms_related_agencies',
      3 => 'field_tags',
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
  $export['group_tab_categorization|node|panel|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_contacts|node|mo_cms_contact|form';
  $field_group->group_name = 'group_tab_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_mo_cms_contact_info_std',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-contacts field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_contacts|node|mo_cms_contact|form'] = $field_group;

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
  $field_group->identifier = 'group_tab_editorial_options|node|article|form';
  $field_group->group_name = 'group_tab_editorial_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Options',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-editorial-options field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_editorial_options|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_editorial_options|node|page|form';
  $field_group->group_name = 'group_tab_editorial_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Options',
    'weight' => '1',
    'children' => array(
      0 => 'field_mo_cms_editorial_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-editorial-options field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_editorial_options|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_features|node|mo_cms_location|form';
  $field_group->group_name = 'group_tab_features';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_location';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Features',
    'weight' => '8',
    'children' => array(
      0 => 'field_mo_cms_location_telepres',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-features field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_features|node|mo_cms_location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_images|node|page|form';
  $field_group->group_name = 'group_tab_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '8',
    'children' => array(
      0 => 'field_mo_cms_node_image',
      1 => 'field_mo_cms_node_preview_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-images field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_images|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_image|node|article|form';
  $field_group->group_name = 'group_tab_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '12',
    'children' => array(
      0 => 'field_image',
      1 => 'field_mo_cms_node_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-image field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_image|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_lists|node|mo_cms_contact|form';
  $field_group->group_name = 'group_tab_lists';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Contact Lists',
    'weight' => '7',
    'children' => array(
      0 => 'field_mo_cms_contact_lists',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-lists field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_lists|node|mo_cms_contact|form'] = $field_group;

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
  $export['group_tab_main|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|article|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Article',
    'weight' => '9',
    'children' => array(
      0 => 'body',
      1 => 'title',
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
  $export['group_tab_main|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|mo_cms_location|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_location';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Name and Type',
    'weight' => '5',
    'children' => array(
      0 => 'field_mo_cms_location_type',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Name and Type',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-tab-main field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_tab_main|node|mo_cms_location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|page|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Page Content',
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'title',
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
  $export['group_tab_main|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_main|node|panel|form';
  $field_group->group_name = 'group_tab_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'panel';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '7',
    'children' => array(
      0 => 'title',
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
  $export['group_tab_main|node|panel|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_name|node|mo_cms_contact|form';
  $field_group->group_name = 'group_tab_name';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '5',
    'children' => array(
      0 => 'field_mo_cms_create_block',
      1 => 'field_mo_cms_name_alpha',
      2 => 'field_mo_cms_title',
      3 => 'field_mo_cms_agency',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tab-name field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_name|node|mo_cms_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_previews|node|panel|form';
  $field_group->group_name = 'group_tab_previews';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'panel';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_main';
  $field_group->data = array(
    'label' => 'Previews',
    'weight' => '8',
    'children' => array(
      0 => 'field_mo_cms_node_preview_image',
      1 => 'field_summary',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tab-previews field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tab_previews|node|panel|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_style_sections|taxonomy_term|mo_cms_out_of_state_locations|form';
  $field_group->group_name = 'group_tab_style_sections';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'mo_cms_out_of_state_locations';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Style Sections',
    'weight' => '1',
    'children' => array(
      0 => 'field_mo_cms_location_lists_pri',
      1 => 'field_mo_cms_location_lists_sec',
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
  $field_group->identifier = 'group_tabs_main|node|article|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_image',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mo_cms_contact|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_tab_contacts',
      1 => 'group_tab_lists',
      2 => 'group_tab_name',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mo_cms_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|mo_cms_location|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mo_cms_location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_features',
      1 => 'group_tab_address',
      2 => 'group_tab_main',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|mo_cms_location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|page|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_categorization',
      1 => 'group_tab_images',
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
  $export['group_tabs_main|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_main|node|panel|form';
  $field_group->group_name = 'group_tabs_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'panel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_previews',
      2 => 'group_tab_categorization',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-main field-group-tabs',
      ),
    ),
  );
  $export['group_tabs_main|node|panel|form'] = $field_group;

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
      0 => 'field_user_real_name',
      1 => 'field_user_org',
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
