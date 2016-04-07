<?php

/**
 * Add necessary support files, then hand off to appropriate script builder
 */
function mogov_sliders_add_support($slider, $mode) {
  global $module_path;
  $library_field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_library');
  switch($library_field[0]['value']) {
    case 'flexslider':
      libraries_load('flexslider');
      drupal_add_css($module_path . '/css/mogov_sliders.css');
      module_load_include('inc', 'mogov_sliders', 'includes/script_flexslider');
      mogov_sliders_add_flexslider_script($slider, $mode);
      break;
    default:
      return FALSE;
  }
}

/**
 * Build the slider script
 */
function mogov_sliders_add_cr(&$script, &$i) {
  if ($i > 0) {
    $script .= ",\n";
  } else {
    $i++;
  }  
}
