<?php

/**
 * @file
 * Defines the "5 Panes C" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('5 Panes C'),
  'category' => t('Blue Layouts: 5 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_5_c',
  'css' => '../../../css/panels/layouts/panes_5_c/panes-5-c.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Middle'),
    'row3_col1' => t('Bottom Left (2/3)'),
    'row3_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_layout().
 */
function template_preprocess_panes_5_c(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-5-c';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-c-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-5-c-region--' . drupal_clean_css_identifier($name);
  }
}
