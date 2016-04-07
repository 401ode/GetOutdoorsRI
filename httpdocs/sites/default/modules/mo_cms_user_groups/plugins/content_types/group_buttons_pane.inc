<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Buttons'),
  'description' => t('Buttons pane for group node display'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_use_groups_group_buttons_pane_render',
  'admin info' => 'mo_cms_use_groups_group_buttons_pane_admin_info',
  'all contexts' => TRUE,
);

function mo_cms_use_groups_group_buttons_pane_render($subtype, $conf, $args, $contexts) {
  global $user;
  $node = $contexts['panelizer']->data;
  $join_field = field_get_items('node', $node, 'field_mo_cms_user_groups_join');
  if ($join_field[0]['value'] == 'open') {
    $join_value = 'open';
  } else {
    $join_value = 'by approval only';
  }
  $user_status = mo_cms_user_groups_get_membership_status($node->nid, $user->uid);
  $buttons = mo_cms_user_groups_group_buttons($user_status, $node, $user->uid, $join_value);
  $content = array();
  if ($user_status['owner'] and $waiting = mo_cms_user_groups_get_join_requests($node->nid)) {
    $text = 'There ';
    $link_text = count($waiting) . ' join request';
    if (count($waiting) > 1) {
      $text .= 'are ';
      $link_text .= 's';
    } else {
      $text .= 'is ';
    }
    $link = l($link_text, 'groups/approval/' . $node->nid);
    $text .= $link . ' awaiting approval.';
    $content[] = array(
      '#markup' => t($text),
    );
  }
  $content[] = array(
    '#markup' => drupal_render($buttons),
  );
  $pane = new stdClass();
  $pane->title = t('<none>');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_use_groups_group_buttons_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Group Buttons');
    }
    $block->content = '';
    return $block;
  }
}
