<?php
/**
 * @file
 * mogov_foundations.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function mogov_foundations_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_address'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_address'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => array(
      0 => array(
        'element_key' => 'field_collection_item|field_mogov_contact_information|field_mogov_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'locality' => '',
        'administrative_area' => 'MO',
        'postal_code' => '',
        'country' => 'US',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'quickedit' => array(
            'editor' => 'form',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_address',
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
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_coordinates'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_coordinates'] = array(
    'bundle' => 'field_mogov_contact_information',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'slim' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_coordinates',
    'label' => 'Map Coordinates',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geocoder',
      'settings' => array(
        'delta_handling' => 'default',
        'geocoder_field' => 'field_mogov_address',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_email'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_email'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'email_default',
        'weight' => 7,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'emailwidget',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_links'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_links'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'link_default',
        'weight' => 8,
      ),
      'slim' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_links',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 2,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone',
    'label' => 'Phone',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone_fax'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone_fax'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 5,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone_fax',
    'label' => 'Fax',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone_hotline'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone_hotline'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 1,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone_hotline',
    'label' => 'Hotline',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone_mobile'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone_mobile'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 3,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone_mobile',
    'label' => 'Mobile',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone_tdd'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone_tdd'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 4,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone_tdd',
    'label' => 'TDD',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_mogov_contact_information-field_mogov_phone_toll_free'
  $field_instances['field_collection_item-field_mogov_contact_information-field_mogov_phone_toll_free'] = array(
    'bundle' => 'field_mogov_contact_information',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'telephone',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'title' => '',
        ),
        'type' => 'telephone_link',
        'weight' => 6,
      ),
      'slim' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_mogov_phone_toll_free',
    'label' => 'Toll-Free',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'telephone',
      'settings' => array(
        'placeholder' => '###-###-####',
      ),
      'type' => 'telephone_default',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'file-audio-field_mogov_agencies'
  $field_instances['file-audio-field_mogov_agencies'] = array(
    'bundle' => 'audio',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
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
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'file-audio-field_mogov_categories'
  $field_instances['file-audio-field_mogov_categories'] = array(
    'bundle' => 'audio',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
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
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'file-audio-field_mogov_state_locations'
  $field_instances['file-audio-field_mogov_state_locations'] = array(
    'bundle' => 'audio',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
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
    'field_name' => 'field_mogov_state_locations',
    'label' => 'Related Locations',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'file-audio-field_mogov_tags'
  $field_instances['file-audio-field_mogov_tags'] = array(
    'bundle' => 'audio',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 13,
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
    'field_name' => 'field_mogov_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'file-document-field_mogov_agencies'
  $field_instances['file-document-field_mogov_agencies'] = array(
    'bundle' => 'document',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 10,
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
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'file-document-field_mogov_categories'
  $field_instances['file-document-field_mogov_categories'] = array(
    'bundle' => 'document',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
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
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'file-document-field_mogov_state_locations'
  $field_instances['file-document-field_mogov_state_locations'] = array(
    'bundle' => 'document',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
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
    'field_name' => 'field_mogov_state_locations',
    'label' => 'Related Locations',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'file-document-field_mogov_tags'
  $field_instances['file-document-field_mogov_tags'] = array(
    'bundle' => 'document',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 12,
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
    'field_name' => 'field_mogov_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'file-image-field_mogov_agencies'
  $field_instances['file-image-field_mogov_agencies'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 13,
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
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'file-image-field_mogov_categories'
  $field_instances['file-image-field_mogov_categories'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
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
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'file-image-field_mogov_state_locations'
  $field_instances['file-image-field_mogov_state_locations'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 14,
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
    'field_name' => 'field_mogov_state_locations',
    'label' => 'Related Locations',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'file-image-field_mogov_tags'
  $field_instances['file-image-field_mogov_tags'] = array(
    'bundle' => 'image',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 15,
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
    'field_name' => 'field_mogov_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'file-video-field_mogov_agencies'
  $field_instances['file-video-field_mogov_agencies'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
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
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'file-video-field_mogov_categories'
  $field_instances['file-video-field_mogov_categories'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
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
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'file-video-field_mogov_state_locations'
  $field_instances['file-video-field_mogov_state_locations'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 12,
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
    'field_name' => 'field_mogov_state_locations',
    'label' => 'Related Locations',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'file-video-field_mogov_tags'
  $field_instances['file-video-field_mogov_tags'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 13,
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
    'field_name' => 'field_mogov_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_agency'
  $field_instances['node-mogov_contact-field_mogov_agency'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_agency',
    'label' => 'Agency',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_contact_division'
  $field_instances['node-mogov_contact-field_mogov_contact_division'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_contact_division',
    'label' => 'Division',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_contact_information'
  $field_instances['node-mogov_contact-field_mogov_contact_information'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 3,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_contact_information',
    'label' => 'Contact information',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_contact_lists'
  $field_instances['node-mogov_contact-field_mogov_contact_lists'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Selecting one or more contact lists in which this contact should be included will cause the contact to display on automated contact list displays generated using the selected list or lists. Note that this feature is not actually used on every site.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_contact_lists',
    'label' => 'Contact lists',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_create_block'
  $field_instances['node-mogov_contact-field_mogov_create_block'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Usually unnecessary, as entities may be inserted into content panes. However, this will generate a block should it not be possible to use a content pane.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_create_block',
    'label' => 'Create block',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_name_alpha'
  $field_instances['node-mogov_contact-field_mogov_name_alpha'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'For an individual, this will usually be "Last Name, First Name", e.g. "Smythe, Jane Q." For an organization, it may be appropriate to reposition parts of the name, e.g. "Cole County Historical Society, the".',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_name_alpha',
    'label' => 'Name (for alphabetical display)',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-mogov_contact-field_mogov_position_title'
  $field_instances['node-mogov_contact-field_mogov_position_title'] = array(
    'bundle' => 'mogov_contact',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_position_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-mogov_page-field_mogov_agencies'
  $field_instances['node-mogov_page-field_mogov_agencies'] = array(
    'bundle' => 'mogov_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page-field_mogov_body'
  $field_instances['node-mogov_page-field_mogov_body'] = array(
    'bundle' => 'mogov_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'quickedit' => array(
            'editor' => 'form',
          ),
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 7,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page-field_mogov_categories'
  $field_instances['node-mogov_page-field_mogov_categories'] = array(
    'bundle' => 'mogov_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page-field_mogov_state_locations'
  $field_instances['node-mogov_page-field_mogov_state_locations'] = array(
    'bundle' => 'mogov_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_state_locations',
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
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 10,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page-field_mogov_tags'
  $field_instances['node-mogov_page-field_mogov_tags'] = array(
    'bundle' => 'mogov_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_tags',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-mogov_page_panelized-field_mogov_agencies'
  $field_instances['node-mogov_page_panelized-field_mogov_agencies'] = array(
    'bundle' => 'mogov_page_panelized',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_agencies',
    'label' => 'Related Agencies',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page_panelized-field_mogov_body'
  $field_instances['node-mogov_page_panelized-field_mogov_body'] = array(
    'bundle' => 'mogov_page_panelized',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'quickedit' => array(
            'editor' => 'form',
          ),
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_body',
    'label' => 'Body',
    'required' => 1,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 9,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page_panelized-field_mogov_categories'
  $field_instances['node-mogov_page_panelized-field_mogov_categories'] = array(
    'bundle' => 'mogov_page_panelized',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_categories',
    'label' => 'Categories',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page_panelized-field_mogov_state_locations'
  $field_instances['node-mogov_page_panelized-field_mogov_state_locations'] = array(
    'bundle' => 'mogov_page_panelized',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'mo_cms_slider' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'slim' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mogov_state_locations',
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
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 9,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-mogov_page_panelized-field_mogov_tags'
  $field_instances['node-mogov_page_panelized-field_mogov_tags'] = array(
    'bundle' => 'mogov_page_panelized',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'slim' => array(
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
    'field_name' => 'field_mogov_tags',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'taxonomy_term-mogov_agencies-field_mogov_abbreviation'
  $field_instances['taxonomy_term-mogov_agencies-field_mogov_abbreviation'] = array(
    'bundle' => 'mogov_agencies',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_mogov_abbreviation',
    'label' => 'Abbreviation',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 5,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'taxonomy_term-mogov_agencies-field_mogov_short_name'
  $field_instances['taxonomy_term-mogov_agencies-field_mogov_short_name'] = array(
    'bundle' => 'mogov_agencies',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_mogov_short_name',
    'label' => 'Short Name',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'taxonomy_term-mogov_out_of_state_locations-field_mogov_location_lists_pri'
  $field_instances['taxonomy_term-mogov_out_of_state_locations-field_mogov_location_lists_pri'] = array(
    'bundle' => 'mogov_out_of_state_locations',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_mogov_location_lists_pri',
    'label' => 'Primary',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'taxonomy_term-mogov_out_of_state_locations-field_mogov_location_lists_sec'
  $field_instances['taxonomy_term-mogov_out_of_state_locations-field_mogov_location_lists_sec'] = array(
    'bundle' => 'mogov_out_of_state_locations',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_mogov_location_lists_sec',
    'label' => 'Secondary',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'user-user-field_mogov_agency'
  $field_instances['user-user-field_mogov_agency'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'edit' => array(
            'editor' => 'form',
          ),
          'link' => FALSE,
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mogov_agency',
    'label' => 'Agency',
    'required' => 1,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'user-user-field_mogov_real_name'
  $field_instances['user-user-field_mogov_real_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Will not be displayed to public unless explicitly noted in a content type (e.g., if the site implements a blog, and blog posts display their author). Used to identify people who have worked on content more clearly than by username.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'edit' => array(
            'editor' => 'plain_text',
          ),
          'quickedit' => array(
            'editor' => 'plain_text',
          ),
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_mogov_real_name',
    'label' => 'Real Name',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 40,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abbreviation');
  t('Address');
  t('Agency');
  t('Body');
  t('Categories');
  t('Contact information');
  t('Contact lists');
  t('Create block');
  t('Division');
  t('Email');
  t('Fax');
  t('For an individual, this will usually be "Last Name, First Name", e.g. "Smythe, Jane Q." For an organization, it may be appropriate to reposition parts of the name, e.g. "Cole County Historical Society, the".');
  t('Hotline');
  t('Links');
  t('Map Coordinates');
  t('Mobile');
  t('Name (for alphabetical display)');
  t('Phone');
  t('Primary');
  t('Real Name');
  t('Related Agencies');
  t('Related Locations');
  t('Secondary');
  t('Selecting one or more contact lists in which this contact should be included will cause the contact to display on automated contact list displays generated using the selected list or lists. Note that this feature is not actually used on every site.');
  t('Short Name');
  t('TDD');
  t('Tags');
  t('Title');
  t('Toll-Free');
  t('Usually unnecessary, as entities may be inserted into content panes. However, this will generate a block should it not be possible to use a content pane.');
  t('Will not be displayed to public unless explicitly noted in a content type (e.g., if the site implements a blog, and blog posts display their author). Used to identify people who have worked on content more clearly than by username.');

  return $field_instances;
}
