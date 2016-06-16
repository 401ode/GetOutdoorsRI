<?php

/**
 * @file
 * Definition of the 'Sidebar' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Sidebar'),
  'description' => t('Adds classes required to style sidebar content.'),
  'render region' => 'panels_mogov_foundations_sidebar_style_render_region',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_mogov_foundations_sidebar_style_render_region($vars) {
  $output = '<div class="sidebar-wrapper">';
  $output .= implode('<div class="panel-separator"></div>', $vars['panes']);
  $output .= '</div>';
  return $output;
}

