<?php

/**
 * @file
 * Customize the display of the Request a Medal webform.
 * 2013-10-17 by D. Trussell
 */
?>
<?php
  global $user;
  $hide = FALSE;

  $mileage = mo_project_get_total_mileage(array($user->uid));
  print $hide;
  if ( (empty($mileage)) OR ($mileage < 100.00) ) {
    $hide = TRUE;
    
  } else {
    $qry = db_select('webform_submissions', 's');
    $qry->fields('s', array('sid'));
    $qry->condition('s.nid', '38243', '=');
    $qry->condition('s.is_draft', '0', '=');  
    $qry->condition('s.uid', $user->uid, '=');
    $requested = $qry->execute()->fetchField();

    if ($requested == FALSE) {
      // No sids were found
      $hide = FALSE;
    } else {
      $hide = TRUE;
  
    }
  }

  if ($hide == FALSE) {
    // remove options for State dropdown that are outside the contiguous 48 states
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['AA']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['AE']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['AK']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['AP']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['AS']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['FM']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['GU']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['HI']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['MH']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['MP']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['PW']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['PR']);
    unset($form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#options']['VI']);

    // Pre-populate form
    $query = db_select('field_data_field_mo_cms_postal_address', 'ad');
    $query->join('field_data_field_user_first_name', 'fn', 'ad.entity_id = fn.entity_id AND (fn.entity_type = :type AND fn.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));  
    $query->join('field_data_field_user_last_name', 'ln', 'ad.entity_id = ln.entity_id AND (ln.entity_type = :type AND ln.deleted = :deleted)', array(':type' => 'user', ':deleted' => 0));
    $query->fields('ad', array('field_mo_cms_postal_address_thoroughfare', 'field_mo_cms_postal_address_premise', 'field_mo_cms_postal_address_locality', 'field_mo_cms_postal_address_administrative_area', 'field_mo_cms_postal_address_postal_code'));
    $query->fields('fn', array('field_user_first_name_value'));
    $query->fields('ln', array('field_user_last_name_value'));
    $query->condition('ad.entity_type', 'user', '=');
    $query->condition('ad.deleted', 0, '=');  
    $query->condition('ad.entity_id', $user->uid, '=');

    $result = $query->execute();
    if ($result) {
      foreach ($result as $row) {
        if (!empty($row->field_user_first_name_value)) {
          $form['submitted']['contact_information']['first_name']['#value'] = $row->field_user_first_name_value;
        }
        if (!empty($row->field_user_last_name_value)) {
          $form['submitted']['contact_information']['last_name']['#value'] = $row->field_user_last_name_value;
        }
        if (!empty($row->field_mo_cms_postal_address_thoroughfare)) {
          $form['submitted']['contact_information']['mailing_address']['street_block']['thoroughfare']['#value'] = $row->field_mo_cms_postal_address_thoroughfare;
        }
        if (!empty($row->field_mo_cms_postal_address_premise)) {
          $form['submitted']['contact_information']['mailing_address']['street_block']['premise']['#value'] = $row->field_mo_cms_postal_address_premise;
        }
        if (!empty($row->field_mo_cms_postal_address_locality)) {
          $form['submitted']['contact_information']['mailing_address']['locality_block']['locality']['#value'] = $row->field_mo_cms_postal_address_locality;
        }
        if (!empty($row->field_mo_cms_postal_address_administrative_area)) {
          $form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#value'] = $row->field_mo_cms_postal_address_administrative_area;
        } else {
          $form['submitted']['contact_information']['mailing_address']['locality_block']['administrative_area']['#value'] = 'MO';  
        }
        if (!empty($row->field_mo_cms_postal_address_postal_code)) {
          $form['submitted']['contact_information']['mailing_address']['locality_block']['postal_code']['#value'] = $row->field_mo_cms_postal_address_postal_code;
        }      
      }
    }  
    
    // Print out the main part of the form.
    // Feel free to break this up and move the pieces within the array.
    print drupal_render($form['submitted']);

    // Always print out the entire $form. This renders the remaining pieces of the
    // form that haven't yet been rendered above.
    print drupal_render_children($form);
  } else {
    print '<br>';
  }
