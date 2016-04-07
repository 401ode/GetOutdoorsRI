<?php

/**
 * Export code for mogov_dashboard page
 */

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'mogov_dashboard_history';
$page->task = 'page';
$page->admin_title = 'Dashboard: History';
$page->admin_description = 'Dashboard page displaying revision history';
$page->path = 'admin/dashboard/history';
$page->access = array(
  'logic' => 'and',
);
$page->menu = array(
  'type' => 'tab',
  'title' => 'History',
  'name' => 'navigation',
  'weight' => '2',
  'parent' => array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
  ),
);
$page->arguments = array();
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_mogov_dashboard_history_panel_context';
$handler->task = 'page';
$handler->subtask = 'mogov_dashboard_history';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(
    0 => array(
      'identifier' => 'Site Name',
      'keyword' => 'site_name',
      'name' => 'token',
      'id' => 1,
    ),
  ),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'col1' => NULL,
    'col2_row1_col1' => NULL,
    'col2_row1_col2' => NULL,
    'col2_row2_col1' => NULL,
    'col2_row3_col1' => NULL,
    'col2_row3_col2' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = '%site_name:site:name History';
$display->uuid = 'ecfbfcdb-8f10-4e93-ba7e-29661b66dd1f';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-acb8da73-b4b6-4ea5-aa3b-15a2527ca062';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'mogov_dashboard_revisions-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'acb8da73-b4b6-4ea5-aa3b-15a2527ca062';
  $display->content['new-acb8da73-b4b6-4ea5-aa3b-15a2527ca062'] = $pane;
  $display->panels['middle'][0] = 'new-acb8da73-b4b6-4ea5-aa3b-15a2527ca062';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
