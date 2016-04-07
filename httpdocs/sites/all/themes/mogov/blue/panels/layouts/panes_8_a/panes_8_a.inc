<?php

/**
 * @file
 * Defines the "8 Panes A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('8 Panes A'),
  'category' => t('Blue Layouts: 8 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_8_a',
  'css' => '../../../css/panels/layouts/panes_8_a/panes-8-a.layout.css',
  'regions' => array(
    'row1' => t('Row 1'),
    'row2_col1' => t('Row 2 Left'),
    'row2_col2' => t('Row 2 Middle'),
    'row2_col3' => t('Row 2 Right'),
    'row3' => t('Row 3'),
    'row4_col1' => t('Row 4 Left (2/3)'),
    'row4_col2' => t('Row 4 Right (1/3)'),
    'row5' => t('Row 5'),
  ),
);

/**
 * Implements hook_preprocess_panes_8_a().
 */
function template_preprocess_panes_8_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-8-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-8-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-8-a-region--' . drupal_clean_css_identifier($name);
  }
}
