<?php

/**
 * Functions for handling medals
 */
 
/*function mo_project_menu() {

  $items = array();

  $items['medals/approve'] = array(
    'title' => t('Approve Medal Requests'),
    'description' => 'Track and approve requests for completion medals',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mo_project_medal_request_details_form'),
    'access arguments' => array('approve medals'),
    'theme callback' => 'mo_project_use_admin_theme',
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['medals/locate'] = array(
    'title' => t('Locate Medalists'),
    'type' => MENU_NORMAL_ITEM,
    'page callback' => 'mo_project_locate_medalists',
    'access arguments' => array('approve medals'),
  );
  
  return $items;

} */ 

/*function mo_project_webform_validation_validators() {
  $validators = array(
    /**
     * Custom webform validator to ensure that user has logged 100 miles before submitting 
     * the Request a Medal form. 
     * References https://drupal.org/node/908600 'Adding custom validation rules - Webform Validation hooks'
     *   https://drupal.org/node/822146#comment-3080360 'How do I validate a number...'
     * 2013-07-17 
     *
    'validate_miles' => array(
      'name' => 'Mileage',
      'component_types' => array(
        'all',
      ),
      'description' => t('Ensure user has logged at least 100 miles'),
    ),
      return $validators;
} */

/*function mo_project_webform_validation_validate($validator_name, $items, $components, $rule) {
  if (!$items) {
    return;
  }
  $errors = array();
  switch($validator_name) {
    
    case 'validate_miles':

      foreach ($items as $key => $val) { 
        $requestor = user_load_by_name(check_plain($val));     
        $mileage = mo_project_get_total_mileage(array($requestor->uid));
      
        if ( (empty($mileage)) OR ($mileage < 100.00) ) {
          $errors[$key] = t("We're sorry, you must complete 100 miles before requesting a medal.<br>You have logged %item miles.", array('%item' => $mileage));
        }
      }
      break;
  }
  return $errors;
} */

/*function mo_project_block_info() {
  $blocks = array();
  $blocks['medal_status']['info'] = t('Medal Status');
  return $blocks;
} */

/*function mo_project_block_view($delta='') {
  $block = array();
  global $user;
  $id_string = drupal_clean_css_identifier($delta);

  switch ($delta) {
    case 'medal_status':
      $block['subject'] = 'Medal Status';
      $block['content'] = render(mo_project_show_medal_status($id_string));
      break;
  }

  return $block;
} */

/**
 * Add functionality to the Request a Medal form to save the 'requested date' upon submit. 
 * 2013-07-12 
 */
function mo_project_form_webform_client_form_38243_alter(&$form, $form_state, $form_id) {
  $form['#submit'][] = 'mo_project_custom_webform_38243_submit';   
}
// DEV VERSION HAS A DIFFERENT NODE FORM ID NUMBER - Not Anymore (2013-09-17)
//function mo_project_form_webform_client_form_13551_alter(&$form, $form_state, $form_id) {
//  $form['#submit'][] = 'mo_project_custom_webform_13551_submit';   
//}

/**
 * Save 'requested date' upon submit of Request a Medal form.
 * Set the flag to display the request on the Approve Medals form.
 * 2013-07-12 
 * References https://drupal.org/node/1842304 'Example: Programmatically create and update field collection with Entity API'
 */
function mo_project_custom_webform_38243_submit() {
  // load a user called $user_fields that has a field of the field collection type
  // called field_user_medal, which in turn is defined as having two fields
  // called field_user_medal_date_requested and field_user_medal_date_mailed
  global $user;
  $user_fields = user_load($user->uid);

  // create field_collection_item entity
  $fc_item = entity_create('field_collection_item', array('field_name' => 'field_user_medal'));

  // attach the new field collection item to the user
  $fc_item->setHostEntity('user', $user_fields);

/*  // use wrapper to make it easy to access and set values within the collection
  $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);  
  $now = time();
  $fc_wrapper->field_user_medal_date_requested->set($now);
  $fc_wrapper->field_user_medal_date_displayed->set(1);
  
  // save the field collection entity to the database
  $fc_wrapper->save(TRUE);
*/  
  if (empty($fc_item->field_user_medal_date_requested['LANGUAGE_NONE']['']['value'])) {
    $now = time();
    $fc_item->field_user_medal_date_requested[LANGUAGE_NONE][]['value'] = date('Y-m-d H:i:s', $now);
  } else {
    $fc_item->field_user_medal_date_requested[LANGUAGE_NONE][]['value'] = $fc_item->field_user_medal_date_requested['LANGUAGE_NONE']['']['value'];
  }
  if ( (empty($fc_item->field_user_medal_date_displayed['LANGUAGE_NONE']['']['value'])) 
    OR ($fc_item->field_user_medal_date_displayed['LANGUAGE_NONE']['']['value'] = 0) ) {
    $fc_item->field_user_medal_date_displayed[LANGUAGE_NONE][]['value'] = 1;
  } else {
    $fc_item->field_user_medal_date_displayed[LANGUAGE_NONE][]['value'] = $fc_item->field_user_medal_date_displayed['LANGUAGE_NONE']['']['value'];
  }
  if (!empty($fc_item->field_user_medal_date_displayed['LANGUAGE_NONE']['']['value'])) {
    $fc_item->field_user_medal_date_mailed[LANGUAGE_NONE][]['value'] = $fc_item->field_user_medal_date_mailed['LANGUAGE_NONE']['']['value'];
  }
  $fc_item->save();

  // field_attach_update saves field data for an existing entity but
  // doesn't save the entity itself.
  field_attach_update('user', $user_fields);
}

// DEV VERSION HAS A DIFFERENT NODE FORM ID NUMBER Not Anymore (2013-09-17)
/* function mo_project_custom_webform_13551_submit() {
  // load a user called $user_fields that has a field of the field collection type
  // called field_user_medal, which in turn is defined as having two fields
  // called field_user_medal_date_requested and field_user_medal_date_mailed
  global $user;
  $user_fields = user_load($user->uid);

  // create field_collection_item entity
  $fc_item = entity_create('field_collection_item', array('field_name' => 'field_user_medal'));

  // attach the new field collection item to the user
  $fc_item->setHostEntity('user', $user_fields);
  
  // use wrapper to make it easy to access and set values within the collection
  $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);  
  $now = time();
  $fc_wrapper->field_user_medal_date_requested->set($now);
  $fc_wrapper->field_user_medal_date_displayed->set(1);
  
  // save the field collection entity to the database
  $fc_wrapper->save(TRUE);
  
  // field_attach_update saves field data for an existing entity but
  // doesn't save the entity itself.
  field_attach_update('user', $user_fields);
} */


/**
 * Get nid of Request a Medal form and either:
 *   build table of unprocessed requests, or
 *   confirm user selections for mailing or deletion.
 * References B. Dickson's mo_cms_user_groups_membership_requests_form_ * functions
 * from mo_cms_user_groups module 
 * 2013-07-16 
 */
function mo_project_medal_request_details_form($form, &$form_state) {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.title', 'Request a Medal Status', '=');
  $nid = $query->execute()->fetchField();

  if (!empty($form_state['input']['admin_action'])) {
    return mo_project_medal_request_details_form_confirm($form, $form_state, $nid);
  }
  return mo_project_medal_request_details_form_actions($form, $form_state, $nid);
}

/**
 * Build table of unprocessed submissions from the Request a Medal form. 
 * 2013-07-12 
 */
function mo_project_medal_request_details_form_actions($form, &$form_state, $nid) {

  mo_project_add_webform_support();
  $webform_node = node_load($nid);
  $submissions = webform_get_submissions(array('nid' => $nid));
  $components = array();  
  // Give the components array human-readable array keys
  foreach ($webform_node->webform['components'] as $key=>$component) {
    $components[$component['form_key']] = $key;
  }
  
  // Create table headers
  $header = array(
    'id' => array(
      'data' => t('SID'),
    ),
    'nid' => array(
      'data' => t('NID'),
      'style' => 'display: none;',
    ),
    'uid' => array(
      'data' => t('UID'),
      'style' => 'display: none;',
    ),    
    'requested' => array(
      'data' => t('Date Requested'),
      'sort' => 'asc',
    ),
    'name' => t('Name'),
    'address' => t('Address'),
    'mailed' => t('Date Mailed'),
    'total_mileage' =>  array(
      'data' => t('Mileage To Date'),
      'sort' => 'desc',
    ),
  );

  $options = array(); 
  $addresses = array();
  
  if (!empty($submissions)) {
    foreach ($submissions as $submission) {
    
      // Get uid
      $query1 = db_select('webform_submissions', 'w');
      $query1->fields('w', array('uid'));
      $query1->condition('sid', $submission->sid, '=');
      $uid = $query1->execute()->fetchField();     
    
      // Get field collection item id     
      $query = db_select('field_data_field_user_medal', 'f');
      $query->fields('f', array('field_user_medal_value'));
      $query->condition('f.entity_id', $uid, '=');
      $query->condition('f.deleted', 0, '=');
      $item_id = $query->execute()->fetchField();

      if (empty($item_id) ) {
        $requestor = $submission->data[$components['requestor_uname']]['value'][0] . ' (' .
            $uid . ')';
        drupal_set_message('Unable to locate medal data for user ' . $requestor, 'error');
        continue;
      }
     
      // Get user's medal dates from field collection
      $fc_item = entity_load('field_collection_item', array($item_id));     
      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item[$item_id]); 

      if($fc_wrapper->field_user_medal_date_displayed->value() == 1) {
        $requested = date('M j Y, g:i a', $fc_wrapper->field_user_medal_date_requested->value());
        // Don't bother displaying already mailed requests
//      $mailed = $fc_wrapper->field_user_medal_date_mailed->value();
//      if(empty($mailed)) {
        $mailed = NULL; 
//      } else {
//        $mailed = date('M j Y, g:i a', $mailed);
//      }

      
        // Get user's name
        if(!empty($submission->data[$components['first_name']]['value'][0])) {
          $medalist_name = $submission->data[$components['first_name']]['value'][0] . ' ' . $submission->data[$components['last_name']]['value'][0];
          $mailto_fname = strtoupper($submission->data[$components['first_name']]['value'][0]);
        } else {
          $user_fields = user_load($uid);
          $gender = field_get_items('user', $user_node, 'field_user_gender');
          if ($gender == 'male') {
            $medalist_name = 'Mr. ' . $submission->data[$components['last_name']]['value'][0];
            $mailto_fname = 'MR.';            
          } elseif ($gender == 'female') {
            $medalist_name = 'Miss/Mrs. ' . $submission->data[$components['last_name']]['value'][0];
            $mailto_fname = 'MISS/MRS.';
          } else {
            $medalist_name = 'Mr./Mrs./Miss ' . $submission->data[$components['last_name']]['value'][0];
            $mailto_fname = 'MR./MRS./MISS';
          }
        }
        $mailto_lname = strtoupper($submission->data[$components['last_name']]['value'][0]);

        // Get mailing address
        $mailto_street1 = strtoupper($submission->data[$components['mailing_address']]['value'][0]['thoroughfare']);
        $mailto_city = strtoupper($submission->data[$components['mailing_address']]['value'][0]['locality']);
        $mailto_state = strtoupper($submission->data[$components['mailing_address']]['value'][0]['administrative_area']);
        $mailto_zip = strtoupper($submission->data[$components['mailing_address']]['value'][0]['postal_code']);
        
        // Get formatted standard 3-line address
        if(!empty($submission->data[$components['mailing_address']]['value'][0]['premise'])) {
          $medalist_address = $submission->data[$components['mailing_address']]['value'][0]['thoroughfare'] . 
          '<br>' . $submission->data[$components['mailing_address']]['value'][0]['premise'] . 
          '<br>' . $submission->data[$components['mailing_address']]['value'][0]['locality'] . 
          ', ' . $submission->data[$components['mailing_address']]['value'][0]['administrative_area'] . 
          ' ' . $submission->data[$components['mailing_address']]['value'][0]['postal_code'];
          $mailto_street2 = strtoupper($submission->data[$components['mailing_address']]['value'][0]['premise']);

        } else {
          $medalist_address = $submission->data[$components['mailing_address']]['value'][0]['thoroughfare'] . 
          '<br>' . $submission->data[$components['mailing_address']]['value'][0]['locality'] . 
          ', ' . $submission->data[$components['mailing_address']]['value'][0]['administrative_area'] . 
          ' ' . $submission->data[$components['mailing_address']]['value'][0]['postal_code'];
          $mailto_street2 = NULL;
        }
        
        // Get user's total mileage
        $mileage = number_format(mo_project_get_total_mileage(array($uid))) . ' mi';
        
        // Populate the options array with table row values
        $options[$submission->sid] = array(
          'id' => array(
            'data' => $submission->sid,
          ),
          'nid' => array(
            'data' => $nid,
            'style' => 'display: none;',
          ),
          'uid' => array(
            'data' => $uid,
            'style' => 'display: none;',
          ),
          'requested' => $requested,
          'name' => $medalist_name,
          'address' => $medalist_address,
          'mailed' => $mailed,
          'total_mileage' => $mileage,
        );
        
        // Create array for excel download
        $addresses[] = array(
          $submission->sid,
          $mailto_fname,
          $mailto_lname,
          $mailto_street1, 
          $mailto_street2,
          $mailto_city, 
          $mailto_state,
          $mailto_zip, 
        );        
      }
    }
    $downloaded = mo_project_export_addresses($addresses);
  }
  
  // Create the form
  $form = array(
    'admin_action' => array(
      '#type' => 'select',
      '#title' => t('Action'),
      '#attributes' => array(),
      '#options' => array(
        'none' => t('- Select -'),
        'mail' => t('Mark as Mailed'),
        'delete' => t('Delete'),
      ),
    ),
    'table' => array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#multiple' => TRUE,
      '#empty' => 'Congratulations! There are no medal requests to be approved.',
    ),
    'nid' => array(
      '#type' => 'hidden',
      '#value' => $webform_node->nid,
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Submit'),
      '#attributes' => array(
        'id' => 'medal-action',
      ),
    ),
  );
  $form['download_button'] = array(
      '#type' => 'submit',
      '#value' => t('Download Spreadsheet'),
      '#attributes' => array(
        'id' => 'download',
      ),
  ); 
    
  return $form;
}

/**
 * Use File API to locate and provide the created excel file to the user
 * 2013-07-24 
 * References http://drupal.stackexchange.com/questions/34244/
 * creating-a-file-object-from-a-file-already-in-public-drupal-7
 * References: http://blog.sebcorbin.fr/en/how-force-downloading-file-drupal-7
 */
function mo_project_medal_request_download_excel() {
  // Check the medals directory for files
  $directory = 'sites/default/files/medals';
  $scanned_directory = array_diff(scandir($directory), array('..', '.'));
  if (count($scanned_directory) >= 1) {
    // Get the filename of the latest excel file
    $scanned_directory = array_reverse($scanned_directory);
    $filename = $scanned_directory[0];
    
    // Create a file object
    global $user;
    $uri = 'public://medals/' . $filename;
    $file = new stdClass;
    $file->uid = $user->uid;
    $file->filename = $filename;
    $file->uri = $uri;
    $file->filemime = 'application/vnd.ms-excel';
    $file->filesize = filesize($uri);
    $file->status = 1;

    // Force file download
    file_transfer($file->uri, array('Content-disposition' => 'attachment; filename=' . $file->filename));  
    // NOTE:  DO NOT CODE BELOW THIS LINE!!
    // As soon as the file transfer is complete, Drupal calls drupal_exit().
    // No further code is executed automatically.
    // In this case it is okay, because the user is already back to the approval listing.
    // They should be expecting to need to click something to resume interaction with the site.
  }
}

/**
 * On submit, verify that user chose a request, and an action to perform on that request.
 * Call mo_project_medal_request_details_do_action function to mark requests as mailed, or
 * remove requests from the display.
 * 2013-07-16 
 */
function mo_project_medal_request_details_form_submit($form_id, &$form_state) {
  if (empty($form_state['input']['admin_action']) or $form_state['input']['admin_action'] == 'none') {

      if ($form_state['input']['op'] == 'Submit') {
        drupal_set_message('No action selected.', 'warning');
      }
      elseif ($form_state['input']['op'] == 'Download Spreadsheet') {
        mo_project_medal_request_download_excel();
      }
      return;

  } elseif (isset($form_state['input']['admin_action']) and in_array($form_state['input']['admin_action'], array('mail', 'delete'))) {
    if (empty($form_state['input']['table'])) {
      drupal_set_message('No submissions were selected.', 'warning');
      return;
    }
  }
  if (isset($form_state['input']['process']) and $form_state['input']['process']) {
    $targets = array();
    foreach ($form_state['values']['table'] as $row_id) {
      $targets[$row_id] = $row_id;
    }
    mo_project_medal_request_details_do_action($targets, $form_state['values']['nid'], $form_state['values']['admin_action']);
  } else {
    $form_state['rebuild'] = TRUE;
  } 
}

/**
 * Confirm changes to database before proceeding.
 * 2013-07-16 
 */
function mo_project_medal_request_details_form_confirm($form, &$form_state, $nid) {
  mo_project_add_webform_support();
  $submissions = webform_get_submissions(array('nid' => $nid));

  if(empty($form_state['input']['admin_action'])) {
    $form_state['input']['admin_action'] = NULL;
  }
  $desc = array(
    '#type' => 'markup',
    '#markup' => t('<p>Are you sure you wish to <b>' . $form_state['input']['admin_action'] . '</b> the following requests?</p>'),
  );
  $items_list = array(
    'type' => 'ul',
    'title' => NULL,
    'attributes' => array(),
    'items' => array(),
  );
  if(!empty($form_state['input']['table'])) {
    foreach ($form_state['input']['table'] as $row_id) {
      $request = $submissions[$row_id];
    
      // User's name
      $items_list['items'][] = $request->data[8]['value'][0] . ' ' . $request->data[9]['value'][0];
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
  }
  $form['process'] = array(
    '#type' => 'hidden',
    '#value' => 'true',
  );
  $form['destination'] = array(
    '#type' => 'hidden',
    '#value' => 'medals/approve',
  );
  return confirm_form($form, 'Are you sure?', 'medals/approve', render($desc), 'Continue', 'Cancel');
}

/**
 * If the passed in $form_state['input']['admin_action'] is 'delete', then 
 * mark the field collection  field_data_field_user_medal  as not displayed.
 * (All this really does is remove the request from the display on the Approve Medals form,
 * and disallow the user to make a new request.)
 * If the passed in $form_state['input']['admin_action'] is 'mail', then
 * store the field_user_medal_date_mailed date in the field collection to 
 * mark the request as approved and mailed.
 * Then also mark the field collection as not displayed.
 * 2013-07-24 
 */
function mo_project_medal_request_details_do_action($targets, $nid, $action) {
  if($action == 'mail') {
    mo_project_add_webform_support();
    $submissions = webform_get_submissions(array('nid' => $nid));
    $addresses = array();
  } 

  foreach ($targets as $webform_sid) {
    // get uid from table 'webform_submissions' where sid = target
    $query1 = db_select('webform_submissions', 'w');
    $query1->fields('w', array('uid'));
    $query1->condition('w.sid', $webform_sid, '=');
    $query1->condition('w.nid', $nid, '=');    
    $uid = $query1->execute()->fetchField();
    
    // load the user 
    $user_fields = user_load($uid);
    
    // get item_id from table 'field_data_field_user_medal' where uid = entity_id
    $query2 = db_select('field_data_field_user_medal', 'f');
    $query2->fields('f', array('field_user_medal_value'));
    $query2->condition('f.entity_id', $uid, '=');
    $item_id = $query2->execute()->fetchField();

    // get the field collection entity
    $fc_item = entity_load('field_collection_item', array($item_id));
    
    // use wrapper to make it easy to access and set values within the collection
    $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item[$item_id]);  
    if($action == 'mail') {
      $now = time();
      $fc_wrapper->field_user_medal_date_mailed->set($now);
    }
    $fc_wrapper->field_user_medal_date_displayed->set(0);
    
    // save the field collection entity to the database
    $fc_wrapper->save(TRUE);

    // field_attach_update saves field data for an existing entity but
    // doesn't save the entity itself.
    field_attach_update('user', $user_fields);
    
    // save the user
    
  }
}

/**
 * Use PHPExcel library to create and save an excel 2007 (.xlsx) file of the approved
 * medal requests.  This file will be available to the user for downloading later.
 * References: http://stackoverflow.com/questions/7834755/drupal-export-data-from-table-to-excel
 * References: https://github.com/PHPOffice/PHPExcel/wiki/User%20Documentation
 * References: https://drupal.org/node/1342238 Using Libraries API 2.x
 * 2013-07-24 
 */
function mo_project_export_addresses($a) {
  $lib_path = libraries_get_path('phpexcel');
  $lib_path .= '/Classes/PHPExcel.php';
  require_once($lib_path);

  $objPHPExcel = new PHPExcel();
  $objPHPExcel->setActiveSheetIndex(0);
  $objPHPExcel->getActiveSheet()->setTitle('Address List');

  // Set header row
  $objPHPExcel->getActiveSheet()
      ->setCellValue('A1', 'SID')
      ->setCellValue('B1', 'FIRST NAME')
      ->setCellValue('C1', 'LAST NAME')
      ->setCellValue('D1', 'STREET1')
      ->setCellValue('E1', 'STREET2')
      ->setCellValue('F1', 'CITY')
      ->setCellValue('G1', 'STATE')
      ->setCellValue('H1', 'ZIP');
      
  // Set the default column width
  $objPHPExcel->getActiveSheet()->getDefaultColumnDimension()->setWidth(20);
  
  // Loop through the address array
  $rowNumber = 2;
  foreach ($a AS $row) {
    $col = 'A';
    foreach($row as $cell) {  
      $objPHPExcel->getActiveSheet()->setCellValue($col . $rowNumber, $cell);
      $col++;
    }
    $rowNumber++;
  }
      
  // Save the spreadsheet to public/files/medals
  $filename = 'medals_' . date('YmdHis') . '.xlsx';
  $fullname = 'sites/default/files/medals/' . $filename;
  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel2007');
  $objWriter->save($fullname);
}

/**
 * Register the PHPExcel library with Drupal
 * References: https://drupal.org/node/1342238 Using Libraries API 2.x
 * 2013-07-16 
 */
function mo_project_libraries_info() {
  $libraries['phpexcel'] = array(
    // Only used in administrative UI of Libraries API.
    'name' => 'PHPExcel library',
    'vendor url' => 'http://www.phpexcel.net',
    'download url' => 'http://phpexcel.codeplex.com/#',
    // Optional: If, after extraction, the actual library files are contained in
    // 'sites/all/libraries/example/lib', specify the relative path here.
    'path' => 'Classes',
    // This doesn't work and I don't know why
    'version arguments' => array(
      'file' => 'VERSION.txt',
      'pattern' => '@version\s+([0-9a-zA-Z\.-]+)@',
    ),
    // Default list of files of the library to load. Important: Only specify
    // third-party files belonging to the library here, not integration files of
    // your module.
    'files' => array(
      // For PHP libraries, specify include files here, still relative to the
      // library path.
      'php' => array(
        'PHPExcel.php',
      ),
    ),
  );
  return $libraries;
}

/**
 * Redundancy to ensure that the webform submission of a medal request 
 * creates and populates the file collection  field_user_medal_value
 * 2013-08-14 
 */
function mo_project_locate_medalists() {
  // load all the webform submissions without a field collection record
  $subquery = db_select('webform_submissions', 'w');
  $subquery->fields('w', array('uid', 'submitted'));
  $subquery->condition('w.is_draft', 0, '=');
// DEV VERSION HAS A DIFFERENT NODE NUMBER - Not Anymore (2013-09-17)
//  if ($_SERVER['SERVER_NAME'] == '100missourimiles.com') {  
    $subquery->condition('w.nid', 38243, '=');
//  } else {
//    $subquery->condition('w.nid', 13551, '=');
//  }

  $query = db_select($subquery, 's');
  $query->leftJoin('field_data_field_user_medal', 'm', 's.uid = m.entity_id');
  $query->fields('s', array('uid', 'submitted'));
  $query->isNull('m.entity_id');
  $result = $query->execute()->fetchAll();

  // create the field collection for each orphaned submission
  foreach ($result AS $row1) {
    $row = (array)$row1;
    
    // load the user entity
    $user_ent = user_load($row['uid']);

    if ($user_ent == FALSE) {
      drupal_set_message('Unable to load user ' . $row['uid'], 'error');
      continue;
    } else {
      // create field_collection_item entity
      $fc_item = entity_create('field_collection_item', array('field_name' => 'field_user_medal'));

      // attach the new field collection item to the user
      $fc_item->setHostEntity('user', $user_ent);
                
      $requested = date('Y-m-d H:i:s', $row['submitted']);
      $fc_item->field_user_medal_date_requested[LANGUAGE_NONE][]['value'] = $requested;
      $fc_item->field_user_medal_date_displayed[LANGUAGE_NONE][]['value'] = 1;
      $fc_item->save();
      
      // field_attach_update saves field data for an existing entity but
      // doesn't save the entity itself.
      field_attach_update('user', $user_ent);
    }
  }
}

function mo_project_show_medal_status($block_delta = '') {

  global $user;
  $user_total_mileage = mo_project_get_total_mileage(array($user->uid));

  $output = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $block_delta,
      'class' => array(
        $block_delta,
      ),
    ),
  );
  
  if ($block_delta == 'medal-status') {
      // If $user_miles < 100
      if ($user_total_mileage < 100.00) {
          $output[0] = array(
            '#type' => 'markup',
            '#markup' => t("<p>You're well on your way to earning your medal; you only need to <b>log " . number_format((int) (100.00 - round($user_total_mileage)), 0) . " more miles!</b> Check back here when you reach 100 to request your medal.</p>"),
          );
          
      } else {    // User has logged at least 100 miles
          // Has the user already requested a medal?
          $qry = db_select('webform_submissions', 's');
          $qry->fields('s', array('sid'));
          $qry->condition('s.nid', '38243', '=');
          $qry->condition('s.is_draft', '0', '=');  
          $qry->condition('s.uid', $user->uid, '=');
          $requested = $qry->execute()->fetchField();

          // User has not requested a medal before, show medal request form
          if ($requested == FALSE) {     
              $output[0] = array(
                '#type' => 'markup',
                '#markup' => t("<p>Congratulations, you've completed the Governor's 100 Missouri Mile Challenge! Please fill out the form below to request your medal and it will be mailed out to you within 2-3 weeks.</p>"),
              );      
              
          } else {     // $request_medal exists, show "We received your request for a medal on $request_medal"

            $user_node = user_load($user->uid);    
            $fc_fields = field_get_items('user', $user_node, 'field_user_medal');
            if(!empty($fc_fields)) {
              $item = field_collection_item_load($fc_fields[0]['value']);
              $request_medal = field_get_items('field_collection_item', $item, 'field_user_medal_date_requested');
              $mailed_medal = field_get_items('field_collection_item', $item, 'field_user_medal_date_mailed');
            }
            if (!empty($request_medal)) {
              // Has the medal already been mailed?
              if (!empty($mailed_medal)) {
                  // $mailed_medal exists, show "We mailed your medal on $mailed_medal"
                  $output[0] = array(
                    '#type' => 'markup',
                    '#markup' => t("<p>Thank you for completing the Governor's 100 Missouri Mile Challenge! Our records show we received your request for a medal on  " . date('F j, Y', strtotime($request_medal[0]['value'])) . ".</p>" . 
                    "<p>Your medal was mailed on " . date('F j, Y', strtotime($mailed_medal[0]['value'])) . '.</p><p>If you have questions, or still have not received your medal, please e-mail us:<br><a href="mailto:emailaddress@mail.com" target="_blank">mailto:emailaddress@mail.com</a>.</p>'),
                  );
                  
              } else {
                  $weekday = date('w', strtotime($request_medal[0]['value']));
                 
                  if ($weekday == 6) {
                    $next_week = strtotime("+2 weeks 2 days", strtotime($request_medal[0]['value']));
                  } elseif ($weekday == 0) {
                    $next_week = strtotime("+2 weeks 1 day", strtotime($request_medal[0]['value']));
                  } else {
                    $next_week = strtotime("+2 weeks", strtotime($request_medal[0]['value']));
                  }
                  
                  $output[0] = array(
                    '#type' => 'markup',
                    '#markup' => t("<p>Thank you for completing the Governor's 100 Missouri Mile Challenge! Our records show that you've requested your medal on " . date('F j, Y', strtotime($request_medal[0]['value'])) . ".</p>" . 
                    "<p>Your medal should be mailed by " . date('F j, Y', $next_week) . '.</p><p>If you have questions, or still have not received your medal, please e-mail us:<br><a href="mailto:emailaddress@mail.com" target="_blank">mailto:emailaddress@mail.com</a>.</p>'),
                  );        
              }
            } else {
              $output[0] = array(
                '#type' => 'markup',
                '#markup' => t("<p>Thank you for completing the Governor's 100 Missouri Mile Challenge! We have received your request for a medal and it will be mailed out to you within 2-3 weeks.</p>" . '<p>If you have questions, or it has been more than 3 weeks since your request and you still have not received your medal, please e-mail us:<br><a href="mailto:emailaddress@mail.com" target="_blank">mailto:emailaddress@mail.com</a>.</p>'),    
              ); 
            }
          }
      }
  }
  
  if ($block_delta == 'my-medal') {
    // Show link to content/medal-request
    $output[0] = array(
      '#type' => 'markup',
      '#markup' => l('Check medal status', 'content/request-medal-status', array(
          'attributes' => array(
              'id' => 'req-medal', 
              'class' => array('req-medal'),
          )
      ))
    );          
  }
  $output[1] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'clearfix',
      ),
    ),
  );
  return $output;
}  



