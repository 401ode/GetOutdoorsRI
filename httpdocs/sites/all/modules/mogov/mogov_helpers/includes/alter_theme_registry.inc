<?php

/**
 * Implements hook_theme_registry_alter()
 */
function mogov_helpers_alter_theme_registry(&$theme_registry, $path) {
  $theme_registry_copy = $theme_registry;
  _theme_process_registry($theme_registry_copy, 'phptemplate', 'theme_engine', 'pow', $path);
  $theme_registry += array_diff_key($theme_registry_copy, $theme_registry);
  $hooks = array('node');
  foreach ($hooks as $h) {
    _mogov_helpers_insert_after_first_element($theme_registry[$h]['theme paths'], $path);
  }
}

/**
 * Helper function for re-ordering arrays (needed by theme_registry_alter)
*/
function _mogov_helpers_insert_after_first_element(&$a, $element) {
  if(is_array($a)) {
    $first_element = array_shift($a);
    array_unshift($a, $first_element, $element);
  }
}
