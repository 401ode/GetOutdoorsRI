<?php

/**
 * @file
 * Defines the "5 Panes A" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('5 Panes A'),
  'category' => t('Blue Layouts: 5 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_5_a',
  'css' => '../../../css/panels/layouts/panes_5_a/panes-5-a.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Bottom Left (1/3)'),
    'row2_col2' => t('Bottom Center (1/3)'),
    'row2_col3' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_landing_page_2().
 */
function template_preprocess_panes_5_a(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-5-a';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-a-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-a-region--' . drupal_clean_css_identifier($name);
  }
}
