<?php
/**
 *  @file mileage_hooks.inc
 *  @brief  Code to process edits to mileage nodes
 *
 *  @details 
 *  mo_project_node_delete = Update mileage node to 0 miles, recheck earned badges
 *  mo_project_node_update = Update mileage node fields, recheck earned and unearned badges
 */

 
/**
 *  @brief  Update mileage node to 0 miles, recheck earned badges
 *  
 *  @param [in] $node  mileage node entity
 *  @return  void
 *  
 *  @details  2013
 *            Edit 2014-03-17
 *  updated 2015-04-24  to add sub-user
 */ 
function mo_project_node_delete($node) {
  if ($node->type == 'mileage') {
    $subuser = field_get_items('node', $node, 'field_mileage_subuser');
    $suid = $subuser[0]['value'];
    $date_field = field_get_items('node', $node, 'field_mileage_date');
    if (!empty($date_field[0]['value'])) {
      $year = date('Y', strtotime($date_field[0]['value']));
    }
    
    // Zero out the mileage
    $distance = field_get_items('node', $node, 'field_mileage_distance'); 
    $query = db_update('field_data_field_mileage_distance');
    $query->fields(array('field_mileage_distance_value' => 0));
    $query->condition('entity_type', 'node');
    $query->condition('bundle', 'mileage');
    $query->condition('entity_id', $node->nid);
    $query->condition('revision_id', $node->vid);
    $query->execute();  

    // Get the earned badges and re-evaluate them
    $nids_delete = mo_project_get_earned_badges($node->uid, $suid, $year);
    mo_project_evaluate_badges($node->uid, $suid, $nids_delete, $year, 'delete');
  }
}


/**
 *  @brief  Update mileage node fields, recheck earned and unearned badges
 *  
 *  @param [in] $node  mileage node entity
 *  @return  void
 *  
 *  @details  2013
 *            Edit 2014-03-17
 *  updated 2014-04-28  to add sub-user
 */
function mo_project_node_update($node) {
  if ($node->type == 'mileage') {
    global $user;

    // We need to check both the old node (in the database) and the new (passed in)
    $original = node_load($node->nid);
    $orig_suid = $original->field_mileage_subuser_value[$original->language][0]['value'];
        $date_field1 = field_get_items('node', $original, 'field_mileage_date');    
        if (!empty($date_field1[0]['value'])) {
          $orig_year = date('Y', strtotime($date_field1[0]['value']));
          $orig_nids_write = mo_project_get_affected_badges($original);
          $orig_nids_delete = mo_project_get_earned_badges($original->uid, $orig_suid, $orig_year);
        }
        
    // Save the fields that might affect badges
    //sub-user
    $subuser = field_get_items('node', $node, 'field_mileage_subuser');
    $suid = $subuser[0]['value'];
    $query = db_update('field_data_field_mileage_subuser');
    $query->fields(array('field_mileage_subuser_value' => $suid));
    $query->condition('entity_type', 'node');
    $query->condition('bundle', 'mileage');
    $query->condition('entity_id', $node->nid);
    $query->condition('revision_id', $node->vid);
    $query->execute();
    
    //date
    $date_field2 = field_get_items('node', $node, 'field_mileage_date'); 
    $query = db_update('field_data_field_mileage_date');
    $query->fields(array('field_mileage_date_value' => $date_field2[0]['value']));
    $query->condition('entity_type', 'node');
    $query->condition('bundle', 'mileage');
    $query->condition('entity_id', $node->nid);
    $query->condition('revision_id', $node->vid);
    $query->execute();

    //activity  
    $activity = field_get_items('node', $node, 'field_mileage_activity'); 
    $query = db_update('field_data_field_mileage_activity');
    $query->fields(array('field_mileage_activity_tid' => $activity[0]['tid']));
    $query->condition('entity_type', 'node');
    $query->condition('bundle', 'mileage');
    $query->condition('entity_id', $node->nid);
    $query->condition('revision_id', $node->vid);
    $query->execute();
   
    //facility
    $facility = field_get_items('node', $node, 'field_mileage_facility');
    if (!empty($facility)) {
      $query = db_update('field_data_field_mileage_facility');
      $query->fields(array('field_mileage_facility_value' => $facility[0]['value']));
      $query->condition('entity_type', 'node');
      $query->condition('bundle', 'mileage');
      $query->condition('entity_id', $node->nid);
      $query->condition('revision_id', $node->vid);
      $query->execute();
    }

    //distance
    $distance = field_get_items('node', $node, 'field_mileage_distance'); 
    $query = db_update('field_data_field_mileage_distance');
    $query->fields(array('field_mileage_distance_value' => $distance[0]['value']));
    $query->condition('entity_type', 'node');
    $query->condition('bundle', 'mileage');
    $query->condition('entity_id', $node->nid);
    $query->condition('revision_id', $node->vid);
    $query->execute();  

    if (!empty($date_field2[0]['value'])) {
      $year = date('Y', strtotime($date_field2[0]['value']));
      $nids_write = mo_project_get_affected_badges($node);
      $nids_delete = mo_project_get_earned_badges($node->uid, $suid, $year);
    }
    
    if (!empty($orig_nids_write) and !empty($orig_year)) {
      mo_project_evaluate_badges($user->uid, $orig_suid, $orig_nids_write, $orig_year);
    }
    if (!empty($orig_nids_delete) and !empty($orig_year)) {
      mo_project_evaluate_badges($user->uid, $orig_suid, $orig_nids_delete, $orig_year, 'delete');
    }
    if (!empty($nids_write) and !empty($orig_year)) {
      mo_project_evaluate_badges($user->uid, $suid, $nids_write, $year);
    }
    if (!empty($nids_delete) and !empty($orig_year)) {
      mo_project_evaluate_badges($user->uid, $suid, $nids_delete, $year, 'delete');
    }
  }
}