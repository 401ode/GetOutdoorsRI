<?php

/**
 * Set up a Google API analytics service
 */
function mogov_dashboard_google_analytics_create_service() {
  $application_name = variable_get_value('mogov_api_key_google_application_name');
  $service_account_email = variable_get_value('mogov_api_key_google_service_email');
  $keyfile_fid = variable_get_value('mogov_api_key_google_service_keyfile_fid');
  if (!$service_account_email or !$keyfile_fid) {
    return FALSE;
  }
  $keyfile = file_load($keyfile_fid);
  $keyfile_path = drupal_realpath($keyfile->uri);
  global $conf;
  set_include_path($_SERVER['DOCUMENT_ROOT'] . '/sites/all/libraries/google-api-php-client/src/' . PATH_SEPARATOR . get_include_path());
  require_once 'Google/Client.php';
  require_once 'Google/Service/Analytics.php';
  if (!$service_account_email) {
    return FALSE;
  }
  $client = new Google_Client();
  $client->setClassConfig('Google_Cache_File', 'directory', $conf['file_temporary_path']);
  $client->setApplicationName($application_name);
  $client->setAssertionCredentials(
    new Google_Auth_AssertionCredentials(
      $service_account_email,
      array('https://www.googleapis.com/auth/analytics.readonly'),
      file_get_contents($keyfile_path)
    )
  );
  $service = new Google_Service_Analytics($client);
  return $service;
}

/**
 * Get the top pages for the past week
 */
function mogov_dashboard_google_analytics_query($service, $start_date, $end_date, $params) {
  $analytics_id = t('ga:!view_id', array('!view_id' => variable_get_value('mogov_api_key_google_view_id')));
  try {
    $results = $service->data_ga->get(
      $analytics_id,
      $start_date,
      $end_date,
      'ga:pageviews',
      $params
    );
    if (empty($results->rows)) {
      return t('No results found.');
    }
  } catch(Exception $e) {
    return t('There was an error : - ' . $e->getMessage());
  }
  return $results->rows;
}
