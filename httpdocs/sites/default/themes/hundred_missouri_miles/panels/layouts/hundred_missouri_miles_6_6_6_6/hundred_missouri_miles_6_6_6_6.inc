<?php

/**
 * Implements hook_panels_layouts().
 */
function hundred_missouri_miles_hundred_missouri_miles_6_6_6_6_panels_layouts() {
  $items['hundred_missouri_miles_6_6_6_6'] = array(
    'title' => t('6/6/6/6'),
    'category' => t('100 Missouri Miles'),
    'icon' => 'hundred_missouri_miles_6_6_6_6.png',
    'theme' => 'hundred_missouri_miles_6_6_6_6',
    'admin css' => '../hundred_missouri_miles_panels_admin.css',
    'regions' => array(
      'col1' => t('Column 1 (6)'),
      'col2' => t('Column 2 (6)'),
      'col3' => t('Column 3 (6)'),
      'col4' => t('Column 4 (6)'),
    ),
  );

  return $items;
}
