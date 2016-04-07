<?php

/**
 * Implements hook_block_info().
 */
function mogov_sliders_block_info() {
  module_load_include('inc', 'mogov_sliders', 'includes/data');
  $blocks = array();
  $sliders = mogov_sliders_get_sliders(TRUE); // requests only sliders with "create block" option set
  foreach ($sliders as $block) {
    $blocks['slider_' . $block->id]['info'] = t('Slider: ' . $block->title);
  }
  return $blocks;
}

/**
 * Implements hook_ctools_block_info().
 */
function mogov_sliders_ctools_block_info($module, $delta, &$info) {
  $info['category'] = t('Sliders');
  $info['render last'] = TRUE;
}

/**
 * Implements hook_block_view().
 */
function mogov_sliders_block_view($delta='') {

  $block = array();
  $split = explode('_', $delta);
  $id = end($split);
  $slider = entity_load_single('mogov_slider', $id);

  module_load_include('inc', 'mogov_sliders', 'includes/view');

  $block['title'] = t($slider->title);
  $block['content'] = mogov_sliders_view_slider($slider->id, 'block');

  return $block;
    
}
