<?php

/**
 * @file mo_project.views.inc
 *
 * @details
 * mo_project_views_query_alter = Implements hook_views_query_alter
 *
 */


/**
 * @brief Implements hook_views_data_alter()
 *
 * @details 2015-03-18 
 */
function mo_project_views_data_alter(&$data) {

  $data['subuser']['created'] = array(
    'field' => array(
      'title' => t('Created'),
      'help' => t('Date/time when the record was first created.'),
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'title' => t('Created'),
      'help' => t('Date/time when the record was first created.'),
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'title' => t('Created'),
      'help' => t('Date/time when the record was first created.'),
      'handler' => 'views_handler_filter_date',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 *
 * @details 2015-02-17 
 */
function mo_project_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'mo_project'). '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  if (isset($views)) {
    return $views;
  } else {
    return TRUE;
  }
}


/**
 * Implements hook_form_views_exposed_form_alter().
 *
 * @details 2015-04-10 
 */
function mo_project_form_views_exposed_form_alter(&$form, &$form_state) {
  switch ($form['#id']) {
    case 'views-exposed-form-administration-sub-users-page-2':
      $form['name']['#size'] = 20;
      $form['field_user_last_name_value']['#size'] = 20;
      $form['field_user_first_name_value']['#size'] = 20;
      break;

    case 'views-exposed-form-miles-by-user-panel-pane-1':
      global $user;
      $all_subusers = mo_project_get_subusers($user->uid);
      foreach ($all_subusers as $row) {
        $allowed_subusers[$row->suid] = t($row->name);
      }
      $allowed_subusers = array_reverse($allowed_subusers, TRUE);
      $allowed_subusers[""] = t(' - Any -');
      $allowed_subusers = array_reverse($allowed_subusers, TRUE);
      $form['field_mileage_subuser_value']['#type'] = 'select';
      $form['field_mileage_subuser_value']['#size'] = 1.95;
      $form['field_mileage_subuser_value']['#options'] = $allowed_subusers;
      $form['field_mileage_subuser_value']['#default_value'] = '';
      break;

  }
}    
