<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_16x2_8_24_panels_layouts() {
  $items['hundred_missouri_miles_16x2_8_24'] = array(
    'title' => t('16x2/8 top, 24 bottom'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_16x2_8_24.png',
    'theme' => 'hundred_missouri_miles_16x2_8_24',
    'admin css' => '../hundred_missouri_miles_panels_admin.css',
    'regions' => array(
      'top_left_upper' => t('Top Left Upper (16)'),
      'top_left_lower' => t('Top Left Lower (16)'),
      'top_right' => t('Top Right (8)'),
      'bottom' => t('Bottom (24)'),
    ),
  );

  return $items;
}
