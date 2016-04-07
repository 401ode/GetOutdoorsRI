<?php
       
/**
 * Implements hook_views_default_views().
 */
function mogov_dashboard_views_default_views() {
  $views = array();
  $path = drupal_get_path('module', 'mogov_dashboard') . '/views';
  $files = drupal_system_listing('/\.inc$/', $path, 'name', 0);
  foreach($files as $file) {
    include_once 'views/' . $file->filename;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
