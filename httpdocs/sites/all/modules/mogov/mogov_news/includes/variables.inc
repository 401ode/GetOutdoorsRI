<?php

/**
 * Implements hook_variable_info().
 */
function mogov_news_variable_info($options) {
    
  $variables['mogov_news_archive_path'] = array(
    'title' => t('Path to the main news archive', array(), $options),
    'description' => t('Used to build links to the news archive at the end of lists.'),
    'type' => 'string',
    'access' => 'access administration pages',
    'default' => 'newsroom/news-archive',
  );
  
  $variables['mogov_news_recent_block_count'] = array(
    'title' => t('Number of items to display in Recent News Releases block', array(), $options),
    'description' => t('Enter 0 to disable block.'),
    'type' => 'number',
    'access' => 'access administration pages',
    'default' => 5,
    'element' => array(
      '#size' => 3,
    ),
  );
  
  $variables['mogov_news_topic_block_count'] = array(
    'title' => t('Number of items to display in Related News Releases block', array(), $options),
    'description' => t('Enter 0 to disable block.'),
    'type' => 'number',
    'access' => 'access administration pages',
    'default' => 5,
    'element' => array(
      '#size' => 3,
    ),
  );
  
  $variables['mogov_news_support_multiple_sources'] = array(
    'title' => t('Support multiple sources', array(), $options),
    'description' => t('Do not enable this unless you know what you\'re doing.'),
    'type' => 'boolean',
    'access' => 'access administration pages',
    'default' => 0,
  );

  return $variables;
}
