<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_12_4_16_panels_layouts() {
  $items['hundred_missouri_miles_12_4_16'] = array(
    'title' => t('Minipanel, 12/4 top, 16 bottom'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_12_4_16.png',
    'theme' => 'hundred_missouri_miles_12_4_16',
    'admin css' => '../hundred_missouri_miles_panels_admin.css',
    'regions' => array(
      'top_left' => t('Top Left (12)'),
      'top_right' => t('Top Right (4)'),
      'bottom' => t('Bottom (16)'),
    ),
  );

  return $items;
}
