<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_4_4_4_4_16_panels_layouts() {
  $items['hundred_missouri_miles_4_4_4_4_16'] = array(
    'title' => t('Minipanel, 4/4/4/4 top, 16 bottom'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_4_4_4_4_16.png',
    'theme' => 'hundred_missouri_miles_4_4_4_4_16',
    'admin css' => '../hundred_missour_miles_panels_admin.css',
    'regions' => array(
      'top_1' => t('Top Col 1 (4)'),
      'top_2' => t('Top Col 2 (4)'),
      'top_3' => t('Top Col 3 (4)'),
      'top_4' => t('Top Col 4 (4)'),
      'bottom' => t('Bottom (16)'),
    ),
  );

  return $items;
}
