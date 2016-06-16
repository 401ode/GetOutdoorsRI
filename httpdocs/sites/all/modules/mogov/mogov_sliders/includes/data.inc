<?php

/**
 * Takes a field collection and returns an array of all its items
 */
function mogov_sliders_get_slides_data($slides_field) {
  $fc_items = array();
  foreach ($slides_field as $field_item) {
    $fc_items[] = $field_item['value'];
  }
  $slides_data = entity_load('field_collection_item', $fc_items);
  return $slides_data;
}

/**
 * Gets sliders
 */
function mogov_sliders_get_sliders($block_option=FALSE) {
  $sliders = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'mogov_slider');
  $query->entityCondition('bundle', array('mogov_slider_titles', 'mogov_slider_images'));
  if ($block_option) {
    $query->fieldCondition('field_mogov_slider_create_block', 'value', 1);
  }
  $result = $query->execute();
  if (isset($result['mogov_slider'])) {
    $ids = array_keys($result['mogov_slider']);
    $sliders = entity_load('mogov_slider', $ids);
  }
  return $sliders;
}
