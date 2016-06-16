<?php

/**
 * @file
 * Defines the "3 Panes B" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('3 Panes B'),
  'category' => t('Blue Layouts: 3 Panes'),
  'icon' => 'preview.png',
  'theme' => 'panes_3_b',
  'css' => '../../../css/panels/layouts/panes_3_b/panes-3-b.layout.css',
  'regions' => array(
    'row1_col1' => t('Top Left (2/3)'),
    'row1_col2' => t('Top Right (1/3)'),
    'row2_col1' => t('Bottom (full width)'),
  ),
);

/**
 * Implements hook_preprocess_panes_3_b().
 */
function template_preprocess_panes_3_b(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--panes-3-b';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'panes-3-b-region';
    $variables['region_attributes_array'][$name]['class'][] = 'panes-3-b-region--' . drupal_clean_css_identifier($name);
  }
}
