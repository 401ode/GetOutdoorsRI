<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Slider'),
  'description' => t('A panel display for sliders.'),
  'category' => t('Site: all'),
  'edit form' => 'mogov_sliders_slider_pane_edit_form',
  'render callback' => 'mogov_sliders_slider_pane_render',
  'admin info' => 'mogov_sliders_slider_pane_admin_info',
  'defaults' => array(
    'slider' => '_none',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_sliders_slider_pane_edit_form($form, &$form_state) {
  module_load_include('inc', 'mogov_sliders', 'includes/data');
  $conf = $form_state['conf'];
  if (isset($conf['slider'])) {
    $default = $conf['slider'];
  } else {
    $default = '_none';
  }
 
  $options = array(
    '_none' => '',
  );
  $sliders = mogov_sliders_get_sliders();
  foreach ($sliders as $id=>$slider) {
    $options[$id] = $slider->title;
  }
  $form['slider'] = array(
    '#type' => 'select',
    '#title' => t('Select a slider'),
    '#options' => $options,
    '#default_value' => $default,
  );
 
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_sliders_slider_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the pane
 * See ctools_plugin_examples for more advanced info
 */
function mogov_sliders_slider_pane_render($subtype, $conf, $args, $contexts) {
 
  $pane = new stdClass();
  
  // initial content is blank
  $pane->title = t('<none>');
  $pane->content = '';
  
  if (isset($conf['slider']) and is_numeric($conf['slider'])) {
    module_load_include('inc', 'mogov_sliders', 'includes/view');
    $pane->content = mogov_sliders_view_slider($conf['slider'], 'pane');
  }
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_sliders_slider_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $slider = entity_load_single('mogov_slider', $conf['slider']);
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : $slider->title;
    $pane->content = '';
    return $pane;
  }
}