<?php

/**
 * Implements hook_field_formatter_info
 */
function mogov_foundations_field_formatter_info() {
  return array(
    'us_telephone_link' => array(
      'label' => t('Telephone link (US format)'),
      'field types' => array('telephone'),
      'settings' => array(
        'title' => '',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function mogov_foundations_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $elements['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title to replace basic numeric telephone number display.'),
    '#default_value' => $settings['title'],
  );
  $elements['ac_format'] = array(
    '#type' => 'radios',
    '#title' => 'format',
    '#default_value' => isset($settings['ac_format']) ? $settings['ac_format'] : 'parens',
    '#options' => array(
      'parens' => '(###) ###-####',
      'dashes' => '###-###-####',
    ),
  );

  return $elements;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function mogov_foundations_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = '';

  if (!empty($settings['title'])) {
    $summary .= t('Link using text: @title<br>', array('@title' => $settings['title']));
  } else {
    $summary .= t('Link using provided telephone number.<br>');
  }
  if ($settings['ac_format'] == 'dashes') {
    $summary .= t('Format: ###-###-####');
  } else {
    $summary .= t('Format: (###) ###-####');
  }

  return $summary;
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function mogov_foundations_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  foreach ($entities as $id => $entity) {
    $settings = $displays[$id]['settings'];
    foreach ($items[$id] as &$item) {
      // If available, set custom link text.
      if (!empty($settings['title'])) {
        $item['title'] = $settings['title'];
      }
      // Otherwise, use telephone number itself as title.
      else {
        $number = preg_replace('/[^0-9]/', '', $item['value']);
        if (strlen($number) == 7) {
          $parts = array(
            '!prefix' => substr($number, 0, 3),
            '!number' => substr($number, 3),
          );
          $item['title'] = t('!prefix-!number', $parts);
        } elseif (strlen($number) == 10) {
          $parts = array(
            '!area' => substr($number, 0, 3),
            '!prefix' => substr($number, 3, 3),
            '!number' => substr($number, 6),
          );
          if ($settings['ac_format'] == 'dashes') {
            $item['title'] = t('!area-!prefix-!number', $parts);
          } else {
            $item['title'] = t('(!area) !prefix-!number', $parts);
          }
        } else {
          $item['title'] = $item['value'];
        }
      }
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function mogov_foundations_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  foreach ($items as $delta => $item) {
    // Prepend 'tel:' to the telephone number.
    $href = 'tel:' . rawurlencode(preg_replace('/\s+/', '', $item['value']));

    // Render each element as link.
    $element[$delta] = array(
      '#type' => 'link',
      '#title' => $item['title'],
      '#href' => $href,
      '#options' => array('external' => TRUE),
    );
  }

  return $element;
}
