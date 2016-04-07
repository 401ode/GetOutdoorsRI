<?php

/**
 * @file
 * Defines the "2 Cols A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('2 Cols A'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_2_a',
  'css' => '../../../css/panels/layouts/columns_2_a/columns-2-a.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (1/2)'),
    'column_2' => t('Column 2 (1/2)'),
  ),
);

/**
 * Implements hook_preprocess_columns_2_a().
 */
function template_preprocess_columns_2_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-2-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-2-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-2-a-region--' . drupal_clean_css_identifier($name);
  }
}
