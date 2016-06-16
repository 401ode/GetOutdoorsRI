<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_12_8_4_panels_layouts() {
  $items['hundred_missouri_miles_12_8_4'] = array(
    'title' => t('Minipanel, 12/8/4'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_12_8_4.png',
    'theme' => 'hundred_missouri_miles_12_8_4',
    'admin css' => '../hundred_missouri_miles_panels_admin.css',
    'regions' => array(
      'left' => t('Left (12)'),
      'mid' => t('Mid (8)'),
      'right' => t('Right (4)'),
    ),
  );

  return $items;
}
