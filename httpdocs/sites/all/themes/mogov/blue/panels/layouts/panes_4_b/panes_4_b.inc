<?php

/**
 * @file
 * Defines the "4 Panes B" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('4 Panes B'),
  'category' => t('Blue Layouts: 4 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_4_b',
  'css' => '../../../css/panels/layouts/panes_4_b/panes-4-b.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Bottom Left (1/2)'),
    'row2_col2' => t('Bottom Left (1/2)'),
  ),
);

/**
 * Implements hook_preprocess_layout().
 */
function template_preprocess_panes_4_b(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-4-b';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-4-b-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-4-b-region--' . drupal_clean_css_identifier($name);
  }
}
