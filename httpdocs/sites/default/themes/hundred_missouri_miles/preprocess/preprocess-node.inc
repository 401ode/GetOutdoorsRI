<?php

function hundred_missouri_miles_alpha_preprocess_node(&$vars) {
  switch ($vars['type']) {
    case 'mo_cms_user_group':
      $vars = hundred_missouri_miles_preprocess_user_group($vars);
      break;
    case 'mo_cms_umbrella_group':
      $vars = hundred_missouri_miles_preprocess_umbrella_group($vars);
      break;
  }
}

function hundred_missouri_miles_preprocess_user_group($vars) {
  
  global $user;
  
  $activities_field = field_get_items('node', $vars['node'], 'field_trail_activity');
  $activity_tids = array();
  if (isset($activities_field[0]['tid'])) {
    foreach ($activities_field as $activities_field_item) {
      $activity_tids[] = $activities_field_item['tid'];
    }
  }

  // Switch back to this and uncomment items below when people realize the change was a horrible mistake
//  switch ($vars['field_mo_cms_user_groups_stats']['und'][0]['value']) {
  switch ($vars['field_mo_cms_user_groups_join'][0]['value']) {
    case 'open':
      $stats_value = 'the public';
      $vars['show_roster'] = TRUE;
      break;
    default:
      $stats_value = 'group members only';
  }
//  $vars['content']['group_privacy']['field_mo_cms_user_groups_stats'][0]['#markup'] = t('This group\'s membership mileage stats are viewable by <b>' . $stats_value . '</b>.');

  $group_mileage = 0;
  if (!empty($members) and $member_uids = array_keys($members)) {
    $group_mileage_array = mo_project_get_mileage_per_subuser(array_keys($members), array('Me'), $activity_tids);
    foreach ($group_mileage_array AS $record) {
      $group_mileage = $group_mileage + $record->distance;
    }
  }
  
  $vars['miles'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'group-' . $vars['nid'] . '-total-miles',
      'class' => array(
        'group-total-miles',
      ),
    ),
    0 => array(
      '#type' => 'markup',
      '#markup' => t('Miles: ' . number_format($group_mileage, 0)),
    ),
  );
  if (!empty($vars['show_roster']) and $vars['show_roster'] and $group_mileage) {
    $members_by_uid = array();
    $mileage_by_uid = array();
    foreach ($vars['members_data'] as $uid=>$member) {
      $member_mileage_array = mo_project_get_mileage_per_subuser(array($uid), array('Me'), $activity_tids);
      $member_mileage = $member_mileage_array[0]->distance;
      if ($uid != $user->uid and $member_mileage === 0) {
        continue;
      }
      $mileage_by_uid[$uid] = $member_mileage;
    }
    if (count($mileage_by_uid) < 3) {
      $vars['leaderboard'] = array(
        '#type' => 'markup',
        '#markup' => t('<p class="no-leaderboard">Too few of this group\'s members have logged miles to generate a leaderboard.</p>'),
      );
    } else {
      arsort($mileage_by_uid);
      foreach ($mileage_by_uid as $uid=>$mileage) {
        $members_by_uid[$uid] = array(
          'mileage' => $mileage,
          'member' => $vars['members_data'][$uid],
        );
      }
      $members_keys = array_keys($members_by_uid);
      $user_position = array_search($user->uid, $members_keys);
      $leaderboard_start = 0;
      if (count($members_by_uid) < 10 and $vars['user_status']['member']) {
        $leaderboard_end = count($members_by_uid) - 1;
      } elseif ($user_position < 7 and $vars['user_status']['member']) {
        $leaderboard_end = min(count($members_by_uid) - 1, $user_position + 2, 10);
      } else {
        $leaderboard_end = min(4, count($members_by_uid) - 1);
        if ($vars['user_status']['member']) {
          $user_board_end = min(count($members_by_uid) - 1, $user_position + 2);
          $user_board_start = $user_board_end - 4;
        }
      }
      $range = range($leaderboard_start, $leaderboard_end);
      $max = $members_by_uid[$members_keys[0]]['mileage'];
      $group_type = $vars['field_mo_cms_user_groups_join'][0]['value'];
      $full_names = FALSE;
      if ($vars['user_status']['member'] or $vars['user_status']['owner']) {
        $word = 'My';
        if ($group_type == 'approve') {
          $full_names = TRUE;
        }
      } else {
        $word = 'This';
      }
      $title = 'Top ' . count($range) . ' in ' . $word . ' Group';
      if (count($range) > 2) {
        $vars['leaderboard'] = mo_cms_user_groups_build_group_leaderboard($range, $members_keys, $members_by_uid, $max, $user, $user_position, $title, $full_names);
        $vars['leaderboard']['attributes']['id'] = 'group-' . $vars['nid'] . '-leaderboard';
        if (isset($user_board_start)) {
          $range = range($user_board_start, $user_board_end);
          $title = 'My Ranking';
          $vars['user_board'] = mo_cms_user_groups_build_group_leaderboard($range, $members_keys, $members_by_uid, $max, $user, $user_position, $title,$full_names);
          $vars['user_board']['attributes']['id'] = 'group-' . $vars['nid'] . '-user-board';
        }
      }
    }
  } elseif (!empty($vars['show_roster']) and $vars['show_roster']) {
    $vars['leaderboard'] = array(
      '#type' => 'markup',
      '#markup' => t('<p class="no-leaderboard">This group does not yet have any mileage to display.</p>'),
    );
  }
  
  return $vars;
}

function hundred_missouri_miles_preprocess_umbrella_group($vars) {
  $total_mileage = array();
  $average_mileage = array();
  $groups = array();
  $nodes = entity_load('node', array_keys($vars['groups']));
  foreach ($vars['groups'] as $nid=>$group_link) {
    $activities_field = field_get_items('node', $nodes[$nid], 'field_trail_activity');
    $activity_tids = array();
    if (isset($activities_field[0]['tid'])) {
      foreach ($activities_field as $activities_field_item) {
        $activity_tids[] = $activities_field_item['tid'];
      }
    }
    $members = mo_cms_user_groups_get_members($nid);
    $group_mileage = 0;
    if (!empty($members) and $member_uids = array_keys($members)) {
      $group_mileage_array = mo_project_get_mileage_per_subuser(array_keys($members), array('Me'), $activity_tids, $period);
      foreach ($group_mileage_array AS $record) {
        $group_mileage = $group_mileage + $record->distance;
      }
    }
    if (!isset($total_mileage[$group_mileage])) {
      $total_mileage[$group_mileage] = array();
    }
    $total_mileage[$group_mileage][] = $nid;
    if ($member_uids) {
      $average = $group_mileage / count($members);
    } else {
      $average = 0;
    }
    if (!isset($average_mileage[$average])) {
      $average_mileage[$average] = array();
    }
    $average_mileage[$average][] = $nid;
  }
  $total_miles = array_keys($total_mileage);
  rsort($total_miles);
  $max = $total_miles[0] * 1.25;
  $vars['total_mileage_leaderboard'] = mo_cms_user_groups_build_umbrella_group_leaderboard($total_miles, $total_mileage, $vars['groups'], $max, 'Total');
  $average_miles = array_keys($average_mileage);
  rsort($average_miles);
  $max = $average_miles[0] * 1.25;
  $vars['average_mileage_leaderboard'] = mo_cms_user_groups_build_umbrella_group_leaderboard($average_miles, $average_mileage, $vars['groups'], $max, 'Average');
  return $vars;
}