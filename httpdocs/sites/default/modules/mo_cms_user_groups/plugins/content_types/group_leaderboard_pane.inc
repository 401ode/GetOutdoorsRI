<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Group Leaderboard'),
  'description' => t('Leaderboard pane for group node display'),
  'category' => t('100 Missouri Miles (groups)'),
  'render callback' => 'mo_cms_user_groups_group_leaderboard_pane_render',
  'admin info' => 'mo_cms_user_groups_group_leaderboard_pane_admin_info',
  'all contexts' => TRUE,
);

/*
 *  @details  2014-03-19
 *  updated 2014-05-15  to exclude sub-user miles
 */
function mo_cms_user_groups_group_leaderboard_pane_render($subtype, $conf, $args, $contexts) {
  global $user;
  $node = $contexts['panelizer']->data;
  $pane = new stdClass();
  $show_roster = FALSE;
  $members = mo_cms_user_groups_get_members($node->nid);
  $user_status = mo_cms_user_groups_get_membership_status($node->nid, $user->uid);
  $join_field = field_get_items('node', $node, 'field_mo_cms_user_groups_join');
  $group_type = $join_field[0]['value'];
  $activities_field = field_get_items('node', $node, 'field_trail_activity');
  $activity_tids = array();
  if (isset($activities_field[0]['tid'])) {
    foreach ($activities_field as $activities_field_item) {
      $activity_tids[] = $activities_field_item['tid'];
    }
  }
  if ($user_status['member']) {
    $show_roster = TRUE;
  } else {
    if (!empty($group_type) and $group_type == 'open') {
      $show_roster = TRUE;
    }
  }
  
  $group_mileage = 0;
  if (!empty($members) and $member_uids = array_keys($members)) {
    $group_mileage_array = mo_project_get_mileage_per_subuser(array_keys($members), array('Me'), $activity_tids);
    foreach ($group_mileage_array AS $record) {
      $group_mileage = $group_mileage + $record->distance;
    }
  }

  $content = array();
  $content['miles'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'group-' . $node->nid . '-total-miles',
      'class' => array(
        'group-total-miles',
      ),
    ),
  );
  if (!empty($show_roster) and $show_roster and $group_mileage) {
    $members_by_uid = array();
    $mileage_by_uid = array();
    foreach ($members as $uid=>$member) {
      $member_mileage_array = mo_project_get_mileage_per_subuser(array($uid), array('Me'), $activity_tids);
      $member_mileage = $member_mileage_array[0]->distance;
      if ($uid != $user->uid and $member_mileage === 0) {
        continue;
      }
      $mileage_by_uid[$uid] = $member_mileage;
    }
    if (count($mileage_by_uid) < 3) {
      $content['leaderboard'] = array(
        '#type' => 'markup',
        '#markup' => t('<p class="no-leaderboard">Too few of this group\'s members have logged miles to generate a leaderboard.</p>'),
      );
    } else {
      arsort($mileage_by_uid);
      foreach ($mileage_by_uid as $uid=>$mileage) {
        $members_by_uid[$uid] = array(
          'mileage' => $mileage,
          'member' => $members[$uid],
        );
      }
      $members_keys = array_keys($members_by_uid);
      $user_position = array_search($user->uid, $members_keys);
      $leaderboard_start = 0;
      if (count($members_by_uid) < 10 and $user_status['member']) {
        $leaderboard_end = count($members_by_uid) - 1;
      } elseif ($user_position < 7 and $user_status['member']) {
        $leaderboard_end = min(count($members_by_uid) - 1, $user_position + 2, 10);
      } else {
        $leaderboard_end = min(4, count($members_by_uid) - 1);
        if ($user_status['member']) {
          $user_board_end = min(count($members_by_uid) - 1, $user_position + 2);
          $user_board_start = $user_board_end - 4;
        }
      }
      $range = range($leaderboard_start, $leaderboard_end);
      $max = $members_by_uid[$members_keys[0]]['mileage'];
      $full_names = FALSE;
      if ($user_status['member'] or $user_status['owner']) {
        $word = 'My';
        if ($group_type == 'approve') {
          $full_names = TRUE;
        }
      } else {
        $word = 'This';
      }
      $title = 'Top ' . count($range) . ' in ' . $word . ' Group';
      if (count($range) > 2) {
        $content['leaderboard'] = mo_cms_user_groups_build_group_leaderboard($range, $members_keys, $members_by_uid, $max, $user, $user_position, $title, $full_names);
        $content['leaderboard']['attributes']['id'] = 'group-' . $node->nid . '-leaderboard';
        if (isset($user_board_start)) {
          $range = range($user_board_start, $user_board_end);
          $title = 'My Ranking';
          $content['user_board'] = mo_cms_user_groups_build_group_leaderboard($range, $members_keys, $members_by_uid, $max, $user, $user_position, $title,$full_names);
          $content['user_board']['attributes']['id'] = 'group-' . $node->nid . '-user-board';
        }
      }
    }
  } elseif (!empty($show_roster) and $show_roster) {
    $content['leaderboard'] = array(
      '#type' => 'markup',
      '#markup' => t('<p class="no-leaderboard">This group does not yet have any mileage to display.</p>'),
    );
  }
  $pane->title = t('<none>');
  $pane->content = render($content);
 
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mo_cms_use_groups_group_leaderboard_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    if ($conf['override_title'] and $conf['override_title_text'] != '<none>') {
      $block->title = $conf['override_title_text'];
    } else {
      $block->title = t('Group Leaderboard');
    }
    $block->content = '';
    return $block;
  }
}