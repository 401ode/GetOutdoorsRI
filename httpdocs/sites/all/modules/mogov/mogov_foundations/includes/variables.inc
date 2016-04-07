<?php

/**
 * Implements hook_variable_group_info().
 */
function mogov_foundations_variable_group_info() {
  $groups['mogov_agency_info'] = array(
    'title' => t('Agency configuration'), 
    'description' => t('Basic information about the agency that owns this site.'),
    'access' => 'administer mogov site configuration', 
    'path' => array('admin/config/mogov/agency', 'admin/config/development/maintenance'),
  );
  $groups['mogov_social_info'] = array(
    'title' => t('Social settings'), 
    'description' => t('Information required to build the agency\'s social bar in the header.'), 
    'access' => 'administer social media accounts',
    'path' => array('admin/config/mogov/social', 'admin/config/development/maintenance'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function mogov_foundations_variable_info($options) {
  
  global $base_url;
  $variables = array();

  $variables['mogov_governor_name'] = array(
    'title' => t('Governor', array(), $options),
    'description' => t('Governor\'s full name.'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => '',
  );

  $variables['mogov_governor_url'] = array(
    'title' => t('Governor site URL', array(), $options),
    'description' => t('URL to the Governor\'s website.'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => '',
  );

  $variables['mogov_agency_name'] = array(
    'title' => t('Agency name', array(), $options),
    'description' => t('Full name of the agency that owns the site.'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => '',
  );

  $variables['mogov_agency_head'] = array(
    'title' => t('Agency head', array(), $options),
    'description' => t('Full name of the head of the agency that owns the site.'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => '',
  );

  $variables['mogov_agency_head_title'] = array(
    'title' => t('Agency head title', array(), $options),
    'description' => t('Title of the head of the agency that owns the site (e.g., "Commissioner").'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => '',
  );

  $variables['mogov_agency_url'] = array(
    'title' => t('Agency URL', array(), $options),
    'description' => t('URL to the website of the agency that owns this website (may be same as this site).'),
    'group' => 'mogov_agency_info',
    'type' => 'string',
    'access' => 'administer mogov site configuration',
    'default' => $base_url,
  );
  
  $variables['mogov_social_bar_mailto'] = array(
    'title' => t('Mailto address', array(), $options),
    'description' => t('The Email address for which the social bar should build a mailto link.'),
    'group' => 'mogov_social_info',
    'type' => 'string',
    'access' => 'administer social media accounts',
    'default' => NULL,
  );
  
  $variables['mogov_social_bar_youtube'] = array(
    'title' => t('YouTube channel', array(), $options),
    'description' => t('The YouTube channel to which the social bar should link.'),
    'group' => 'mogov_social_info',
    'type' => 'string',
    'access' => 'administer social media accounts',
    'default' => NULL,
  );
  
  $variables['mogov_social_bar_twitter'] = array(
    'title' => t('Twitter account', array(), $options),
    'description' => t('The Twitter account (just the username, not the full URL) to which the social bar should link.'),
    'group' => 'mogov_social_info',
    'type' => 'string',
    'access' => 'administer social media accounts',
    'default' => NULL,
  );
    
  $variables['mogov_social_bar_facebook'] = array(
    'title' => t('Facebook page', array(), $options),
    'description' => t('The Facebook page to which the social bar should link (just the page, not the full URL).'),
    'group' => 'mogov_social_info',
    'type' => 'string',
    'access' => 'administer social media accounts',
    'default' => NULL,
  );
    
  $variables['mogov_social_bar_googleplus'] = array(
    'title' => t('Google+ page', array(), $options),
    'description' => t('The page to which the social bar should link (just the page ID, not the full URL).'),
    'group' => 'mogov_social_info',
    'type' => 'string',
    'access' => 'administer social media accounts',
    'default' => NULL,
  );

  return $variables;
}
