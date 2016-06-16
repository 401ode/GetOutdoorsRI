<?php
/**
 * @file
 * mo_cms_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mo_cms_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mo_cms_events_calendars';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'MO CMS: Events Calendars';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['id'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['field'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['delta_offset'] = '0';
  /* Sort criterion: Content: Dates -  start date (field_mo_cms_event_dates) */
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['id'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['field'] = 'field_mo_cms_event_dates_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $handler->display->display_options['path'] = 'events/calendar/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $handler->display->display_options['path'] = 'events/calendar/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $handler->display->display_options['path'] = 'events/calendar/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['id'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['field'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['label'] = '';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $handler->display->display_options['path'] = 'events/calendar/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );

  /* Display: iCal */
  $handler = $view->new_display('feed', 'iCal', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $handler->display->display_options['path'] = 'events/ical/%/calendar.ics';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'page_1' => 'page_1',
    'page_2' => 'page_2',
    'page_3' => 'page_3',
    'block_1' => 'block_1',
    'block_2' => 'block_2',
    'default' => 0,
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value' => 'field_data_field_mo_cms_event_dates.field_mo_cms_event_dates_value',
  );
  $export['mo_cms_events_calendars'] = $view;

  $view = new view();
  $view->name = 'mo_cms_events_lists';
  $view->description = 'List views of MO CMS: Event nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MO CMS: Events Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_geofield_distance' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '',
        'bef_slider_max' => '',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_mo_cms_event_type_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'raw_html';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_geofield_distance' => 'field_geofield_distance',
    'field_mo_cms_event_dates' => 'field_mo_cms_event_dates',
    'title' => 'title',
    'field_mo_cms_postal_address' => 'field_mo_cms_postal_address',
    'field_mo_cms_event_type' => 'field_mo_cms_event_type',
  );
  $handler->display->display_options['style_options']['default'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['style_options']['info'] = array(
    'field_geofield_distance' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mo_cms_event_dates' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mo_cms_postal_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mo_cms_event_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Found @total results.';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>We\'re sorry, we were unable to find any events that meet your criteria.</p>

<p>You may want to explore these additional resources:</p>
<ul>
<li><a href="http://www.visitmo.com/search-results.aspx">Missouri Division of Tourism</a></li> 
<li><a href="http://search.active.com/search?v=list&f=activities&l=Jefferson%20City,%20MO,%20US&m=meta:endDate:daterange:today..">Active.com</a></li>
<li><a href="http://www.getsetusa.com/missouri/calendar.php">GetSetMO.com</a></li>
<li><a href="http://http://www.race360.com">RACE 360</a></li>
<li><a href="http://runningintheusa.com/Race/List.aspx?State=MO">Running in the USA</a></li>
<li><a href="http://www.usacycling.org/events/?state=MO">USA Cycling</a></li>
<li><a href="https://www.actha.us/events">American Competitive Trail Horse Association</a></li>
<li><a href="http://kayakmo.com/kayakmo/calendar.php">Kayak MO!</a></li>
</ul>';
  $handler->display->display_options['empty']['area']['format'] = 'raw_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Event Types';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'mo_cms_event_types' => 'mo_cms_event_types',
    'mo_gov_taxonomy' => 0,
    'mo_cms_contact_lists' => 0,
    'mo_gov_counties' => 0,
    'tags' => 0,
    'workbench_sections' => 0,
  );
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['id'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['field'] = 'field_mo_cms_event_dates';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['label'] = 'Date';
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mo_cms_event_dates']['settings'] = array(
    'format_type' => 'numeric_with_',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['id'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['table'] = 'field_data_field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['field'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['label'] = 'Location';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['type'] = 'addressfield_citystate';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['settings'] = array(
    'components' => array(
      'thoroughfare' => 'thoroughfare',
      'premise' => 'premise',
      'locality' => 'locality',
      'administrative_area' => 'administrative_area',
      'postal_code' => 'postal_code',
      'country' => 'country',
    ),
    'separator' => ', ',
  );
  /* Sort criterion: Content: Dates -  start date (field_mo_cms_event_dates) */
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['id'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['field'] = 'field_mo_cms_event_dates_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mo_cms_event' => 'mo_cms_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Dates - end date (field_mo_cms_event_dates:value2) */
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['id'] = 'field_mo_cms_event_dates_value2';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['field'] = 'field_mo_cms_event_dates_value2';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value2']['year_range'] = '-0:+3';
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Event Type';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    14 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    16 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'mo_cms_event_types';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    14 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    16 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_mo_cms_event_type' => 'field_mo_cms_event_type',
    'body' => 'body',
  );
  /* Filter criterion: Content: Dates -  start date (field_mo_cms_event_dates) */
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['id'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['field'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['group'] = 1;
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['expose']['operator_id'] = 'field_mo_cms_event_dates_value_op';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['expose']['label'] = 'Starts On or After';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['expose']['operator'] = 'field_mo_cms_event_dates_value_op';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['expose']['identifier'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    14 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    16 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
    13 => 0,
    15 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_mo_cms_event_dates_value']['year_range'] = '-0:+3';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Dates -  start date (field_mo_cms_event_dates) */
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['id'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['table'] = 'field_data_field_mo_cms_event_dates';
  $handler->display->display_options['sorts']['field_mo_cms_event_dates_value']['field'] = 'field_mo_cms_event_dates_value';
  $handler->display->display_options['block_description'] = 'MO CMS Events: Upcoming Events';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['mo_cms_events_lists'] = $view;

  return $export;
}
