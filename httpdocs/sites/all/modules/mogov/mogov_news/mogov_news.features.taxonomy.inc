<?php
/**
 * @file
 * mogov_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mogov_news_taxonomy_default_vocabularies() {
  return array(
    'additional_news_sources' => array(
      'name' => 'Additional News Sources',
      'machine_name' => 'additional_news_sources',
      'description' => 'Most news comes from agencies. This vocabulary is a catch-all for other sources.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'mogov_news_remote_news_sources' => array(
      'name' => 'Remote News Sources',
      'machine_name' => 'mogov_news_remote_news_sources',
      'description' => 'Non-local sources for News Release Link nodes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
