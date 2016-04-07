<?php

/**
 * Field groups for mogov_slider and associated field_collection_item entities
 */

$field_groups = array(

  // Field groups for the flex options field collection
  
  // Animation group
  array(
    'group_name' => 'group_slider_animation',
    'label' => 'Animation',
    'identifier' => 'group_slider_animation|field_collection_item|field_mogov_slider_flex_options|form',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_mogov_slider_flex_options',
    'parent_name' => '',
    'weight' => '0',
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_flex_animat',
      1 => 'field_mogov_slider_flex_transspd',
      2 => 'field_mogov_slider_loop_animat',
      3 => 'field_mogov_slider_reverse',
      4 => 'field_mogov_slider_smooth_height',
    ),
  ),
  
  // Controls group
  array(
    'group_name' => 'group_slider_controls',
    'label' => 'Controls',
    'identifier' => 'group_slider_controls|field_collection_item|field_mogov_slider_flex_options|form',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_mogov_slider_flex_options',
    'parent_name' => '',
    'weight' => '10',
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
    ),
    'children' => array(
      0 => 'field_mogov_slider_pause_play',
      1 => 'field_mogov_slider_touch',
      2 => 'field_mogov_slider_slide_nav',
      3 => 'field_mogov_slider_dir_nav',
      4 => 'field_mogov_slider_pause_action',
      5 => 'field_mogov_slider_pause_hover',
    ),
  ),
  
  // Miscellaneous group
  array(
    'group_name' => 'group_slider_misc',
    'label' => 'Miscellaneous Options',
    'identifier' => 'group_slider_misc|field_collection_item|field_mogov_slider_flex_options|form',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_mogov_slider_flex_options',
    'parent_name' => '',
    'weight' => '20',
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
    ),
    'children' => array(
      0 => 'field_mogov_slider_randomize',
      1 => 'field_mogov_slider_use_css',
    ),
  ),
  
  // Carousel group
  array(
    'group_name' => 'group_slider_carousel',
    'label' => 'Carousel Options',
    'identifier' => 'group_slider_carousel|field_collection_item|field_mogov_slider_flex_options|form',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_mogov_slider_flex_options',
    'parent_name' => '',
    'weight' => '30',
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
    ),
    'children' => array(
      0 => 'field_mogov_slider_carsl_width',
      1 => 'field_mogov_slider_carsl_margin',
      2 => 'field_mogov_slider_carsl_min',
      3 => 'field_mogov_slider_carsl_max',
      4 => 'field_mogov_slider_carsl_move',
    ),
  ),

  // Field groups for the image slider entity
  
  // Slider group
  array(
    'group_name' => 'group_tab_main',
    'label' => 'Slider',
    'identifier' => 'group_tab_main|mogov_slider|mogov_slider_images|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_images',
    'parent_name' => 'group_tabs_main',
    'weight' => '1',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_library',
      1 => 'field_mogov_slider_orientation',
      2 => 'field_mogov_slider_autoplay',
      3 => 'field_mogov_slider_autoplay_ms',
      4 => 'field_mogov_additional_classes',
    ),
  ),
  
  // Slides group
  array(
    'group_name' => 'group_tab_slides',
    'label' => 'Slides',
    'identifier' => 'group_tab_slides|mogov_slider|mogov_slider_images|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_images',
    'parent_name' => 'group_tabs_main',
    'weight' => '2',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_images',
    ),
  ),
  
  // Configuration group
  array(
    'group_name' => 'group_tab_config',
    'label' => 'Configuration',
    'identifier' => 'group_tab_config|mogov_slider|mogov_slider_images|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_images',
    'parent_name' => 'group_tabs_main',
    'weight' => '3',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_create_block',
      1 => 'field_mogov_slider_flex_options',
    ),
  ),
  
  // Enclosing tab set
  array(
    'group_name' => 'group_tabs_main',
    'label' => 'Main Tabs',
    'identifier' => 'group_tabs_main|mogov_slider|mogov_slider_images|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_images',
    'parent_name' => '',
    'weight' => '0',
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_slides',
      2 => 'group_tab_config',
    ),
  ),

  // Field groups for the title slider entity
  
  // Slider group
  array(
    'group_name' => 'group_tab_main',
    'label' => 'Slider',
    'identifier' => 'group_tab_main|mogov_slider|mogov_slider_titles|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_titles',
    'parent_name' => 'group_tabs_main',
    'weight' => '1',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_library',
      1 => 'field_mogov_slider_orientation',
      2 => 'field_mogov_slider_autoplay',
      3 => 'field_mogov_slider_autoplay_ms',
      4 => 'field_mogov_additional_classes',
    ),
  ),
  
  // Slides group
  array(
    'group_name' => 'group_tab_slides',
    'label' => 'Slides',
    'identifier' => 'group_tab_slides|mogov_slider|mogov_slider_titles|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_titles',
    'parent_name' => 'group_tabs_main',
    'weight' => '2',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_titles',
    ),
  ),
  
  // Configuration group
  array(
    'group_name' => 'group_tab_config',
    'label' => 'Configuration',
    'identifier' => 'group_tab_config|mogov_slider|mogov_slider_titles|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_titles',
    'parent_name' => 'group_tabs_main',
    'weight' => '3',
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'field_mogov_slider_flex_options',
    ),
  ),
  
  // Enclosing tab set
  array(
    'group_name' => 'group_tabs_main',
    'label' => 'Main Tabs',
    'identifier' => 'group_tabs_main|mogov_slider|mogov_slider_titles|form',
    'entity_type' => 'mogov_slider',
    'bundle' => 'mogov_slider_titles',
    'parent_name' => '',
    'weight' => '0',
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
      ),
    ),
    'children' => array(
      0 => 'group_tab_main',
      1 => 'group_tab_slides',
      2 => 'group_tab_config',
    ),
  ),

);
