<?php
/**
 *  @file ajax.inc
 *  @brief  Various functions used to serve/update content via ajax
 *
 *  @details
 *  mo_project_ajax_submit_mileage = Creates a new mileage node.  Evaluates new earned badges.  Creates the badge earned banner with tweet capability.
 *  mo_project_ajax_block_content = Displays blocks for home page and dashboard
 *  mo_project_ajax_total_mileage = Displays total mileage logged by all verified users in the site header
 *  mo_project_ajax_convert_activity = Displays results of activity conversions
 *  mo_project_convert_activity = Converts minutes to walking miles
 *  mo_project_ajax_convert_km = Calculates and displays kilometer to mile conversion
 *  mo_project_ajax_calculate_calories = Calculates and displays calories burned for supplied time of supplied activity
 *  mo_project_mileage_location_autocomplete = Creates and displays autocomplete locations from facilities and trail names
 *  mo_project_get_user_current_stats = Updates mileage totals on homepage and dashboard
 *  mo_project_badge_detail = Display individual badge description on click
 */


/**
 *  @brief  Creates a new mileage node.  Evaluates new earned badges.  Creates the badge earned banner with tweet capability.
 *
 *  @return  void
 *
 *  @details  2013
 *  updated 2015-04-28  to add sub-user
 */
function mo_project_ajax_submit_mileage() {
  global $user;
  $node = new stdClass();
  $node->type = 'mileage';
  $node->language = LANGUAGE_NONE;
  $node->revision = 0;
  $node->uid = $user->uid;
  $node->status = 1;
  $node->promote = 0;
  $node->sticky = 0;
  node_object_prepare($node);

  $date = $_POST['date']['date'] . ' 00:00:00';
  $node->field_mileage_date[$node->language][0]['value'] = t($date);
  $i = 0;
  if (!empty($_POST['activity'])) {
    $node->field_mileage_activity[$node->language][0]['tid'] = $_POST['activity'];
  }
  if (!empty($_POST['location'])) {
    $node->field_mileage_facility[$node->language][0]['value'] = t($_POST['location']);
  }
  if (!empty($_POST['subuser'])) {
    $pieces = explode("|", $_POST['subuser']);
    $suid = $pieces[0];
    $buddy_class = $pieces[1];
    $node->field_mileage_subuser[$node->language][0]['value'] = $suid;
  }
  $distance = $_POST['distance'];
  if ($_POST['units'] == 'kilometers') {
    $distance *= 0.621371;
  }
  $node->field_mileage_distance[$node->language][0]['value'] = $distance;
  node_submit($node);
  node_save($node);
  $year = date('Y', strtotime($date));
  $results = array(
    'year' => $year,
  );
  $affected_badges = mo_project_get_affected_badges($node);
  $new_badges = mo_project_evaluate_badges($user->uid, $suid, $affected_badges, $year);

  if (is_array($new_badges)) {
    $new_badge_nodes = entity_load('node', array_keys($new_badges));
    $badges = array();
    if (!empty($new_badge_nodes)) {
      $badge_template = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'badge-notification',
            $buddy_class,
          ),
        ),
        'image' => array(),
        'text' => array(),
      );
    }

    // Get sub-user name
    $query_name = db_select('subuser', 's');
    $query_name->fields('s', array('name'));
    $query_name->condition('s.suid', $suid, '=');
    $name = $query_name->execute()->fetchCol();

    foreach ($new_badge_nodes as $nid=>$node) {
      $badge = $badge_template;
      $image_field = field_get_items('node', $node, 'field_achievement_badge');
      $badge['image']['#markup'] = mo_project_get_badge_image($image_field, 'sm');
      $badge['text']['#prefix'] = t('<p>');
      $badge['text']['#markup'] = t('Congratulations, ' . $name[0] . '! You\'ve earned the <span class="badge-name">' . $node->title . '</span> badge! You can view it in your <a href="/trophy">Trophy&nbsp;Room</a>.');
      $badge['text']['#suffix'] = t('</p>');
      if ($buddy_class == "Me") {
        $tweet = 'I just earned the ' . $node->title . ' badge with @GetOutdoorsRI! Explore #GetOutdoorsRI with me at http://GetOutdoorsRI.com.';
        $badge['share'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'message-share',
            ),
          ),
          'twitter' => array(
            '#markup' => theme('twitter_button', array('content' => urlencode($tweet))),
          ),
        );
      }
      $badges[] = drupal_render($badge);
    }
    drupal_json_output($badges);
  }
  drupal_exit();
}


/**
 *  @brief  Displays blocks for home page and dashboard
 *
 *  @param [in] $delta  Machine name of block
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_ajax_block_content($delta) {
  global $user;
  switch($delta) {
    case 'global_stats':
      print render(mo_project_build_global_stats_content());
      break;
    case 'user_stats':
      print render(mo_project_build_user_stats_content($user));
      break;
    case 'achievements':
      $user_total_mileage = mo_project_get_total_mileage(array($user->uid));
      print mo_project_get_user_badges($user_total_mileage, 'all');
      break;
    case 'leaderboard':
      break;
  }
}


/**
 *  @brief  Displays total mileage logged by all verified users in the site header
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_ajax_total_mileage() {
  $total_mileage = (int) round(variable_get_value('total_mileage'));
  print $total_mileage;
  drupal_exit();
}


/**
 *  @brief  Displays results of activity conversions
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_ajax_convert_activity() {
  $result = array(
    'mileage' => NULL,
    'text' => NULL,
    'tid' => NULL,
  );
  $conversion = mo_project_convert_activity();
  if ($conversion['mileage'] and $conversion['mileage'] > 0.0) {
    $result['mileage'] = number_format($conversion['mileage'], 2);
    $result['text'] = number_format($_POST['time'], 2) . ' minutes of ' . strtolower($conversion['activity']->name) . ' is approximately equivalent to walking ' . $result['mileage'] . ' miles.';
    if (drupal_is_front_page()) {
      $result['text'] .= ' This number has been added to the Submit Mileage form in case you wish to log these miles.';
    }
    $result['tid'] = $conversion['activity']->tid;
  }
  print drupal_json_output($result);
  drupal_exit();
}


/**
 *  @brief  Converts minutes to walking miles
 *
 *  @return  Array of the converted mileage and the activity performed
 *
 *  @details  2013
 */
function mo_project_convert_activity() {

  $result = array();
  if (!empty($_POST['activity']) and !empty($_POST['time'])) {
    $activity = taxonomy_term_load($_POST['activity']);
    $field = field_get_items('taxonomy_term', $activity, 'field_activity_conversion_coef');
    if (!empty($field[0]['value'])) {
      $mileage = (float) $_POST['time'] / 60.0 * $field[0]['value'];
    }
  }
  $result['mileage'] = $mileage;
  $result['activity'] = $activity;
  return $result;

}


/**
 *  @brief  Calculates and displays kilometer to mile conversion
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_ajax_convert_km() {
  $result = NULL;
  $km = 0;
  if (!empty($_POST['km']) and is_numeric($_POST['km'])) {
    $km = $_POST['km'];
    $result = $_POST['km'] * 0.621371;
  }
  print number_format($km, 2) . ' km = ' . number_format($result, 2) . ' miles.';
  drupal_exit();
}


/**
 *  @brief  Calculates and displays calories burned for supplied time of supplied activity
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_ajax_calculate_calories() {
  $result = NULL;
  if (empty($_POST['activity']) or empty($_POST['time']) or empty($_POST['weight'])) {
    return $result;
  }
  $time = 0;
  $activity = taxonomy_term_load($_POST['activity']);
  $field = field_get_items('taxonomy_term', $activity, 'field_metabolic_equivalent_coef');
  if (!empty($field[0]['value']) and is_numeric($_POST['time'])) {
    $time = $_POST['time'];
    $result = $time * ($field[0]['value'] * 3.5 * $_POST['weight'] / 0.454) / 200;
  }
  if ($result) {
    print number_format($time, 2) . ' minutes of ' . strtolower($activity->name) . ' burns approximately ' . number_format(round($result), 0) . ' calories.';
  }
  drupal_exit();
}


/**
 *  @brief  Creates and displays autocomplete locations from facilities and trail names
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_mileage_location_autocomplete($string) {
  if (strlen($string) < 3) {
    drupal_json_output(array());
    drupal_exit();
  }
  $string = strtolower($string);
  $matches = array();
  $scores = array();
  $titles = array();
  $v = taxonomy_vocabulary_machine_name_load('facilities');
  $tree = taxonomy_get_tree($v->vid);
  foreach ($tree as $term) {
    if (in_array($term->name, $titles)) {
      continue;
    }
    $titles[] = $term->name;
    $score = mo_project_score_string_match($string, strtolower($term->name));
    if (!isset($scores[$score])) {
      $scores[$score] = array();
    }
    $scores[$score][] = $term->name;
  }
  $query = db_select('node', 'n');
  $query->condition('n.type', 'trail');
  $query->condition('n.status', 0, '>');
  $query->addField('n', 'title');
  $result = $query->execute();
  foreach ($result as $row) {
    if (in_array($row->title, $titles)) {
      continue;
    }
    $titles[] = $row->title;
    $score = mo_project_score_string_match($string, strtolower($row->title));
    if (!isset($scores[$score])) {
      $scores[$score] = array();
    }
    $scores[$score][] = $row->title;
  }
  $score_keys = array_keys($scores);
  sort($score_keys);
  foreach ($score_keys as $score) {
    if ($score > 0 and count($matches) > 10) {
      break;
    }
    $suggestions = $scores[$score];
    sort($suggestions);
    foreach ($suggestions as $suggestion) {
      if ($score > 0 and count($matches) > 10) {
        break;
      }
      $matches[$suggestion] = $suggestion;
    }
  }
  drupal_json_output($matches);
}


/**
 *  @brief  Updates mileage totals on homepage and dashboard
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_get_user_current_stats() {
  global $user;
  $output = array();
  $output['total'] = (int) round(mo_project_get_total_mileage(array(), array(), 'all'));
  $output['user_total'] = (int) round(mo_project_get_total_mileage(array($user->uid), array(), 'all'));
  $output['user_challenge_total'] = (int) round(mo_project_get_total_mileage(array($user->uid)));
  $v = taxonomy_vocabulary_machine_name_load('activities');
  $v_tree = taxonomy_get_tree($v->vid, 0, 1);
  foreach ($v_tree as $activity) {
    if ($activity->name != 'Other') {
      $name = drupal_clean_css_identifier(strtolower($activity->name));
      $activity_total = (int) round(mo_project_get_total_mileage(array($user->uid), array($activity->tid)));
      if (!$activity_total) {
        continue;
      }
      $output['user_total_' . $name] = $activity_total;

      $user30_mileage = mo_project_get_total_mileage(array($user->uid), array($activity->tid), '30day');
      $avg30_mileage = mo_project_get_leaderboard_activity_stats('average', $activity->tid, $user->uid);
      $leader30_mileage = mo_project_get_leaderboard_activity_stats('leader', $activity->tid, $user->uid);

      // If the user enters miles that make him/her the leader and cron has not yet run,
      // make the user the leader.
      if ($user30_mileage > $leader30_mileage) {
        $leader30_mileage = $user30_mileage;
        if ($avg30_mileage == 0) {
          $avg30_mileage = $user30_mileage;
        }
      }

      $output['user_30day_' . $name] = (int) round($user30_mileage);
      $output['avg_30day_' . $name] = (int) round($avg30_mileage);
      $output['leader_30day_' . $name] = (int) round($leader30_mileage);
    }
  }

  $output['upcoming_trophies'] = drupal_render(mo_project_build_upcoming_trophy_block());
  drupal_json_output($output);
  drupal_exit();
}


/**
 *  @brief  Display individual badge description on click
 *
 *  @return  void
 *
 *  @details  2013
 */
function mo_project_badge_detail($nid) {
  if (!empty($nid)) {
    $node = node_load($nid);
    $image_field = field_get_items('node', $node, 'field_achievement_badge');
    $body_field = field_get_items('node', $node, 'body');
    $output = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'badge-detail',
        ),
      ),
      'image' => array(
        '#markup' => mo_project_get_badge_image($image_field, 'sm'),
      ),
      'title' => array(
        '#prefix' => t('<h3>'),
        '#markup' => t($node->title),
        '#suffix' => t('</h3>'),
      ),
    );
    if (!empty($body_field[0]['safe_value'])) {
      $output['body'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'badge-description',
          ),
        ),
        'content' => array(
          '#markup' => t($body_field[0]['safe_value']),
        ),
      );
    }
    print drupal_render($output);
  }
  drupal_exit();
}
