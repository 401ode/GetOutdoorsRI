<?php
/**
 * @file
 * mogov_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mogov_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mogov_news_releases';
  $view->description = 'An archive view of news releases, filterable by year';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Releases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News Releases';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['id'] = 'field_mogov_news_remote_url';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['table'] = 'field_data_field_mogov_news_remote_url';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['field'] = 'field_mogov_news_remote_url';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['label'] = '';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['empty'] = '[path]';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_mogov_news_remote_url']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_mogov_news_remote_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_mogov_news_date']['id'] = 'field_mogov_news_date';
  $handler->display->display_options['fields']['field_mogov_news_date']['table'] = 'field_data_field_mogov_news_date';
  $handler->display->display_options['fields']['field_mogov_news_date']['field'] = 'field_mogov_news_date';
  $handler->display->display_options['fields']['field_mogov_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Remote Source */
  $handler->display->display_options['fields']['field_mogov_news_remote_source']['id'] = 'field_mogov_news_remote_source';
  $handler->display->display_options['fields']['field_mogov_news_remote_source']['table'] = 'field_data_field_mogov_news_remote_source';
  $handler->display->display_options['fields']['field_mogov_news_remote_source']['field'] = 'field_mogov_news_remote_source';
  $handler->display->display_options['fields']['field_mogov_news_remote_source']['empty'] = 'Ferguson Commission';
  $handler->display->display_options['fields']['field_mogov_news_remote_source']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Date (field_mogov_news_date) */
  $handler->display->display_options['sorts']['field_mogov_news_date_value']['id'] = 'field_mogov_news_date_value';
  $handler->display->display_options['sorts']['field_mogov_news_date_value']['table'] = 'field_data_field_mogov_news_date';
  $handler->display->display_options['sorts']['field_mogov_news_date_value']['field'] = 'field_mogov_news_date_value';
  $handler->display->display_options['sorts']['field_mogov_news_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mogov_news_release' => 'mogov_news_release',
    'mogov_news_release_link' => 'mogov_news_release_link',
  );
  /* Filter criterion: Content: Date (field_mogov_news_date) */
  $handler->display->display_options['filters']['field_mogov_news_date_value']['id'] = 'field_mogov_news_date_value';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['table'] = 'field_data_field_mogov_news_date';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['field'] = 'field_mogov_news_date_value';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mogov_news_date_value']['expose']['operator_id'] = 'field_mogov_news_date_value_op';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['expose']['operator'] = 'field_mogov_news_date_value_op';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['expose']['identifier'] = 'field_mogov_news_date_value';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_mogov_news_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_mogov_news_date_value']['year_range'] = '2014:+0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'newsroom/news-archive';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $export['mogov_news_releases'] = $view;

  return $export;
}
