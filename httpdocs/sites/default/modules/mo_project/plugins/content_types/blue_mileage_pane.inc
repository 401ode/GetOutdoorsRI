<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Blue Mileage'),
  'description' => t('A mileage count'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_project_bluemileage_pane_render',
  'edit form' => 'mo_project_bluemileage_pane_edit_form',
  'admin info' => 'mo_project_bluemileage_pane_admin_info',
  'all contexts' => TRUE,
  'defaults' => array(
    'miles' => 'all',
  ),
);

function mo_project_bluemileage_pane_render($subtype, $conf, $args, $contexts) {
  global $user;
  $activities = array(
    'pad' => 'Paddling',
    'swm' => 'Swimming',
    'hik' => 'Hiking',
    'bik' => 'Biking',
    'wlk' => 'Walking',
    'run' => 'Running',
  );
  $mileage = 0;
  
  switch($conf['miles']) {
    case 'all':
      if ($user->uid <> 0) {
        $all_ids = array();
        foreach ($activities as $act_name) {
          array_push($all_ids, key(taxonomy_get_term_by_name($act_name)));
        }
        $subs_mileage = mo_project_get_mileage_per_subuser(array($user->uid), array('Me'), $all_ids);
        $mileage = (int) round($subs_mileage[0]->distance);
      }
      $name = 'all miles';
      break;
    default:
      $act_name = $activities[$conf['miles']];
      if ($user->uid <> 0) {
        $act_id = key(taxonomy_get_term_by_name($act_name));
        $subs_mileage = mo_project_get_mileage_per_subuser(array($user->uid), array('Me'), array($act_id));
        $mileage = count($subs_mileage) > 0 ? ((int) round($subs_mileage[0]->distance)) : 0;
      }
      $name = strtolower($act_name);
      break;
  }

  $mileage = '<span class="value counter" data-from="0" data-to="' . $mileage . '">' . $mileage . '</span>&nbsp;<span class="mi">mi</span>';

  $content = array();
  $content['bluemileage'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'mileage',
      ),
    ),
    '0' => array(
      '#markup' => t($mileage),
    ),
  );
  $content['label'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'mileage-label',
      ),
    ),
    0 => array(
      '#markup' => t($name),
    ),
  );

  $pane = new stdClass();
  $pane->title = t('Blue Mileage');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * An edit form for the pane's settings.
 */
function mo_project_bluemileage_pane_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $default = 'all';
  if (isset($conf['miles'])) {
    $default = $conf['miles'];
  }
  $form['miles'] = array(
    '#type' => 'select',
    '#title' => t('Select'),
    '#options' => array(
      'all' => t('All Blue Miles'),
      'pad' => t('Paddling Miles'),
      'swm' => t('Swimming Miles'),
      'hik' => t('Hiking Miles'),
      'bik' => t('Biking Miles'),
      'wlk' => t('Walking Miles'),
      'run' => t('Running Miles'),
    ),
    '#default_value' => $default,
  );

  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mo_project_bluemileage_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_project_bluemileage_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = $conf['miles'];
    }
    $block->content = '';
    return $block;
  }
}
