<?php
/**
 * @file
 * campus_challenge.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campus_challenge_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "data" && $api == "data_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function campus_challenge_image_default_styles() {
  $styles = array();

  // Exported image style: campus_logo.
  $styles['campus_logo'] = array(
    'name' => 'campus_logo',
    'label' => 'Campus Logo (125x75)',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '125',
          'height' => '75',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function campus_challenge_node_info() {
  $items = array(
    'campus' => array(
      'name' => t('Campus'),
      'base' => 'node_content',
      'description' => t('Higher Education institutions participating in the Campus Challenge'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
