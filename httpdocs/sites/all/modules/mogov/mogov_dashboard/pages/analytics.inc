<?php

/**
 * Export code for mogov_dashboard page
 */

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'mogov_dashboard_analytics';
$page->task = 'page';
$page->admin_title = 'Dashboard: Analytics';
$page->admin_description = 'Temporary dashboard page for widgets that haven\'t been evaluated and/or don\'t have a home yet';
$page->path = 'admin/dashboard/analytics';
$page->access = array(
  'logic' => 'and',
);
$page->menu = array(
  'type' => 'tab',
  'title' => 'Analytics',
  'name' => 'navigation',
  'weight' => '3',
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
$handler->name = 'page_mogov_dashboard_analytics_panel_context';
$handler->task = 'page';
$handler->subtask = 'mogov_dashboard_analytics';
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
$display->layout = 'dashboard_alt1';
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
  ),
);
$display->cache = array();
$display->title = '%site_name:site:name Analytics';
$display->uuid = 'ecfbfcdb-8f10-4e93-ba7e-29661b66dd1f';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7cbfd2e5-6a3f-4f0f-83c1-bcf42178b719';
  $pane->panel = 'col1';
  $pane->type = 'google_analytics';
  $pane->subtype = 'google_analytics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'visits',
    'override_title' => 0,
    'override_title_text' => '',
    'color' => 'blue',
    'units' => 'days',
    'days' => '14',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7cbfd2e5-6a3f-4f0f-83c1-bcf42178b719';
  $display->content['new-7cbfd2e5-6a3f-4f0f-83c1-bcf42178b719'] = $pane;
  $display->panels['col1'][0] = 'new-7cbfd2e5-6a3f-4f0f-83c1-bcf42178b719';
  $pane = new stdClass();
  $pane->pid = 'new-5cb5a970-efd7-43f8-b61e-a2742f96ff1f';
  $pane->panel = 'col2_row1_col1';
  $pane->type = 'google_analytics';
  $pane->subtype = 'google_analytics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'pageviews',
    'override_title' => 0,
    'override_title_text' => '',
    'color' => 'green',
    'units' => 'days',
    'days' => '7',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5cb5a970-efd7-43f8-b61e-a2742f96ff1f';
  $display->content['new-5cb5a970-efd7-43f8-b61e-a2742f96ff1f'] = $pane;
  $display->panels['col2_row1_col1'][0] = 'new-5cb5a970-efd7-43f8-b61e-a2742f96ff1f';
  $pane = new stdClass();
  $pane->pid = 'new-0c4cb588-e087-4cc2-9d57-faca8fd8c8a0';
  $pane->panel = 'col2_row2_col1';
  $pane->type = 'google_analytics';
  $pane->subtype = 'google_analytics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'top_pages',
    'override_title' => 0,
    'override_title_text' => '',
    'color' => 'orange',
    'units' => 'days',
    'days' => '7',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0c4cb588-e087-4cc2-9d57-faca8fd8c8a0';
  $display->content['new-0c4cb588-e087-4cc2-9d57-faca8fd8c8a0'] = $pane;
  $display->panels['col2_row2_col1'][0] = 'new-0c4cb588-e087-4cc2-9d57-faca8fd8c8a0';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
