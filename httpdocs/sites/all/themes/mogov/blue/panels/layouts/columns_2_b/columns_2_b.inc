<?php

/**
 * @file
 * Defines the "2 Cols B" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('2 Cols B'),
  'category' => t('Blue Layouts: Columns'),
  'icon' => 'preview.png',
  'theme' => 'columns_2_b',
  'css' => '../../../css/panels/layouts/columns_2_b/columns-2-b.layout.css',
  'regions' => array(
    'column_1' => t('Column 1 (2/3)'),
    'column_2' => t('Column 2 (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_columns_2_b().
 */
function template_preprocess_columns_2_b(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--columns-2-b';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'columns-2-b-region';
    $variables['region_attributes_array'][$name]['class'][] = 'columns-2-b-region--' . drupal_clean_css_identifier($name);
  }
}
