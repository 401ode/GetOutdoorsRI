<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('File tools'),
  'description' => t('Link to add file, filename search field.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_file_tools_pane_edit_form',
  'render callback' => 'mogov_dashboard_file_tools_pane_render',
  'admin info' => 'mogov_dashboard_file_tools_pane_admin_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_file_tools_pane_edit_form($form, &$form_state) {
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_file_tools_pane_edit_form_submit(&$form, &$form_state) {
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
function mogov_dashboard_file_tools_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  $pane->title = t('Files');
  $content = '';
  
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
  if (user_access('create files') or user_access('administer files')) {
    $title = 'Add file';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'file/add', $link_options);
    $title = 'Manage files';
    $link_options['attributes']['title'] = $title;
    $list['items'][] = l($title, 'admin/content/file', $link_options);
  }
  if ($list['items']) {
    $content .= theme_item_list($list);
  }
  $content .= views_embed_view('mogov_dashboard_files', 'default');
  if ($content) {
    $pane->content = $content;
  } else {
    $pane->content = mogov_dashboard_no_permissions();
  }
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_file_tools_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('File tools');
    $pane->content = '';
    return $pane;
  }
}

function mo_dashboard_find_files_form() {
  $form = array(
    'filename' => array(
      '#type' => 'textfield',
      '#id' => 'find-file-filename',
      '#title' => t('Name'),
      '#autocomplete_path' => 'admin/dashboard/ajax/find-files-autocomplete',
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Search'),
      '#attributes' => array(
        'id' => 'find-file-submit',
      ),
    ),
  );
  return $form;
}

function mo_dashboard_find_files_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['filename'])) {
    drupal_goto('admin/content/file', array('query' => array('filename' => $form_state['values']['filename'])));
  }
}

function mo_dashboard_find_files_autocomplete($string) {
  if (strlen($string) < 3) {
    drupal_json_output(array());
    drupal_exit();
  }
  mogov_helpers_load('score_string_match');
  $string = strtolower($string);
  $matches = array();
  $scores = array();
  $titles = array();
  $query = db_select('file_managed', 'f');
  $query->condition('f.status', 0, '>');
  $query->addField('f', 'filename');
  $result = $query->execute();
  foreach ($result as $row) {
    if (in_array($row->filename, $titles)) {
      continue;
    }
    $titles[] = $row->filename;
    $score = mogov_helpers_score_string_match($string, strtolower($row->filename));
    if (!isset($scores[$score])) {
      $scores[$score] = array();
    }
    $scores[$score][] = $row->filename;
  }
  $score_keys = array_keys($scores);
  sort($score_keys);
  foreach ($score_keys as $score) {
    if ($score > 0 and count($matches) >= 5) {
      break;
    }
    $suggestions = $scores[$score];
    sort($suggestions);
    foreach ($suggestions as $suggestion) {
      if ($score > 0 and count($matches) >= 5) {
        break;
      }
      $matches[$suggestion] = $suggestion;
    }
  }
  drupal_json_output($matches);
}
