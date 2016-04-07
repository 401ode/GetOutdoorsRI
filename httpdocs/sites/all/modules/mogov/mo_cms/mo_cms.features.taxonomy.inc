<?php
/**
 * @file
 * mo_cms.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mo_cms_taxonomy_default_vocabularies() {
  return array(
    'mo_cms_agencies' => array(
      'name' => 'MO CMS: Agencies',
      'machine_name' => 'mo_cms_agencies',
      'description' => 'Used as local editorial sections',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-10',
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
    'mo_cms_categories' => array(
      'name' => 'MO CMS: Categories',
      'machine_name' => 'mo_cms_categories',
      'description' => 'The categories shared in common by all sites.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
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
    'mo_cms_contact_lists' => array(
      'name' => 'MO CMS: Contact Lists',
      'machine_name' => 'mo_cms_contact_lists',
      'description' => 'Used for grouping MO CMS: Contact nodes into lists',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-6',
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
    'mo_cms_counties' => array(
      'name' => 'MO CMS: Counties',
      'machine_name' => 'mo_cms_counties',
      'description' => 'Missouri Counties',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-9',
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
    'mo_cms_editorial_sections' => array(
      'name' => 'MO CMS: Editorial Sections',
      'machine_name' => 'mo_cms_editorial_sections',
      'description' => 'Used to group content into editorial sections for Workbench Access',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-5',
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
    'mo_cms_municipalities' => array(
      'name' => 'MO CMS: Municipalities',
      'machine_name' => 'mo_cms_municipalities',
      'description' => 'A complete list of cities and towns in Missouri.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-8',
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
    'mo_cms_out_of_state_locations' => array(
      'name' => 'MO CMS: Out-of-State Locations',
      'machine_name' => 'mo_cms_out_of_state_locations',
      'description' => 'A companion vocabulary to the Counties and Municipalities lists, for other locations.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-7',
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
