<?php

/**
 * Export code for mogov_dashboard page
 */

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'mogov_dashboard';
$page->task = 'page';
$page->admin_title = 'Dashboard';
$page->admin_description = 'Dashboard for content managers and webmasters.';
$page->path = 'admin/dashboard/default';
$page->access = array(
  'logic' => 'and',
);
$page->menu = array(
  'type' => 'default tab',
  'title' => 'Main',
  'name' => 'navigation',
  'weight' => '0',
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
$handler->name = 'page_mogov_dashboard_panel_context';
$handler->task = 'page';
$handler->subtask = 'mogov_dashboard';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 1,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => 'mogov-dashboard',
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
$display->layout = 'dashboard_main';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'row1_col1' => NULL,
    'row1_col2' => NULL,
    'row2_col1' => NULL,
    'row2_col2' => NULL,
    'row2_col3' => NULL,
    'col1' => NULL,
    'col2_row1_col1' => NULL,
    'col2_row1_col2' => NULL,
    'col2_row2_col1' => NULL,
    'col2_row3_col1' => NULL,
    'col2_row3_col2' => NULL,
    'col2_row2_col2' => NULL,
  ),
);
$display->cache = array();
$display->title = '%site_name:site:name Dashboard';
$display->uuid = '40b5053a-fcdd-481b-a07c-828531325f3e';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bc5d0ba3-f504-4237-af19-5e57521fbce9';
  $pane->panel = 'col1';
  $pane->type = 'create_content';
  $pane->subtype = 'create_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bc5d0ba3-f504-4237-af19-5e57521fbce9';
  $display->content['new-bc5d0ba3-f504-4237-af19-5e57521fbce9'] = $pane;
  $display->panels['col1'][0] = 'new-bc5d0ba3-f504-4237-af19-5e57521fbce9';
  $pane = new stdClass();
  $pane->pid = 'new-a3e68fff-4516-41bc-9df9-a65735f4e582';
  $pane->panel = 'col1';
  $pane->type = 'landing_pages';
  $pane->subtype = 'landing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a3e68fff-4516-41bc-9df9-a65735f4e582';
  $display->content['new-a3e68fff-4516-41bc-9df9-a65735f4e582'] = $pane;
  $display->panels['col1'][1] = 'new-a3e68fff-4516-41bc-9df9-a65735f4e582';
  $pane = new stdClass();
  $pane->pid = 'new-e5e865f7-28ba-44c2-9b31-d359c9eaed20';
  $pane->panel = 'col1';
  $pane->type = 'manage_advanced_content';
  $pane->subtype = 'manage_advanced_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e5e865f7-28ba-44c2-9b31-d359c9eaed20';
  $display->content['new-e5e865f7-28ba-44c2-9b31-d359c9eaed20'] = $pane;
  $display->panels['col1'][2] = 'new-e5e865f7-28ba-44c2-9b31-d359c9eaed20';
  $pane = new stdClass();
  $pane->pid = 'new-88740a70-dc7d-4159-bc4a-3bed3888a4c0';
  $pane->panel = 'col2_row1_col1';
  $pane->type = 'views_panes';
  $pane->subtype = 'mogov_dashboard_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '88740a70-dc7d-4159-bc4a-3bed3888a4c0';
  $display->content['new-88740a70-dc7d-4159-bc4a-3bed3888a4c0'] = $pane;
  $display->panels['col2_row1_col1'][0] = 'new-88740a70-dc7d-4159-bc4a-3bed3888a4c0';
  $pane = new stdClass();
  $pane->pid = 'new-336eba0f-ee19-4b96-af4e-ebf39a90be11';
  $pane->panel = 'col2_row1_col1';
  $pane->type = 'file_tools';
  $pane->subtype = 'file_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '336eba0f-ee19-4b96-af4e-ebf39a90be11';
  $display->content['new-336eba0f-ee19-4b96-af4e-ebf39a90be11'] = $pane;
  $display->panels['col2_row1_col1'][1] = 'new-336eba0f-ee19-4b96-af4e-ebf39a90be11';
  $pane = new stdClass();
  $pane->pid = 'new-a3ae947b-5e52-436e-a068-38fa720d9d26';
  $pane->panel = 'col2_row2_col1';
  $pane->type = 'admin_tools';
  $pane->subtype = 'admin_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3ae947b-5e52-436e-a068-38fa720d9d26';
  $display->content['new-a3ae947b-5e52-436e-a068-38fa720d9d26'] = $pane;
  $display->panels['col2_row2_col1'][0] = 'new-a3ae947b-5e52-436e-a068-38fa720d9d26';
  $pane = new stdClass();
  $pane->pid = 'new-d8bf5246-2049-4fe4-b9f9-e320415fa884';
  $pane->panel = 'col2_row2_col2';
  $pane->type = 'views_panes';
  $pane->subtype = 'mogov_dashboard_users-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd8bf5246-2049-4fe4-b9f9-e320415fa884';
  $display->content['new-d8bf5246-2049-4fe4-b9f9-e320415fa884'] = $pane;
  $display->panels['col2_row2_col2'][0] = 'new-d8bf5246-2049-4fe4-b9f9-e320415fa884';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
