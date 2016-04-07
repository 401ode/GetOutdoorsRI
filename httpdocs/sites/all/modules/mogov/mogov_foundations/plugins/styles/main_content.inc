<?php

/**
 * @file
 * Definition of the 'Main Content' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Main Content'),
  'description' => t('Adds a class to indicate that this pane contains main content.'),
  'render region' => 'panels_mogov_foundations_main_content_style_render_region',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_mogov_foundations_main_content_style_render_region($vars) {
  $output = '<div class="main-content-wrapper">';
  $output .= implode('<div class="panel-separator"></div>', $vars['panes']);
  $output .= '</div>';
  return $output;
}

