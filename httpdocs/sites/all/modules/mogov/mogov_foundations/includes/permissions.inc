<?php

/**
 * Implements hook_menu().
 */
function mogov_foundations_permission() {
  return array(
    // Allow access to mogov site configuration
    'administer mogov site configuration' => array(
      'title' => t('Administer MO.gov site configuration'),
      'description' => t('State and agency leadership info, API keys, etc.'),
    ),
    // Allow access to social media accounts configuration
    'administer social media accounts' => array(
      'title' => t('Administer social media accounts'),
      'description' => t('URLs and other information for social media accounts associated with this site.'),
    ),
  );
}
