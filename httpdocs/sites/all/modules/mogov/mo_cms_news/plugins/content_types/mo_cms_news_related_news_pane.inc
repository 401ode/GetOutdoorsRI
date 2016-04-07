<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('MO CMS: News - Related News'),
  'description' => t('A list of related news items'),
  'category' => t('MO CMS'),
  'edit form' => 'mo_cms_news_related_news_pane_edit_form',
  'render callback' => 'mo_cms_news_related_news_pane_render',
  'admin info' => 'mo_cms_news_related_news_pane_admin_info',
  'defaults' => array(
    'count' => '5',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mo_cms_news_related_news_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $default = '5';
  if (isset($conf['count'])) {
    $default = $conf['count'];
  }
 
  $form['count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items to display'),
    '#default_value' => $conf['count'],
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 3,
    '#maxlength' => 3,
  );
 
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mo_cms_news_related_news_pane_edit_form_submit(&$form, &$form_state) {
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
function mo_cms_news_related_news_pane_render($subtype, $conf, $args, $contexts) {
 
  $count = 5;
  if (!empty($conf['count']) and $conf['count']) {
    $count = $conf['count'];
  }
 
  $block = new stdClass();
 
  // initial content is blank
  $block->title = t('Recent News');
  $block->content = mo_cms_news_get_related_news_content($count);
 
  return $block;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_news_related_news_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : 'Related News';
    $block->content = mo_cms_news_get_related_news_content($conf['count']);
    return $block;
  }
}