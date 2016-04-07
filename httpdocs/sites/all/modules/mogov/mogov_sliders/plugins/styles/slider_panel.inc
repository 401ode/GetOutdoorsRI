<?php

/**
 * @file
 * Definition of the 'Slider' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Slider'),
  'description' => t('Displays a panel as a slider, using the panes as slides.'),
  'render region' => 'panels_mogov_sliders_slider_panel_style_render_region',
  'settings form' => 'panels_mogov_sliders_slider_panel_style_settings_form',
  'settings validate' => 'panels_mogov_sliders_slider_panel_style_settings_validate',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_mogov_sliders_slider_panel_style_render_region($vars) {
  $id = drupal_clean_css_identifier($vars['display']->css_id);
  $output = array(
    'wrapper' => array(
      '#type' => 'container',
      '#title' => NULL,
      '#attributes' => array(
        'class' => array(
          'panel-slider',
        ),
      ),
      'slider' => array(
        '#type' => 'container',
        '#title' => NULL,
        '#attributes' => array(
          'id' => $id,
          'class' => array(
            'flexslider',
          ),
        ),
        'slides' => array(
          '#type' => 'container',
          '#title' => NULL,
          '#attributes' => array(
            'class' => array(
              'slides',
            ),
          ),
        ),
      ),
    ),
  );
  foreach ($vars['panes'] as $i=>$pane) {
    $output['wrapper']['slider']['slides'][$i] = array(
      '#type' => 'container',
      '#title' => NULL,
      '#attributes' => array(
        'class' => array(
          'slide',
        ),
      ),
      0 => array(
        '#markup' => $pane,
      ),
    );
  }
  if (!empty($vars['settings']['navigation_options']['title_nav'])) {
    $position = !empty($vars['settings']['navigation_options']['title_nav_position']) ? $vars['settings']['navigation_options']['title_nav_position'] : 'bottom';
    $output['wrapper']['#attributes']['class'][] = t('title-nav');
    $list = array(
      'type' => 'ol',
      'title' => NULL,
      'attributes' => array(
        'class' => 'flex-control-nav',
      ),
      'items' => array(),
    );
    foreach (array_keys($vars['panes']) as $pid) {
      $panel_info = $vars['display']->content[$pid];
      $list['items'][] = panels_mogov_sliders_slider_panel_get_title($panel_info);
    }
    $output['wrapper']['navigation'] = array(
      '#type' => 'container',
      '#title' => NULL,
      '#attributes' => array(
        'class' => array(
          'flexslider-controls',
          $position,
        ),
      ),
      'nav_items' => array(
        '#markup' => theme_item_list($list),
      ),
    );
  }
  $markup = render($output);
  mogov_sliders_slider_panel_add_script($id, $vars['settings']);
  return $markup;
}

/**
 * Settings form callback.
 */
function panels_mogov_sliders_slider_panel_style_settings_form($style_settings) {
  $form['animation_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Animation options'),
  );
  $form['animation_options']['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      'horizontal' => t('Horizontal'),
      'vertical' => t('Vertical'),
    ),
    '#default_value' => (isset($style_settings['animation_options']['direction'])) ? $style_settings['animation_options']['direction'] : 'horizontal',
  );
  $form['animation_options']['animation'] = array(
    '#type' => 'select',
    '#title' => t('Animation'),
    '#options' => array(
      'slide' => t('Slide'),
      'fade' => t('Fade'),
    ),
    '#default_value' => (isset($style_settings['animation_options']['animation'])) ? $style_settings['animation_options']['animation'] : 'slide',
  );
  $form['animation_options']['interval'] = array(
    '#type' => 'numberfield',
    '#title' => t('Slide interval'),
    '#default_value' => (isset($style_settings['animation_options']['interval'])) ? $style_settings['animation_options']['interval'] : 7000,
  );
  $form['animation_options']['smooth_height'] = array(
    '#type' => 'checkbox',
    '#title' => t('Variable height'),
    '#default_value' => (isset($style_settings['animation_options']['smooth_height'])) ? $style_settings['animation_options']['smooth_height'] : 0,
    '#description' => t('Dynamically adjust slider height to match each slide. This does not work well on carousels.'),
  );
  $form['animation_options']['randomize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Randomize slide order'),
    '#default_value' => (isset($style_settings['animation_options']['randomize'])) ? $style_settings['animation_options']['randomize'] : 0,
  );
  $form['navigation_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navigation options'),
    '#description' => t('These settings modify or add navigational elements.'),
  );
  $form['navigation_options']['control_nav'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable control navigation'),
    '#default_value' => (isset($style_settings['navigation_options']['control_nav'])) ? $style_settings['navigation_options']['control_nav'] : 1,
    '#description' => t('Enables bullet-style pager navigation.'),
  );
  $form['navigation_options']['title_nav'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use pane titles for navigation'),
    '#default_value' => (isset($style_settings['navigation_options']['title_nav'])) ? $style_settings['navigation_options']['title_nav'] : 0,
    '#description' => t('Replaces bullet navigation with pane titles. <strong>You must enter a title for every pane if using this option.</strong>'),
    '#states' => array(
      'invisible' => array(
        ':input[name="settings[navigation_options][control_nav]"]' => array('checked' => FALSE),
      ),
      'unchecked' => array(
        ':input[name="settings[navigation_options][control_nav]"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['navigation_options']['title_nav_position'] = array(
    '#type' => 'radios',
    '#title' => t('Nav position'),
    '#options' => array(
      'bottom' => t('Bottom'),
      'right' => t('Right'),
    ),
    '#default_value' => (isset($style_settings['navigation_options']['title_nav_position'])) ? $style_settings['navigation_options']['title_nav_position'] : 'bottom',
    '#states' => array(
      'invisible' => array(
        ':input[name="settings[navigation_options][title_nav]"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['carousel_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Carousel options'),
    '#description' => t('These settings are used for "carousel mode," where multiple slides display at once. Leave all these items set to 0 for normal non-carousel slider behavior.'),
  );
  $form['carousel_options']['item_width'] = array(
    '#type' => 'numberfield',
    '#title' => t('Item width'),
    '#default_value' => (isset($style_settings['carousel_options']['item_width'])) ? $style_settings['carousel_options']['item_width'] : '0',
  );
  $form['carousel_options']['item_margin'] = array(
    '#type' => 'numberfield',
    '#title' => t('Item margin'),
    '#default_value' => (isset($style_settings['carousel_options']['item_margin'])) ? $style_settings['carousel_options']['item_margin'] : '0',
    '#description' => t('This property does not do anything on its own. The margin must also be set in CSS. The property value simply allows the plugin to predict the CSS value (presumably for performance reasons). The value in this field should be the total of the margin on both sides of the slide. E.g., if the slide has a 5px margin on right and left, this value should be set to 10.'),
  );
  $form['carousel_options']['min_items'] = array(
    '#type' => 'numberfield',
    '#title' => t('Minimum items'),
    '#default_value' => (isset($style_settings['carousel_options']['min_items'])) ? $style_settings['carousel_options']['min_items'] : '0',
  );
  $form['carousel_options']['max_items'] = array(
    '#type' => 'numberfield',
    '#title' => t('Maximum items'),
    '#default_value' => (isset($style_settings['carousel_options']['max_items'])) ? $style_settings['carousel_options']['max_items'] : '0',
  );
  $form['carousel_options']['move'] = array(
    '#type' => 'numberfield',
    '#title' => t('Move items per transition'),
    '#default_value' => (isset($style_settings['carousel_options']['move'])) ? $style_settings['carousel_options']['move'] : '0',
  );

  return $form;
}

/**
 * Build flexslider script
 */
function mogov_sliders_slider_panel_add_script($id, $settings) {
  module_load_include('inc', 'mogov_sliders', 'includes/script_support');
  $options = array(
    'selector' => '".slides > .slide"',
    'direction' => '"' . $settings['animation_options']['direction'] . '"',
    'slideshow' => 'true',
    'slideshowSpeed' => $settings['animation_options']['interval'],
    'animation' => '"' . $settings['animation_options']['animation'] . '"',
    'animationLoop' => 'true',
    'reverse' => 'false',
    'smoothHeight' => $settings['animation_options']['smooth_height'] ? 'true' : 'false',
    'pausePlay' => 'true',
    'touch' => 'true',
    'controlNav' => 'false',
    'directionNav' => 'true',
    'pauseOnAction' => 'true',
    'pauseOnHover' => 'true',
    'randomize' => $settings['animation_options']['randomize'] ? 'true' : 'false',
    'itemWidth' => $settings['carousel_options']['item_width'],
    'itemMargin' => $settings['carousel_options']['item_margin'],
    'minItems' => $settings['carousel_options']['min_items'],
    'maxItems' => $settings['carousel_options']['max_items'],
    'move' => $settings['carousel_options']['move'],
    'useCSS' => 'true',
  );
  if (!empty($settings['navigation_options']['control_nav']) and $settings['navigation_options']['control_nav']) {
    $options['controlNav'] = 'true';
    if (!empty($settings['navigation_options']['title_nav']) and $settings['navigation_options']['title_nav']) {
      $options['manualControls'] = '".flex-control-nav li"';
    }
  }

  $script = 'jQuery(document).ready(function($) {' . "\n"
          . '  $("#' . $id . '").flexslider({' . "\n";
  $i = 0;
  foreach ($options as $option=>$value) {
    mogov_sliders_add_cr($script, $i);
    $script .= '    ' . $option . ': ' . $value;
  }
  $script .= "\n  });\n";
  $script .= "});\n";

  libraries_load('flexslider');
  $module_path = drupal_get_path('module', 'mogov_sliders');
  drupal_add_css($module_path . '/css/mogov_sliders.css');
  drupal_add_js($script, array('type' => 'inline', 'scope' => 'footer'));
}

function panels_mogov_sliders_slider_panel_get_title($panel_info) {
  switch($panel_info->type) {
    case 'custom':
      if (!empty($panel_info->configuration['title'])) {
        return $panel_info->configuration['title'];
      }
      break;
    case 'fieldable_panels_pane':
      $uuid = substr($panel_info->subtype, 5);
      $entities = entity_uuid_load($panel_info->type, array($uuid));
      if (!empty($entities)) {
        $keys = array_keys($entities);
        return $entities[$keys[0]]->title;
      }
      break;      
    case 'panels_mini':
      return t('');
      break;    
  }

  return t('Title undefined!');

}