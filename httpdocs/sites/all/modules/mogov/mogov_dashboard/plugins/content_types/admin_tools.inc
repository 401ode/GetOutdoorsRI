<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Administrative tools'),
  'description' => t('Links to admin pages for taxonomy, menus, redirects, etc.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_admin_tools_pane_edit_form',
  'render callback' => 'mogov_dashboard_admin_tools_pane_render',
  'admin info' => 'mogov_dashboard_admin_tools_pane_admin_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_admin_tools_pane_edit_form($form, &$form_state) {
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_admin_tools_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the pane
 * See ctools_plugin_examples for more advanced info
 */
function mogov_dashboard_admin_tools_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  $pane->title = t('Tools');
  global $user;
  
  $list = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'class' => array(
        'admin-list',
      ),
    ),
    'items' => array(),
  );
  $link_options = array(
    'attributes' => array(),
  );
  if (user_access('create url aliases') or user_access('administer url aliases')) {
    $title = 'Aliases';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/config/search/path', $link_options);
  }
  if (user_access('administer blocks')) {
    $title = 'Blocks';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/structure/block', $link_options);
  }
  $title = 'Broken links';
  $link_options['attributes']['title'] = $title;
  if (user_access('access broken links report')) {
    $list['items'][] = l($title, 'admin/reports/linkchecker', $link_options);
  } elseif ('access own broken links report') {
    $list['items'][] = l($title, 'user/' . $user->uid . '/linkchecker', $link_options);
  }
  if (user_access('administer menu')) {
    $title = 'Menus';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/structure/menu', $link_options);
  }
  if (user_access('administer redirects')) {
    $title = 'Redirections';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/configure/search/redirect', $link_options);
  }
  if (user_access('administer social media accounts')) {
    $title = 'Social media accounts';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/config/mogov/social', $link_options);
  }
  $perms = array(
    'administer taxonomy',
  );
  $vocabularies = taxonomy_get_vocabularies();
  foreach (array_keys($vocabularies) as $vid) {
    $perms[] = 'edit terms in ' . $vid;
    $perms[] = 'delete terms in ' . $vid;
  }
  foreach ($perms as $perm) {
    if (user_access($perm)) {
      $title = 'Taxonomy';
      $link_options['attributes']['title'] = $title;
      $list['items'][] = l($title, 'admin/structure/taxonomy', $link_options);
      break;
    }
  }
  if ($list['items']) {
    $pane->content = theme_item_list($list);
  } else {
    $pane->content = mogov_dashboard_no_permissions();
  }
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_admin_tools_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Admin tools');
    $pane->content = '';
    return $pane;
  }
}