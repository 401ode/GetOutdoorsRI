<?php

/**
 * Builds slides for image sliders.
 * Input: field_mogov_slides_images array
 * Output: Render array for slides
 */
function mogov_sliders_images_build_slides($slider, $slides_data, $mode) {

  // Prepend module classes
  // Is slider a carousel-style slider or regular image slider?
  $class_array = array();
  $options_field = field_get_items('mogov_slider', $slider, 'field_mogov_slider_flex_options');
  $options_fc_items = entity_load('field_collection_item', array($options_field[0]['value']));
  $options_data = $options_fc_items[$options_field[0]['value']];
  $field = field_get_items('field_collection_item', $options_data, 'field_mogov_slider_carsl_width');
  if (!empty($field[0]['value'])) {
    array_unshift($class_array, 'carousel-slider');
  } else {
    array_unshift($class_array, 'image-slider');  
  }
  
  array_unshift($class_array, 'flexslider', 'mogov-slider-content');
  
  $slider_id = 'mogov-slider-' . $slider->id;
  if ($mode != 'entity') {
    $slider_id .= '-' . drupal_clean_css_identifier($mode);
  }
  $slides = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $slider_id,
      'class' => $class_array,
    ),
  );
  $slides_list = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'class' => array(
        'slides',
      ),
    ),
    'items' => array(),
  );
  foreach ($slides_data as $slide_data) {
    $field = field_get_items('field_collection_item', $slide_data, 'field_mogov_slider_image');
    if (empty($field[0]['uri'])) {
      continue;
    }
    $image_options = array(
      'path' => $field[0]['uri'],
      'width' => $field[0]['width'],
      'height' => $field[0]['height'],
      'alt' => $field[0]['alt'],
      'title' => $field[0]['title'],
      'attributes' => array(),
    );
    $slide = theme_image($image_options);
    $field = field_get_items('field_collection_item', $slide_data, 'field_mogov_slider_caption');
    if (!empty($field[0]['value'])) {
      $slide = array(
        0 => array(
          '#type' => 'markup',
          '#markup' => $slide,
        ),
        1 => array(
          '#type' => 'markup',
          '#prefix' => '<span class="mogov-slider-caption">',
          '#markup' => t($field[0]['value']),
          '#suffix' => '</span>',
        ),
      );
    }
    $slide = render($slide);
    $link_field = field_get_items('field_collection_item', $slide_data, 'field_mogov_slider_url');
    if (!empty($link_field[0]['url'])) {
      $slide = l($slide, $link_field[0]['url'], array('html' => TRUE, 'external' => TRUE));
    }
    $slides_list['items'][] = array(
      'class' => array(
        'slide',
      ),
      'style' => 'display: none;',
      'data' => $slide,
    );
  }
  $slides['slides'] = array(
    '#markup' => theme_item_list($slides_list),
  );
  return render($slides);
}
