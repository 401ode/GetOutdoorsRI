<?php

$view = new view();
$view->name = 'mogov_dashboard_users';
$view->description = 'List of users and last login time';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Dashboard: Users';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Recent users';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['date_format'] = 'time ago';
$handler->display->display_options['fields']['access']['second_date_format'] = 'html5_tools_iso8601';
/* Sort criterion: User: Last access */
$handler->display->display_options['sorts']['access']['id'] = 'access';
$handler->display->display_options['sorts']['access']['table'] = 'users';
$handler->display->display_options['sorts']['access']['field'] = 'access';
$handler->display->display_options['sorts']['access']['order'] = 'DESC';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

/* Display: Content pane */
$handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
$handler->display->display_options['pane_title'] = 'Recent users';
$handler->display->display_options['pane_category']['name'] = 'Dashboard';
$handler->display->display_options['pane_category']['weight'] = '0';
$handler->display->display_options['inherit_panels_path'] = '1';
