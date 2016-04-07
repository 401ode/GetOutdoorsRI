<?php
/**
 * @file
 * mo_cms_user_groups.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mo_cms_user_groups_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'administration_groups_moderation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administration: User Groups Moderation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Groups Moderation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    12 => '12',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_mo_cms_event_dates' => 'field_mo_cms_event_dates',
    'field_mo_cms_event_type' => 'field_mo_cms_event_type',
    'body' => 'body',
    'field_mo_cms_postal_address' => 'field_mo_cms_postal_address',
    'field_mo_cms_event_website' => 'field_mo_cms_event_website',
    'changed' => 'changed',
    'state' => 'state',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
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
    'field_mo_cms_event_dates' => array(
      'sortable' => 1,
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
    'body' => array(
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
    'field_mo_cms_event_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Owner(s) */
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['id'] = 'field_mo_cms_user_groups_owners';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['table'] = 'field_data_field_mo_cms_user_groups_owners';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['field'] = 'field_mo_cms_user_groups_owners';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_owners']['multi_type'] = 'ul';
  /* Field: Content: Membership */
  $handler->display->display_options['fields']['field_mo_cms_user_groups_join']['id'] = 'field_mo_cms_user_groups_join';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_join']['table'] = 'field_data_field_mo_cms_user_groups_join';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_join']['field'] = 'field_mo_cms_user_groups_join';
  /* Field: Content: Visibility */
  $handler->display->display_options['fields']['field_mo_cms_user_groups_vis']['id'] = 'field_mo_cms_user_groups_vis';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_vis']['table'] = 'field_data_field_mo_cms_user_groups_vis';
  $handler->display->display_options['fields']['field_mo_cms_user_groups_vis']['field'] = 'field_mo_cms_user_groups_vis';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Submitted';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mo_cms_user_group' => 'mo_cms_user_group',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['path'] = 'admin/groups';
  $export['administration_groups_moderation'] = $view;

  $view = new view();
  $view->name = 'mo_cms_user_groups_directory';
  $view->description = 'Display listing of all publically-viewable user groups';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MO CMS: User Groups Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'MO CMS: User Groups Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_trail_activity' => 'field_trail_activity',
    'field_mo_cms_postal_address' => 'field_mo_cms_postal_address',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trail_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mo_cms_postal_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results were found; please broaden the parameters of your search.';
  $handler->display->display_options['empty']['area']['format'] = 'raw_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Activities */
  $handler->display->display_options['fields']['field_trail_activity']['id'] = 'field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['table'] = 'field_data_field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['field'] = 'field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_trail_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trail_activity']['multi_type'] = 'ul';
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['id'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['table'] = 'field_data_field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['field'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['label'] = 'Location';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['alter']['text'] = '[field_mo_cms_postal_address-locality]';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['settings'] = array(
    'components' => array(
      'locality' => 'locality',
    ),
    'separator' => ', ',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'mo_cms_user_group' => 'mo_cms_user_group',
  );
  /* Filter criterion: Content: Visibility (field_mo_cms_user_groups_vis) */
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['id'] = 'field_mo_cms_user_groups_vis_value';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['table'] = 'field_data_field_mo_cms_user_groups_vis';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['field'] = 'field_mo_cms_user_groups_vis_value';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['value'] = array(
    'visible' => 'visible',
  );

  /* Display: Directory Page */
  $handler = $view->new_display('page', 'Directory Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Directory';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Request Group';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php global $user; ?>
<?php if ($user->uid): ?>
<form method="link" action="/groups/create">
<input id="request-group" class="form-submit" type="submit" value="Request a New Group">
</form>
<?php else: ?>
<a href="/user/login">Login</a> or <a href="/user/register">Register</a> to join or request groups!
<?php endif; ?>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Clubs, Groups, Organizations and Teams</h2>
<p>Share your journey and compare your progress with others by joining one or more of these user groups!</p>';
  $handler->display->display_options['header']['area']['format'] = 'raw_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<em>@total total groups</em>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Group Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['id'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['table'] = 'field_data_field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['field'] = 'field_mo_cms_postal_address';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['label'] = 'Location';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['alter']['text'] = '[field_mo_cms_postal_address-locality]';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['type'] = 'addressfield_components';
  $handler->display->display_options['fields']['field_mo_cms_postal_address']['settings'] = array(
    'components' => array(
      'locality' => 'locality',
    ),
    'separator' => ', ',
  );
  /* Field: Content: Activities */
  $handler->display->display_options['fields']['field_trail_activity']['id'] = 'field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['table'] = 'field_data_field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['field'] = 'field_trail_activity';
  $handler->display->display_options['fields']['field_trail_activity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_trail_activity']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trail_activity']['multi_type'] = 'ul';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Members';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$result = db_select(\'mo_cms_user_groups_membership\', \'g\');
$result->addExpression(\'COUNT(row_id)\', \'node_count\');
$result->condition(\'entity_id\', $data->nid, \'=\');
$result->condition(\'deleted\', 0, \'=\');
$value = $result->execute()->fetchField();
return $value;';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Miles';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$q_users = db_select(\'mo_cms_user_groups_membership\', \'g\');
$q_users->fields(\'g\', array(\'uid\'));
$q_users->condition(\'entity_id\', $data->nid, \'=\');
$group_users = $q_users->execute()->fetchCol();
if (count($group_users) == 0) {
     $value = "0.00";
}

$q_activities = db_select(\'field_data_field_trail_activity\', \'f\');
$q_activities->fields(\'f\', array(\'field_trail_activity_tid\'));
$q_activities->condition(\'entity_id\', $data->nid, \'=\');
$group_activities = $q_activities->execute()->fetchCol();

$result = db_select(\'field_data_field_mileage_distance\', \'d\');
$result->join(\'field_data_field_mileage_date\', \'dt\', \'d.entity_id = dt.entity_id\');
$result->join(\'node\', \'n\', \'d.entity_id = n.nid\');
$result->addExpression(\'ROUND(SUM(d.field_mileage_distance_value), 2)\', \'distance\');
$result->condition(\'n.uid\', $group_users, \'IN\');
$result->condition(\'dt.field_mileage_date_value\', \'2013-06-01 00:00:00\', \'>=\');
$result->condition(\'dt.field_mileage_date_value\', \'2014-01-01 00:00:00\', \'<\');

if (count($group_activities) != 0) {
     $result->join(\'field_data_field_mileage_activity\', \'a\', \'d.entity_id = a.entity_id\');
     $result->join(\'taxonomy_term_data\', \'t\', \'a.field_mileage_activity_tid = t.tid\');
     $result->condition(\'a.field_mileage_activity_tid\', $group_activities, \'IN\');
}
if (!isset($value)) {
     $value = $result->execute()->fetchField();
     if (!isset($value)) {
          $value = "0.00";
     }
}
return $value;';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'mo_cms_user_group' => 'mo_cms_user_group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Visibility (field_mo_cms_user_groups_vis) */
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['id'] = 'field_mo_cms_user_groups_vis_value';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['table'] = 'field_data_field_mo_cms_user_groups_vis';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['field'] = 'field_mo_cms_user_groups_vis_value';
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['value'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['filters']['field_mo_cms_user_groups_vis_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Keyword';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
  );
  /* Filter criterion: Field: Address (field_mo_cms_postal_address:locality) */
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['id'] = 'field_mo_cms_postal_address_locality';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['table'] = 'field_data_field_mo_cms_postal_address';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['field'] = 'field_mo_cms_postal_address_locality';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['operator_id'] = 'field_mo_cms_postal_address_locality_op';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['operator'] = 'field_mo_cms_postal_address_locality_op';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['identifier'] = 'field_mo_cms_postal_address_locality';
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_mo_cms_postal_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Activities (field_trail_activity) */
  $handler->display->display_options['filters']['field_trail_activity_tid']['id'] = 'field_trail_activity_tid';
  $handler->display->display_options['filters']['field_trail_activity_tid']['table'] = 'field_data_field_trail_activity';
  $handler->display->display_options['filters']['field_trail_activity_tid']['field'] = 'field_trail_activity_tid';
  $handler->display->display_options['filters']['field_trail_activity_tid']['value'] = array(
    118 => '118',
    119 => '119',
    130 => '130',
    121 => '121',
    120 => '120',
    122 => '122',
    128 => '128',
    129 => '129',
  );
  $handler->display->display_options['filters']['field_trail_activity_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_trail_activity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['operator_id'] = 'field_trail_activity_tid_op';
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['operator'] = 'field_trail_activity_tid_op';
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['identifier'] = 'field_trail_activity_tid';
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
    11 => 0,
    10 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_trail_activity_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_trail_activity_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_trail_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_trail_activity_tid']['vocabulary'] = 'activities';
  $handler->display->display_options['path'] = 'groups/directory';
  $export['mo_cms_user_groups_directory'] = $view;

  return $export;
}
