<?php

/**
 * @file
 * Defines the "3 Cols A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('3 Cols A'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_3_a',
  'css' => '../../../css/panels/layouts/columns_3_a/columns-3-a.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (1/3)'),
    'column_2' => t('Column 2 (1/3)'),
    'column_3' => t('Column 3 (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_columns_3_a().
 */
function template_preprocess_columns_3_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-3-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-3-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-3-a-region--' . drupal_clean_css_identifier($name);
  }
}
