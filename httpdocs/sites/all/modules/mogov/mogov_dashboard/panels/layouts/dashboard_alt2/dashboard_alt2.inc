<?php

/**
 * @file
 * Defines the "Dashboard Alt 2" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Dashboard Alt 2'),
  'category' => t('Dashboard'),
  'icon' => 'preview.png',
  'theme' => 'dashboard_alt2',
  'css' => 'dashboard_alt2.css',
  'regions' => array(
    'col1' => t('Left (1/3)'),
    'col2_row1_col1' => t('Top Center (1/3)'),
    'col2_row1_col2' => t('Top Right (1/3)'),
    'col2_row2_col1' => t('Middle Center (1/3)'),
    'col2_row2_col2' => t('Middle Right (1/3)'),
    'col2_row3_col1' => t('Bottom Center (1/3)'),
    'col2_row3_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_dashboard_alt2().
 */
function template_preprocess_dashboard_alt2(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--dashboard-alt2';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-alt2-region';
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-alt2-region--' . drupal_clean_css_identifier($name);
  }
}
