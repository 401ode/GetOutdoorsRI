<?php

/**
 * Field instances for mogov_slider entities
 */

$field_instances = array(

  /**
   * These fields are used on all slider types
   */

  // The slider orientation -- horizontal or vertical
  // Attaches to the slider bundles
  'field_mogov_slider_library' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_library',
      'entity_type' => 'mogov_slider',
      'label' => t('Library'),
      'description' => 'Select the library to use for this slider (currently only FlexSlider is supported).',
      'required' => TRUE,
      'default_value' => array(
        0 => array(
          'value' => 'flexslider',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'type' => 'options_select',
        'weight' => 11,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  // The slider orientation -- horizontal or vertical
  // Attaches to the slider bundles
  'field_mogov_slider_orientation' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_orientation',
      'entity_type' => 'mogov_slider',
      'label' => t('Orientation'),
      'description' => 'Select whether the slides should be oriented horizontally or vertically.',
      'required' => TRUE,
      'default_value' => array(
        0 => array(
          'value' => 'horizontal',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'type' => 'options_select',
        'weight' => 12,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  // Start slider on page load?
  // Attaches to the slider bundles
  'field_mogov_slider_autoplay' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_autoplay',
      'entity_type' => 'mogov_slider',
      'label' => t('Autoplay'),
      'description' => 'Start the slider on page load.',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 13,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  // Delay between slides
  // Attaches to the slider bundles
  'field_mogov_slider_autoplay_ms' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_autoplay_ms',
      'entity_type' => 'mogov_slider',
      'label' => t('Delay between slides'),
      'description' => '',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 7000,
        ),
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 14,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  // Create block?
  // Attaches to the slider bundles
  'field_mogov_slider_create_block' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_create_block',
      'entity_type' => 'mogov_slider',
      'label' => t('Create block'),
      'description' => 'All sliders are available in a content pane for placement in panels. Usually, this is sufficient, but if a block is needed, this option will generate one for this slider..',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => -1,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  /**
   * These fields are used on sliders that use the FlexSlider library
   */

  // Options (flexslider)
  // Attaches to the slider bundles
  'field_mogov_slider_flex_options' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_flex_options',
      'entity_type' => 'mogov_slider',
      'label' => t('Options'),
      'description' => '',
      'required' => TRUE,
      'default_value' => NULL,
      'widget' => array(
        'module' => 'field_collection',
        'type' => 'field_collection_embed',
        'weight' => 31,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
      'mogov_slider_titles',
    ),
  ),

  // ANIMATION OPTIONS
  
  // Animation
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_flex_animat' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_flex_animat',
      'entity_type' => 'field_collection_item',
      'label' => t('Animation'),
      'required' => TRUE,
      'default_value' => array(
        0 => array(
          'value' => 'slide',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'type' => 'options_select',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Transition speed
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_flex_transspd' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_flex_transspd',
      'entity_type' => 'field_collection_item',
      'label' => t('Transition speed'),
      'description' => '',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 600,
        ),
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 2,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Loop animation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_loop_animat' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_loop_animat',
      'entity_type' => 'field_collection_item',
      'label' => t('Loop animation'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 3,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Reverse animation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_reverse' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_reverse',
      'entity_type' => 'field_collection_item',
      'label' => t('Reverse animation'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 4,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Smooth neight?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_smooth_height' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_smooth_height',
      'entity_type' => 'field_collection_item',
      'label' => t('Smooth height'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 5,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // CONTROLS OPTIONS

  // Pause/play button?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_play' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_pause_play',
      'entity_type' => 'field_collection_item',
      'label' => t('Pause/play button'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Touch support?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_touch' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_touch',
      'entity_type' => 'field_collection_item',
      'label' => t('Allow touch swipe navigation of the slider on enabled devices'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 2,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Side nav controls?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_slide_nav' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_slide_nav',
      'entity_type' => 'field_collection_item',
      'label' => t('Create navigation for paging control of each slide'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 3,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Previous/Next navigation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_dir_nav' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_dir_nav',
      'entity_type' => 'field_collection_item',
      'label' => t('Create previous/next arrow navigation'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 4,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Pause when interacting with control elements?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_action' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_pause_action',
      'entity_type' => 'field_collection_item',
      'label' => t('Pause the slider when interacting with control elements'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 5,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Pause when hovering over the slider?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_hover' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_pause_hover',
      'entity_type' => 'field_collection_item',
      'label' => t('Pause the slider when hovering over it, then resume when no longer hovering'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 6,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // MISCELLANEOUS OPTIONS

  // Randomize slide order?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_randomize' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_randomize',
      'entity_type' => 'field_collection_item',
      'label' => t('Randomize slide order on load'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Use CSS3 transitions if available?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_use_css' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_use_css',
      'entity_type' => 'field_collection_item',
      'label' => t('Use CSS3 transitions if available'),
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 2,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // CAROUSEL OPTIONS

  // Width of individual carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_width' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_carsl_width',
      'entity_type' => 'field_collection_item',
      'label' => t('Total width of individual carousel items'),
      'description' => '',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'settings' => array(
        'max' => '',
        'min' => 0,
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Margin between carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_margin' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_carsl_margin',
      'entity_type' => 'field_collection_item',
      'label' => t('Margin between carousel items'),
      'description' => '',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'settings' => array(
        'max' => '',
        'min' => 0,
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Min number of visible carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_min' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_carsl_min',
      'entity_type' => 'field_collection_item',
      'label' => t('Minimum number of visible carousel items'),
      'description' => 'Minimum number of carousel items that should be visible. Items will resize fluidly when below this.',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'settings' => array(
        'max' => '',
        'min' => 0,
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Max number of visible carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_max' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_carsl_max',
      'entity_type' => 'field_collection_item',
      'label' => t('Maximum number of visible carousel items'),
      'description' => '',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'settings' => array(
        'max' => '',
        'min' => 0,
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  // Number of carousel items that move per navigation event
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_move' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_carsl_move',
      'entity_type' => 'field_collection_item',
      'label' => t('Number of carousel items that move'),
      'description' => 'Number of carousel items that should move on animation. If 0, slider will move all visible items.',
      'required' => FALSE,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'settings' => array(
        'max' => '',
        'min' => 0,
      ),
      'widget' => array(
        'module' => 'html5_tools',
        'type' => 'numberfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_flex_options',
    ),
  ),

  /**
   * These fields are used on image sliders
   */

  // Images
  // Attaches to the image slider bundle
  'field_mogov_slider_images' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_images',
      'entity_type' => 'mogov_slider',
      'label' => t('Slides'),
      'description' => '',
      'required' => TRUE,
      'default_value' => NULL,
      'widget' => array(
        'module' => 'field_collection',
        'type' => 'field_collection_embed',
        'weight' => 21,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_images',
    ),
  ),

  // Image
  // Attaches to the image slides field collection item bundle
  'field_mogov_slider_image' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_image',
      'entity_type' => 'field_collection_item',
      'label' => t('Image'),
      'description' => '',
      'required' => FALSE,
      'default_value' => NULL,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'mogov_slider',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
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
        ),
        'type' => 'media_generic',
        'weight' => 0,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_images',
    ),
  ),

  // Caption
  // Attaches to the image slides field collection item bundle
  'field_mogov_slider_caption' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_caption',
      'entity_type' => 'field_collection_item',
      'label' => t('Caption'),
      'description' => '',
      'required' => FALSE,
      'default_value' => NULL,
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_images',
    ),
  ),

  // URL
  // Attaches to the image slides field collection item bundle
  'field_mogov_slider_url' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_url',
      'entity_type' => 'field_collection_item',
      'label' => t('URL'),
      'description' => '',
      'required' => FALSE,
      'default_value' => NULL,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 0,
        'rel_remove' => 'default',
        'title' => 'none',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'html5_tools',
        'settings' => array(),
        'type' => 'urlwidget',
        'weight' => 2,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_images',
    ),
  ),

  /**
   * These fields are used on title sliders
   */

  // Slides
  // Attaches to the title slider bundle
  'field_mogov_slider_titles' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_titles',
      'entity_type' => 'mogov_slider',
      'label' => t('Slides'),
      'description' => '',
      'required' => TRUE,
      'default_value' => NULL,
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
        'module' => 'field_collection',
        'type' => 'field_collection_embed',
        'weight' => 21,
      ),
    ),
    'attach_to' => array(
      'mogov_slider_titles',
    ),
  ),

  // Local content - entity reference.
  // Attaches to the title slides field collection item bundle
  'field_mogov_slider_reference' => array(
    'instance' => array(
      'bundle' => 'field_mogov_slides_titles',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => t('Select a local node to use for the link and title. Note taht if the Link field (below) is also filled out, this field will be ignored.'),
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
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_mogov_slider_reference',
      'label' => 'Local content',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => 60,
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => 1,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_titles',
    ),
  ),

  // Link. Takes precedence over entity reference field above.
  // Attaches to the title slides field collection item bundle
  'field_mogov_slider_link' => array(
    'instance' => array(
      'field_name' => 'field_mogov_slider_link',
      'entity_type' => 'field_collection_item',
      'label' => t('Link'),
      'description' => 'You may enter a URL and title. If the Local Content field is also populated, this field takes precedence.',
      'required' => FALSE,
      'default_value' => NULL,
      'settings' => array(
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
        'title' => 'required',
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
        'weight' => 2,
      ),
    ),
    'attach_to' => array(
      'field_mogov_slider_titles',
    ),
  ),

);
