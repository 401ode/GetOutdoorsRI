<?php

/**
 * Implements hook_variable_group_info().
 */
function mogov_environment_variable_group_info() {
  $groups['mogov_environment_settings'] = array(
    'title' => t('Agency configuration'), 
    'description' => t('Basic information about the agency that owns this site.'),
    'access' => 'administer site configuration', 
    'path' => array('admin/config/mogov/agency', 'admin/config/development/maintenance'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function mogov_environment_variable_info($options) {
  $variables = array(
    'mogov_environment_nscache_clear' => array(
      'title' => t('NetScaler cache active', array(), $options),
      'description' => t('There is a NetScaler cache active for this site'),
      'group' => 'mogov_environment_settings',
      'type' => 'boolean',
      'access' => 'access administration pages',
      'default' => FALSE,
      'element' => array(
        '#type' => 'checkbox',
      ),
    ),
  );
  return $variables;
}
