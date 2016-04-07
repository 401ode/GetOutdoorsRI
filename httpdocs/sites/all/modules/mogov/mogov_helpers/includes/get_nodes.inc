<?php
/**
 * Get current node
 * Uses the current path to try to find the current node, if it exists.
 */
function mogov_helpers_get_current_node() {
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
 * Get a list of nids of published nodes based on content type.
 * If $nid is supplied, the returned list will not include the supplied nid.
 */
function mogov_helpers_get_nids_by_types($types, $nid=FALSE) {
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
 * Get an array of published nodes based on content type. If $nid is supplied,
 * the returned list will not include the supplied nid.
 */
function mogov_helpers_get_nodes_by_types($types, $nid=FALSE) {
  $nids = mogov_helpers_get_nids_by_types($types, $nid);
  $nodes = node_load($nids);
  return $nodes;
}
