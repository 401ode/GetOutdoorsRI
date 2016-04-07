<?php
/**
 * @file
 * mo_cms.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mo_cms_user_default_roles() {
  $roles = array();

  // Exported role: designer.
  $roles['designer'] = array(
    'name' => 'designer',
    'weight' => '6',
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '5',
  );

  // Exported role: publisher.
  $roles['publisher'] = array(
    'name' => 'publisher',
    'weight' => '4',
  );

  // Exported role: webmaster.
  $roles['webmaster'] = array(
    'name' => 'webmaster',
    'weight' => '3',
  );

  return $roles;
}
