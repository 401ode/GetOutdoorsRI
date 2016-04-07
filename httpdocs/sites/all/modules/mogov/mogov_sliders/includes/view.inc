<?php

/**
 * View an individual slider directly.
 */
function mogov_sliders_view_slider($id, $mode='entity') {

  // Try to load the entity
  $slider = entity_load_single('mogov_slider', $id);
  if (!$slider) {
    return FALSE;
  }

  // We have the entity. Build the slider output.
  module_load_include('inc', 'mogov_sliders', 'includes/data');
  switch($slider->bundle) {
    case 'mogov_slider_images':
      module_load_include('inc', 'mogov_sliders', 'includes/slider_images');
      $slides_field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_images');
      $slides_data = mogov_sliders_get_slides_data($slides_field);
      $slides = mogov_sliders_images_build_slides($slider, $slides_data, $mode);
      break;
    case 'mogov_slider_titles':
      module_load_include('inc', 'mogov_sliders', 'includes/slider_titles');
      $slides_field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_titles');
      $slides_data = mogov_sliders_get_slides_data($slides_field);
      $build = mogov_sliders_titles_build_slides($slider, $slides_data, $mode);
      $slides = drupal_render($build);
      break;
  }
  if (!isset($slides) or !$slides) {
    return FALSE;
  }
  
  // These functions support the construction of the javascript
  module_load_include('inc', 'mogov_sliders', 'includes/script_support');
  mogov_sliders_add_support($slider, $mode);

  // Return output
  drupal_set_title($slider->title);
  return $slides;
  
}
