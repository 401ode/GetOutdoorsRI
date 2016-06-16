<?php
/**
 *  @file trailheads.inc
 *  @brief  Mass create trailhead field collection for trail nodes without one.
 *  Trails without at least one trailhead and coordinates will not display on the Find a Trail page.
 *  These functions will create a trailhead from the trail_facility, but the coordinates still need to be added manually.
 */

/**
 *  @brief  Add field collection 'field_trailheads' to an existing trail node
 *  
 *  @param [in] $node    node object of type 'trail'
 *  @param [in] $message field_trail_facility name
 *  @return  void
 *  
 *  @details  2014-05-29 
 */
function mo_project_helper_create_trailhead($node, $trailhead_name) {
  // Load the controller class file.
  module_load_include('inc', 'entity', 'includes/entity.controller');

  // Setup the values in the structure expected by the field_collection entity.
  $values = array(
    'field_name' => 'field_trailheads',
    'field_trailhead_name' => array(
      LANGUAGE_NONE => array(array('value' => $trailhead_name)),
    ),
  );
  $entity = entity_create('field_collection_item', $values);
  // Attach the field_collection entity to the application node. This has to
  // happen separately so that it actually works -- you can't just specify
  // this via the $values array.
  $entity->setHostEntity('node', $node);
  // Save the entity. Since it's attached to the right application node, this
  // will both create the field_collection entity and update the application
  // node to point to the new field_activity_log record.
  $entity->save();
  watchdog('helper_create_trailhead', 'Trailhead created for node %nodenid.', array('%nodenid' => $node->nid), WATCHDOG_INFO, $link = NULL);
}

/**
 *  @brief  Select trail nodes without trailheads and call mo_project_helper_create_trailhead function
 *  
 *  @return  void
 *  
 *  @details  2014-05-29 
 */
function mo_project_helper_get_trails_needing_trailheads() {
  // Get all trails with a facility that do not have a trailhead/geocode
  $query = db_select('node', 'n');
  $query->join('field_data_field_trail_facility', 'f', 'n.nid = f.entity_id AND (f.entity_type = :type1 AND f.deleted = :deleted1)', array(':type1' => 'node', ':deleted1' => 0));
  $query->join('taxonomy_term_data', 'x', 'f.field_trail_facility_tid = x.tid');
  $query->leftJoin('field_data_field_trailheads', 't', 'n.nid = t.entity_id AND (t.entity_type = :type2 AND t.deleted = :deleted2)', array(':type2' => 'node', ':deleted2' => 0)); 
  $query->fields('n', array('nid'));
  $query->fields('x', array('name'));  
  $query->condition('n.type', 'trail', '=');
  $query->condition('n.status', 0, '<>');
  $query->isNull('t.field_trailheads_value');

  $result = $query->execute();
// For debugging
//  $r_count = $result->rowCount();  
//  watchdog('helper_get_trails', 'Query ran, returned %rows results.', array('%rows' => $r_count), WATCHDOG_INFO, $link = NULL);
//  $q_string = mo_cms_show_sql($query);
//  watchdog('helper_get_trails', $q_string, array(), WATCHDOG_INFO, $link = NULL);

  foreach ($result as $record) {
    // Get node object
    $node = node_load($record->nid);
    
    // Create trailhead
    mo_project_helper_create_trailhead($node, $record->name);
  } 
}
?>