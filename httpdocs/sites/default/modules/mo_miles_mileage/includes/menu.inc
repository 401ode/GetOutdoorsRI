<?php
/**
 *  @file  menu.inc
 *  @brief  Code for the MO project: 100 Missouri Miles.com
 *
 *  @details
 *  mo_miles_mileage_menu = Implements hook_menu
 *  
 *  
 */


/**
 *  @brief  Implements hook_menu()
 *
 *  @details  2014-09-12 
 */
/****************************
 *  don't know why this is not working. 

function mo_miles_mileage_menu() {

  $items = array();
  
  $items['admin/data/mileage-convert'] = array(
    'title' => 'Convert Mileage Nodes to Entities',
    'description' => 'Convert existing mileage nodes to mileage entities.',
    'page callback' => 'mo_miles_mileage_convert',
//    'access arguments' => array('access administration pages', 'administer mileage'),
    'access arguments' => array('access content'),
    'type' => MENU_NORMAL_ITEM,
  );  

  
// Below examples from   http://www.trellon.com/content/blog/creating-own-entities-entity-api
  
  
  $items['mileage/add'] = array(
    'title' => 'Add mileage',
    'page callback' => 'mo_miles_mileage_admin_add_page',
    'access arguments' => array('administer mileage'),
    'file' => 'mo_miles_mileage.admin.inc',
    'type' => MENU_LOCAL_ACTION,
    'tab_parent' => 'mileage',
    'tab_root' => 'mileage',
  );

  $mileage_uri = 'mileage/%mo_miles_mileage';
  $mileage_uri_argument_position = 1;

  $items[$mileage_uri] = array(
    'title callback' => 'entity_label',
    'title arguments' => array('mo_miles_mileage', $mileage_uri_argument_position),
    'page callback' => 'mo_miles_mileage_view',
    'page arguments' => array($mileage_uri_argument_position),
    'access callback' => 'entity_access',
    'access arguments' => array('view', 'mo_miles_mileage', $mileage_uri_argument_position),
    'file' => 'mo_miles_mileage.pages.inc',
  );

  $items[$mileage_uri . '/view'] = array(
    'title' => 'View',
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'weight' => -10,
  );

  $items[$mileage_uri . '/delete'] = array(
    'title' => 'Delete mileage',
    'title callback' => 'mo_miles_mileage_label',
    'title arguments' => array($mileage_uri_argument_position),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mo_miles_mileage_delete_form', $mileage_uri_argument_position),
    'access callback' => 'entity_access',
    'access arguments' => array('edit', 'mo_miles_mileage', $mileage_uri_argument_position),
    'file' => 'mo_miles_mileage.admin.inc',
  );

  $items[$mileage_uri . '/edit'] = array(
    'title' => 'Edit',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mo_miles_mileage_form', $mileage_uri_argument_position),
    'access callback' => 'entity_access',
    'access arguments' => array('edit', 'mo_miles_mileage', $mileage_uri_argument_position),
    'file' => 'mo_miles_mileage.admin.inc',
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
  );

  foreach (mo_miles_mileage_types() as $type => $info) {
    $items['mileage/add/' . $type] = array(
      'title' => 'Add mileage',
      'page callback' => 'mo_miles_mileage_add',
      'page arguments' => array(2),
      'access callback' => 'entity_access',
      'access arguments' => array('create', 'mo_miles_mileage', $type),
      'file' => 'mo_miles_mileage.admin.inc',
    );
  }

  $items['admin/structure/mileage-types/%mo_miles_mileage_type/delete'] = array(
    'title' => 'Delete',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mo_miles_mileage_type_form_delete_confirm', 4),
    'access arguments' => array('administer mileage'),
    'weight' => 1,
    'type' => MENU_NORMAL_ITEM,
    'file' => 'mo_miles_mileage.admin.inc',
  );
  
  return $items;
}
 */