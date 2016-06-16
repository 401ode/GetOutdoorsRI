<?php
/**
 * @file
 * mo_cms_news.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mo_cms_news_user_default_roles() {
  $roles = array();

  // Exported role: news contributor.
  $roles['news contributor'] = array(
    'name' => 'news contributor',
    'weight' => '7',
  );

  return $roles;
}
