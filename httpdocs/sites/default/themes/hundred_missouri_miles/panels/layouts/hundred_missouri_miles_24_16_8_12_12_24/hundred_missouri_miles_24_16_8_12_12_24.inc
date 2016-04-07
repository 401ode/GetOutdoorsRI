<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_24_16_8_12_12_24_panels_layouts() {
  $items['hundred_missouri_miles_24_16_8_12_12_24'] = array(
    'title' => t('24 top, 16/8 mid, 12/12 mid, 24 bottom'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_24_16_8_12_12_24.png',
    'theme' => 'hundred_missouri_miles_24_16_8_12_12_24',
    'admin css' => '../hundred_missouri_miles_panels_admin.css',
    'regions' => array(
      'top' => t('Top (24)'),
      'mid1_left' => t('Mid 1 Left (16)'),
      'mid1_right' => t('Mid 1 Right (8)'),
      'mid2_left' => t('Mid 1 Left (12)'),
      'mid2_right' => t('Mid 1 Right (12)'),
      'bottom' => t('Bottom (24)'),
    ),
  );

  return $items;
}
