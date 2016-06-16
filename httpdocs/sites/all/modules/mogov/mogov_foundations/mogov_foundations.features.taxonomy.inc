<?php
/**
 * @file
 * mogov_foundations.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mogov_foundations_taxonomy_default_vocabularies() {
  return array(
    'mogov_agencies' => array(
      'name' => 'Agencies',
      'machine_name' => 'mogov_agencies',
      'description' => 'A list of state agencies.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'mogov_categories' => array(
      'name' => 'Categories',
      'machine_name' => 'mogov_categories',
      'description' => 'Used to categorize content by topics of interest to constituents',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
    'mogov_contact_lists' => array(
      'name' => 'Contact Lists',
      'machine_name' => 'mogov_contact_lists',
      'description' => 'Used to categorize contacts for automatic generation of contact lists.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -5,
    ),
    'mogov_counties' => array(
      'name' => 'Counties',
      'machine_name' => 'mogov_counties',
      'description' => 'A list of Missouri counties.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'mogov_municipalities' => array(
      'name' => 'Municipalities',
      'machine_name' => 'mogov_municipalities',
      'description' => 'A complete list of cities and towns in Missouri.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -7,
    ),
    'mogov_out_of_state_locations' => array(
      'name' => 'Out-of-State Locations',
      'machine_name' => 'mogov_out_of_state_locations',
      'description' => 'A companion vocabulary to the Counties and Municipalities lists, for other locations.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -6,
    ),
    'mogov_tags' => array(
      'name' => 'Tags',
      'machine_name' => 'mogov_tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -2,
    ),
  );
}
