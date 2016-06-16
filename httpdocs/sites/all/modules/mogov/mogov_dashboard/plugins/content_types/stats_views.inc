<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Stats'),
  'description' => t('List of recently logged-in users.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_stats_views_pane_edit_form',
  'render callback' => 'mogov_dashboard_stats_views_pane_render',
  'admin info' => 'mogov_dashboard_stats_views_pane_admin_info',
  'defaults' => array(
    'type' => 'type1',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_stats_views_pane_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $default = 'type1';
  if (isset($conf['type'])) {
    $default = $conf['type'];
  }
  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Select display type'),
    '#options' => array(
      'type1' => t('Placeholder 1'),
      'type2' => t('Placeholder 2'),
      'type3' => t('Placeholder 3'),
      'type4' => t('Placeholder 4'),
    ),
    '#default_value' => $default,
  );

  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_stats_views_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_dashboard_stats_views_pane_render($subtype, $conf, $args, $contexts) {

  $pane = new stdClass();
  $pane->title = t('Stats');
  $pane->content = $conf['type'];
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_stats_views_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Stats: ' . $conf['type']);
    $pane->content = '';
    return $pane;
  }
}