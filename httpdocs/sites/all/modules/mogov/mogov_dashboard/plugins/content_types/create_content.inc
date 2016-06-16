<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Create content'),
  'description' => t('"Add" links for content types the user has permission to create nodes for.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_create_content_pane_edit_form',
  'render callback' => 'mogov_dashboard_create_content_pane_render',
  'admin info' => 'mogov_dashboard_create_content_pane_admin_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_create_content_pane_edit_form($form, &$form_state) {
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_create_content_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_dashboard_create_content_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  $pane->title = t('Create content');
  $links = mogov_dashboard_create_content_links();
  if ($links) {
    $pane->content = $links;
    $tooltip_script = 'jQuery("#dashboard-create-content [title!=\'\']").qtip({
      style: {
        classes: "qtip-light qtip-shadow",
      },
    });';
    drupal_add_css('sites/all/libraries/qtip2/jquery.qtip.min.css');
    drupal_add_js('sites/all/libraries/qtip2/jquery.qtip.min.js', array('type' => 'file', 'scope' => 'footer'));
    drupal_add_js($tooltip_script, array('type' => 'inline', 'scope' => 'footer'));
  } else {
    $pane->content = mogov_dashboard_no_permissions();
  }
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_create_content_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Create content');
    $links = mogov_dashboard_create_content_links();
    if ($links) {
      $pane->content = $links;
    } else {
      $pane->content = t('Create content links');
    }
    return $pane;
  }
}

/**
 * Create content links
 */
function mogov_dashboard_create_content_links() {
  $allowed_types = mogov_dashboard_creatable_content_types_list();
  $list = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(
      'id' => 'dashboard-create-content',
      'class' => array(
        'admin-list',
      ),
    ),
    'items' => array(),
  );
  $link_options = array(
    'attributes' => array(),
  );
  foreach ($allowed_types as $name=>$type) {
    $path = t('node/add/' . str_replace('_', '-', $type->type));
    $link_options['attributes']['title'] = $type->description;
    $list['items'][] = t(l($name, $path, $link_options));
  }
  if ($list['items']) {
    return theme_item_list($list);
  }
  return FALSE;
}

/**
 * Content type list
 */
function mogov_dashboard_creatable_content_types_list() {
  $allowed_types = array();
  $content_types = node_type_get_types();
  foreach ($content_types as $machine_name=>$content_type) {
    if (node_access('create', $machine_name)) {
      $allowed_types[$content_type->name] = $content_type;
    }
  }
  ksort($allowed_types);
  return $allowed_types;
}