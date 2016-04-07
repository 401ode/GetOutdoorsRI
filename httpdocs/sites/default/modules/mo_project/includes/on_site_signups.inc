<?php
/**
 * On-site signups functions
 */

function mo_project_on_site_signups_list() {

  mo_project_add_webform_support();

  $output = array(
    'header' => array(
      0 => array(
        'data' => t('Created'),
        'field' => 'created',
        'sort' => 'desc',
      ),
      1 => array(
        'data' => t('Title'),
        'field' => 'title',
        'sort' => 'asc',
      ),
      2 => array(
        'data' => t('Status'),
        'field' => 'webform_status',
        'sort' => 'desc',
      ),
      3 => array(
        'data' => t('# Submissions'),
      ),
    ),
    'rows' => array(),
    'attributes' => array(),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => TRUE,
    'empty' => NULL,
  );
  
  $query = db_select('node', 'n');
  $query->join('webform', 'webform', 'n.nid = webform.nid');
  $query->addField('n', 'nid');
  $query->addField('n', 'title');
  $query->addField('n', 'created');
  $query->addField('webform', 'status', 'webform_status');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.type', array('on_site_signup_form', 'on_site_signup_form_with_group'));
  $query->extend('TableSort')->orderByHeader($output['header']);
  $result = $query->execute();
  
  foreach ($result as $key=>$row) {
    $output['rows'][$key] = array(
      'data' => array(),
    );
    $output['rows'][$key]['data']['date'] = array(
      'data' => t(date('M j, Y g:i a', $row->created)),
    );
    $output['rows'][$key]['data']['title'] = array(
      'data' => t(l($row->title, 'node/' . $row->nid)),
    );
    if ($row->webform_status) {
      $status = 'Open';
    } else {
      $status = 'Closed';
    }
    $output['rows'][$key]['data']['webform_status'] = array(
      'data' => t($status),
    );
    $submissions = webform_get_submission_count($row->nid);
    $output['rows'][$key]['data']['submissions'] = array(
      'data' => t($submissions . ' ' . l('[details]', 'admin/on-site-signups/' . $row->nid)),
    );
  }
  return theme_table($output);
  
}

function mo_project_on_site_signups_details_title($nid) {
  
  $node = node_load($nid);
  return t('On-Site Signups Details: ' . $node->title);
  
}

function mo_project_on_site_signups_details_form($form, &$form_state, $nid) {
  if (!empty($form_state['input']['admin_action'])) {
    return mo_project_on_site_signups_details_form_confirm($form, $form_state, $nid);
  }
  return mo_project_on_site_signups_details_form_actions($form, $form_state, $nid);
}

function mo_project_on_site_signups_details_form_confirm($form, &$form_state, $nid) {
  mo_project_add_webform_support();
  $submissions = webform_get_submissions(array('nid' => $nid));
  $desc = array(
    '#type' => 'markup',
    '#markup' => t('<p>Are you sure you wish to <b>' . $form_state['input']['admin_action'] . '</b> the following submissions?</p>'),
  );
  $items_list = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(),
    'items' => array(),
  );
  if (!empty($form_state['input']['table'])) {
    foreach ($form_state['input']['table'] as $sid) {
      $submission = $submissions[$sid];
      $items_list['items'][] = $submission->data[2]['value'][0];
    }
    $desc['#markup'] .= theme_item_list($items_list);
    $desc['#markup'] .= t('<p>This action cannot be undone.');
    $form['admin_action'] = array(
      '#type' => 'hidden',
      '#value' => $form_state['input']['admin_action'],
    );
    $form['table'] = array(
      '#type' => 'hidden',
      '#value' => $form_state['input']['table'],
    );
    $form['nid'] = array(
      '#type' => 'hidden',
      '#value' => $form_state['input']['nid'],
    );
    $form['process'] = array(
      '#type' => 'hidden',
      '#value' => 'true',
    );
    $form['destination'] = array(
      '#type' => 'hidden',
      '#value' => 'admin/on-site-signups/' . $nid,
    );
  }
  return confirm_form($form, 'Are you sure?', 'admin/on-site-signups/' . $nid, render($desc), 'Continue', 'Cancel');
}

function mo_project_on_site_signups_details_form_actions($form, &$form_state, $nid) {
  mo_project_add_webform_support();

  $webform_node = node_load($nid);
  $components = array();
  foreach ($webform_node->webform['components'] as $key=>$component) {
    $components[$component['form_key']] = $key;
  }

  $submissions = webform_get_submissions(array('nid' => $nid));
  $invalid_submissions = array();
  
  $header = array(
    'id' => array(
      'data' => t('ID'),
      'style' => 'display: none;',
    ),
    'nid' => array(
      'data' => t('NID'),
      'style' => 'display: none;',
    ),
    'submitted' => t('Submitted'),
    'name' => t('Name'),
    'username' => t('Username'),
    'email' => t('Email'),
    'initial_mileage' => array(
      'data' => t('Mileage'),
      'style' => 'display: none;',
    ),
    'activity' => array(
      'data' => t('Activity'),
      'style' => 'display: none;',
    ),
  );
  if ($webform_node->type == 'on_site_signup_form_with_group') {
    $header['group_name'] = array(
      'data' => t('Group Name'),
      'class' => array(
        'nowrap',
      ),
    );
    $header['group_description'] = t('Description');
    $header['group_membership'] = t('Membership');
    $header['group_visibility'] = t('Listing');
    $header['group_activities'] = t('Activities');
  }
  $header['links'] = NULL;
  $options = array();
  foreach ($submissions as $submission) {
    $reasons = array();
    if (mo_project_check_username_exists($submission->data[$components['username']]['value'][0])) {
      $reasons[] = 'username';
    }
    if (mo_project_check_email_exists($submission->data[$components['email']]['value'][0])) {
      $reasons[] = 'email';
    }
    if ($reasons) {
      $invalid_submissions[] = array(
        'submission' => $submission,
        'reasons' => $reasons,
      );
      continue;
    }
    $options[$submission->sid] = array(
      'id' => array(
        'data' => $submission->sid,
        'style' => 'display: none;',
      ),
      'nid' => array(
        'data' => $nid,
        'style' => 'display: none;',
      ),
      'submitted' => array(
        'data' => format_date($submission->submitted),
        'class' => array(
          'nowrap',
        ),
      ),
      'name' => array(
        'data' => $submission->data[$components['name']]['value'][0],
        'class' => array(
          'nowrap',
        ),
      ),
      'username' => $submission->data[$components['username']]['value'][0],
      'email' => $submission->data[$components['email']]['value'][0],
      'initial_mileage' => array(
        'data' => NULL,
        'style' => 'display: none;',
      ),
      'activity' => array(
        'data' => NULL,
        'style' => 'display: none;',
      ),
    );
    if (!empty($components['activity']) and !empty($components['distance']) and !empty($components['units']) and !empty($submission->data[$components['activity']]['value'][0]) and !empty($submission->data[$components['distance']]['value'][0]) and !empty($submission->data[$components['units']]['value'][0])) {
      $initial_value = $submission->data[$components['distance']]['value'][0];
      if ($submission->data[$components['units']]['value'][0] == 'kilometers') {
        $initial_value *= 0.621371;
      }
      $options[$submission->sid]['initial_mileage']['data'] = t(number_format($initial_value, 2));
      $options[$submission->sid]['activity']['data'] = t($submission->data[$components['activity']]['value'][0]);
    }
    if ($webform_node->type == 'on_site_signup_form_with_group') {
      $options[$submission->sid]['group_name'] = array(
        'data' => t($submission->data[$components['group_name']]['value'][0]),
        'class' => array(
          'nowrap',
        ),
      );
      $options[$submission->sid]['group_description'] = t($submission->data[$components['description']]['value'][0]);
      if ($submission->data[$components['membership']]['value'][0] == 'open') {
        $options[$submission->sid]['group_membership'] = t('Open');
      } else {
        $options[$submission->sid]['group_membership'] = t('By approval');
      }
      $options[$submission->sid]['group_visibility'] = t(ucwords($submission->data[$components['visibility']]['value'][0]));
      $activities_string = NULL;
      if (!empty($submission->data[$components['activities']]['value'])) {
        $activities_string = ucwords(implode(', ', $submission->data[$components['activities']]['value']));
      }
      $options[$submission->sid]['group_activities'] = t($activities_string);
    }
    $view_path = 'node/' . $webform_node->nid . '/submission/' . $submission->sid;
    $edit_path = $view_path . '/edit';
    $options[$submission->sid]['links'] = t(l('[view]', $view_path) . ' ' . l('[edit]', $edit_path));
  }
 
  $form = array(
    'admin_action' => array(
      '#type' => 'select',
      '#title' => t('Action'),
      '#attributes' => array(),
      '#options' => array(
        'none' => t('- Select -'),
        'register' => t('Register'),
        'delete' => t('Delete'),
      ),
    ),
    'table' => array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#multiple' => TRUE,
    ),
    'nid' => array(
      '#type' => 'hidden',
      '#value' => $webform_node->nid,
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Submit'),
      '#attributes' => array(
        'id' => 'signup-action',
      ),
    ),
  );
 
  if (!empty($invalid_submissions)) {
    $invalid_submissions_table = array(
      'header' => array(
        NULL,
        t('Submitted'),
        t('Name'),
        t('Username'),
        t('Email'),
      ),
      'rows' => array(),
      'attributes' => array(),
      'caption' => t('<b>Invalid Submissions:</b> Username or Email Address conflicts with an existing account.<br>(Note: for now, you will need to navigate back to this page after editing an invalid submission.)'),
      'colgroups' => array(),
      'sticky' => FALSE,
      'empty' => NULL,
    );
    foreach ($invalid_submissions as $invalid_submission) {
      $path = 'node/' . $webform_node->nid . '/submission/' . $invalid_submission['submission']->sid . '/edit';
      $row = array(
        'data' => array(
          'edit' => array(
            'data' => l('edit', $path),
          ),
          'submitted' => array(
            'data' => format_date($invalid_submission['submission']->submitted),
          ),
          'name' => array(
            'data' => $invalid_submission['submission']->data[$components['name']]['value'][0],
          ),
          'username' => array(
            'data' => $invalid_submission['submission']->data[$components['username']]['value'][0],
          ),
          'email' => array(
            'data' => $invalid_submission['submission']->data[$components['email']]['value'][0],
          ),
        ),
      );
      foreach ($invalid_submission['reasons'] as $reason) {
        $row['data'][$reason]['class'] = 'invalid';
      }
      $invalid_submissions_table['rows'][] = $row;
    }
    $form['invalid_submissions'] = array(
      '#type' => 'markup',
      '#markup' => theme_table($invalid_submissions_table),
    );
  }

  return $form;
  
}

function mo_project_on_site_signups_details_form_submit($form_id, &$form_state) {
  if (empty($form_state['input']['admin_action']) or $form_state['input']['admin_action'] == 'none') {
    drupal_set_message('No action selected.', 'warning');
    return;
  } elseif (isset($form_state['input']['admin_action']) and in_array($form_state['input']['admin_action'], array('register', 'delete'))) {
    if (empty($form_state['input']['table'])) {
      drupal_set_message('No submissions were selected.', 'warning');
      return;
    }
  }
  if (isset($form_state['input']['process']) and $form_state['input']['process']) {
    $node = node_load($form_state['values']['nid']);
    switch($form_state['values']['admin_action']) {
      case 'register':
        $targets = array();
        foreach ($form_state['values']['table'] as $sid) {
          $targets[$sid] = $sid;
        }
        mo_project_on_site_signups_create_users($targets, $form_state['values']['nid']);
        if ($node->type == 'on_site_signup_form_with_group') {
          mo_project_on_site_signups_create_groups($targets, $form_state['values']['nid']);
        }
        break;
      case 'delete':
        $targets = array();
        foreach ($form_state['values']['table'] as $sid) {
          $targets[$sid] = $sid;
        }
        break;
    }
    mo_project_on_site_signups_delete_submissions($targets, $form_state['values']['nid']);
  } else {
    $form_state['rebuild'] = TRUE;
  }
  
}

function mo_project_on_site_signups_create_users($targets, $nid) {
  $webform_node = node_load($nid);
  $components = array();
  foreach ($webform_node->webform['components'] as $key=>$component) {
    $components[$component['form_key']] = $key;
  }
  $result = mo_project_on_site_signups_get_node_and_submissions($targets, $nid);
  foreach ($targets as $target) {
    $submission = $result['submissions'][$target];
    $account = new stdClass;
    $account->is_new = TRUE;
    $account->name = $submission->data[$components['username']]['value'][0];
    $account->pass = user_password();
    $account->mail = $submission->data[$components['email']]['value'][0];
    $account->init = $submission->data[$components['email']]['value'][0];
    $account->status = TRUE;
    $account->roles = array(DRUPAL_AUTHENTICATED_RID => TRUE);
    $account->timezone = variable_get('date_default_timezone', '');
    user_save($account);
    _user_mail_notify('register_no_approval_required', $account);
    drupal_set_message('<b>Registered</b> submission #' . $submission->sid . ' (' . $submission->data[$components['name']]['value'][0] . ') with uid ' . $account->uid);
    if (!empty($components['distance']) and !empty($submission->data[$components['distance']]['value'][0]) and !empty($submission->data[$components['units']]['value'][0]) and !empty($submission->data[$components['activity']]['value'][0])) {
      $distance = $submission->data[$components['distance']]['value'][0];
      if ($submission->data[$components['units']]['value'][0] == 'kilometers') {
        $distance *= 0.621371;
      }
      $tid = FALSE;
      $terms = taxonomy_get_term_by_name($submission->data[$components['activity']]['value'][0], 'activities');
      foreach ($terms as $tid=>$term) {
        break;
      }
      $node = new stdClass();
      $node->type = 'mileage';
      $node->language = LANGUAGE_NONE;
      $node->revision = 0;
      $node->status = 1;
      $node->promote = 0;
      $node->sticky = 0;
      node_object_prepare($node);
      $node->field_mileage_date[$node->language][0]['value'] = date('Y-m-d 00:00:00', $submission->submitted);
      $node->field_mileage_distance[$node->language][0]['value'] = $distance;
      if ($tid) {
        $node->field_mileage_activity[$node->language][0]['tid'] = $tid;
      }
      $node->field_class_spec_promotional[$node->language][0]['value'] = 1;
      node_submit($node);
      $node->uid = $account->uid;
      node_save($node);
    }
  }
}

function mo_project_on_site_signups_create_groups($targets, $nid) {
  $webform_node = node_load($nid);
  $components = array();
  foreach ($webform_node->webform['components'] as $key=>$component) {
    $components[$component['form_key']] = $key;
  }
  $result = mo_project_on_site_signups_get_node_and_submissions($targets, $nid);
  foreach ($targets as $target) {
    $submission = $result['submissions'][$target];
    $account = user_load_by_mail($submission->data[$components['email']]['value'][0]);
    $node = new stdClass();
    $node->type = 'mo_cms_user_group';
    $node->language = LANGUAGE_NONE;
    $node->revision = 0;
    $node->status = 1;
    $node->promote = 0;
    $node->sticky = 0;
    node_object_prepare($node);
    $node->title = t($submission->data[$components['group_name']]['value'][0]);
    if (!empty($submission->data[$components['group_info']]['value'][0])) {
      $node->body['und'][0]['value'] = t($submission->data[$components['group_info']]['value'][0]);
    }
    $node->field_mo_cms_user_groups_join['und'][0]['value'] = $submission->data[$components['membership']]['value'][0];
    $node->field_mo_cms_user_groups_owners['und'][0]['target_id'] = 1;
    $node->field_mo_cms_user_groups_owners['und'][1]['target_id'] = $account->uid;
    $node->field_mo_cms_user_groups_vis['und'][0]['value'] = $submission->data[$components['visibility']]['value'][0];
    $node->field_trail_activity['und'] = array();
    if (!empty($submission->data[$components['activities']]['value'])) {
      foreach ($submission->data[$components['activities']]['value'] as $activity_name) {
        $activity_terms = taxonomy_get_term_by_name($activity_name, 'activities');
        $activity_tids = array_keys($activity_terms);
        $node->field_trail_activity['und'][] = array(
          'tid' => $activity_tids[0],
        );
      }
    }
    
    node_submit($node);
    $node->uid = 1;
    node_save($node);
    drupal_set_message('Created group: ' . $node->title);
  }
}

function mo_project_on_site_signups_delete_submissions($targets, $nid) {
  $result = mo_project_on_site_signups_get_node_and_submissions($targets, $nid);
  foreach ($targets as $target) {
    $submission = $result['submissions'][$target];
    webform_submission_delete($result['node'], $submission);
    drupal_set_message('<b>Deleted</b> submission #' . $submission->sid . ' (' . $submission->data[2]['value'][0] . ')');
  }
}

function mo_project_on_site_signups_get_node_and_submissions($targets, $nid) {
  mo_project_add_webform_support();
  $node = node_load($nid);
  $submissions = webform_get_submissions(array('nid' => $node->nid));
  return array(
    'node' => $node,
    'submissions' => $submissions,
  );
}
