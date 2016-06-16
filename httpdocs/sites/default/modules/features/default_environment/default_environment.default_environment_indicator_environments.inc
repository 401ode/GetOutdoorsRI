<?php
/**
 * @file
 * default_environment.default_environment_indicator_environments.inc
 */

/**
 * Implements hook_default_environment_indicator_environment().
 */
function default_environment_default_environment_indicator_environment() {
  
  global $conf;
  $export = array();

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'local_environment';
  $environment->name = 'Local environment';
  $environment->regexurl = $conf['local_host'];
  $environment->settings = array(
    'color' => '#000000',
    'text_color' => '#ffffff',
    'weight' => '0',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['local_environment'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'development_environment';
  $environment->name = 'Development environment';
  $environment->regexurl = $conf['development_host'];
  $environment->settings = array(
    'color' => '#86a447',
    'text_color' => '#ffffff',
    'weight' => '10',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['development_environment'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'production_environment';
  $environment->name = 'Production environment';
  $environment->regexurl = $conf['production_host'];
  $environment->settings = array(
    'color' => '#a91e23',
    'text_color' => '#ffffff',
    'weight' => '20',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['production_environment'] = $environment;

  return $export;
}
