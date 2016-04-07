<?php

/**
 * Implements hook_form_alter()
 * Moves the panels node fields into the main field group
 */
function mo_cms_form_panel_node_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#groups']['group_tab_main'])) {
    $form['panels_node']['#group'] = 'group_tab_main';
    $form['panels_node']['#weight'] = 10;
    $form['#group_children']['panels_node'] = 'group_tab_main';
    $form['#groups']['group_tab_main']->children[] = 'panels_node';
  }
}