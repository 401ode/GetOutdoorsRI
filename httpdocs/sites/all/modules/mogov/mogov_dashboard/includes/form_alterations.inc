<?php
/**
 * Implements hook_menu()
 */
function mogov_dashboard_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  switch($form['#id']) {
    case 'views-exposed-form-mogov-dashboard-content-panel-pane-1':
      $form['title'] = mogov_dashboard_change_textfield_to_searchfield($form['title'], 'Quick search');
      break;
    case 'views-exposed-form-mogov-dashboard-files-default':
      $form['filename'] = mogov_dashboard_change_textfield_to_searchfield($form['filename'], 'Quick search');
      break;
  }
}

function mogov_dashboard_change_textfield_to_searchfield($field, $placeholder) {
  $field['#type'] = 'searchfield';
  $field['#attributes']['placeholder'] = $placeholder;
  return $field;
}
