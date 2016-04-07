<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Total Miles'),
  'description' => t('Total Miles pane for group node display'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_user_groups_group_total_miles_pane_render',
  'admin info' => 'mo_cms_user_groups_group_total_miles_pane_admin_info',
  'all contexts' => TRUE,
);

function mo_cms_user_groups_group_total_miles_pane_render($subtype, $conf, $args, $contexts) {
  $node = $contexts['panelizer']->data;
  $group_mileage = mo_cms_user_groups_get_group_mileage($node);
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
	'group-total-mileage',
      ),
    ),
    'mileage' => array(
      '#markup' => number_format($group_mileage, 0),
    ),
  );
  $pane = new stdClass();
  $pane->title = t('Total Group Miles');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_use_groups_group_total_miles_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Total Miles');
    }
    $block->content = '';
    return $block;
  }
}