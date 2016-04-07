<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_4_top_1_bottom_panels_layouts() {
  $items['hundred_missouri_miles_4_top_1_bottom'] = array(
    'title' => t('4 columns top, 1 column bottom'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_4_top_1_bottom.png',
    'theme' => 'hundred_missouri_miles_4_top_1_bottom',
    'css' => 'hundred_missouri_miles_4_top_1_bottom.css',
    'admin css' => '../hundred_missour_miles_panels_admin.css',
    'regions' => array(
      'top_1' => t('Top Col 1'),
      'top_2' => t('Top Col 2'),
      'top_3' => t('Top Col 3'),
      'top_4' => t('Top Col 4'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
