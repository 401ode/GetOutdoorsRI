<?php

/**
 * Field bases for mogov_slider entities
 */

$field_bases = array(

  /**
   * These fields are used on all slider types
   */

  // The slider orientation -- horizontal or vertical
  // Attaches to the slider bundles
  'field_mogov_slider_library' => array(
    'field_name' => 'field_mogov_slider_library',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'flexslider' => 'FlexSlider',
      ),
    ),
    'type' => 'list_text',
  ),

  // The slider orientation -- horizontal or vertical
  // Attaches to the slider bundles
  'field_mogov_slider_orientation' => array(
    'field_name' => 'field_mogov_slider_orientation',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'horizontal' => 'Horizontal',
        'vertical' => 'Vertical',
      ),
    ),
    'type' => 'list_text',
  ),

  // Start slider on page load?
  // Attaches to the slider bundles
  'field_mogov_slider_autoplay' => array(
    'field_name' => 'field_mogov_slider_autoplay',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Delay between slides
  // Attaches to the slider bundles
  'field_mogov_slider_autoplay_ms' => array(
    'field_name' => 'field_mogov_slider_autoplay_ms',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Create block?
  // Attaches to the slider bundles
  'field_mogov_slider_create_block' => array(
    'field_name' => 'field_mogov_slider_create_block',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  /**
   * These fields are used on sliders that use the FlexSlider library
   */

  // ANIMATION OPTIONS

  // Options (flexslider)
  // Attaches to the slider bundles
  'field_mogov_slider_flex_options' => array(
    'field_name' => 'field_mogov_slider_flex_options',
    'cardinality' => '1',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
  ),

  // Animation
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_flex_animat' => array(
    'field_name' => 'field_mogov_slider_flex_animat',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'fade' => 'Fade',
        'slide' => 'Slide',
      ),
    ),
    'type' => 'list_text',
  ),  

  // Transition speed
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_flex_transspd' => array(
    'field_name' => 'field_mogov_slider_flex_transspd',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Loop animation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_loop_animat' => array(
    'field_name' => 'field_mogov_slider_loop_animat',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Reverse animation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_reverse' => array(
    'field_name' => 'field_mogov_slider_reverse',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Smooth neight?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_smooth_height' => array(
    'field_name' => 'field_mogov_slider_smooth_height',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // CONTROLS OPTIONS

  // Pause/play button?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_play' => array(
    'field_name' => 'field_mogov_slider_pause_play',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Touch support?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_touch' => array(
    'field_name' => 'field_mogov_slider_touch',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Side nav controls?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_slide_nav' => array(
    'field_name' => 'field_mogov_slider_slide_nav',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Previous/Next navigation?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_dir_nav' => array(
    'field_name' => 'field_mogov_slider_dir_nav',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Pause when interacting with control elements?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_action' => array(
    'field_name' => 'field_mogov_slider_pause_action',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Pause when hovering over the slider?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_pause_hover' => array(
    'field_name' => 'field_mogov_slider_pause_hover',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // MISCELLANEOUS OPTIONS

  // Randomize slide order?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_randomize' => array(
    'field_name' => 'field_mogov_slider_randomize',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // Use CSS3 transitions if available?
  // Attaches to the flexslider options field collection item bundle
  'field_mogov_slider_use_css' => array(
    'field_name' => 'field_mogov_slider_use_css',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
    ),
    'type' => 'list_boolean',
  ),

  // CAROUSEL OPTIONS

  // Width of individual carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_width' => array(
    'field_name' => 'field_mogov_slider_carsl_width',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Margin between carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_margin' => array(
    'field_name' => 'field_mogov_slider_carsl_margin',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Min number of visible carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_min' => array(
    'field_name' => 'field_mogov_slider_carsl_min',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Max number of visible carousel items
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_max' => array(
    'field_name' => 'field_mogov_slider_carsl_max',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  // Number of carousel items that move per navigation event
  // Attaches to the slider bundles
  'field_mogov_slider_carsl_move' => array(
    'field_name' => 'field_mogov_slider_carsl_move',
    'cardinality' => '1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'number',
    'type' => 'number_integer',
  ),

  /**
   * These fields are used on image sliders
   */

  // Images
  // Attaches to the image slider bundle
  'field_mogov_slider_images' => array(
    'field_name' => 'field_mogov_slider_images',
    'cardinality' => '-1',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
  ),

  // Image
  // Attaches to the field_mogov_slider_images bundle
  'field_mogov_slider_image' => array(
    'field_name' => 'field_mogov_slider_image',
    'cardinality' => 1,
    'entity_types' => array(
      'field_collection_item',
    ),
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
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'type' => 'image',
  ),

  // Caption
  // Attaches to the field_mogov_slider_images bundle
  'field_mogov_slider_caption' => array(
    'cardinality' => 1,
    'entity_types' => array(
      'field_collection_item',
    ),
    'field_name' => 'field_mogov_slider_caption',
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
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'type' => 'text',
  ),
  
  // URL
  // Attaches to the field_mogov_slider_images bundle
  'field_mogov_slider_url' => array(
    'cardinality' => 1,
    'entity_types' => array(
      'field_collection_item',
    ),
    'field_name' => 'field_mogov_slider_url',
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => 'optional',
      'title_maxlength' => 128,
    ),
    'type' => 'link_field',
  ),

  /**
   * These fields are used on title sliders
   */

  // Titles
  // Attaches to the title slider bundle
  'field_mogov_slider_titles' => array(
    'field_name' => 'field_mogov_slider_titles',
    'cardinality' => '-1',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'type' => 'field_collection',
  ),

  // Node reference
  // Attaches to the field_mogov_slider_titles bundle
  'field_mogov_slider_reference' => array(
    'field_name' => 'field_mogov_slider_reference',
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_mogov_slider_reference',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
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
          'article' => 'article',
          'mogov_page' => 'mogov_page',
          'mogov_page_panelized' => 'mogov_page_panelized',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  ),

  // Link
  // Attaches to the field_mogov_slider_titles bundle
  'field_mogov_slider_link' => array(
    'cardinality' => 1,
    'entity_types' => array(
      'field_collection_item',
    ),
    'field_name' => 'field_mogov_slider_link',
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => 'optional',
      'title_maxlength' => 128,
    ),
    'type' => 'link_field',
  ),

);
