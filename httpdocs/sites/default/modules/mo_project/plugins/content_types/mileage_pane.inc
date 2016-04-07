<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Mileage'),
  'description' => t('A mileage count'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_project_mileage_pane_render',
  'edit form' => 'mo_project_mileage_pane_edit_form',
  'admin info' => 'mo_project_mileage_pane_admin_info',
  'all contexts' => TRUE,
  'defaults' => array(
    'user' => 'user',
    'label' => 'user',
    'period' => 'current',
  ),
);

function mo_project_mileage_pane_render($subtype, $conf, $args, $contexts) {
  switch($conf['user']) {
    case 'user':
      global $user;
      $name = 'Me';
      break;
    case 'Governor':
      global $static_users;
      $user = user_load($static_users[$conf['user']]);
      $name = 'Governor';
      break;
    case 'First Lady':
      global $static_users;
      $user = user_load($static_users[$conf['user']]);
      $name = 'First Lady';
      break;
    case 'Huck':
      global $static_users;
      $user = user_load($static_users['First Lady']);
      $name = 'Huck';
      break;
  }
  
  if ($conf['user'] == 'Governor') {
    $mileage = (int) round(mo_project_get_total_mileage(array($user->uid), array(), $conf['period']));
  } else {
    $subs_mileage = mo_project_get_mileage_per_subuser(array($user->uid));
    $mileage = 0;
    foreach ($subs_mileage AS $row) {
      if ( ($conf['user'] == 'Huck') AND ($row->name == 'Huck') ) {
        $mileage = (int) round($row->distance);
      }
      if ( ($conf['user'] == 'First Lady') AND ( ($row->name == 'First Lady Nixon') OR ($row->name == 'Georganne') ) ) {
        $mileage = (int) round($row->distance);
      }
      if ( ($conf['user'] == 'user') AND ($row->type_name == 'Me') ) {
        $mileage = (int) round($row->distance);
      }
    }
  }
  if ($conf['label'] == 'total') {
    $mileage = 'Since joining on <span class="join-date"><strong>' . format_date($user->created, 'numeric_with_') . '</strong></span> you\'ve logged <span class="value"><strong>' . number_format($mileage, 0) . '</strong></span> miles.';
  } else {
    $mileage = '<span class="value counter" data-from="0" data-to="' . $mileage . '">' . $mileage . '</span>&nbsp;<span class="mi">mi</span>';
  }
  $content = array();
  $content['mileage'] = array(
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
  if ($conf['label'] == 'user') {
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
  }
  $pane = new stdClass();
  $pane->title = t('Mileage');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * An edit form for the pane's settings.
 */
function mo_project_mileage_pane_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $default = 'user';
  if (isset($conf['user'])) {
    $default = $conf['user'];
  }
  $form['user'] = array(
    '#type' => 'select',
    '#title' => t('Select user'),
    '#options' => array(
      'user' => t('Current user'),
      'Governor' => t('Governor'),
      'First Lady' => t('First Lady'),
      'Huck' => t('Huck'),
    ),
    '#default_value' => $default,
  );

  $default = 'user';
  if (isset($conf['label'])) {
    $default = $conf['label'];
  }
  $form['label'] = array(
    '#type' => 'select',
    '#title' => t('Label style'),
    '#options' => array(
      'user' => t('# Miles top, "User\'s Miles" bottom'),
      'total' => t('"Total miles: ###"'),
    ),
    '#default_value' => $default,
  );

  $default = 'current';
  if (isset($conf['period'])) {
    $default = $conf['period'];
  }
  $form['period'] = array(
    '#type' => 'select',
    '#title' => t('Select challenge period'),
    '#options' => array(
      'current' => t('Current challenge'),
      'all' => t('Since user registered'),
    ),
    '#default_value' => $default,
  );
 
  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mo_project_mileage_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_project_mileage_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = $conf['user'] . ' ' . $conf['period'] . ' Mileage';
    }
    $block->content = '';
    return $block;
  }
}
