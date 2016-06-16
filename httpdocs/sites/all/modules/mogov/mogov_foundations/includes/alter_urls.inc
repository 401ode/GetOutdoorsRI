<?php

/**
 * Implements hook_file_url_alter().
 *
 * Make all URLs be protocol relative.
 * Note: protocol relatice URLs will cause IE7/8 to download stylesheets twice.
 * Source: http://engineeredweb.com/blog/11/12/protocol-relative-urls-drupal-7/
 */
function mogov_foundations_file_url_alter(&$url) {

  global $base_url;

  static $relative_base_url = NULL, $relative_base_length = NULL;

  $scheme = file_uri_scheme($url);

  // For some things (e.g., images) hook_file_url_alter can be called multiple
  // times. So, we have to be sure not to alter it multiple times. If we already
  // are relative protocol we can just return.
  // Only setup the and parse this stuff once.
  if (!$relative_base_url || !$relative_base_length) {
    $relative_base_url = '//' . file_uri_target($base_url);
    $relative_base_length = strlen($relative_base_url);
  }
  if (!$scheme && substr($url, 0, $relative_base_length) == $relative_base_url) {
    return;
  }

  // Handle the case where we have public files with the scheme public:// or
  // the case the relative path doesn't start with a /. Internal relative urls
  // have the base url prepended to them.
  if (!$scheme || $scheme == 'public') {

    // Internal Drupal paths.
    if (!$scheme) {
      $path = $url;
    }
    else {
      $wrapper = file_stream_wrapper_get_instance_by_scheme($scheme);
      $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($url);
    }

    // Clean up Windows paths.
    $path = str_replace('\\', '/', $path);

    $url = $base_url . '/' . $path;
  }

  // Convert full URLs to relative protocol.
  $protocols = array('http', 'https');
  $scheme = file_uri_scheme($url);
  if ($scheme && in_array($scheme, $protocols)) {
    $url = '//' . file_uri_target($url);
  }
}
