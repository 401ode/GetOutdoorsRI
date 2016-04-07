<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Umbrellas'),
  'description' => t('Umbrellas pane for group node display'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_user_groups_group_umbrellas_pane_render',
  'admin info' => 'mo_cms_user_groups_group_umbrellas_pane_admin_info',
  'all contexts' => TRUE,
);

function mo_cms_user_groups_group_umbrellas_pane_render($subtype, $conf, $args, $contexts) {
  $node = $contexts['panelizer']->data;
  $pane = new stdClass();
  $umbrellas = mo_cms_user_groups_get_umbrellas($node->nid);
  if (!empty($umbrellas)) {
    $umbrella_list = array(
      'type' => 'ul',
      'title' => NULL,
      'attributes' => array(
	'class' => array(
	  'umbrella-groups-list',
	),
      ),
      'items' => array(),
    );
    foreach ($umbrellas as $umbrella) {
      $umbrella_list['items'][] = l($umbrella->title, 'node/' . $umbrella->nid);
    }
    $content = array(
      '#markup' => theme_item_list($umbrella_list),
    );
    $pane->title = t('Parent Groups');
    $pane->content = render($content);
  }
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_use_groups_group_umbrellas_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Group Umbrellas');
    }
    $block->content = '';
    return $block;
  }
}