<?php

/**
 * @file
 * Defines the "Dashboard Alt 1" layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Dashboard Alt 1'),
  'category' => t('Dashboard'),
  'icon' => 'preview.png',
  'theme' => 'dashboard_alt1',
  'css' => 'dashboard_alt1.css',
  'regions' => array(
    'col1' => t('Left (1/3)'),
    'col2_row1_col1' => t('Top Center (1/3)'),
    'col2_row1_col2' => t('Top Right (1/3)'),
    'col2_row2_col1' => t('Middle (2/3)'),
    'col2_row3_col1' => t('Bottom Center (1/3)'),
    'col2_row3_col2' => t('Bottom Right (1/3)'),
  ),
);

/**
 * Implements hook_preprocess_landing_page_2().
 */
function template_preprocess_dashboard_alt1(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-display';
  $variables['attributes_array']['class'][] = 'panel-display--dashboard-alt1';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-alt1-region';
    $variables['region_attributes_array'][$name]['class'][] = 'dashboard-alt1-region--' . drupal_clean_css_identifier($name);
  }
}
