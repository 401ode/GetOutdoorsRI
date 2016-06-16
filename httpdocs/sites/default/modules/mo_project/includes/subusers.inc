<?php
/**
 *  @file  subuser.inc
 *  @brief  Code for the MO project: 100 Missouri Miles.com
 *
 *  @details
 *  mo_project_user_insert = Implements hook_user_insert
 *  subuser_edit = Creates the edit sub-user form
 *  subuser_edit_submit = Submit handler for subuser_edit
 *  subuser_delete = Confirmation page for deleting a sub-user
 *  subuser_delete_submit = Submit handler for subuser_delete
 *  
 *  mo_project_count_all_subusers = Gets count of all sub-users and main users (via the 'Me' sub-user)
 *  mo_project_get_subusers = Gets suid, name, type_tid and type_name of all sub-users belonging to provided user
 *  mo_project_get_mileage_per_subuser = Gets suid, name, type_tid, type_name and total mileage for the sub-users of the passed in user
 *  mo_project_build_mileage_by_subuser = Displays the name and total mileage for sub-users
 *  mo_project_custom_subusers_sort = Sorts sub-users by type: Child, Pet, Other, Me
 *  mo_project_build_blue_mileage_by_subuser = Displays the name and total Blue mileage for sub-users
 *  
 *  mo_project_populate_subuser = Populate the "Me" sub-user in the `subuser` table, using the batch API.
 *  mo_project_populate_subuser_get_range = Determines the start and end values of one thousand uids
 *  mo_project_populate_subuser_with_me = Create the list of operations to call when the batch starts
 *  mo_project_populate_single_subuser = Populate 1 users record into 1 new subuser record, of type "Me".
 *  mo_project_populate_subuser_with_me_finished = User feedback when finished successfully or if there were any errors.
 *  
 *  mo_project_tag_mileage = Populate the subuser field on an existing mileage node with the "Me" sub-user, using the batch API.
 *  mo_project_tag_mileage_get_range = Determines the start and end values of one thousand nids
 *  mo_project_tag_mileage_with_me = Create the list of operations to call when the batch starts
 *  mo_project_tag_single_mileage = Populate 1 `field_data_field_mileage_subuser` record.
 *  mo_project_tag_mileage_with_me_finished = User feedback when finished successfully or if there were any errors.
 *  
 *  mo_project_tag_badges = Populate the suid field on an existing badge record with the "Me" sub-user, using the batch API.
 *  mo_project_tag_badges_get_range = Determines the start and end values of one thousand badge ids
 *  mo_project_tag_badges_with_me = Create the list of operations to call when the batch starts
 *  mo_project_tag_single_badges = Populate 1 `field_badges_suid` record.
 *  mo_project_tag_badges_with_me_finished = User feedback when finished successfully or if there were any errors.
 *  
 */

 
/**
 *  @brief Implements hook_user_insert
 *  to create the "Me" sub-user upon new user registration
 *  
 *  @param [in] $edit     The array of form values submitted by the user.
 *  @param [in] $account  The user object on which the operation is being performed.
 *  @param [in] $category The active category of user information being edited.
 *  
 *  @return nothing
 *  
 *  @details 2015-03-24 
 *  Call mo_project_populate_single_subuser to 
 *  populate the newly registered user's record into a new subuser record
 */
function mo_project_user_insert(&$edit, $account, $category) {

  $fname = $edit['field_user_first_name']['und'][0]['value'];
  mo_project_populate_single_subuser($edit['uid'], $fname, REQUEST_TIME);
}


/**
 *  @brief Creates the edit subuser form.
 *
 *  @param [in] $form_id    
 *  @param [in] $form_state 
 *  @param [in] $suid   Subuser ID to edit
 *  
 *  @return  new form
 *  
 *  @details  2015-03-20 
 */
function subuser_edit($form, &$form_state, $suid) {
  $query = db_select('subuser', 's');
  $query->fields('s');
  $query->condition('s.suid', $suid, '=');
  $results = $query->execute()->fetchAll();

  $user = user_load($results[0]->uid);
  $user_first = field_get_items('user', $user, 'field_user_first_name');
  $user_first = $user_first[0]['value'];
  $user_last = field_get_items('user', $user, 'field_user_last_name'); 
  $user_last = $user_last[0]['value'];
  
  $form = array();
	$form['suid'] = array(
		'#type' => 'value',
		'#value' => $suid,
	);
  $form[0] = array(
    '#type' => 'markup',
    '#prefix' => '<p>',   
    '#markup' => t("Editing Sub-user '@name', belonging to User '@first @last'", array(
      '@name' => $results[0]->name, 
      '@first' => $user_first, 
      '@last' => $user_last,
    )),
    '#suffix' => '</p>',
  );
  
  $form[1]['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('container-inline'),
    ),
  );
  
  $form[1]['container'][0] = array(
    'name' => array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => t("@name", array('@name' => $results[0]->name)),
    '#size' => 12,
    ),
  );
  
  $vid = taxonomy_vocabulary_machine_name_load("sub_user")->vid;
  $terms = taxonomy_get_tree($vid);
  foreach ($terms AS $term) {
    $allowed_values[$term->tid] = $term->name;
  }
  $form[1]['container'][1] = array(
    'type' => array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#options' => $allowed_values,
      '#default_value' => $results[0]->type_tid,
    ),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#attributes' => array(
      'id' => 'submit-subuser',
    ),
  );
 
  return $form;
} 


/**
 *  @brief  Submit handler for subuser_edit
 *  
 *  @param [in] $form_id    
 *  @param [in] $form_state 
 *
 *  @details 2015-03-20 
 */
function subuser_edit_submit($form, &$form_state) {
  // update the Sub-user record
  try {
    $num_updated = db_update('subuser')
      ->fields(array(
        'name' => $form_state['values']['name'],
        'type_tid' => $form_state['values']['type'],
        'created' => REQUEST_TIME,
      ))
      ->condition('suid', $form_state['values']['suid'])
      ->execute();
  } catch (Exception $e) {
    drupal_set_message('Error: <pre>' . print_r($e, TRUE) . '</pre>');
  }

  // notify the user that the selected sub-user has been updated.
  if ($num_updated == 1) {
    drupal_set_message('The Sub-user <em>' . $form_state['values']['name'] . '</em> has been updated.');
  }

  $form_state['redirect'] = array('dashboard', array('fragment' => 'my_family'));
}


/**
 *  @brief  Delete a subuser - with confirmation page
 *  
 *  @param [in] $suid      
 *  
 *  @details  2015-03-20 
 */
function subuser_delete($form, &$form_state, $suid) {
	$form = array();
	$form['suid'] = array(
		'#type' => 'value',
		'#value' => $suid,
	);

  $query_name = db_select('subuser', 's');
  $query_name->fields('s', array('name'));
  $query_name->condition('s.suid', $suid, '=');
  $name = $query_name->execute()->fetchCol();

	return confirm_form(
		$form,
		t('Are you sure you want to delete the Sub-user <em>' . $name[0] . '</em> ?'),
		'admin/people/subuser',
		t('This action cannot be undone.'),
		t('Delete'),
		t('Cancel')
	);

	return $form;
}


/**
 *  @brief  Submit handler for subuser_delete
 *  
 *  @param [in] $form_id    
 *  @param [in] $form_state 
 *
 *  @details 2015-03-20 
 *  this function is invoked only when the user clicks confirm button
 *  clicking on cancel, the user goes back to the $path
 */
function subuser_delete_submit($form, &$form_state) {
  $suid = $form_state['values']['suid'];
  $query_name = db_select('subuser', 's');
  $query_name->fields('s', array('name'));
  $query_name->condition('s.suid', $suid, '=');
  $name = $query_name->execute()->fetchCol();

	if ($form_state['values']['confirm'] == 1) {
		// delete any mileage belonging to this Sub-user
    $query_nodes = db_select('node', 'n');
    $query_nodes->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query_nodes->fields('n', array('nid'));
    $query_nodes->condition('n.type', 'mileage');
    $query_nodes->condition('s.field_mileage_subuser_value', $suid, '=');
    $nodes = $query_nodes->execute()->fetchCol();
    foreach ($nodes AS $nid) {
      node_delete($nid);
    }
    
    // delete the Sub-user
    try {
      $num_deleted = db_delete('subuser')
        ->condition('suid', $suid)
        ->execute();
    } catch (Exception $e) {
      drupal_set_message('Error: <pre>' . print_r($e, TRUE) . '</pre>');
    }

    // notify the user that the selected sub-user has been deleted.
    if ($num_deleted == 1) {
      drupal_set_message('The Sub-user <em>' . $name[0] . '</em> has been deleted.');
    }
	}

  $form_state['redirect'] = array('dashboard', array('fragment' => 'my_family'));
}


/**
 *  @brief  Gets count of all sub-users and main users (via the 'Me' sub-user)
 *  
 *  @return  count of users
 *  
 *  @details 2015-05-13 
 */
function mo_project_count_all_subusers() {
  $query = db_select('subuser', 's');
  $query->leftJoin('users', 'u', 's.uid = u.uid');
  $query->addField('s', 'suid');
  $query->condition('u.status', 0, '<>');
  $result = $query->execute();
  return $result->rowCount();
}


/**
 *  @brief  Gets suid, name, type_tid and type_name of all sub-users belonging to provided user
 *  
 *  @param [in] $uid          Main user uid
 *  @param [in] $sub_types    Optional. Type name(s) of sub-users to return
 *  @return  Array of suid => name for each sub-user
 *  
 *  @details 2014-04-10 
 */
function mo_project_get_subusers($uid, $sub_types=array() ) {

  $type_tids = array();
  if(!empty($sub_types)) {
    foreach($sub_types AS $s_type) {
      $term = taxonomy_get_term_by_name($s_type, 'sub_user');
      $keys = array_keys($term);
      $type_tids[] = array_pop($keys);
    }
  }
  
  $query = db_select('subuser', 's');
  $query->join('taxonomy_term_data', 'x', 's.type_tid = x.tid');
  $query->fields('s', array('suid', 'name', 'type_tid'));
  $query->addField('x', 'name', 'type_name');
  $query->condition('s.uid', $uid, '=');
  if (!empty($type_tids)) {
    $query->condition('s.type_tid', $type_tids, 'IN');
  }
  $query->orderBy('s.uid');
  $results = $query->execute()->fetchAll();
  
  return $results;
}


/**
 *  @brief  Gets suid, name, type_tid, type_name and total mileage for the sub-users of the passed in user
 *  
 *  @param [in] $uids         Array of Main user uids
 *  @param [in] $sub_types    Optional. Array of type name(s) of sub-users to return
 *  @param [in] $activities   Optional. Array of activity tids
 *  @param [in] $period  Optional. Time period to calculate mileage for. ('current', 'all', '30day', [ChallengeYear], array of 2 dates)
 *  
 *  @return  Array of results
 *  
 *  @details  2014-04-10 
 */
function mo_project_get_mileage_per_subuser($uids=array(), $sub_types=array(), $activities=array(), $period='current') { 
  if (is_array($period)) {
    $min_date = $period[0];
    $max_date = $period[1];
  } else if ((is_numeric($period)) AND ($period != '30day')) {
    $query_dates = mo_project_get_challenge_dates_by_year($period);
    $min_date = $query_dates['start'];
    $max_date = $query_dates['end'];
  } else {
    list($min_date, $max_date) = mo_project_get_query_dates($period);
  }

  $type_tids = array();
  if(!empty($sub_types)) {
    foreach($sub_types AS $s_type) {
      $term = taxonomy_get_term_by_name($s_type, 'sub_user');
      $keys = array_keys($term);
      $type_tids[] = array_pop($keys);
    }
  }

  $query = db_select('node', 'n');
  $query->join('field_data_field_mileage_distance', 'd', 'n.nid = d.entity_id AND (d.entity_type = :type AND d.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->join('field_data_field_mileage_date', 't', 'n.nid = t.entity_id AND (t.entity_type = :type AND t.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));  
  $query->join('field_data_field_mileage_subuser', 's', 'n.nid = s.entity_id AND (s.entity_type = :type AND s.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0)); 
  $query->join('subuser', 'su', 's.field_mileage_subuser_value = su.suid');
  $query->join('taxonomy_term_data', 'x', 'su.type_tid = x.tid');
  if ($activities) {
    $query->join('field_data_field_mileage_activity', 'a', 'n.nid = a.entity_id AND (a.entity_type = :type AND a.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
    $query->condition('a.field_mileage_activity_tid', $activities);
  }
  $query->fields('su', array('suid', 'name', 'type_tid'));
  $query->addField('x', 'name', 'type_name');
  $query->addExpression('SUM(d.field_mileage_distance_value)', 'distance');
  $query->condition('n.type', 'mileage');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.uid', $uids, 'IN');
  if (!empty($type_tids)) {
    $query->condition('su.type_tid', $type_tids, 'IN');
  }
  $query->condition('t.field_mileage_date_value', $min_date, '>=');
  $query->condition('t.field_mileage_date_value', $max_date, '<');
  $query->groupBy('su.name');
  $query->orderBy('su.type_tid');
  $results = $query->execute()->fetchAll();

  return $results;
}  


/**
 *  @brief Displays the name and total mileage for sub-users
 *  
 *  @return render array
 *  
 *  @details 2014-04-10 
 */
function mo_project_build_mileage_by_subuser() {
  global $user;
  // This only gets subusers with mileage
  $subusers = mo_project_get_mileage_per_subuser(array($user->uid));
  
  // Check for subusers with zero mileage and add them to the array
  $subusers_all = mo_project_get_subusers(array($user->uid));
  $suids = array();
  $suids_all = array();
  foreach($subusers AS $s1) {
    $suids[] = $s1->suid;
  }
  foreach($subusers_all AS $s2) {
    $suids_all[] = $s2->suid;
  }
  $zeros = array_diff($suids_all, $suids);
  
  if (!empty($zeros)) {
    foreach($zeros AS $s3) {
      foreach($subusers_all AS $record) {
        if ($record->suid == $s3) {
          $obj = new stdClass();
          $obj->suid = $s3;
          $obj->name = $record->name;
          $obj->type_tid = $record->type_tid;
          $obj->type_name = $record->type_name;      
          $obj->distance = 0.0;
          array_unshift($subusers, $obj);
        }
      }
    }
  }
  
  // if there are no true sub-users, don't display this
  // (every user has one sub-user, the "Me" sub-user)
  if(count($subusers) <= 1){
    return t('');
  }
  
  // Sort the multidimensional array
  usort($subusers, "mo_project_custom_subusers_sort");  
  
  $headers = array(
    array(
      'data' => t('Name'),
      'field' => 'name',
    ),
    array(
      'data' => t('Miles'),
      'field' => 'distance',
      'class' => array('align-right'),
    ),
    array(
      'data' => t('&nbsp;'),
      'field' => 'operations',
      'class' => array('align-right'),
    ),
  );
  $rows = array(); 
  $tot_distance = 0;
  $tot_operations = '&nbsp;';
  $tot_name = '<span class="family"></span>Total Family';
  
  foreach ($subusers as $s) { 
    if ($s->type_name == "Me") {
      $operations = $tot_operations;
    } else {
      $operations = l('edit', 'subuser/' . $s->suid . '/edit') . '&nbsp;&nbsp;&nbsp;' .
      l('delete', 'subuser/' . $s->suid . '/delete');
    }
    $name = '<span class="' . $s->type_name . '"></span>' . $s->name;
    
    $rows[] = array(
        $name,
        array(
          'data' => number_format($s->distance, 2),
          'class' => array('align-right'),
        ),
        array(
          'data' => $operations,
          'class' => array('align-right'),
        ),          
    );
    $tot_distance = ($tot_distance + $s->distance);
  }
  
  $rows[] = array(
        $tot_name,
        array(
          'data' => number_format($tot_distance, 2),
          'class' => array('align-right'),
        ),
        $tot_operations,
    );
  
  $output = theme_table(
    array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => NULL,
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    )
  ).theme('pager');
  
  return $output;  
}

/**
 *  @brief Sorts sub-users by type: Child, Pet, Other, Me
 *  
 *  @return boolean
 *  
 *  @details 2014-05-20 
 */
function mo_project_custom_subusers_sort($a,$b) {
  if ($a->type_name == 'Me') {
    return TRUE;
  } else if ($b->type_name == 'Me') {
    return FALSE;    
  } else {
    return $a->type_tid > $b->type_tid;
  }
}


/**
 *  @brief Displays the name and total blue mileage for sub-users
 *  
 *  @return render array
 *  
 *  @details 2014-05-01 
 */
function mo_project_build_blue_mileage_by_subuser() {
  global $user;
  $pad_id = key(taxonomy_get_term_by_name('Paddling'));
  $swm_id = key(taxonomy_get_term_by_name('Swimming'));

  $subusers = mo_project_get_mileage_per_subuser(array($user->uid), array(), array($pad_id, $swm_id));
  
  // if there are no true sub-users, don't display this
  // (every user has one sub-user, the "Me" sub-user)
  if(count($subusers) == 1){
    return t('');
  }
  
  $headers = array(
    array(
      'data' => t('Name'),
      'field' => 'name',
    ),
    array(
      'data' => t('Miles'),
      'field' => 'distance',
      'class' => array('align-right'),
    ),
    array(
      'data' => t('&nbsp;'),
      'field' => 'operations',
      'class' => array('align-right'),
    ),
  );
  $rows = array(); 
  $tot_distance = 0;
  $tot_operations = '&nbsp;';
  $tot_name = '<span class="family"></span>Total Family';
  
  foreach ($subusers as $s) { 
    if ($s->type_name == "Me") {
      $operations = $tot_operations;
    } else {
      $operations = l('edit', 'subuser/' . $s->suid . '/edit') . '&nbsp;&nbsp;&nbsp;' .
      l('delete', 'subuser/' . $s->suid . '/delete');
    }
    $name = '<span class="' . $s->type_name . '"></span>' . $s->name;
    
    $rows[] = array(
        $name,
        array(
          'data' => number_format($s->distance, 2),
          'class' => array('align-right'),
        ),
        array(
          'data' => $operations,
          'class' => array('align-right'),
        ),          
    );
    $tot_distance = ($tot_distance + $s->distance);
  }
  
  $rows[] = array(
        $tot_name,
        array(
          'data' => number_format($tot_distance, 2),
          'class' => array('align-right'),
        ),
        $tot_operations,
    );
  
  $output = theme_table(
    array(
      'header' => $headers,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => NULL,
      'colgroups' => array(),
      'sticky' => TRUE,
      'empty' => NULL,
    )
  ).theme('pager');
  
  return $output;  
}


/**
 *  @brief Populate the "Me" sub-user in the `subuser` table using the batch API.
 *  
 *  @return Nothing
 *  
 *  @details  2015-04-10 
 *  References -  https://www.drupal.org/node/180528 'Batch API'
 *  -  https://api.drupal.org/api/examples/batch_example!batch_example.module/
 *  group/batch_example/7
 *  -  http://www.drupology.co.uk/blog/using-batch-api-drupal-7-batch-api-tutorial
 *  
 */
function mo_project_populate_subuser() {
  
  // Get the uid range (one thousand) user records
  $uidrange = mo_project_populate_subuser_get_range();

  // Build the array which tells batch API what to do
  batch_set(mo_project_populate_subuser_with_me($uidrange[0], $uidrange[1]));

  // If there are more users to process, come back here
  $query = db_select('users', 'u');
  $query->addExpression('MAX(u.uid)', 'max_uid');
  $max_uid = $query->execute()->fetchCol();
  
  if ($uidrange[1] < $max_uid[0]) {
    // Since this is not a form submit handler, we must explicitly call batch_process
    // Argument (required) is the path to display once batch_process is complete.
    batch_process('admin/data/subuser-pop');
  } else {
    // All users have been processed, go to the People >> Sub-user listing
    batch_process('admin/people/subuser');
  }
} 
 
 
/**
 *  @brief Determines the start and end values of one thousand uids 
 *  
 *  @return Array of start uid and (start uid + 1000)
 *  
 *  @details 2015-04-10 
 */
function mo_project_populate_subuser_get_range() {
  
  // Get the uid of the most recent sub-user added
  $query = db_select('subuser', 's');  
  $query->addExpression('MAX(s.uid)', 'new_min');
  $result = $query->execute()->fetchCol();

  if (empty($result[0])) {
    
    // There are no sub-user records yet
    // Break the user records into groups of no more than 1000,
    // otherwise there are too many for Drupal to handle
   
    // Get the smallest uid (this is where we begin)
    $query2 = db_select('users', 'u');
    $query2->addExpression('MIN(u.uid)', 'min');
    $query2->condition('u.uid', 1, '>');
    $result2 = $query2->execute()->fetchCol();
    $min = $result2[0];

    // Set $max as $min rounded to the next thousand
    $max = (ceil($min / 1000) * 1000);
    
  } else {

    // Round $result[0] (the most recent sub-user added) to the next thousand
    // Example: If $result[0] is 2986, get 3000
    $min = (ceil($result[0] / 1000) * 1000);
    $max = ($min + 1000);  
  }

  // Check if there are any user registrations within that range
  $query3 = db_select('users', 'u');
  $query3->fields('u', array('uid'));  
  $query3->condition('u.uid', $min, '>=');
  $query3->condition('u.uid', $max, '<');
  $query3->range(0,1);
  $result3 = $query3->execute()->fetchCol();

  // If there are no user registrations within that range, 
  // advance a thousand at a time until there ARE user registrations
  if (empty($result3[0])) {
    while (empty($result3[0])) {

      unset($query3);
      unset($result3);
      
      // Advance uid range
      $min = $max;
      $max = ($min + 1000);

      // Check if there are any user registrations within that range
      $query3 = db_select('users', 'u');
      $query3->fields('u', array('uid'));  
      $query3->condition('u.uid', $min, '>=');
      $query3->condition('u.uid', $max, '<');
      $query3->range(0,1);
      $result3 = $query3->execute()->fetchCol();
    }
  } 

  return array($min, $max);
}


/**
 *  @brief Create the list of operations to call when the batch starts
 *  
 *  @param [in] $min_uid  start uid
 *  @param [in] $max_uid  end uid
 *  @return The $batch array
 *  
 *  @details Build the $operations array. When the batch starts it will loop through that array calling those function names with those arguments.
 *  Batch operation: Populate the "Me" sub-user in the "subuser" table.
 *  2015-04-10 
 */
function mo_project_populate_subuser_with_me($min_uid, $max_uid) {
 
  // Get user ids, created timestamps and first names
  $query = db_select('users', 'u');
  $query->leftJoin('field_data_field_user_first_name', 'f', 'u.uid = f.entity_id AND (f.entity_type = :type AND f.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
  $query->condition('u.uid', $min_uid, '>=');
  $query->condition('u.uid', $max_uid, '<');
  $query->addField('u', 'uid');
  $query->addField('u', 'created');
  $query->addField('f', 'field_user_first_name_value', 'name');
  $query->addMetaData('account', user_load(1));  
  $results = $query->execute();

  // Build the list of operation functions and function arguments
  $operations = array();
  foreach($results as $row) {    
    $operations[] = array('mo_project_populate_single_subuser', array($row->uid, $row->name, $row->created));
  }

  $title_str = 'Populating User Registrations ' . number_format($min_uid) . ' through ' . number_format($max_uid) . ' to table `subuser`';  
  // Build the batch instructions
  $batch = array(
    'operations' => $operations,
    'title' => t($title_str),    
    'finished' => 'mo_project_populate_subuser_with_me_finished',
  );

  return $batch;  
}


/**
 *  @brief Populate 1 users record into 1 new subuser record, of type "Me".
 *  
 *  @param [in] $uid      ID of user
 *  @param [in] $name     User's first name
 *  @param [in] $created  Unix Timestamp of the User account creation 
 *  
 *  @return Nothing
 *  
 *  @details 2015-03-17 
 */
function mo_project_populate_single_subuser($uid, $name=NULL, $created=NULL) {

  if (empty($name)) {
    $name = 'Me';
  } else {
    $working = trim($name);
    $pos = strpos($working, ' ');
    if ($pos === false) {
        $first = substr($working, 0, 1);
        $second = substr($working, 1, 1);
        if ($first === strtolower($first)) {
          // Name is not capitalized
          $name = ucfirst(strtolower($working));      
        }
        if ( ($first === strtoupper($first)) AND ($second === strtoupper($second)) ) {
          // Name is all caps
          $name = ucfirst(strtolower($working));
        }
        if (empty($name)) {
          $name = $working;
        }
    } else {
        // Name has space(s) in it
        $name = '';
        $pieces = explode(" ", $working);
        foreach ($pieces AS $piece) {
          $name .= ucfirst(strtolower($piece)) . ' ';
        }
        $name = trim($name);
    }
  }
  if ($created == NULL) {
    $created = 315554400;     // January 1, 1980 00:00:00
  }
 
  $term = taxonomy_get_term_by_name('Me', 'sub_user');
  $term = array_keys($term);
  $type = array_pop($term);

  $query = db_insert('subuser')
    ->fields(array(
      'uid' => $uid,
      'name' => $name,
      'type_tid' => $type,
      'created' => $created,
    ))
    ->execute();

  return TRUE;
}  


/**
 *  @brief User feedback when finished successfully or if there were any errors.
 *  
 *  @return Nothing
 *  
 *  @details 2015-03-17 
 */  
function mo_project_populate_subuser_with_me_finished($success, $results, $operations) {

  if ($success) {
    $messages = drupal_get_messages();
    foreach($messages as $type => $type_messages) {
      foreach ($type_messages as $message) {
        if( ($type != 'status') OR (substr($message, 0, 12) != 'Finished pop') ) {
          drupal_set_message($message, $type);
        }
      }
    }      
    drupal_set_message('Finished populating table `subuser` on ' . date('M j') . ' at ' . date('g:i a'));  
    
  } else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
    drupal_set_message('Populating table `subuser` aborted on ' . date('M j') . ' at ' . date('g:i a'));  
  }
}

 
/**
 *  @brief Populate `field_data_field_mileage_subuser` for all existing mileage
 *  with the "Me" sub-user using the batch API.
 *  
 *  @return Nothing
 *  
 *  @details  2015-04-10 
 *  References -  https://www.drupal.org/node/180528 'Batch API'
 *  -  https://api.drupal.org/api/examples/batch_example!batch_example.module/
 *  group/batch_example/7
 *  -  http://www.drupology.co.uk/blog/using-batch-api-drupal-7-batch-api-tutorial
 *  
 */
function mo_project_tag_mileage() {
  
  // Get the nid range (one thousand) mileage records
  $nidrange = mo_project_tag_mileage_get_range();

  // Build the array which tells batch API what to do
  batch_set(mo_project_tag_mileage_with_me($nidrange[0], $nidrange[1]));

  // If there are more mileage records to process, come back here
  $query = db_select('node', 'n');
  $query->addExpression('MAX(n.nid)', 'max_nid');
  $query->condition('n.uid', 1, '>');
  $query->condition('n.status', 0, '<>');
  $query->condition('n.type', 'mileage', '=');
  $max_nid = $query->execute()->fetchCol();  
  
//  if ($nidrange[1] < 10001) {
  if ($nidrange[1] < $max_nid[0]) {
    // Since this is not a form submit handler, we must explicitly call batch_process
    // Argument (required) is the path to display once batch_process is complete.
    batch_process('admin/data/mileage-tag');
  } else {
    // All mileage records have been processed, go to the mileage listing
    batch_process('admin/content/mileage-nodes');
  }
} 
 

/**
 *  @brief Determines the start and end values of one thousand nids 
 *  
 *  @return  Array of start nid and (start nid + 1000)
 *  
 *  @details 2015-04-10 
 */
function mo_project_tag_mileage_get_range() {
  
  // Get the nid of the most recent mileage record tagged with a sub-user
  $query = db_select('field_data_field_mileage_subuser', 's');
  $query->addExpression('MAX(s.entity_id)', 'new_min');
  $query->condition('s.field_mileage_subuser_value', 0, '!=');
  $result = $query->execute()->fetchCol();

  if (empty($result[0])) {
    
    // There are no mileage records tagged with a sub-user yet
    // Break the mileage records into groups of no more than 1000,
    // otherwise there are too many for Drupal to handle
   
    // Get the lowest mileage node nid (this is where we begin)
    $query2 = db_select('node', 'n');
    $query2->addExpression('MIN(n.nid)', 'min');
    $query2->condition('n.uid', 1, '>');
    $query2->condition('n.status', 0, '<>');
    $query2->condition('n.type', 'mileage', '=');
    $result2 = $query2->execute()->fetchCol();
    $min = $result2[0];


    // Set $max as $min rounded to the next thousand
    $max = (ceil($min / 1000) * 1000);
 
  } else {

    // Round $result[0] (the most recent mileage record tagged) to the next thousand
    // Example: If $result[0] is 2986, get 3000
    $min = (ceil($result[0] / 1000) * 1000);
    $max = ($min + 1000);  
    
  }

  // Check if there are any mileage records within that range
  $query3 = db_select('node', 'n');
  $query3->addExpression('n.nid', 'nid');
  $query3->condition('n.uid', 1, '>');
  $query3->condition('n.status', 0, '<>');
  $query3->condition('n.type', 'mileage', '=');
  $query3->condition('n.nid', $min, '>=');
  $query3->condition('n.nid', $max, '<');
  $query3->range(0,1);
  $result3 = $query3->execute()->fetchCol();
    
  // If there are no mileage records within that range, 
  // advance a thousand at a time until there ARE mileage records
  if (empty($result3[0])) {
    while (empty($result3[0])) {

      unset($query3);
      unset($result3);
      
      // Advance nid range
      $min = $max;
      $max = ($min + 1000);

      // Check if there are any mileage records within that range
      $query3 = db_select('node', 'n');
      $query3->addExpression('n.nid', 'min');
      $query3->condition('n.uid', 1, '>');
      $query3->condition('n.status', 0, '<>');
      $query3->condition('n.type', 'mileage', '=');
      $query3->condition('n.nid', $min, '>=');
      $query3->condition('n.nid', $max, '<');
      $query3->range(0,1);
      $result3 = $query3->execute()->fetchCol();
    }
  } 

  return array($min, $max);
}


/** 
 *  @brief Create the list of operations to call when the batch starts
 *  
 *  @param [in] $min_nid  start nid
 *  @param [in] $max_nid  end nid
 *  @return The $batch array
 *  
 *  @details Build the $operations array. When the batch starts it will loop through that array calling those function names with those arguments.
 *  Batch operation: Populate `field_data_field_mileage_subuser` for all existing mileage
 *  with the "Me" sub-user.
 *  2015-04-10 
 */
function mo_project_tag_mileage_with_me($min_nid, $max_nid) {
  // Get the tid of the "Me" Sub-user
  $term = taxonomy_get_term_by_name('Me', 'sub_user');
  $term = array_keys($term);
  $type = array_pop($term);
 
  // Get fields to insert
  $query = db_select('node', 'n');
  $query->leftJoin('subuser', 's', 'n.uid = s.uid');
  $query->condition('s.type_tid', $type, '=');
  $query->condition('n.nid', $min_nid, '>=');
  $query->condition('n.nid', $max_nid, '<');
  $query->fields('n', array('nid', 'vid', 'language'));
  $query->addField('s', 'suid');  
  $query->addMetaData('account', user_load(1));  
  $results = $query->execute();

  // Build the list of operation functions and function arguments
  $operations = array();
  foreach($results as $row) {    
    $operations[] = array('mo_project_tag_single_mileage', array($row->nid, $row->vid, $row->language, $row->suid));
  }

  $title_str = 'Tagging mileage records ' . number_format($min_nid) . ' through ' . number_format($max_nid);  
  // Build the batch instructions
  $batch = array(
    'operations' => $operations,
    'title' => t($title_str),    
    'finished' => 'mo_project_tag_mileage_with_me_finished',
  );

  return $batch;  
}


/**
 *  @brief  Populate 1 `field_data_field_mileage_subuser` record.
 *  
 *  @param [in] $nid        Node ID of mileage node
 *  @param [in] $rev_id     Revision ID of mileage node
 *  @param [in] $lang       Language
 *  @param [in] $suid       Subuser ID of type "Me" matching the node user
 *  
 *  @return Nothing
 *  
 *  @details 2015-03-17 
 */
function mo_project_tag_single_mileage($nid, $rev_id, $lang, $suid) {
  $result = array();
  $find_query = db_select('field_data_field_mileage_subuser', 's');
  $find_query->fields('s', array('field_mileage_subuser_value'));
  $find_query->condition('s.entity_type', 'node', '=');
  $find_query->condition('s.deleted', 0, '=');
  $find_query->condition('s.entity_id', $nid, '=');
  $find_query->condition('s.language', 'und', '=');
  $find_query->condition('s.delta', 0, '=');
  $result = $find_query->execute()->fetchCol();
  
  if ( (empty($result)) OR ($result[0] == NULL) ) {
      $query = db_insert('field_data_field_mileage_subuser')
        ->fields(array(
          'entity_type' => 'node',
          'bundle' => 'mileage',
          'deleted' => 0,
          'entity_id' => $nid,
          'revision_id' => $rev_id,
          'language' => $lang,
          'delta' => 0,
          'field_mileage_subuser_value' => $suid,
        ))
        ->execute();   
  } else {
      $query = db_update('field_data_field_mileage_subuser')
        ->fields(array(
          'revision_id' => $rev_id,
          'field_mileage_subuser_value' => $suid,
        ))
        ->condition('entity_id', $nid, '=')
        ->execute();
  }
  unset($result);
  unset($query);
  return TRUE;
}  


/**
 *  @brief User feedback when finished successfully or if there were any errors.
 *  
 *  @return Nothing
 *  
 *  @details 2015-03-17 
 */  
function mo_project_tag_mileage_with_me_finished($success, $results, $operations) {

  if ($success) {
    $messages = drupal_get_messages();
    foreach($messages as $type => $type_messages) {
      foreach ($type_messages as $message) {
        if( ($type != 'status') OR (substr($message, 0, 12) != 'Finished pop') ) {
          drupal_set_message($message, $type);
        }
      }
    }    
    drupal_set_message('Finished populating `field_data_field_mileage_subuser` for all existing mileage on ' . date('M j') . ' at ' . date('g:i a'));  
    
  } else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
    drupal_set_message('Populating table `field_data_field_mileage_subuser` aborted on ' . date('M j') . ' at ' . date('g:i a'));  
  }
}


/**
 *  @brief Populate the suid field on an existing badge record with the "Me" sub-user, using the batch API.
 *  
 *  @return Nothing
 *  
 *  @details  2015-04-20 
 *  References -  https://www.drupal.org/node/180528 'Batch API'
 *  -  https://api.drupal.org/api/examples/batch_example!batch_example.module/
 *  group/batch_example/7
 *  -  http://www.drupology.co.uk/blog/using-batch-api-drupal-7-batch-api-tutorial
 *  
 */
function mo_project_tag_badges() {
  
  // Get the field_badges_row_id range (one thousand) badge records
  $bidrange = mo_project_tag_badges_get_range();

  // Build the array which tells batch API what to do
  batch_set(mo_project_tag_badges_with_me($bidrange[0], $bidrange[1]));

  // If there are more badge records to process, come back here
  $query = db_select('badges_earned', 'b');
  $query->addExpression('MAX(b.field_badges_row_id)', 'max_bid');
  $query->isNull('b.field_badges_suid');
  $max_bid = $query->execute()->fetchCol();
  
//  if ($bidrange[1] < 45000) {
  if ($bidrange[1] < $max_bid[0]) {
    // Since this is not a form submit handler, we must explicitly call batch_process
    // Argument (required) is the path to display once batch_process is complete.
    batch_process('admin/data/badge-tag');
  } else {
    // All mileage records have been processed, go to the mileage listing
    batch_process('admin/content/mileage-nodes');
  }
} 
 

/**
 *  @brief Determines the start and end values of one thousand field_badges_row_ids 
 *  
 *  @return  Array of start bid and (start bid + 1000)
 *  
 *  @details 2015-04-20 
 */
function mo_project_tag_badges_get_range() {
  
  // Get the field_badges_row_id of the most recent badge record tagged with a sub-user
  $query = db_select('badges_earned', 'b');
  $query->addExpression('MAX(b.field_badges_row_id)', 'new_min');
  $query->isNotNull('b.field_badges_suid');
  $result = $query->execute()->fetchCol();

  if (empty($result[0])) {
    
    // There are no badge records tagged with a sub-user yet
    // Break the badge records into groups of no more than 1000,
    // otherwise there are too many for Drupal to handle
   
    // Get the lowest badge row nid (this is where we begin)
    $query2 = db_select('badges_earned', 'b');
    $query2->addExpression('MIN(b.field_badges_row_id)', 'min');
    $query2->isNull('b.field_badges_suid');
    $result2 = $query2->execute()->fetchCol();
    $min = $result2[0];

    // Set $max as $min rounded to the next thousand
    $max = (ceil($min / 1000) * 1000);
 
  } else {

    // Round $result[0] (the most recent badge record tagged) to the next thousand
    // Example: If $result[0] is 2986, get 3000
    $min = (ceil($result[0] / 1000) * 1000);
    $max = ($min + 1000);  
    
  }

  // Check if there are any badge records within that range
  $query3 = db_select('badges_earned', 'b');
  $query3->addField('b', 'field_badges_row_id');
  $query3->condition('b.field_badges_row_id', $min, '>=');
  $query3->condition('b.field_badges_row_id', $max, '<');
  $query3->isNull('b.field_badges_suid');
  $query3->range(0,1);
  $result3 = $query3->execute()->fetchCol();
    
  // If there are no badge records within that range, 
  // advance a thousand at a time until there ARE badge records
  if (empty($result3[0])) {
    while (empty($result3[0])) {

      unset($query3);
      unset($result3);
      
      // Advance nid range
      $min = $max;
      $max = ($min + 1000);

      // Check if there are any mileage records within that range
      $query3 = db_select('badges_earned', 'b');
      $query3->addField('b', 'field_badges_row_id');
      $query3->condition('b.field_badges_row_id', $min, '>=');
      $query3->condition('b.field_badges_row_id', $max, '<');
      $query3->isNull('b.field_badges_suid');
      $query3->range(0,1);
      $result3 = $query3->execute()->fetchCol();
    }
  } 

  return array($min, $max);
}


/** 
 *  @brief Create the list of operations to call when the batch starts
 *  
 *  @param [in] $min_bid  start field_badges_row_id
 *  @param [in] $max_bid  end field_badges_row_id
 *  @return The $batch array
 *  
 *  @details Build the $operations array. When the batch starts it will loop through that array calling those function names with those arguments.
 *  Batch operation: Populate `field_badges_suid` for all existing badges_earned
 *  with the "Me" sub-user.
 *  2015-04-20 
 */
function mo_project_tag_badges_with_me($min_bid, $max_bid) {
  // Get the tid of the "Me" Sub-user
  $term = taxonomy_get_term_by_name('Me', 'sub_user');
  $term = array_keys($term);
  $type = array_pop($term);
 
  // Get fields to insert
  $query = db_select('badges_earned', 'b');
  $query->leftJoin('subuser', 's', 'b.field_badges_uid = s.uid');
  $query->condition('s.type_tid', $type, '=');
  $query->condition('b.field_badges_row_id', $min_bid, '>=');
  $query->condition('b.field_badges_row_id', $max_bid, '<');
  $query->addField('b', 'field_badges_row_id', 'bid');
  $query->addField('s', 'suid');  
  $query->addMetaData('account', user_load(1));  
  $results = $query->execute();

  // Build the list of operation functions and function arguments
  $operations = array();
  foreach($results as $row) {    
    $operations[] = array('mo_project_tag_single_badge', array($row->bid, $row->suid));
  }

  $title_str = 'Tagging badge records ' . number_format($min_bid) . ' through ' . number_format($max_bid);  
  // Build the batch instructions
  $batch = array(
    'operations' => $operations,
    'title' => t($title_str),    
    'finished' => 'mo_project_tag_badges_with_me_finished',
  );

  return $batch;  
}


/**
 *  @brief  Populate 1 `field_badges_suid` record.
 *  
 *  @param [in] $bid        field_badges_row_id in the `badges_earned` table
 *  @param [in] $suid       Subuser ID of type "Me" matching the node user
 *  
 *  @return Nothing
 *  
 *  @details 2015-04-20 
 */
function mo_project_tag_single_badge($bid, $suid) {

  $num_updated = db_update('badges_earned')
    ->fields(array(
      'field_badges_suid' => $suid,
    ))
    ->condition('field_badges_row_id', $bid, '=')
    ->execute();

  return TRUE;
}  


/**
 *  @brief User feedback when finished successfully or if there were any errors.
 *  
 *  @return Nothing
 *  
 *  @details 2015-04-20 
 */  
function mo_project_tag_badges_with_me_finished($success, $results, $operations) {

  if ($success) {
    $messages = drupal_get_messages();
    foreach($messages as $type => $type_messages) {
      foreach ($type_messages as $message) {
        if( ($type != 'status') OR (substr($message, 0, 12) != 'Finished pop') ) {
          drupal_set_message($message, $type);
        }
      }
    }    
    drupal_set_message('Finished populating `badges_earned.field_badges_suid` for all existing badges on ' . date('M j') . ' at ' . date('g:i a'));  
    
  } else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
    drupal_set_message('Populating table `badges_earned` aborted on ' . date('M j') . ' at ' . date('g:i a'));  
  }
}
