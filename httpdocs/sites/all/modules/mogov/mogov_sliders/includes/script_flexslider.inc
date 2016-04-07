<?php

/**
 * FlexSlider version of the javascript
 */
function mogov_sliders_add_flexslider_script($slider, $mode) {
  
  $slider_id = '#mogov-slider-' . $slider->id;
  if ($mode != 'entity') {
    $slider_id .= '-' . drupal_clean_css_identifier($mode);
  }
  $options = array();
  
  // Basic config fields from $slider
  $field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_orientation');
  if (!empty($field[0]['value'])) {
    $options['direction'] = '"' . $field[0]['value'] . '"';
  }
  $field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_autoplay');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['slideshow'] = 'true';
    $field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_autoplay_ms');
    if (!empty($field[0]['value'])) {
      $options['slideshowSpeed'] = $field[0]['value'];
    }
  } else {
    $options['slideshow'] = 'false';
  }
  
  // Library-specific configuration options from the field collection item
  $options_field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_flex_options');
  $options_fc_items = entity_load('field_collection_item', array($options_field[0]['value']));
  $options_data = $options_fc_items[$options_field[0]['value']];

  // Animation options
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_flex_animat');
  if (!empty($field[0]['value'])) {
    $options['animation'] = '"' . $field[0]['value'] . '"';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_trans_speed');
  if (!empty($field[0]['value'])) {
    $options['animationSpeed'] = $field[0]['value'];
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_loop_animat');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['animationLoop'] = 'true';
  } else {
    $options['animationLoop'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_reverse');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['reverse'] = 'true';
  } else {
    $options['reverse'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_smooth_ht');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['smoothHeight'] = 'true';
  } else {
    $options['smoothHeight'] = 'false';
  }
  
  // Control options
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_pause_play');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['pausePlay'] = 'true';
  } else {
    $options['pausePlay'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_touch');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['touch'] = 'true';
  } else {
    $options['touch'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_slide_nav');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['controlNav'] = 'true';
  } else {
    $options['controlNav'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_dir_nav');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['directionNav'] = 'true';
  } else {
    $options['directionNav'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_pause_action');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['pauseOnAction'] = 'true';
  } else {
    $options['pauseOnAction'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_pause_hover');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['pauseOnHover'] = 'true';
  } else {
    $options['pauseOnHover'] = 'false';
  }
  
  // Misc options
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_randomize');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['randomize'] = 'true';
  } else {
    $options['randomize'] = 'false';
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_use_css');
  if (!empty($field[0]['value']) and $field[0]['value']) {
    $options['useCSS'] = 'true';
  } else {
    $options['useCSS'] = 'false';
  }
  
//********************************************************* 
  // Carousel Options  
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_width');
  if (!empty($field[0]['value'])) {
    $options['itemWidth'] = $field[0]['value'];
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_mrgin');
  if (!empty($field[0]['value'])) {
    $options['itemMargin'] = $field[0]['value'];
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_min');
  if (!empty($field[0]['value'])) {
    $options['minItems'] = $field[0]['value'];
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_max');
  if (!empty($field[0]['value'])) {
    $options['maxItems'] = $field[0]['value'];
  }
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_move');
  if (!empty($field[0]['value'])) {
    $options['move'] = $field[0]['value'];
  }
  
  $script  = 'jQuery(document).ready(function($) {' . "\n";
  $script .= '  $("' . $slider_id . '").flexslider({' . "\n";
  $i = 0;
  foreach ($options as $option=>$value) {
    mogov_sliders_add_cr($script, $i);
    $script .= '    ' . $option . ': ' . $value;
  }
  $script .= "\n  });\n";
  $script .= "});\n";
    
  drupal_add_js($script, array('type' => 'inline', 'scope' => 'footer'));
}
