<?php

/**
 * Define the environment hostnames
 */
$conf['production_host'] = 'production_host.com';
$conf['staging_host'] = 'staging_host.com';
$conf['development_host'] = 'development_host.com';
$conf['local_host'] = 'local_host.local';

/**
 * Apply various settings according to the local environment
 */
$host = explode(':', $_SERVER['HTTP_HOST']);
switch ($host[0]) {

  // Production environment
  case $conf['production_host']:
  case 'www.' . $conf['production_host']:

    // Set custom environment variable
    $conf['environment'] = 'production';

    // Disable all error reporting
    ini_set('error_reporting', 0);
    ini_set('display_errors', 0);

    // Memcache configuration
    $conf['memcache_key_prefix'] = 'prefix';
    $conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
    $conf['lock_inc'] = 'sites/all/modules/contrib/memcache/memcache-lock.inc';
    $conf['memcache_stampede_protection'] = FALSE;
    $conf['cache_default_class'] = 'MemCacheDrupal';
    $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
    $conf['memcache_servers'] = array(
      'server.path.url:portnumber' => 'default',
    );
    $conf['memcache_bins'] = array(
      'cache' => 'default',
    );
    $conf['page_cache_without_database'] = TRUE;
    $conf['page_cache_invoke_hooks'] = FALSE;

    // CloudFlare header
    if (isset($_SERVER['HTTP_CF_CONNECTING_IP'])) {
      $_SERVER['REMOTE_ADDR'] = $_SERVER['HTTP_CF_CONNECTING_IP'];
    }

    // Set config variables
    $conf['file_temporary_path'] = '/var/www/vhosts/production_url.com/site_temp';
    $conf['file_public_path'] = 'sites/default/files';
//    $conf['file_private_path'] = '/var/www/vhosts/production_url.com/private/sitename';
    $conf['preprocess_css'] = '1';
    $conf['preprocess_js'] = '1';

    break;


  // Staging environment
  case $conf['staging_host']:

    // Set custom environment variable
    $conf['environment'] = 'staging';

    // Disable all error reporting
    ini_set('error_reporting', 0);
    ini_set('display_errors', 0);

    // Memcache configuration
    $conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
    $conf['lock_inc'] = 'sites/all/modules/contrib/memcache/memcache-lock.inc';
    $conf['cache_default_class'] = 'MemCacheDrupal';
    $conf['cache_class_form'] = 'DrupalDatabaseCache';
    $conf['memcache_servers'] = array(
      'YOURMEMCACHESERVER:XXXXX' => 'default', // Port number is site-specific! Change XXXXX
    );
    $conf['memcache_bins'] = array(
      'cache' => 'default',
    );
    $conf['memcache_persistent'] = TRUE;

    // Set config variables
    $conf['file_temporary_path'] = '/var/www/vhosts/YOUR/TEMP/PATH';
    $conf['preprocess_css'] = '0';
    $conf['preprocess_js'] = '0';

    break;


  /*
   * Server Dev environment
   */
  case $conf['development_host']:

    // Set custom environment variable
    $conf['environment'] = 'test';

    // Enable all error reporting
    error_reporting(-1);  // Have PHP complain about absolutely everything.
    $conf['error_level'] = 2;  // Show all messages on your screen
    ini_set('display_errors', TRUE);  // These lines give you content on WSOD pages.
    ini_set('display_startup_errors', TRUE);

    // Set config variables
    $conf['file_temporary_path'] = '/var/www/vhosts/' . $host[0] . '/site_temp';
    $conf['preprocess_css'] = '0';
    $conf['preprocess_js'] = '0';

    break;


  /**
   * Local Development environment, or Drush
   */
  default:

    // Set custom environment variable
    $conf['environment'] = 'local';

    // Enable all error reporting
    error_reporting(-1);  // Have PHP complain about absolutely everything.
    $conf['error_level'] = 2;  // Show all messages on your screen
    ini_set('display_errors', TRUE);  // These lines give you content on WSOD pages.
    ini_set('display_startup_errors', TRUE);

    // Set config variables
    $conf['file_temporary_path'] = '../../tmp';
    $conf['preprocess_css'] = '0';
    $conf['preprocess_js'] = '0';

    break;

}
