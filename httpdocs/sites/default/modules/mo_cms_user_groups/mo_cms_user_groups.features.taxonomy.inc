<?php
/**
 * @file
 * mo_cms_user_groups.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mo_cms_user_groups_taxonomy_default_vocabularies() {
  return array(
    'activities' => array(
      'name' => 'Activities',
      'machine_name' => 'activities',
      'description' => 'The various activities users may select when logging miles.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'mo_cms_user_group_interests' => array(
      'name' => 'MO CMS: User Group Interests',
      'machine_name' => 'mo_cms_user_group_interests',
      'description' => 'Used for finding groups and linking groups with events, activities, etc.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
