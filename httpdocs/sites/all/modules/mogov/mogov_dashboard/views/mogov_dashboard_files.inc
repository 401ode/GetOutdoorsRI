<?php

$view = new view();
$view->name = 'mogov_dashboard_files';
$view->description = 'Searchable file list with condensed display';
$view->tag = 'default';
$view->base_table = 'file_managed';
$view->human_name = 'Dashboard: Files';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Files';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'create files';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'filename' => 'filename',
  'type' => 'type',
  'timestamp' => 'timestamp',
);
$handler->display->display_options['style_options']['default'] = 'timestamp';
$handler->display->display_options['style_options']['info'] = array(
  'filename' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'timestamp' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = FALSE;
/* Field: File: Name */
$handler->display->display_options['fields']['filename']['id'] = 'filename';
$handler->display->display_options['fields']['filename']['table'] = 'file_managed';
$handler->display->display_options['fields']['filename']['field'] = 'filename';
$handler->display->display_options['fields']['filename']['label'] = 'Filename';
$handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
/* Field: File: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'file_managed';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['machine_name'] = 0;
/* Field: File: Upload date */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = 'Uploaded';
$handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
$handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
/* Sort criterion: File: Upload date */
$handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
$handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
/* Filter criterion: File: Name */
$handler->display->display_options['filters']['filename']['id'] = 'filename';
$handler->display->display_options['filters']['filename']['table'] = 'file_managed';
$handler->display->display_options['filters']['filename']['field'] = 'filename';
$handler->display->display_options['filters']['filename']['operator'] = 'contains';
$handler->display->display_options['filters']['filename']['exposed'] = TRUE;
$handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
$handler->display->display_options['filters']['filename']['expose']['label'] = 'Quick search';
$handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
$handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
$handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  10 => 0,
  11 => 0,
  8 => 0,
  6 => 0,
  7 => 0,
  9 => 0,
);
