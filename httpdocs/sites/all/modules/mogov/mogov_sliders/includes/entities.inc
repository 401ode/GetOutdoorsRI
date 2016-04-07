<?php

/**
 * Implements hook_entity_info().
 */
function mogov_sliders_entity_info() {
  
  $info = array();
  
  $info['mogov_slider'] = array(
    'label' => t('Slider'),
    'base table' => 'mogov_sliders',
    'entity keys' => array(
      'id' => 'id',
      'bundle' => 'bundle',
      'label' => 'title',
    ),
    'entity class' => 'SliderEntity',
    'controller class' => 'SliderEntityController',
    'access callback' => 'mogov_sliders_access_callback',
    'uri callback' => 'entity_class_uri',
    'admin ui' => array(
      'path' => 'admin/structure/mogov-sliders',
      'file' => 'mogov_sliders.admin.inc',
      'controller class' => 'SliderUIController',
    ),
    'fieldable' => TRUE,
    'bundles' => array(
      'mogov_slider_images' => array(
        'label' => t('Image Slider'),
      ),
      'mogov_slider_titles' => array(
        'label' => t('Title Slider'),
      ),
    ),
    'module' => 'mogov_sliders',
  );
  
  return $info;
}

/**
 * Implements hook_permission()
 */
function mogov_sliders_permission() {
  return array(
    'administer sliders' => array(
      'title' => t('Administer sliders'),
      'description' => t('Create, edit, and delete sliders.'),
    ),
  );
}

/**
 * Access callback for slider entities.
 */
function mogov_sliders_access_callback() {
  if (user_access('administer sliders')) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Form definition for adding / editing a slider.
 */
function mogov_slider_form($form, &$form_state, $slider=NULL) {
  
  $form['#attributes'] = array(
    'class' => array(
      'entity-form',
    ),
  );
  
  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($slider->title) ? $slider->title : '',
    '#required' => TRUE,
    '#weight' => -10,
  );

  field_attach_form('mogov_slider', $slider, $form, $form_state);
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => isset($slider->id) ? t('Update') : t('Save'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Submit handler for the slider add/edit form.
 */
function mogov_slider_form_submit($form, &$form_state) {
  $slider = entity_ui_form_submit_build_entity($form, $form_state);
  $slider->save();
  drupal_set_message(t('The slider: @title has been saved.', array('@title' => $slider->title)));
  $form_state['redirect'] = 'admin/structure/mogov-sliders';
}

/**
 * Implements hook_entity_property_info().
 */
function mogov_sliders_entity_property_info() {
  
  $info = array();
  
  $info['mogov_slider']['properties']['id'] = array(
    'label' => t('Slider ID'),
    'description' => t('The ID of the slider.'),
    'type' => 'integer',
    'schema field' => 'id',
  );

  $info['mogov_slider']['properties']['bundle'] = array(
    'label' => t('Type'),
    'description' => t('Type of the slider.'),
    'type' => 'text',
    'schema field' => 'bundle',
  );

  $info['mogov_slider']['properties']['title'] = array(
    'label' => t('Title'),
    'description' => t('Title of the slider.'),
    'type' => 'text',
    'schema field' => 'title',
  );
  
  return $info;
}


/**
 * Extending the EntityAPIController for the Slider entity.
 */
class SliderEntityController extends EntityAPIController {
  
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    
    return $build;
  
  }
  
}
  
/**
 * Slider entity class extending the Entity class
 */
class SliderEntity extends Entity {
  
  /**
   * Change the default URI from default/id to slider/id
   */
  protected function defaultUri() {
    return array('path' => 'slider/' . $this->identifier());
  }
  
}

/**
 * Extending UI class
 */
class SliderUIController extends EntityBundleableUIController {

  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $module_path = drupal_get_path('module', 'mogov_sliders');
    // Extend the 'add' path.
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'mogov_sliders_bundle_add_page',
      'page arguments' => array($this->entityType),
      'access arguments' => array('administer sliders'),
      'type' => MENU_LOCAL_ACTION,
      'file' => 'mogov_sliders.admin.inc',
      'file path' => $module_path,
    );
    return $items;
  }
  
  public function overviewTableHeaders($conditions, $rows, $additional_header=array()) {
    $header = parent::overviewTableHeaders($conditions, $rows, array('Type'));
    return $header;
  }
  
  public function overviewTableRow($conditions, $id, $entity, $additional_cols=array()) {
    $entity_info = entity_get_info('mogov_slider');
    $bundle = $entity_info['bundles'][$entity->bundle]['label'];
    $row = parent::overviewTableRow($conditions, $id, $entity, array($bundle));
    return $row;
  }

}
