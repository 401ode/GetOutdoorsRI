<?php

/**
 * Alters the Performance settings form to add an additional action to the Clear Cache button
 */
function mogov_environment_form_system_performance_settings_alter(&$form, $form_state, $form_id) {
  if (module_exists('memcache')) {
    $form['clear_cache']['clear']['#submit'][] = 'mogov_environment_clear_cache_submit';
  }
}
