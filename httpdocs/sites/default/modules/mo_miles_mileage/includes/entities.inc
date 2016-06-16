<?php
/**
 *  @file  entities.inc
 *  @brief  Code for the MO project: 100 Missouri Miles.com
 *
 *  @details
 *  mo_miles_mileage_entity_info = Implements hook_entity_info
 *  mo_miles_mileage_entity_property_info = Implements hook_entity_property_info
 *  mo_miles_mileage_permission = Implements hook_permission
 *  mo_miles_mileage_access_callback = Access callback for mileage entities
 *  mileage_form = Form definition for adding / editing mileage
 *  mileage_form_submit = Submit handler for the mileage add/edit form
 *  class MileageEntityController
 *  buildContent = (public) Extends the EntityAPIController for the Mileage entity.
 *  class MileageEntity
 *  defaultUri = (protected) Change the default URI from default/id to mileage/id
 */


/**
 *  @brief Implements hook_entity_info().
 *  
 *  @details 2014-09-09 
 */
function mo_miles_mileage_entity_info() {
  
  $info = array();
  
  $info['mileage'] = array(
    'label' => t('Mileage'),
    'base table' => 'mo_miles_mileage',
    'entity keys' => array(
      'id' => 'id',
      'label' => 'title',
    ),
    'entity class' => 'MileageEntity',
    'controller class' => 'MileageEntityController',
    'access callback' => 'mo_miles_mileage_access_callback',
    'uri callback' => 'entity_class_uri',
    'admin ui' => array(
      'path' => 'admin/mileage',
      'controller class' => 'EntityDefaultUIController',
    ),
    'fieldable' => FALSE,
    'bundles' => array(
      'mileage' => array(
        'label' => t('Mileage'),
        'admin' => array(
          'path' => 'admin/mileage',
        ),
      ),
    ),
    'views controller class' => 'EntityDefaultViewsController',
    'module' => 'mo_miles_mileage',
  );
  
  return $info;
}

/**
 *  @brief Implements hook_entity_property_info().
 *  
 *  @details 2014-09-09 
 */
function mo_miles_mileage_entity_property_info() {
  
  $info = array();
  
  $info['mileage']['properties']['id'] = array(
    'label' => t('Mileage Entry ID'),
    'description' => t('The ID of the mileage entry.'),
    'type' => 'integer',
    'schema field' => 'id',
  );

  $info['mileage']['properties']['title'] = array(
    'label' => t('Title'),
    'description' => t('Title of the mileage entry.'),
    'type' => 'text',
    'schema field' => 'title',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
  );

  $info['mileage']['properties']['uid'] = array(
    'label' => t('Member UID'),
    'description' => t('The UID of the mileage entry\'s owner.'),
//    'type' => 'integer',
    'type' => 'user',    
    'schema field' => 'uid',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage',    
  );

  $info['mileage']['properties']['date'] = array(
    'label' => t('Date'),
    'description' => t('The date of the mileage entry.'),
    'type' => 'date',
    'schema field' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
    );

  $info['mileage']['properties']['distance'] = array(
    'label' => t('Distance'),
    'description' => t('Amount of mileage entered.'),
    'type' => 'decimal',
    'schema field' => 'distance',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
  );

  $info['mileage']['properties']['activity_tid'] = array(
    'label' => t('Activity'),
    'description' => t('The TID of the mileage entry\'s activity.'),
    'type' => 'integer',
    'schema field' => 'activity_tid',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
  );

  $info['mileage']['properties']['location'] = array(
    'label' => t('Location'),
    'description' => t('Location of the mileage entry.'),
    'type' => 'text',
    'schema field' => 'location',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
  );
  
  $info['mileage']['properties']['note'] = array(
    'label' => t('Note'),
    'description' => t('Note about the mileage entry.'),
    'type' => 'text',
    'schema field' => 'note',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
  );

  $info['mileage']['properties']['status'] = array(
    'label' => t('Status'),
    'description' => t('Boolean indicating whether the node is published (visible to non-administrators).'),
    'type' => 'integer',  
    'schema field' => 'status',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage',    
  );

  $info['mileage']['properties']['created'] = array(
    'label' => t('Created Date'),
    'description' => t('The Unix timestamp when the entity was created.'),
    'type' => 'date',
    'schema field' => 'created',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
    );

  $info['mileage']['properties']['changed'] = array(
    'label' => t('Changed Date'),
    'description' => t('The Unix timestamp when the entity was most recently saved.'),
    'type' => 'date',
    'schema field' => 'changed',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage', 
    );

  $info['mileage']['properties']['uuid'] = array(
    'label' => t('UUID'),
    'description' => t('The Universally Unique Identifier.'),
    'type' => 'text',  
    'schema field' => 'uuid',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage',    
  );

  $info['mileage']['properties']['old_nid'] = array(
    'label' => t('OLD node id'),
    'description' => t('The old nid of the mileage entry.'),
    'type' => 'integer',  
    'schema field' => 'old_nid',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer mileage',    
  );
  
  return $info;
}

/**
 *  @brief Implements hook_permission()
 *  
 *  @details 2014-09-09 
 */
function mo_miles_mileage_permission() {
  return array(
    'administer mileage' => array(
      'title' => t('Administer mileage'),
      'description' => t('Create, edit, and delete mileage entries.'),
    ),
  );
}

/**
 *  @brief Access callback for mileage entities.
 *  
 *  @param [in] $op      #TODO Parameter_Description
 *  @param [in] $mileage #TODO Parameter_Description
 *  @param [in] $account #TODO Parameter_Description
 *  @return TRUE if user is allowed to administer mileage, FALSE otherwise
 *  
 *  @details 2014-09-09 
 */
function mo_miles_mileage_access_callback($op, $mileage=NULL, $account=NULL) {
  if (user_access('administer mileage')) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 *  @brief Form definition for adding / editing mileage.
 *  
 *  @param [in] $mileage #TODO Parameter_Description
 *  @return Render array $form
 *  
 *  @details 2014-09-09 
 */
function mileage_form($form, &$form_state, $mileage=NULL) {
  
  if (isset($mileage->title)) {
    $default_title = $mileage->title;
  } else {
    global $user;
    $default_title = t('Mileage Record: !user_name !current_date', array('!user_name' => format_username($user), '!current_date' => format_date(time())));
  }
  if (isset($mileage->date)) {
    $default_date = date('Y-m-d', $mileage->date);
  } else {
    $default_date = date('Y-m-d 00:00:00');
  }
  
  $form['#attributes'] = array(
    'class' => array(
      'entity-form',
    ),
  );
  
  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $default_title,
    '#required' => TRUE,
    '#weight' => -10,
    '#disabled' => TRUE,
  );
  
  $form['date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date'),
    '#size' => 10,
    '#default_value' => $default_date,
    '#date_format' => 'Y-m-d',
    '#date_label_position' => 'within',
    '#date_timezone' => 'America/Chicago',
    '#date_year_range' => '0:0',
    '#datepicker_options' => array(
      'maxDate' => 0,
    ),
    '#required' => TRUE,
  );

  $v = taxonomy_vocabulary_machine_name_load('activities');
  $v_tree = taxonomy_get_tree($v->vid, 0, 1);
  $allowed_values = array();
  foreach ($v_tree as $t) {
    if ($t->name == 'Other') {
      continue;
    }
    $allowed_values[$t->tid] = t($t->name);
  }
  
  $form['activity_tid'] = array(
    '#type' => 'select',
    '#title' => t('Activity'),
    '#options' => $allowed_values,
    '#default_value' => isset($mileage->activity_tid) ? $mileage->activity_tid : '',
  );
  
  $form['location'] = array(
    '#type' => 'textfield',
    '#id' => 'mileage-location',
    '#title' => t('Location'),
    '#autocomplete_path' => 'ajax/mileage_location_autocomplete',
    '#default_value' => isset($mileage->location) ? $mileage->location : '',
  );

  $form['distance'] = array(
    '#type' => 'textfield',
    '#title' => t('Distance'),
    '#size' => 6,
    '#default_value' => isset($mileage->distance) ? $mileage->distance : '',
    '#required' => TRUE,
  );
  
  $form['units'] = array(
    '#type' => 'select',
    '#options' => array(
      'miles' => t('Mi'),
      'kilometers' => t('Km'),
    ),
    '#default_value' => isset($mileage->units) ? $mileage->units : 'miles',
    '#required' => TRUE,
  );

  $form['note'] = array(
    '#title' => t('Note'),
    '#type' => 'textarea',
    '#default_value' => isset($mileage->note) ? $mileage->note : '',
  );

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => isset($mileage->id) ? t('Update') : t('Save'),
    '#weight' => 50,
  );

  return $form;
}

/**
 *  @brief Submit handler for the mileage add/edit form.
 *  
 *  @details 2014-09-09 
 */
function mileage_form_submit($form, &$form_state) {
//****************************************************************************************
// *
// * THIS NEEDS TO BE ADJUSTED TO ACCOUNT FOR ADDITIONAL FIELDS
// * `status`, `created`, `changed`, `uuid`
// *
//****************************************************************************************

  global $user;
  $mileage = entity_ui_form_submit_build_entity($form, $form_state);
  $mileage->uid = $user->uid;
  $mileage->date = strtotime($mileage->date);
  
  $mileage->save();
  drupal_set_message(t('The mileage entry: @title has been saved.', array('@title' => $mileage->title)));
  $form_state['redirect'] = 'admin/mileage';
}

/**
 *  @brief Extending the EntityAPIController for the Mileage entity.
 *  
 *  @details 2014-09-09 
 */
class MileageEntityController extends EntityAPIController {

  /**
   *  @brief Extends the EntityAPIController for the Mileage entity.
   *  
   *  @details 2014-09-09 
   */
  public function buildContent($entity, $view_mode='full', $langcode=NULL, $content=array()) {
    
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    
    return $build;
  
  }
  
}
  
/**
 *  @brief Mileage entity class extending the Entity class
 *  
 *  @details 2014-09-09 
 */
class MileageEntity extends Entity {
  
  /**
   *  @brief Change the default URI from default/id to mileage/id
   *  
   *  @details 2014-09-09 
   */
  protected function defaultUri() {
    return array('path' => 'mileage/' . $this->identifier());
  }
  
}
