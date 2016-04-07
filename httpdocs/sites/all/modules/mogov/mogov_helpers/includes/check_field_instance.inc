<?php

/**
 * For whatever reason, field_info_instance() completely fails for me. This tries to fill the gap.
 */
function check_field_instance($field_name, $entity_type, $bundle) {
  $query = db_select('field_config_instance', 'f');
  $query->addField('f', 'id');
  $query->condition('f.field_name', $field_name);
  $query->condition('f.entity_type', $entity_type);
  $query->condition('f.bundle', $bundle);
  $query->condition('f.deleted', 0);
  $result = $query->execute();
  if ($result->rowCount()) {
    return TRUE;
  }
  return FALSE;
}