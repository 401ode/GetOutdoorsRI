<?php
/**
 * @file
 * campus_challenge.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function campus_challenge_taxonomy_default_vocabularies() {
  return array(
    'mo_gov_counties' => array(
      'name' => 'MO.gov Counties',
      'machine_name' => 'mo_gov_counties',
      'description' => 'Missouri Counties',
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
