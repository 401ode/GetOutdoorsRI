<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Details'),
  'description' => t('Details pane for group node display'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_user_groups_group_details_pane_render',
  'admin info' => 'mo_cms_user_groups_group_details_pane_admin_info',
  'all contexts' => TRUE,
);

function mo_cms_user_groups_group_details_pane_render($subtype, $conf, $args, $contexts) {
  $node = $contexts['panelizer']->data;
  $members = mo_cms_user_groups_get_members($node->nid);
  $membership_field = field_get_items('node', $node, 'field_mo_cms_user_groups_join');
  if ($membership_field[0]['value'] == 'open') {
    $membership = 'Membership in this group is <strong>open</strong>.';
  } else {
    $membership = 'Membership in this group is <strong>by approval only</strong>.';
  }
  $visibility_field = field_get_items('node', $node, 'field_mo_cms_user_groups_vis');
  if ($visibility_field[0]['value'] == 'visible') {
    $visibility = 'This group is <strong>visible</strong> in directory listings.';
  } else {
    $visibility = 'This group is <strong>not visible</strong> in directory listings.';
  }
  $content = array();
  $content['founded_date'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'founded-date',
      ),
    ),
    'content' => array(
      '#markup' => t('<strong>Founded:</strong> ' . format_date($node->created, 'numeric_with_')),
    ),
  );
  $content['founded_date'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'members-count',
      ),
    ),
    'content' => array(
      '#markup' => t('<strong>Members:</strong> ' . number_format(count($members), 0)),
    ),
  );
  $url_field = field_get_items('node', $node, 'field_url');
  if (!empty($url_field[0]['url'])) {
    if (!empty($url_field[0]['title'])) {
      $link_text = $url_field[0]['title'];
    } else {
      $link_text = $url_field[0]['url'];
    }
    $content['link'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'group-website',
        ),
      ),
      'content' => array(
        '#markup' => t('<strong>Website:</strong> ' . l($link_text, $url_field[0]['url'], array('external' => TRUE))),
      ),
    );
  }
  $content['privacy_settings'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'privacy-settings',
      ),
    ),
    'content' => array(
      '#prefix' => t('<strong>Privacy Settings</strong><br>'),
      '#markup' => t($membership . '<br>' . $visibility),
      '#suffix' => t('<br>Please read our <a href="/content/privacy-policy#group-policy">disclaimer</a>.'),
    ),
  );
  $pane = new stdClass();
  $pane->title = t('Group Details');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_user_groups_group_details_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Group Details');
    }
    $block->content = '';
    return $block;
  }
}