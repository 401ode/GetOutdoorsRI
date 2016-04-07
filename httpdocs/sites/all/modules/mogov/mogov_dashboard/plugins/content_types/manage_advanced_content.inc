<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Manage advanced content'),
  'description' => t('Links to management pages for complex content such as sliders, tab sets, and minipanels.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_manage_advanced_content_pane_edit_form',
  'render callback' => 'mogov_dashboard_manage_advanced_content_pane_render',
  'admin info' => 'mogov_dashboard_manage_advanced_content_pane_admin_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_manage_advanced_content_pane_edit_form($form, &$form_state) {
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_manage_advanced_content_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_dashboard_manage_advanced_content_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  $pane->title = t('Manage advanced content');
  
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
  if (user_access('create mini panels') or user_access('administer mini panels')) {
    $title = 'Mini panels';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/structure/mini-panels', $link_options);
  }
  if (user_access('administer sliders')) {
    $title = 'Sliders';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/structure/mogov-sliders', $link_options);
  }
  if (user_access('administer tab sets')) {
    $title = 'Tab sets';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/structure/mogov-tabs', $link_options);
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
function mogov_dashboard_manage_advanced_content_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Manage advanced content');
    $pane->content = '';
    return $pane;
  }
}