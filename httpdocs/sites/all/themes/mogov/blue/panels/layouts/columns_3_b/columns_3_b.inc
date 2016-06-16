<?php

/**
 * @file
 * Defines the "3 Cols B" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('3 Cols B'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_3_b',
  'css' => '../../../css/panels/layouts/columns_3_b/columns-3-b.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (1/4)'),
    'column_2' => t('Column 2 (1/2)'),
    'column_3' => t('Column 3 (1/4)'),
  ),
);

/**
 * Implements hook_preprocess_columns_3_b().
 */
function template_preprocess_columns_3_b(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-3-b';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-3-b-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-3-b-region--' . drupal_clean_css_identifier($name);
  }
}
