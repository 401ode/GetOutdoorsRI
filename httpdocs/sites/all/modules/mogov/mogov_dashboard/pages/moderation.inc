<?php

/**
 * Export code for mogov_dashboard page
 */

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'mogov_dashboard_moderation';
$page->task = 'page';
$page->admin_title = 'Dashboard: Moderation';
$page->admin_description = 'Dashboard page displaying revision history';
$page->path = 'admin/dashboard/moderation';
$page->access = array(
  'logic' => 'and',
  'plugins' => array(
    0 => array(
      'name' => 'role',
      'settings' => array(
        'rids' => array(
          0 => 3,
          1 => 5,
          2 => 6,
          3 => 10,
        ),
      ),
      'context' => 'logged-in-user',
      'not' => FALSE,
    ),
  ),
);
$page->menu = array(
  'type' => 'tab',
  'title' => 'Moderation',
  'name' => 'navigation',
  'weight' => '1',
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
$handler->name = 'page_mogov_dashboard_moderation__panel_context_d85dffff-1bd7-4485-9782-eb46e5458c68';
$handler->task = 'page';
$handler->subtask = 'mogov_dashboard_moderation';
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
$display->title = '%site_name:site:name Moderation';
$display->uuid = 'ecfbfcdb-8f10-4e93-ba7e-29661b66dd1f';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c2dbf0d3-7389-4d37-8294-d78fb7897f50';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'workbench_moderation';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'use workbench_moderation my drafts tab',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'drafts_page',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c2dbf0d3-7389-4d37-8294-d78fb7897f50';
  $display->content['new-c2dbf0d3-7389-4d37-8294-d78fb7897f50'] = $pane;
  $display->panels['middle'][0] = 'new-c2dbf0d3-7389-4d37-8294-d78fb7897f50';
  $pane = new stdClass();
  $pane->pid = 'new-e46b8489-0285-4147-8e54-5a047feaa318';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'workbench_moderation';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'use workbench_moderation needs review tab',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'needs_review_page',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e46b8489-0285-4147-8e54-5a047feaa318';
  $display->content['new-e46b8489-0285-4147-8e54-5a047feaa318'] = $pane;
  $display->panels['middle'][1] = 'new-e46b8489-0285-4147-8e54-5a047feaa318';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
