<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = array(
  'title' => t('Google Directions Link'),
  'format callback' => 'addressfield_format_directions_link',
  'type' => 'address',
  'weight' => -80,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_directions_link(&$format, $address, $context=array()) {
  if ($context['mode'] == 'render') {
    $segments = array(
      'organisation_name',
      'thoroughfare',
      'premise',
      'sub_premise',
      'administrative_area',
      'postal_code',
    );
    $destination = array();
    foreach ($segments as $key) {
      if (!empty($address[$key])) {
        $destination[] = $address[$key] . ',';
      }
    }
    $options = array(
      'query' => array(
        'saddr' => 'current+location',
        'daddr' => implode('+', $destination),
        'hl' => 'en',
      ),
    );
    $link = l(t('Get directions'), '//maps.google.com/maps', $options);
    $format['directions_link_block'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('addressfield-container-inline', 'directions-link-block')),
      '#weight' => 100,
    );
    $format['directions_link_block']['directions_link'] = array(
      '#title' => t('Directions link'),
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array('directions-link-block'),
      ),
    );
  }
}
