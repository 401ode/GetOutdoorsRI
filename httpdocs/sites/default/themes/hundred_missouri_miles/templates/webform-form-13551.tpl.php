<?php

/**
 * @file
 * Customize the display of the Request a Medal webform.
 * 2013-07-11 by D. Trussell
 */
?>
<?php
global $user;

  // remove options for State dropdown that are outside the contiguous 48 states
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['AA']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['AE']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['AK']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['AP']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['AS']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['FM']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['GU']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['HI']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['MH']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['MP']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['PW']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['PR']);
  unset($form['submitted']['mailing_address']['locality_block']['administrative_area']['#options']['VI']);

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
        $form['submitted']['first_name']['#value'] = $row->field_user_first_name_value;
      }
      if (!empty($row->field_user_last_name_value)) {
        $form['submitted']['last_name']['#value'] = $row->field_user_last_name_value;
      }
      if (!empty($row->field_mo_cms_postal_address_thoroughfare)) {
        $form['submitted']['mailing_address']['street_block']['thoroughfare']['#value'] = $row->field_mo_cms_postal_address_thoroughfare;
      }
      if (!empty($row->field_mo_cms_postal_address_premise)) {
        $form['submitted']['mailing_address']['street_block']['premise']['#value'] = $row->field_mo_cms_postal_address_premise;
      }
      if (!empty($row->field_mo_cms_postal_address_locality)) {
        $form['submitted']['mailing_address']['locality_block']['locality']['#value'] = $row->field_mo_cms_postal_address_locality;
      }
      if (!empty($row->field_mo_cms_postal_address_administrative_area)) {
        $form['submitted']['mailing_address']['locality_block']['administrative_area']['#value'] = $row->field_mo_cms_postal_address_administrative_area;
      } else {
        $form['submitted']['mailing_address']['locality_block']['administrative_area']['#value'] = 'MO';  
      }
      if (!empty($row->field_mo_cms_postal_address_postal_code)) {
        $form['submitted']['mailing_address']['locality_block']['postal_code']['#value'] = $row->field_mo_cms_postal_address_postal_code;
      }      
    }
  }  
  $form['submitted']['mailing_address']['country']['#disabled'] = TRUE;
  
  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
  print drupal_render($form['submitted']);

  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above.
  print drupal_render_children($form);
