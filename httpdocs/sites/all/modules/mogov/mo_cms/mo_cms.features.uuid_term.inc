<?php
/**
 * @file
 * mo_cms.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function mo_cms_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'State of Missouri',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '18d0877e-3d57-4d55-912d-6c7a6962db86',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'State of Missouri',
          'format' => NULL,
          'safe_value' => 'State of Missouri',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Insurance, Financial Institutions and Professional Registration',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '197b70ca-954b-4cc1-9a23-416d892e37fc',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DIFP',
          'format' => NULL,
          'safe_value' => 'DIFP',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Insurance',
          'format' => NULL,
          'safe_value' => 'Insurance',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Revenue',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '2148493c-2750-406b-b214-093af51e6ba0',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DOR',
          'format' => NULL,
          'safe_value' => 'DOR',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Revenue',
          'format' => NULL,
          'safe_value' => 'Revenue',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Labor and Industrial Relations',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '25c1fb23-5b6f-4947-82cf-ff2e5164d71b',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DOLIR',
          'format' => NULL,
          'safe_value' => 'DOLIR',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Labor',
          'format' => NULL,
          'safe_value' => 'Labor',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Public Safety',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '2d56aa06-4504-4a45-a83a-81d04969be92',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DPS',
          'format' => NULL,
          'safe_value' => 'DPS',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Public Safety',
          'format' => NULL,
          'safe_value' => 'Public Safety',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Education',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '3',
    'uuid' => '3259d0fd-f5cd-4c9f-b35e-9e4f3289df3a',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Work',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '4',
    'uuid' => '5137fe9e-1ab9-4dcf-b1a1-b84c9100e4c5',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Department of Higher Education',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '5ea51277-c70c-49ee-ac1d-937a6719e343',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DHE',
          'format' => NULL,
          'safe_value' => 'DHE',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Higher Education',
          'format' => NULL,
          'safe_value' => 'Higher Education',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Mental Health',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '6015f06d-0639-4157-9109-a56b4b0a45a4',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DMH',
          'format' => NULL,
          'safe_value' => 'DMH',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Mental Health',
          'format' => NULL,
          'safe_value' => 'Mental Health',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Safety',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '1',
    'uuid' => '68bedc51-877c-4ad8-96fc-a207c284edd4',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Outdoors and Tourism',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '6',
    'uuid' => '6d066bed-7fc9-4d34-afb7-a5c97c6a046f',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Department of Social Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '79dff7e7-4712-407e-bfb0-8d32ea3a429a',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DSS',
          'format' => NULL,
          'safe_value' => 'DSS',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Social Services',
          'format' => NULL,
          'safe_value' => 'Social Services',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Business',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '5',
    'uuid' => '87b6591f-aed8-4ba6-b879-66a4eb487cfc',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Health',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '7',
    'uuid' => '8a5803ee-b0b0-4c89-80e6-a1e2660ca853',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Department of Transportation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '8fd271ba-6e97-496e-a873-e7d314b66a3a',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DOT',
          'format' => NULL,
          'safe_value' => 'DOT',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Transportation',
          'format' => NULL,
          'safe_value' => 'Transportation',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Office of State Public Defender',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '93e8816f-9ebe-4efa-807b-6a12aaf4cd7a',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'Public Defender',
          'format' => NULL,
          'safe_value' => 'Public Defender',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'State Public Defender',
          'format' => NULL,
          'safe_value' => 'State Public Defender',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Economic Development',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '9d704a5e-6cd3-4b77-8a67-c2aa5b7d9beb',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DED',
          'format' => NULL,
          'safe_value' => 'DED',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Economic Development',
          'format' => NULL,
          'safe_value' => 'Economic Development',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Secretary of State\'s Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => '9f20715f-e890-4975-9177-eb98e6ecea2d',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'SOS',
          'format' => NULL,
          'safe_value' => 'SOS',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Secretary of State',
          'format' => NULL,
          'safe_value' => 'Secretary of State',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Government',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '0',
    'uuid' => 'a3322698-1577-46b4-bc4e-da46ef388074',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Residents',
    'description' => '',
    'format' => 'wysiwyg',
    'weight' => '2',
    'uuid' => 'a9b0be04-7201-4481-bdb0-1f8ab37c967a',
    'vocabulary_machine_name' => 'mo_cms_categories',
  );
  $terms[] = array(
    'name' => 'Office of Administration',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'abcab8b0-ea4b-4b47-a7cf-e30b36d1cbcc',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'OA',
          'format' => NULL,
          'safe_value' => 'OA',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Administration',
          'format' => NULL,
          'safe_value' => 'Administration',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Corrections',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'ae335932-ecbf-42b7-9db2-2c84f156c127',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DOC',
          'format' => NULL,
          'safe_value' => 'DOC',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Corrections',
          'format' => NULL,
          'safe_value' => 'Corrections',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Agriculture',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'b2e5601e-7a22-4aec-b5d0-e352bc8b8697',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'MDA',
          'format' => NULL,
          'safe_value' => 'MDA',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => NULL,
          'safe_value' => 'Agriculture',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Conservation',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'b32d6632-c52c-4985-b718-5c0ce138e868',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'Conservation',
          'format' => NULL,
          'safe_value' => 'Conservation',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Conservation',
          'format' => NULL,
          'safe_value' => 'Conservation',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Elementary and Secondary Education',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'cfb293a1-badf-4171-a1b4-8be0b1ed172d',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DESE',
          'format' => NULL,
          'safe_value' => 'DESE',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Elementary and Secondary Education',
          'format' => NULL,
          'safe_value' => 'Elementary and Secondary Education',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Health and Senior Services',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'd3d86123-a2dd-40d5-9b35-6dfb86e9b087',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DHSS',
          'format' => NULL,
          'safe_value' => 'DHSS',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Health and Senior Services',
          'format' => NULL,
          'safe_value' => 'Health and Senior Services',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'State Treasurer\'s Office',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'dd7f1073-3c4c-44ad-8924-343955f414c5',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'Treasurer',
          'format' => NULL,
          'safe_value' => 'Treasurer',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Treasurer',
          'format' => NULL,
          'safe_value' => 'Treasurer',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Office of the Missouri Governor',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'e3999e73-1919-4ed9-9530-8374915ae0e9',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'Governor',
          'format' => NULL,
          'safe_value' => 'Governor',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Governor\'s Office',
          'format' => NULL,
          'safe_value' => 'Governor&#039;s Office',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Department of Natural Resources',
    'description' => '',
    'format' => 'plain_text',
    'weight' => '0',
    'uuid' => 'f1107797-b3bd-413f-950d-fe5584e43713',
    'vocabulary_machine_name' => 'mo_cms_agencies',
    'field_agency_abbreviation' => array(
      'und' => array(
        0 => array(
          'value' => 'DNR',
          'format' => NULL,
          'safe_value' => 'DNR',
        ),
      ),
    ),
    'field_agency_short_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Natural Resources',
          'format' => NULL,
          'safe_value' => 'Natural Resources',
        ),
      ),
    ),
  );
  return $terms;
}
