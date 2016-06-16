<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Recent News'),
  'description' => t('A list of recent news items'),
  'category' => t('Site: all'),
  'edit form' => 'mogov_news_recent_news_pane_edit_form',
  'render callback' => 'mogov_news_recent_news_pane_render',
  'admin info' => 'mogov_news_recent_news_pane_admin_info',
  'defaults' => array(
    'count' => '5',
    'include_links' => TRUE,
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_news_recent_news_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
 
  $form['count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items to display'),
    '#default_value' => $conf['count'],
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 3,
    '#maxlength' => 3,
  );
 
  $form['include_links'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Include "News Release Link" nodes'),
  );
 
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_news_recent_news_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_news_recent_news_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
 
  // initial content is blank
  $pane->title = t('Recent News');
  $pane->content = mogov_news_get_recent_news_content($conf['count'], $conf['include_links']);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_news_recent_news_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : 'Recent News';
    $pane->content = mogov_news_get_recent_news_content($conf['count'], $conf['include_links']);
    return $pane;
  }
}