<?php

/**
 * Submits http request for the NetScaler's cache invalidation URL
 */
function mogov_environment_clear_cache_submit($form, &$form_state) {
  global $base_url;
  $url = $base_url . '/nscache_inval';
  $response = drupal_http_request($url);
  if ($response->code == 200) {
    drupal_set_message(t('NetScaler caches cleared.'));
  } else {
    drupal_set_message(t('NetScaler caches may have failed to clear. Please contact an administrator.'));
  }
}
