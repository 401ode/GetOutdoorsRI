<?php

/**
 * Implements hook_form_alter() for various news-related forms
 */
function mogov_news_form_mogov_news_release_node_form_alter(&$form, &$form_state, $form_id) {
  $support_multiple_sources = variable_get_value('mogov_news_support_multiple_sources');
  if ($support_multiple_sources) {
    $approved_sources = mogov_news_get_authorized_sources();
    if ($approved_sources == 'none') {
      $form['#disabled'] = TRUE;
      drupal_set_message('<b>Please contact a webmaster or administrator.</b> You have been granted access to the news content type, but have not been authorized for any news sources. Someone will need to correct your user settings.', 'warning');
    } elseif ($approved_sources != 'all') {
      if (count($approved_sources) === 1) {
        $form['field_mogov_news_source']['#disabled'] = TRUE;
        $form['field_mogov_news_source']['und']['#default_value'] = $approved_sources[0];
      } else {
        $keys = array_keys($form['field_mogov_news_source']['und']['#options']);
        foreach ($keys as $key) {
          if ($key != '_none') {
            mogov_news_prune_options($form['field_mogov_news_source']['und']['#options'][$key], $approved_sources);
            if (empty($form['field_mogov_news_source']['und']['#options'][$key])) {
              unset($form['field_mogov_news_source']['und']['#options'][$key]);
            }
          }
        }
      }
    }
  } else {
    unset($form['field_mogov_news_source']);
  }
}

function mogov_news_form_mogov_news_release_link_node_form_alter(&$form, &$form_state, $form_id) {
  mogov_news_form_mogov_news_release_node_form_alter($form, $form_state, $form_id);
}

function mogov_news_form_user_profile_form_alter(&$form, &$form_state) {
  if (!empty($form['field_authorized_sources'])) {
    if (!user_access('administer users')) {
      $form['field_authorized_sources']['#disabled'] = TRUE;
    }
  }
}

function mogov_news_prune_options(&$options, $allowed) {
  foreach ($options as $tid=>$label) {
    if (!in_array($tid, $allowed)) {
      unset($options[$tid]);
    } else {
      $options[$tid] = html_entity_decode($label, ENT_QUOTES);
    }
  }
}
