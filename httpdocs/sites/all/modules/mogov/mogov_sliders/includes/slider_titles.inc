<?php

/**
 * Builds slides for title slider nodes.
 * Input: field_mogov_slides_titles array
 * Output: Render array for slides
 */
function mogov_sliders_titles_build_slides($slider, $slides_data, $mode) {
  $slider_id = 'mogov-slider-' . $slider->id;
  if ($mode != 'entity') {
    $slider_id .= '-' . drupal_clean_css_identifier($mode);
  }
  $slides = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $slider_id,
      'class' => array(
        'flexslider',
        'mogov-slider-content',
        'title-slider',
      ),
    ),
    'slides' => array(
      '#type' => 'markup',
    ),
  );
  $titles = array(
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
    $field = field_get_items('field_collection_item', $slide_data, 'field_mogov_slider_link');
    if (!empty($field[0]['url']) and !empty($field[0]['title'])) {
      $link_options = array(
        'html' => TRUE,
        'external' => TRUE,
      );
      if (!empty($field[0]['attributes'])) {
        $link_options['attributes'] = $field[0]['attributes'];
      }
      $titles['items'][] = l($field[0]['title'], $field[0]['url'], $link_options);
    } else {
      $field = field_get_items('field_collection_item', $slide_data, 'field_mogov_slider_reference');
      if (!empty($field[0]['target_id'])) {
        if (empty($field[0]['entity'])) {
          $field[0]['entity'] = node_load($field[0]['target_id']);
        }
        $titles['items'][] = l($field[0]['entity']->title, 'node/' . $field[0]['target_id']);
      }
    }
  }
  $slides['slides']['#markup'] = theme_item_list($titles);
  return $slides;
}
