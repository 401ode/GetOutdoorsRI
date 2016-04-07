<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Help links'),
  'description' => t('Links to various help pages, mostly on the ITSD wiki.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_help_links_pane_edit_form',
  'render callback' => 'mogov_dashboard_help_links_pane_render',
  'admin info' => 'mogov_dashboard_help_links_pane_admin_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_help_links_pane_edit_form($form, &$form_state) {
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_help_links_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_dashboard_help_links_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  $pane->title = t('Help');
  
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
    'attributes' => array(
      'target' => '_blank',
    ),
  );
  $links = array(
    'http://wiki.url/wiki/Managing_Content_in_Drupal' => 'Managing content in Drupal',
    'http://wiki.url/wiki/Style_Guide_for_Drupal_Editors' => 'Style Guide for Drupal Editors',
  );
  foreach ($links as $url=>$title) {
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'http://wiki.url/wiki/Managing_Content_in_Drupal', $link_options);
  }
  $pane->content = theme_item_list($list);
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_help_links_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Help links');
    $pane->content = '';
    return $pane;
  }
}