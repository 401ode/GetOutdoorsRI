<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Google Analytics'),
  'description' => t('Various views of Google Analytics data.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_google_analytics_pane_edit_form',
  'render callback' => 'mogov_dashboard_google_analytics_pane_render',
  'admin info' => 'mogov_dashboard_google_analytics_pane_admin_info',
  'defaults' => array(
    'type' => '',
    'days' => 7,
    'units' => 'days',
    'color' => 'blue',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_google_analytics_pane_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Select display type'),
    '#options' => array(
      'top_pages' => t('Top pages'),
      'visits' => t('Visits'),
      'pageviews' => t('Pageviews'),
    ),
    '#default_value' => $conf['type'],
  );
  $form['days'] = array(
    '#type' => 'numberfield',
    '#title' => t('Number of days to display'),
    '#default_value' => $conf['days'],
    '#min' => 1,
    '#max' => 30,
  );
  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Select chart bars color'),
    '#options' => array(
      'blue' => t('Blue'),
      'green' => t('Green'),
      'orange' => t('Orange'),
      'yellow' => t('Yellow'),
    ),
    '#default_value' => $conf['color'],
  );

  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_google_analytics_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the pane
 * See ctools_plugin_examples for more advanced info
 */
function mogov_dashboard_google_analytics_pane_render($subtype, $conf, $args, $contexts) {

  // Include the google analytics API functions
  module_load_include('inc', 'mogov_dashboard', 'includes/google_analytics_api');
  
  $pane = new stdClass();
  $service = mogov_dashboard_google_analytics_create_service();
  if (!$service) {
    return FALSE;
  }

  // Add CSS support file
  $css = drupal_get_path('module', 'mogov_dashboard') . '/css/dashboard.css';
  drupal_add_css($css, array('type' => 'file'));
  
  // Pick a query and generate content
  switch($conf['type']) {
    case 'top_pages':
      $pane->title = t('Top pageviews in last !days days', array('!days' => $conf['days']));
      $pane->content = mogov_dashboard_google_analytics_query_top_pages($service, $conf);
      break;
    case 'visits':
      $pane->title = t('Visits in last !days days', array('!days' => $conf['days']));
      $pane->content = mogov_dashboard_google_analytics_query_simple($service, 'Visits', 'sessions', $conf);
      break;
    case 'pageviews':
      $pane->title = t('Pageviews in last !days days', array('!days' => $conf['days']));
      $pane->content = mogov_dashboard_google_analytics_query_simple($service, 'Pageviews', 'pageviews', $conf);
      break;
  }

  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_google_analytics_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Stats: ' . $conf['type']);
    $pane->content = '';
    return $pane;
  }
}

function mogov_dashboard_google_analytics_get_rows($rows, $keys) {
  $parsed_rows = array();
  foreach ($rows as $i=>$row) {
    $parsed_rows[$i] = array();
    foreach ($keys as $j=>$key) {
      $parsed_rows[$i][$key] = $row[$j];
    }
  }
  return $parsed_rows;
}

function mogov_dashboard_google_analytics_query_top_pages($service, $conf) {
  $days_delta = '-' . $conf['days'] - 1 . ' days';
  $last = date('Y-m-d', strtotime($days_delta));
  $today = date('Y-m-d');
  $params = array(
    'max-results' => 10,
    'sort' => '-ga:pageviews',
    'dimensions' => 'ga:pagePath',
  );
  $rows = mogov_dashboard_google_analytics_query($service, $last, $today, $params);
  if (!is_array($rows)) {
    return $rows;
  }
  $header = array(
    'Path',
    'Pageviews',
  );
  $rows = mogov_dashboard_google_analytics_get_rows($rows, $header);
  $output = mogov_dashboard_google_analytics_format_top_pages($rows, $header, $conf['color']);
  return $output;
}

function mogov_dashboard_google_analytics_format_top_pages($rows, $header, $chart_color) {
  $table = array(
    'header' => $header,
    'rows' => array(),
    'attributes' => array(
      'class' => array(
        'chart-table',
        $chart_color,
      ),
    ),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => FALSE,
    'empty' => NULL,
  );
  // Find max value
  $max = 0;
  foreach ($rows as $row) {
    if ($row['Pageviews'] > $max) {
      $max = $row['Pageviews'];
    }
  }
  $max = ceil($max / 100) * 100;
  foreach ($rows as $row) {
    if ($row['Path'] == '/') {
      $title = '&lt;front&gt;';
      $path = '';
      $options = array(
        'html' => TRUE,
      );
    } else {
      $options = array();
      $url = parse_url($row['Path']);
      $path = substr($url['path'], 1);
      if (!empty($url['query'])) {
        parse_str($url['query'], $options['query']);
      }
      $title = substr($row['Path'], 1);
    }
    $table['rows'][] = array(
      array(
        'data' => l($title, $path, $options),
        'class' => 'chart-background',
        'style' => t('background-size: !percentage% 100%', array('!percentage' => $row['Pageviews'] / $max * 100)),
      ),
      $row['Pageviews'],
    );
  }

  return theme_table($table);
}

function mogov_dashboard_google_analytics_query_simple($service, $column_header, $metric, $conf) {
  $days = array();
  for ($i = $conf['days'] - 1; $i >= 0; $i--) {
    $days[] = strtotime('-' . $i . ' days');
  }
  $params = array(
    'metrics' => 'ga:' . $metric,
  );
  $date_rows = array();
  $max = 0;
  foreach ($days as $day) {
    $day_string = date('Y-m-d', $day);
    $date_rows[$day] = mogov_dashboard_google_analytics_query($service, $day_string, $day_string, $params);
    if (!is_array($date_rows[$day])) {
      return $date_rows[$day];
    }
    if ($date_rows[$day][0][0] > $max) {
      $max = $date_rows[$day][0][0];
    }
  }
  $header = array(
    'Date',
    $column_header,
  );
  $output = mogov_dashboard_google_analytics_format_simple($date_rows, $header, $max, $conf['color']);
  return $output;
}

function mogov_dashboard_google_analytics_format_simple($rows, $header, $max, $chart_color) {
  $table = array(
    'header' => $header,
    'rows' => array(),
    'attributes' => array(
      'class' => array(
        'chart-table',
        $chart_color,
      ),
    ),
    'caption' => NULL,
    'colgroups' => array(),
    'sticky' => FALSE,
    'empty' => NULL,
  );
  // Round to number of digits of max value minus 1. E.g., if max value is in the thousands,
  // round up to nearest 100.
  $factor = max(strlen($max) - 2, 1);
  $roundval = pow(10, $factor);
  $max = ceil($max / $roundval) * $roundval;
  foreach ($rows as $day=>$row) {
    $day_string = date('F j, Y', $day);
    $table['rows'][] = array(
      array(
        'data' => $day_string,
        'class' => 'chart-background',
        'style' => t('background-size: !percentage% 100%', array('!percentage' => $row[0][0] / $max * $roundval)),
      ),
      $row[0][0],
    );
  }

  return theme_table($table);
}