<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Weekly Stats'),
  'description' => t('Total Miles and Miles/Member for past 7 days pane'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_user_groups_group_weekly_stats_pane_render',
  'admin info' => 'mo_cms_user_groups_group_weekly_stats_pane_admin_info',
  'all contexts' => TRUE,
);

function mo_cms_user_groups_group_weekly_stats_pane_render($subtype, $conf, $args, $contexts) {
  $node = $contexts['panelizer']->data;
  $today = date_create();
  $minus_seven = date_create();
  date_sub($minus_seven, date_interval_create_from_date_string('7 days'));
  $week = array (
    date_format($minus_seven, 'Y-m-d H:i:s'),
    date_format($today, 'Y-m-d H:i:s'),
  );
  $week_mileage = mo_cms_user_groups_get_group_mileage($node, $week);
  $members = mo_cms_user_groups_get_members($node->nid);
  $week_average = ($week_mileage / count($members));
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'group-weekly-stats',
      ),
    ),
    'mileage' => array(
      '#prefix' => '<p>',
      '#markup' => t('Miles logged in the past seven days: ') . number_format($week_mileage, 2),
      '#suffix' => '</p>',
    ),
    'average' => array(
      '#prefix' => '<p>',
      '#markup' => t('Average miles per member in the past seven days: ') . number_format($week_average, 2),
      '#suffix' => '</p>',
    ),
  );
  $pane = new stdClass();
  $pane->title = t('Group Weekly Stats');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_user_groups_group_weekly_stats_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Group Weekly Stats');
    }
    $block->content = '';
    return $block;
  }
}