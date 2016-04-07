<?php

/**
 * @file
 * Defines the "5 Panes D" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('5 Panes D'),
  'category' => t('Blue Layouts: 5 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_5_d',
  'css' => '../../../css/panels/layouts/panes_5_d/panes-5-d.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Middle Left (1/2)'),
    'row2_col2' => t('Middle Right (1/2)'),
    'row3_col1' => t('Bottom'),
  ),
);

/**
 * Implements hook_preprocess_layout().
 */
function template_preprocess_panes_5_d(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-5-d';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-d-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-d-region--' . drupal_clean_css_identifier($name);
  }
}
