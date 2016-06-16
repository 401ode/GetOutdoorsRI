<?php
/**
 * @file
 * campus_challenge.data_default.inc
 */

/**
 * Implements hook_data_default().
 */
function campus_challenge_data_default() {
  $export = array();

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Leaderboard campus';
  $data_table->name = 'leaderboard_campus';
  $data_table->table_schema = array(
    'description' => 'The lookup table for campus leaderboard statistics.',
    'fields' => array(
      'rid' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'The primary identifier for a row.',
      ),
      'campus_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => 'The node id of the campus.',
      ),
      'challenge_year' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
        'not null' => TRUE,
        'description' => 'The Challenge Year this row belongs to, used for archiving old years data.',
      ),
      'tot_distance_value' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => 'The total mileage logged to the activity by verified users registed with an included email address.',
      ),
      'user_count' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => 'The number of verified users registed with an included email address.',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'leaderboard_campus',
    'primary key' => array(
      0 => 'rid',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'rid' => array(
        'label' => 'Row ID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'challenge_year' => array(
        'label' => 'Challenge Year',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'campus_nid' => array(
        'label' => 'Campus NID',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'tot_distance_value' => array(
        'label' => 'Distance',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'user_count' => array(
        'label' => 'User Count',
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'updated' => array(
        'label' => 'Last Updated',
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
        'date' => array(
          'sql_type' => 'datestamp',
          'granularity' => '',
        ),
      ),
    ),
  );
  $export['leaderboard_campus'] = $data_table;

  return $export;
}
