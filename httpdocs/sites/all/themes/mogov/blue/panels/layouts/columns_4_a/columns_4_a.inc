<?php

/**
 * @file
 * Defines the "4 Cols A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('4 Cols A'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_4_a',
  'css' => '../../../css/panels/layouts/columns_4_a/columns-4-a.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (1/4)'),
    'column_2' => t('Column 2 (1/4)'),
    'column_3' => t('Column 3 (1/4)'),
    'column_4' => t('Column 4 (1/4)'),
  ),
);

/**
 * Implements hook_preprocess_columns_4_a().
 */
function template_preprocess_columns_4_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-4-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-4-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-4-a-region--' . drupal_clean_css_identifier($name);
  }
}
