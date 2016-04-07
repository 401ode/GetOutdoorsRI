<?php
/**
 *  @file leaderboard_activity_stats.inc
 *  @brief  Code for the 'Leaderboard' Panels Pane.
 *
 *  @details
 *  mo_project_timestamp = Creates timestamp
 *  mo_project_leaderboard_activity_stats_render = Creates custom panels pane
 *  mo_project_leaderboard_activity_stats_admin_info = 'admin info' callback for panels pane
 *  mo_project_leaderboard_activity_stats_edit_form = edit form for the pane's settings
 *  mo_project_leaderboard_activity_stats_edit_form_submit = submit function
 */

 
$plugin = array(
  'single' => TRUE,
  'title' => t('Leaderboard Activity Stats'),
  'description' => t('Activity-based leaderboard stats'),
  'category' => t('100 Missouri Miles'),
  'render callback' => 'mo_project_leaderboard_activity_stats_render',
  'edit form' => 'mo_project_leaderboard_activity_stats_edit_form',
  'admin info' => 'mo_project_leaderboard_activity_stats_admin_info',
  'all contexts' => TRUE,
  'defaults' => array(
    'activity' => '_none',
  ),
);


/**
 *  @brief  Creates timestamp
 *  
 *  @return  timestamp
 *  
 *  @details  2014
 */
function mo_project_timestamp() {
  list($usec, $sec) = explode(" ", microtime());
  $timestamp = date('H:i:s', $sec) . substr($usec, 1, 3);
  return $timestamp;
}


/**
 *  @brief  Creates custom panels pane
 *  
 *  @param [in] $subtype  
 *  @param [in] $conf     
 *  @param [in] $args     
 *  @param [in] $contexts 
 *  @return  pane
 *  
 *  @details  2014
 *            Edit 2014-05-04  to account for sub-user
 */
function mo_project_leaderboard_activity_stats_render($subtype, $conf, $args, $contexts) {
  if (empty($conf['activity']) or $conf['activity'] == '_none') {
    return FALSE;
  }
  
  global $user;
  $activity = taxonomy_term_load($conf['activity']);
  $past_tense_field = field_get_items('taxonomy_term', $activity, 'field_activity_past_tense');

  $m_array = mo_project_get_mileage_per_subuser(array($user->uid), array('Me'), $activities=array($activity->tid));
  if (count($m_array) <= 0) {
    return FALSE;
  }
  $mileage = $m_array[0]->distance;
//  $mileage = mo_project_get_total_mileage(array($user->uid), array($activity->tid));
  if (!$mileage) {
    return FALSE;
  }
  $u30_array = mo_project_get_mileage_per_subuser(array($user->uid), array('Me'), array($activity->tid), '30day');
  $user30_mileage = $u30_array[0]->distance;
//  $user30_mileage = mo_project_get_total_mileage(array($user->uid), array($activity->tid), '30day');

  $avg30_mileage = mo_project_get_leaderboard_activity_stats('average', $activity->tid, $user->uid);
//drupal_set_message('<pre>' . print_r($avg30_mileage, TRUE) . '</pre>');
  $leader30_mileage = mo_project_get_leaderboard_activity_stats('leader', $activity->tid, $user->uid);

  // If the user enters miles that make him/her the leader and cron has not yet run, 
  // make the user the leader.
  if ($user30_mileage > $leader30_mileage) {
    $leader30_mileage = $user30_mileage;
    if ($avg30_mileage == 0) {
      $avg30_mileage = $user30_mileage;
    }
  }
  
/*  
  $avg30_mileage = mo_project_get_total_mileage(array(), array($activity->tid), '30day', TRUE);
//  drupal_set_message('mo_project_get_total_mileage average result: ' . $avg30_mileage);
  $leader30_mileage = mo_project_get_total_mileage(array(), array($activity->tid), '30day', FALSE, TRUE);
//  drupal_set_message('mo_project_get_total_mileage leader result: ' . $leader30_mileage);
*/
  $class = drupal_clean_css_identifier(strtolower($activity->name));
  $content = array();
  $content['leaderboard_activity_stats'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'leaderboard-activity-stats',
        $class,
      ),
    ),
    'total' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'leaderboard-box',
          'first',
        ),
      ),
      'content' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'mileage-box',
            'total',
            'first',
          ),
        ),
        'mileage' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage',
            ),
          ),
          0 => array(
            '#markup' => t('<span class="value counter" data-from="0" data-to="' . round($mileage) . '">' . round($mileage) . '</span>&nbsp;<span class="mi">mi</span>'),
          ),
        ),
        'label' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage-label',
            ),
          ),
          0 => array(
            '#markup' => t('Miles ' . $past_tense_field[0]['value']),
          ),
        ),
      ),
    ),
    'my30day' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'leaderboard-box',
        ),
      ),
      'content' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'mileage-box',
            'thirty-day',
            'user-thirty',
          ),
        ),
        'mileage' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage',
            ),
          ),
          0 => array(
            '#markup' => t('<span class="value counter" data-from="0" data-to="' . round($user30_mileage) . '">' . round($user30_mileage) . '</span>&nbsp;<span class="mi">mi</span>'),
          ),
        ),
        'label' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage-label',
            ),
          ),
          0 => array(
            '#markup' => t('My Last 30 Days'),
          ),
        ),
      ),
    ),
    'avg30day' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'leaderboard-box',
        ),
      ),
      'content' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'mileage-box',
            'thirty-day',
            'avg-thirty',
          ),
        ),
        'mileage' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage',
            ),
          ),
          0 => array(
            '#markup' => t('<span class="value counter" data-from="0" data-to="' . round($avg30_mileage) . '">' . round($avg30_mileage) . '</span>&nbsp;<span class="mi">mi</span>'),
          ),
        ),
        'label' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage-label',
            ),
          ),
          0 => array(
            '#markup' => t('30 Day Average *'),
          ),
        ),
      ),
    ),
    'leader30day' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'leaderboard-box',
          'last',
        ),
      ),
      'content' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'mileage-box',
            'thirty-day',
            'leader-thirty',
          ),
        ),
        'mileage' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage',
            ),
          ),
          0 => array(
            '#markup' => t('<span class="value counter" data-from="0" data-to="' . round($leader30_mileage) . '">' . round($leader30_mileage) . '</span>&nbsp;<span class="mi">mi</span>'),
          ),
        ),
        'label' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'mileage-label',
            ),
          ),
          0 => array(
            '#markup' => t('30 Day Leader *'),
          ),
        ),
      ),
    ),
  );
  $pane = new stdClass();
  $pane->title = t($activity->name);
  $pane->content = render($content);
 
  return $pane;
}


/**
 *  @brief  'admin info' callback for panel pane.
 *  
 *  @param [in] $subtype  
 *  @param [in] $conf     
 *  @param [in] $contexts 
 *  @return  block
 *  
 *  @details  2014
 */
function mo_project_leaderboard_activity_stats_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } elseif (!empty($conf['activity']) and $conf['activity'] != '_none') {
      $activity = taxonomy_term_load($conf['activity']);
      $block->title = t('Leaderboard Stats: ' . $activity->name);
    }
    $block->content = '';
    return $block;
  }
}


/**
 *  @brief  An edit form for the pane's settings.
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  form
 *  
 *  @details  2014
 */
function mo_project_leaderboard_activity_stats_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $default = '_none';
  if (isset($conf['activity'])) {
    $default = $conf['activity'];
  }

  $v = taxonomy_vocabulary_machine_name_load('activities');
  $v_tree = taxonomy_get_tree($v->vid);
  $activities = array();
  foreach ($v_tree as $term) {
    $activities[$term->tid] = t($term->name);
  }
  natcasesort($activities);
  $options = array('_none' => '- Select an activity -') + $activities;
 
  $form['activity'] = array(
    '#type' => 'select',
    '#title' => t('Select activity'),
    '#options' => $options,
    '#default_value' => $default,
  );

  return $form;
}
 

/**
 *  @brief Submit function, note anything in the formstate[conf] automatically gets saved
 *  Notice, the magic that automatically does that for you.
 *  
 *  @param [in] $form       
 *  @param [in] $form_state 
 *  @return  void
 *  
 *  @details  2014
 */
function mo_project_leaderboard_activity_stats_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
