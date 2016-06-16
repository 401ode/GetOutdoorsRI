<?php
/**
 * @file
 * mogov_foundations.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mogov_foundations_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: author.
  $roles['author'] = array(
    'name' => 'author',
    'weight' => 5,
  );

  // Exported role: designer.
  $roles['designer'] = array(
    'name' => 'designer',
    'weight' => 6,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: webmaster.
  $roles['webmaster'] = array(
    'name' => 'webmaster',
    'weight' => 3,
  );

  return $roles;
}
