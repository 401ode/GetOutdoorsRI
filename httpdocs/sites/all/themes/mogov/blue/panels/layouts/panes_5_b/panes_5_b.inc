<?php

/**
 * @file
 * Defines the "5 Panes B" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('5 Panes B'),
  'category' => t('Blue Layouts: 5 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_5_b',
  'css' => '../../../css/panels/layouts/panes_5_b/panes-5-b.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (1/3)'),
    'row1_col2' => t('Top Center (1/3)'),
    'row1_col3' => t('Top Right (1/3)'),
    'row2_col1' => t('Bottom Left (2/3)'),
    'row2_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_landing_page_3().
 */
function template_preprocess_panes_5_b(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-5-b';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-b-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-b-region--' . drupal_clean_css_identifier($name);
  }
}
