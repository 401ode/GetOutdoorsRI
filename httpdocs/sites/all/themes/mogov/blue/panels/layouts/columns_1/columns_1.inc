<?php

/**
 * @file
 * Defines the "1 Column" layout.
 */

$theme_path = drupal_get_path('theme', 'blue');

// Plugin definition.
$plugin = array(
  'title' => t('1 Col'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_1',
  'css' => $theme_path . '/css/panels/layouts/columns_1/columns-1.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (full width)'),
  ),
);

/**
 * Implements hook_preprocess_columns_1().
 */
function template_preprocess_columns_1(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-1';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-1-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-1-region--' . drupal_clean_css_identifier($name);
  }
}
