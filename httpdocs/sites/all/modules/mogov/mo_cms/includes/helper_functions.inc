<?php
/**
 * @file
 * MO CMS helper functions used by other modules in the MO CMS suite.
 */


/**
 * Get current node
 */
function mo_cms_get_current_node() {
  $path = current_path();
  $matches = array();
  if (preg_match('/^node\/(\d+)$/', $path, $matches)) {
    $node = node_load($matches[1]);
    return $node;
  } else {
    return FALSE;
  }
}

/**
 * Get related content tids from a querystring
 */
function mo_cms_get_related_content_tids($querystring) {
  $args = array();
  parse_str($querystring, $args);
  $vids = mo_cms_get_related_content_vids();
  if (!empty($args['tags'])) {
    $vids['field_tags']['terms'] = explode(',', $args['tags']);
  }
  if (!empty($args['agencies'])) {
    $vids['field_mo_cms_related_agencies']['terms'] = explode(',', $args['agencies']);
  }
  if (!empty($args['categories'])) {
    $vids['field_mo_cms_related_categories']['terms'] = explode(',', $args['categories']);
  }
  if (!empty($args['locations'])) {
    $vids['field_mo_cms_related_locations']['terms'] = explode(',', $args['locations']);
  }
  $tids = array();
  foreach ($vids as $field=>$data) {
    if (empty($data['terms'])) {
      continue;
    }
    foreach ($data['terms'] as $term_name) {
      foreach ($data['vocabulary_names'] as $vocabulary_name) {
        $terms = taxonomy_get_term_by_name($term_name, $vocabulary_name);
        foreach ($terms as $term) {
          $tids[] = $term->tid;
        }
      }
    }
  }
  return $tids;
}

/**
 * Get tags from node from vocabularies that are relevant to related content lists
 */
function mo_cms_get_node_tags($node) {
  $tags = array();
  $tags_fields = array(
    'field_tags',
    'field_mo_cms_related_agencies',
    'field_mo_cms_categories',
    'field_mo_cms_related_locations',
    'field_mo_cms_county_muni',
  );
  foreach ($tags_fields as $field_name) {
    $field_info = field_info_field($field_name);
    if (!array_key_exists($field_name, $tags)) {
      $tags[$field_name] = array();
    }
    $field = field_get_items('node', $node, $field_name);
    if ($field_info['type'] == 'taxonomy_term_reference') {
      $id_key = 'tid';
      $entity_key = 'taxonomy_term';
    } else {
      $id_key = 'target_id';
      $entity_key = 'entity';
    }
    if (!empty($field[0][$id_key])) {
      foreach ($field as $tag) {
        if (empty($tag[$entity_key])) {
          $tag[$entity_key] = taxonomy_term_load($tag[$id_key]);
        }
        $tags[$field_name][] = $tag[$entity_key]->name;
      }
    }
    // Merge related locations and dateline fields so they're not counted twice
    $location_tags = array();
    if (!empty($tags['field_mo_cms_related_locations'])) {
      $location_tags = array_merge($location_tags, $tags['field_mo_cms_related_locations']);
    }
    if (!empty($tags['field_mo_cms_county_muni'])) {
      $location_tags = array_merge($location_tags, $tags['field_mo_cms_county_muni']);
      unset($tags['field_mo_cms_county_muni']);
    }
    if (!empty($location_tags)) {
      $tags['field_mo_cms_related_locations'] = array_unique($location_tags);
    }
  }
  return $tags;
}

/**
 * Get a list of nids of published nodes based on content type.
 * If $nid is supplied, the returned list will not include the supplied nid.
 */
function mo_cms_get_nids_by_types($types, $nid=FALSE) {
  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->condition('n.type', $types);
  $query->condition('n.status', 0, '>');
  if ($nid) {
    $query->condition('n.nid', $nid, '<>');
  }
  $result = $query->execute();
  $nids = $result->fetchCol();
  return $nids;
}

/**
 * Scores a set of potentially-related nids based on overlap with supplied tags.
 * Returns a list as long as the specified $count.
 */
function mo_cms_score_ids($type, $ids, $tags, $count=0) {
  $related_ids = array();
  $vids = mo_cms_get_related_content_vids();
  foreach ($tags as $field=>$field_tags) {
    if ($field == 'field_mo_cms_county_muni') {
      continue;
    }
    $search_fields = array($field);
    if ($field == 'field_mo_cms_related_locations') {
      $search_fields[] = 'field_mo_cms_county_muni';
    }
    $field_info = field_info_field($field);
    foreach ($field_tags as $tag) {
      $query = new EntityFieldQuery;
      $query->entityCondition('entity_type', 'taxonomy_term');
      $query->propertyCondition('name', $tag);
      $query->propertyCondition('vid', $vids[$field]['vids']);
      $results = $query->execute();
      if (!empty($results['taxonomy_term'])) {
        foreach ($results['taxonomy_term'] as $tid=>$data) {
          if ($type == 'node' and $field_info['type'] == 'taxonomy_term_reference') {
            $term_ids = taxonomy_select_nodes($tid, FALSE);
          } else {
            $bundle = FALSE;
            if ($type == 'file') {
              $bundle = 'image';
            }
            $term_ids = mo_cms_get_ids_by_tids(array($tid), $type, $bundle, $search_fields);
          }
          foreach ($term_ids as $id) {
            if (!in_array($id, $ids)) {
              continue;
            } elseif (array_key_exists($id, $related_ids)) {
              $related_ids[$id] += $vids[$field]['value'];
            } else {
              $related_ids[$id] = $vids[$field]['value'];
            }
          }
        }
      }
    }
  }
  if (!$related_ids) {
    return FALSE;
  }
  arsort($related_ids);
  $related_ids = array_keys($related_ids);
  if ($count and count($related_ids) > $count) {
    array_splice($related_ids, $count);
  }
  return $related_ids;
}

/**
 * Get a list of fids of published nodes based on content type.
 * If $nid is supplied, the returned list will not include the supplied nid.
 */
function mo_cms_get_fids_by_types($types) {
  $query = db_select('file_managed', 'f');
  $query->addField('f', 'fid');
  $query->condition('f.type', $types);
  $query->condition('f.status', 0, '>');
  $result = $query->execute();
  $fids = $result->fetchCol();
  return $fids;
}

/**
 * Get a list of entity IDs by entity type, bundle, fields, and term ID
 */
function mo_cms_get_ids_by_tids($tids, $type='node', $bundle=FALSE, $fields=array('field_tags')) {
  $ids = array();
  if (!empty($tids)) {
    foreach ($fields as $field) {
      $field_info = field_info_field($field);
      $table = 'field_data_' . $field;
      if ($field_info['type'] == 'taxonomy_term_reference') {
        $column = 't.' . $field . '_tid';
      } else {
        $column = 't.' . $field . '_target_id';
      }
      $query = db_select($table, 't');
      $query->addField('t', 'entity_id', 'id');
      $query->condition('deleted', 0);
      $query->condition('t.entity_type', $type);
      if ($bundle) {
        $query->condition('t.bundle', $bundle);
      }
      $query->condition($column, $tids);
      $result = $query->execute();
      $ids = array_merge($ids, $result->fetchCol());
    }
  }
  return array_unique($ids);
}

function mo_cms_get_vid_by_name($vocab_name) {
  $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
  return $vocab->vid;
}

/**
 * Get related content vocabulary VIDs and score values
 */
function mo_cms_get_related_content_vids() {
  $vids = array(
    'field_tags' => array(
      'value' => 1,
      'vids' => array(),
      'vocabulary_names' => array(
        'tags',
      ),
    ),
    'field_mo_cms_related_agencies' => array(
      'value' => 0.3,
      'vids' => array(),
      'vocabulary_names' => array(
        'mo_cms_agencies',
      ),
    ),
    'field_mo_cms_categories' => array(
      'value' => 0.2,
      'vids' => array(),
      'vocabulary_names' => array(
        'mo_cms_categories',
      ),
    ),
    'field_mo_cms_related_locations' => array(
      'value' => 0.5,
      'vids' => array(),
      'vocabulary_names' => array(
        'mo_cms_counties',
        'mo_cms_municipalities',
        'mo_cms_out_of_state_locations',
      ),
    ),
    'field_mo_cms_county_muni' => array(
      'value' => 0.5,
      'vids' => array(),
      'vocabulary_names' => array(
        'mo_cms_counties',
        'mo_cms_municipalities',
        'mo_cms_out_of_state_locations',
      ),
    ),
  );
  foreach ($vids as $field_name=>$data) {
    foreach ($data['vocabulary_names'] as $vocab_name) {
      $vids[$field_name]['vids'][] = mo_cms_get_vid_by_name($vocab_name);
    }
  }
  return $vids;
}

/**
 * Filter by related content score
 */
function mo_cms_filter_view_by_related_content_score($row) {
  parse_str($_SERVER['QUERY_STRING'], $args);
  $tags = array();
  if (!empty($args['categories'])) {
    $tags['field_mo_cms_categories'] = explode(',', $args['categories']);
  }
  if (!empty($args['agencies'])) {
    $tags['field_mo_cms_related_agencies'] = explode(',', $args['agencies']);
  }
  if (!empty($args['locations'])) {
    $tags['field_mo_cms_related_locations'] = explode(',', $args['locations']);
  }
  if (!empty($args['tags'])) {
    $tags['field_tags'] = explode(',', $args['tags']);
  }
  if (!empty($row->rendered_entity)) {
    mo_cms_score_item('file', $row->rendered_entity, $tags);
  }
  return TRUE;
}
