<?php

/**
* Implementation of hook_default_page_manager_pages().
*/
function mogov_dashboard_default_page_manager_pages() {
  $pages = array();
  $path = drupal_get_path('module', 'mogov_dashboard') . '/pages';
  $files = drupal_system_listing('/\.inc$/', $path, 'name', 0);
  foreach($files as $file) {
    include_once 'pages/' . $file->filename;
    if (isset($page)) {
      $pages[$page->name] = $page;
    }
  }
  return $pages;
}
