<?php
/**
 * @file
 * mo_cms.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function mo_cms_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_email'.
  $fields['field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_email',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'email',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_contact_info_std',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'class_spec_migration_links' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'email_default',
          'weight' => '3',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_email',
      'label' => 'Email',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '3',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_links'.
  $fields['field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_links'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_links',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_contact_info_std',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'class_spec_migration_links' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'link_default',
          'weight' => '4',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_links',
      'label' => 'Links',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'user',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 0,
        'title' => 'optional',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '4',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_map_coords'.
  $fields['field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_map_coords'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_map_coords',
      'foreign keys' => array(),
      'indexes' => array(
        'bbox' => array(
          0 => 'top',
          1 => 'bottom',
          2 => 'left',
          3 => 'right',
        ),
        'bottom' => array(
          0 => 'bottom',
        ),
        'centroid' => array(
          0 => 'lat',
          1 => 'lon',
        ),
        'geohash' => array(
          0 => 'geohash',
        ),
        'lat' => array(
          0 => 'lat',
        ),
        'left' => array(
          0 => 'left',
        ),
        'lon' => array(
          0 => 'lon',
        ),
        'right' => array(
          0 => 'right',
        ),
        'top' => array(
          0 => 'top',
        ),
      ),
      'locked' => '0',
      'module' => 'geofield',
      'settings' => array(
        'backend' => 'default',
        'srid' => '4326',
      ),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_contact_info_std',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'class_spec_migration_links' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_map_coords',
      'label' => 'Map Coordinates',
      'required' => 0,
      'settings' => array(
        'local_solr' => array(
          'enabled' => FALSE,
          'lat_field' => 'lat',
          'lng_field' => 'lng',
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'geocoder',
        'settings' => array(
          'delta_handling' => 'default',
          'geocoder_field' => 'field_mo_cms_postal_address',
          'geocoder_handler' => 'google',
          'handler_settings' => array(
            'google' => array(
              'all_results' => 0,
              'geometry_type' => 'point',
              'reject_results' => array(
                'APPROXIMATE' => 0,
                'GEOMETRIC_CENTER' => 0,
                'RANGE_INTERPOLATED' => 0,
                'ROOFTOP' => 0,
              ),
            ),
          ),
        ),
        'type' => 'geocoder',
        'weight' => '1',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_phone_numbers'.
  $fields['field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_phone_numbers'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_phone_numbers',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 1,
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_contact_info_std',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'class_spec_migration_links' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'field_collection',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => '2',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_phone_numbers',
      'label' => 'Phone Numbers',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => '2',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_postal_address'.
  $fields['field_collection_item-field_mo_cms_contact_info_std-field_mo_cms_postal_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_postal_address',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addressfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_contact_info_std',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'class_spec_migration_links' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'addressfield',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'format_handlers' => array(
              'address' => 'address',
              'address-hide-country' => 'address-hide-country',
            ),
            'use_widget_handlers' => 0,
          ),
          'type' => 'addressfield_default',
          'weight' => '0',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_postal_address',
      'label' => 'Address',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(
            'US' => 'US',
          ),
          'format_handlers' => array(
            'address' => 'address',
            'address-hide-country' => 'address-hide-country',
            'organisation' => 0,
            'name-full' => 0,
            'name-oneline' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => 0,
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_phone_numbers-field_mo_cms_phone'.
  $fields['field_collection_item-field_mo_cms_phone_numbers-field_mo_cms_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'telephone',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'telephone',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_phone_numbers',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_plain',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_phone',
      'label' => 'Number',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'telephone',
        'settings' => array(
          'placeholder' => '',
        ),
        'type' => 'telephone_default',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_mo_cms_phone_numbers-field_mo_cms_phone_numbers_label'.
  $fields['field_collection_item-field_mo_cms_phone_numbers-field_mo_cms_phone_numbers_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_phone_numbers_label',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'field_mo_cms_phone_numbers',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Phone, Fax, TDD, Toll-free, etc.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'number_only' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mo_cms_phone_numbers_label',
      'label' => 'Label',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '20',
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'file-audio-field_license'.
  $fields['file-audio-field_license'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_license',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '1',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '_media_gallery_get_field_license_values',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => array(
        0 => array(
          'value' => 'nothing',
        ),
      ),
      'deleted' => '0',
      'description' => 'Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this audio.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_license',
      'label' => 'License settings for this audio',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'file-audio-field_mo_cms_categories'.
  $fields['file-audio-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 6,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-audio-field_mo_cms_date'.
  $fields['file-audio-field_mo_cms_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'repeat' => '0',
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 8,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_date',
      'label' => 'Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
        'wysiwyg_override' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '11',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-audio-field_mo_cms_related_agencies'.
  $fields['file-audio-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 7,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 1,
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-audio-field_mo_cms_related_locations'.
  $fields['file-audio-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 9,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-audio-field_tags'.
  $fields['file-audio-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a comma-separated list of words to describe your audio.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 2,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'file-audio-media_description'.
  $fields['file-audio-media_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_description',
      'label' => 'Description',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 4,
        ),
        'type' => 'text_textarea',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'file-audio-media_title'.
  $fields['file-audio-media_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'audio',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_title',
      'label' => 'Title',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'file-document-field_license'.
  $fields['file-document-field_license'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_license',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '1',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '_media_gallery_get_field_license_values',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => array(
        0 => array(
          'value' => 'nothing',
        ),
      ),
      'deleted' => '0',
      'description' => 'Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this file.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_license',
      'label' => 'License settings for this file',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'file-document-field_mo_cms_categories'.
  $fields['file-document-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 6,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-document-field_mo_cms_related_agencies'.
  $fields['file-document-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 7,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 1,
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-document-field_mo_cms_related_locations'.
  $fields['file-document-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 8,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-document-field_tags'.
  $fields['file-document-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a comma-separated list of words to describe your file.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 2,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'file-document-media_description'.
  $fields['file-document-media_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_description',
      'label' => 'Description',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 4,
        ),
        'type' => 'text_textarea',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'file-document-media_title'.
  $fields['file-document-media_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'document',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_title',
      'label' => 'Title',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'file-image-field_file_image_alt_text'.
  $fields['file-image-field_file_image_alt_text'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_file_image_alt_text',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Alternative text is used by screen readers, search engines, and when the image cannot be loaded. By adding alt text you improve accessibility and search engine optimization.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_file_image_alt_text',
      'label' => 'Alt Text',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'file-image-field_file_image_title_text'.
  $fields['file-image-field_file_image_title_text'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_file_image_title_text',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Title text is used in the tool tip when a user hovers their mouse over the image. Adding title text makes it easier to understand the context of an image and improves usability.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 1,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_file_image_title_text',
      'label' => 'Title Text',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'file-image-field_license'.
  $fields['file-image-field_license'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_license',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '1',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '_media_gallery_get_field_license_values',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => array(
        0 => array(
          'value' => 'nothing',
        ),
      ),
      'deleted' => '0',
      'description' => 'Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this image.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 9,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => '4',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => '4',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_license',
      'label' => 'License settings for this image',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'file-image-field_mo_cms_categories'.
  $fields['file-image-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 5,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-image-field_mo_cms_date'.
  $fields['file-image-field_mo_cms_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'repeat' => '0',
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 10,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'hidden',
          'module' => 'date',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '2',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_date',
      'label' => 'Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
        'wysiwyg_override' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '10',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-image-field_mo_cms_related_agencies'.
  $fields['file-image-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 6,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 1,
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-image-field_mo_cms_related_locations'.
  $fields['file-image-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 11,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '7',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-image-field_tags'.
  $fields['file-image-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a comma-separated list of words to describe your image.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 4,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'file-image-media_description'.
  $fields['file-image-media_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_description',
      'label' => 'Description',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 4,
        ),
        'type' => 'text_textarea',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'file-image-media_title'.
  $fields['file-image-media_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 7,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_title',
      'label' => 'Title',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'file-video-field_license'.
  $fields['file-video-field_license'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_license',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '1',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '_media_gallery_get_field_license_values',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => array(
        0 => array(
          'value' => 'nothing',
        ),
      ),
      'deleted' => '0',
      'description' => 'Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this video.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 3,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_license',
      'label' => 'License settings for this video',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'file-video-field_mo_cms_categories'.
  $fields['file-video-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 6,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-video-field_mo_cms_date'.
  $fields['file-video-field_mo_cms_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'repeat' => '0',
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 8,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_date',
      'label' => 'Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'now',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
        'wysiwyg_override' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '11',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-video-field_mo_cms_related_agencies'.
  $fields['file-video-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 7,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 1,
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-video-field_mo_cms_related_locations'.
  $fields['file-video-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 9,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'file-video-field_tags'.
  $fields['file-video-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter a comma-separated list of words to describe your video.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 2,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'file-video-media_description'.
  $fields['file-video-media_description'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_description',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_description',
      'label' => 'Description',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 4,
        ),
        'type' => 'text_textarea',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'file-video-media_title'.
  $fields['file-video-media_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'media_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'media_gallery_block_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_collection_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_gallery_detail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_lightbox' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'media_gallery_thumbnail' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
        'preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'views_gallery_thumbnail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'file',
      'field_name' => 'media_title',
      'label' => 'Title',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-article-field_mo_cms_node_image'.
  $fields['node-article-field_mo_cms_node_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_node_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'article',
      'deleted' => '0',
      'description' => 'You may use this field to attach a single image to be displayed on the full page view of this piece of content. The image will be displayed in a standard size and location based on the site configuration. If you are using only a single image, it is probably better to use this field rather than inserting the image into the WYSIWYG editor.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_node_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'node_images/full',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'feed' => 0,
            'http' => 0,
            'https' => 0,
            'public' => 'public',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'remote_file' => 0,
            'upload' => 'upload',
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_agency'.
  $fields['node-mo_cms_contact-field_mo_cms_agency'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_agency',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '1',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_agency',
      'label' => 'Agency',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '-2',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_contact_info_std'.
  $fields['node-mo_cms_contact-field_mo_cms_contact_info_std'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_contact_info_std',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 1,
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'field_collection',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => '2',
        ),
        'embedded_contact' => array(
          'label' => 'hidden',
          'module' => 'field_collection',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => '1',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_contact_info_std',
      'label' => 'Contact Information',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => '44',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_contact_lists'.
  $fields['node-mo_cms_contact-field_mo_cms_contact_lists'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_contact_lists',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_contact_lists',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Tag this contact with one or more list names. Views can be built to list contacts matching a given tag.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'embedded_contact' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_contact_lists',
      'label' => 'Contact Lists',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '42',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_create_block'.
  $fields['node-mo_cms_contact-field_mo_cms_create_block'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_create_block',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'If enabled, a block will be created containing this contact\'s info. Useful if you wish to place the contact into a sidebar or other region on other pages.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'embedded_contact' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_create_block',
      'label' => 'Create Block',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '-1',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_name_alpha'.
  $fields['node-mo_cms_contact-field_mo_cms_name_alpha'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_name_alpha',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'contact_block' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'embedded_contact' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_name_alpha',
      'label' => 'Name (last, first)',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '-4',
      ),
    ),
  );

  // Exported field: 'node-mo_cms_contact-field_mo_cms_title'.
  $fields['node-mo_cms_contact-field_mo_cms_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_contact',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'contact_block' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'embedded_contact' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_title',
      'label' => 'Position Title',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '-3',
      ),
    ),
  );

  // Exported field: 'node-mo_cms_location-field_mo_cms_contact_info_std'.
  $fields['node-mo_cms_location-field_mo_cms_contact_info_std'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_contact_info_std',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 1,
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_location',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 3,
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_contact_info_std',
      'label' => 'Contact Information',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_location-field_mo_cms_location_telepres'.
  $fields['node-mo_cms_location-field_mo_cms_location_telepres'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_location_telepres',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'immersive' => 'Immersive',
          'nonimmersive' => 'Non-Immersive',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_location',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_location_telepres',
      'label' => 'Telepresence',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '41',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-mo_cms_location-field_mo_cms_location_type'.
  $fields['node-mo_cms_location-field_mo_cms_location_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_location_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'State Facility' => 'State Facility',
          'Hotel' => 'Hotel',
          'Other' => 'Other',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_location',
      'default_value' => array(
        0 => array(
          'value' => 'State Facility',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'list_default',
          'weight' => 0,
        ),
        'ical' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_location_type',
      'label' => 'Type',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-page-field_mo_cms_categories'.
  $fields['node-page-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-page-field_mo_cms_editorial_section'.
  $fields['node-page-field_mo_cms_editorial_section'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_editorial_section',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_editorial_sections',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_editorial_section',
      'label' => 'Editorial Section',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
      'workbench_access_field' => 1,
    ),
  );

  // Exported field: 'node-page-field_mo_cms_node_image'.
  $fields['node-page-field_mo_cms_node_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_node_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'deleted' => '0',
      'description' => 'You may use this field to attach a single image to be displayed on the full page view of this piece of content. The image will be displayed in a standard size and location based on the site configuration. If you are using only a single image, it is probably better to use this field rather than inserting the image into the WYSIWYG editor.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'colorbox',
          'settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'none',
            'colorbox_gallery_custom' => '',
            'colorbox_image_style' => 'large',
            'colorbox_multivalue_index' => NULL,
            'colorbox_node_style' => 'grid_8',
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'colorbox',
          'weight' => '0',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_node_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'node_images/full',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'feed' => 0,
            'http' => 0,
            'https' => 0,
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'remote_file' => 0,
            'upload' => 'upload',
            'youtube' => 0,
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-page-field_mo_cms_node_preview_image'.
  $fields['node-page-field_mo_cms_node_preview_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_node_preview_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'deleted' => '0',
      'description' => 'You may attach a single image to be displayed in a standard size and location when this content is displayed in preview mode.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_node_preview_image',
      'label' => 'Preview Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'node_images/preview',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'feed' => 0,
            'http' => 0,
            'https' => 0,
            'public' => 'public',
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'remote_file' => 0,
            'upload' => 'upload',
            'youtube' => 0,
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-page-field_mo_cms_related_agencies'.
  $fields['node-page-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 1,
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-page-field_mo_cms_related_locations'.
  $fields['node-page-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '7',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-page-field_tags'.
  $fields['node-page-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '8',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_mo_cms_categories'.
  $fields['node-panel-field_mo_cms_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_categories',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 3,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '9',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_mo_cms_node_preview_image'.
  $fields['node-panel-field_mo_cms_node_preview_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_node_preview_image',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'deleted' => '0',
      'description' => 'Images will be scaled and cropped to the appropriate size.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 1,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_node_preview_image',
      'label' => 'Preview Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'node_images/preview',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'feed' => 0,
            'http' => 0,
            'https' => 0,
            'public' => 'public',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'remote_file' => 0,
            'upload' => 'upload',
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_mo_cms_related_agencies'.
  $fields['node-panel-field_mo_cms_related_agencies'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_agencies',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 4,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mo_cms_related_agencies',
      'label' => 'Related Agencies',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '10',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_mo_cms_related_locations'.
  $fields['node-panel-field_mo_cms_related_locations'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_related_locations',
      'foreign keys' => array(
        'taxonomy_term_data' => array(
          'columns' => array(
            'target_id' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'mo_cms_counties' => 'mo_cms_counties',
            'mo_cms_municipalities' => 'mo_cms_municipalities',
            'mo_cms_out_of_state_locations' => 'mo_cms_out_of_state_locations',
          ),
        ),
        'target_type' => 'taxonomy_term',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter locations of relevance to this content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'entityconnect_unload_add' => '1',
      'entityconnect_unload_edit' => '1',
      'field_name' => 'field_mo_cms_related_locations',
      'label' => 'Related Locations',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'taxonomy-index' => array(
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete_tags',
        'weight' => '11',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_summary'.
  $fields['node-panel-field_summary'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_summary',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'plain_text',
            ),
          ),
          'type' => 'text_default',
          'weight' => 2,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_summary',
      'label' => 'Summary',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '7',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'node-panel-field_tags'.
  $fields['node-panel-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'tags',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'panel',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 5,
        ),
        'mo_cms_slider' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '12',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'taxonomy_term-mo_cms_agencies-field_agency_abbreviation'.
  $fields['taxonomy_term-mo_cms_agencies-field_agency_abbreviation'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_agency_abbreviation',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_agencies',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'exclude_cv' => 0,
      'field_name' => 'field_agency_abbreviation',
      'label' => 'Abbreviation',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'taxonomy_term-mo_cms_agencies-field_agency_short_name'.
  $fields['taxonomy_term-mo_cms_agencies-field_agency_short_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_agency_short_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_agencies',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'exclude_cv' => 0,
      'field_name' => 'field_agency_short_name',
      'label' => 'Short Name',
      'required' => 1,
      'settings' => array(
        'exclude_cv' => FALSE,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'taxonomy_term-mo_cms_out_of_state_locations-field_mo_cms_location_lists_pri'.
  $fields['taxonomy_term-mo_cms_out_of_state_locations-field_mo_cms_location_lists_pri'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_location_lists_pri',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_out_of_state_locations',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'For "Kansas City, KS", this field should contain what you want displayed in place of "Kansas City". In most cases, this will simply duplicate the first part of the text from the full name. <b>Note:</b> Do not force case here! Use normal capitalization. Styles will be used to apply the desired capitalization for display.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_mo_cms_location_lists_pri',
      'label' => 'Primary',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '20',
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'taxonomy_term-mo_cms_out_of_state_locations-field_mo_cms_location_lists_sec'.
  $fields['taxonomy_term-mo_cms_out_of_state_locations-field_mo_cms_location_lists_sec'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mo_cms_location_lists_sec',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mo_cms_out_of_state_locations',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'For "Kansas City, KS", this field should contain what you want displayed in place of "KS", for example, "Ks.".',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_mo_cms_location_lists_sec',
      'label' => 'Secondary',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '20',
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'user-user-field_user_org'.
  $fields['user-user-field_user_org'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_user_org',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'mo_cms_agencies',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => array(
        0 => array(
          'tid' => '140',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(
            'edit' => array(
              'editor' => 'form',
            ),
          ),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_user_org',
      'label' => 'Organization',
      'required' => 1,
      'settings' => array(
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'apply_chosen' => 0,
        ),
        'type' => 'options_select',
        'weight' => '3',
      ),
      'workbench_access_field' => 0,
    ),
  );

  // Exported field: 'user-user-field_user_real_name'.
  $fields['user-user-field_user_real_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_user_real_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Will not be displayed to public unless explicitly noted in a content type (e.g., if the site implements a blog, and blog posts display their author). Used to identify people who have worked on content more clearly than by username.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(
            'edit' => array(
              'editor' => 'direct',
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_user_real_name',
      'label' => 'Real Name',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '40',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abbreviation');
  t('Address');
  t('Agency');
  t('Alt Text');
  t('Alternative text is used by screen readers, search engines, and when the image cannot be loaded. By adding alt text you improve accessibility and search engine optimization.');
  t('Categories');
  t('Contact Information');
  t('Contact Lists');
  t('Create Block');
  t('Date');
  t('Description');
  t('Editorial Section');
  t('Email');
  t('Enter a comma-separated list of words to describe your audio.');
  t('Enter a comma-separated list of words to describe your file.');
  t('Enter a comma-separated list of words to describe your image.');
  t('Enter a comma-separated list of words to describe your video.');
  t('Enter locations of relevance to this content.');
  t('For "Kansas City, KS", this field should contain what you want displayed in place of "KS", for example, "Ks.".');
  t('For "Kansas City, KS", this field should contain what you want displayed in place of "Kansas City". In most cases, this will simply duplicate the first part of the text from the full name. <b>Note:</b> Do not force case here! Use normal capitalization. Styles will be used to apply the desired capitalization for display.');
  t('If enabled, a block will be created containing this contact\'s info. Useful if you wish to place the contact into a sidebar or other region on other pages.');
  t('Image');
  t('Images will be scaled and cropped to the appropriate size.');
  t('Label');
  t('License settings for this audio');
  t('License settings for this file');
  t('License settings for this image');
  t('License settings for this video');
  t('Links');
  t('Map Coordinates');
  t('Name (last, first)');
  t('Number');
  t('Organization');
  t('Phone Numbers');
  t('Phone, Fax, TDD, Toll-free, etc.');
  t('Position Title');
  t('Preview Image');
  t('Primary');
  t('Real Name');
  t('Related Agencies');
  t('Related Locations');
  t('Secondary');
  t('Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this audio.');
  t('Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this file.');
  t('Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this image.');
  t('Select a <a href="http://creativecommons.org" target="_new">Creative Commons</a> license for others who use this video.');
  t('Select any agencies that may be of relevance or interest to someone reading this item. This will be combined with the Tags field to help find related sites and content.');
  t('Short Name');
  t('Summary');
  t('Tag this contact with one or more list names. Views can be built to list contacts matching a given tag.');
  t('Tags');
  t('Telepresence');
  t('Title');
  t('Title Text');
  t('Title text is used in the tool tip when a user hovers their mouse over the image. Adding title text makes it easier to understand the context of an image and improves usability.');
  t('Type');
  t('Will not be displayed to public unless explicitly noted in a content type (e.g., if the site implements a blog, and blog posts display their author). Used to identify people who have worked on content more clearly than by username.');
  t('You may attach a single image to be displayed in a standard size and location when this content is displayed in preview mode.');
  t('You may use this field to attach a single image to be displayed on the full page view of this piece of content. The image will be displayed in a standard size and location based on the site configuration. If you are using only a single image, it is probably better to use this field rather than inserting the image into the WYSIWYG editor.');

  return $fields;
}
