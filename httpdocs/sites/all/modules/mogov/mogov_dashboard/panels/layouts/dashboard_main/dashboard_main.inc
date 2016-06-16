<?php

/**
 * @file
 * Defines the "Main Dashboard" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Main Dashboard'),
  'category' => t('Dashboard'),
  'icon' => 'preview.png',
  'theme' => 'dashboard_main',
  'css' => 'dashboard_main.css',
  'regions' => array(
    'col1' => t('Left (1/3)'),
    'col2_row1_col1' => t('Top (2/3)'),
    'col2_row2_col1' => t('Bottom Center (1/3)'),
    'col2_row2_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_landing_page_2().
 */
function template_preprocess_dashboard_main(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--dashboard-main';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-main-region';
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-main-region--' . drupal_clean_css_identifier($name);
  }
}
