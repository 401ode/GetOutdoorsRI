<?php

/**
 * @file
 * Defines the "4 Panes A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('4 Panes A'),
  'category' => t('Blue Layouts: 4 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_4_a',
  'css' => '../../../css/panels/layouts/panes_4_a/panes-4-a.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Bottom Left (2/3)'),
    'row2_col2' => t('Bottom Left (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_landing_page_1().
 */
function template_preprocess_panes_4_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-4-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-4-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-4-a-region--' . drupal_clean_css_identifier($name);
  }
}
