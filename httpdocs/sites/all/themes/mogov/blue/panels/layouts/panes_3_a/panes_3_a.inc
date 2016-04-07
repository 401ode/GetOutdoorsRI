<?php

/**
 * @file
 * Defines the "3 Panes A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('3 Panes A'),
  'category' => t('Blue Layouts: 3 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_3_a',
  'css' => '../../../css/panels/layouts/panes_3_a/panes-3-a.layout.css',
  'regions' => array(
    'row1_col1' => t('Top (full width)'),
    'row2_col1' => t('Bottom Left (2/3)'),
    'row2_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_panes_3_a().
 */
function template_preprocess_panes_3_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-3-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-3-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-3-a-region--' . drupal_clean_css_identifier($name);
  }
}
