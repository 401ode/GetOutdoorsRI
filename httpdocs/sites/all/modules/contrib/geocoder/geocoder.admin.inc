<?php

/**
 * @file
 * Settings form.
 */

/**
 * Module settings page.
 */
function geocoder_admin_settings($form, &$form_state) {
  $geocoder_settings= variable_get("geocoder_settings", array());
  $form['geocoder_apikey_yahoo'] = array(
    '#type' => 'textfield',
    '#title' => t('Yahoo PlaceFinder API Key'),
    '#description' => t('You can obtain a Yahoo PlaceFinder consumer key at') . ' ' . 'http://developer.yahoo.com/geo/placefinder/',
    '#default_value' => empty($geocoder_settings['geocoder_apikey_yahoo']) ? '' : $geocoder_settings['geocoder_apikey_yahoo'],
    '#required' => FALSE,
  );

  $form['geocoder_apikey_yandex'] = array(
    '#type' => 'textfield',
    '#title' => t('Yandex Maps API Key'),
    '#description' => t('You can obtain a Yandex API Key at ') . 'http://api.yandex.ru/maps/getkey.xml',
    '#default_value' => empty($geocoder_settings['geocoder_apikey_yandex']) ? '' : $geocoder_settings['geocoder_apikey_yandex'],
    '#required' => FALSE,
  );

  $form['geocoder_apikey_bing'] = array(
    '#type' => 'textfield',
    '#title' => t('Bing API Key'),
    '#description' => t('You can obtain a Bing API Key at ') . 'http://msdn.microsoft.com/en-us/library/ff428642.aspx',
    '#default_value' => empty($geocoder_settings['geocoder_apikey_bing']) ? '' : $geocoder_settings['geocoder_apikey_bing'],
    '#required' => FALSE,
  );

  $form['geocoder_google_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Delay between Google geocoding requests (in milliseconds)'),
    '#description' => t('Adds a delay between geocoding requests, to avoid OVER_QUERY_LIMIT errors from Google. 200ms is recommended.'),
    '#default_value' => variable_get('geocoder_google_delay', 0),
    '#size' => 10,
  );

  $form['geocoder_google_business_api_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Business API Client ID'),
    '#description' => t('You can signup for Google Maps for Business at ') . 'http://www.google.com/enterprise/earthmaps/maps.html',
    '#default_value' => empty($geocoder_settings['geocoder_google_business_api_client_id']) ? '' : $geocoder_settings['geocoder_google_business_api_client_id'],
    '#required' => FALSE,
  );

  $form['geocoder_google_business_api_crypto_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Business API Key'),
    '#default_value' => empty($geocoder_settings['geocoder_google_business_api_crypto_key']) ? '' : $geocoder_settings['geocoder_google_business_api_crypto_key'],
    '#required' => FALSE,
  );

  $form['geocoder_google_business_api_use'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Google Business API'),
    '#default_value' => empty($geocoder_settings['geocoder_google_business_api_use']) ? '' : $geocoder_settings['geocoder_google_business_api_use'],
    '#required' => FALSE,
  );

  $form['#submit'][] = 'geocoder_admin_settings_submit';
  return system_settings_form($form);
}

function geocoder_admin_settings_validate($form_id, $form_values) {
  if (!empty($form_values['values']['geocoder_apikey_yahoo']) && preg_match("/[^A-Za-z0-9\\-]/", trim($form_values['values']['geocoder_apikey_yahoo']))) {
    form_set_error('geocoder_apikey_yahoo', t('Yahoo API keys are alpha numeric and dashes only.'));
  }
}

function geocoder_admin_settings_submit($form, &$form_state) {
  $geocoder_settings= variable_get("geocoder_settings", array());
  $geocoder_settings['geocoder_apikey_yahoo'] = trim($form_state['values']['geocoder_apikey_yahoo']);
  $geocoder_settings['geocoder_apikey_yandex'] = trim($form_state['values']['geocoder_apikey_yandex']);
  $geocoder_settings['geocoder_apikey_bing'] = trim($form_state['values']['geocoder_apikey_bing']);
  $geocoder_settings['geocoder_google_business_api_client_id'] = trim($form_state['values']['geocoder_google_business_api_client_id']);
  $geocoder_settings['geocoder_google_business_api_crypto_key'] = trim($form_state['values']['geocoder_google_business_api_crypto_key']);
  $geocoder_settings['geocoder_google_business_api_use'] = trim($form_state['values']['geocoder_google_business_api_use']);
  variable_set("geocoder_settings", $geocoder_settings);
}
