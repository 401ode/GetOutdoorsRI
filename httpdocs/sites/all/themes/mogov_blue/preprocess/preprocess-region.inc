<?php

function mogov_blue_alpha_preprocess_region(&$vars) {

      switch($vars['elements']['#region']) {
            
            case 'content':
                  $theme = alpha_get_theme();
                  $vars['breadcrumb'] = $theme->page['breadcrumb'];
                  if (function_exists('mo_social_render_buttons')) {
                    $social = mo_social_render_buttons();
                    if ($social) {
                          $vars['social'] = $social;
                    }
                  }
                  break;
            
      }

}
