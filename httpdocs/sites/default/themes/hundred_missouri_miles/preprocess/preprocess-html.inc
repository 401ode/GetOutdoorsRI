<?php

/**
* Preprocesses the wrapping HTML.
*
* @param array &$variables
*   Template variables.
*/
function hundred_missouri_miles_alpha_preprocess_html(&$vars) {
  $theme_path = drupal_get_path('theme', $GLOBALS['theme']);

  // Setup meta tag 
  $meta_descr = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'description',
      'content' => 'Governor Nixon recently launched the 100 Missouri Miles initiative, challenging Missourians to complete 100 miles of outdoor physical activity by the end of the year.',
    )
  );
  $meta_keywords = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' =>  'keywords',
      'content' => '100 missouri miles, 100momiles, Missouri outdoors, Missouri activities, Missouri health incentive, Missouri trails, Missouri events',
    )
  );
 
  // Setup link rels
  $apple_touch_icon = array(
    '#tag' => 'link',
    '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'href' => $GLOBALS['base_url'] . '/' . $theme_path . '/img/apple-touch-icon.png',
    )
  );
  $facebook_post_img = array(
    '#tag' => 'link',
    '#attributes' => array(
        'rel' => 'img_src',
        'href' => $GLOBALS['base_url'] . '/' . $theme_path . '/img/100-Mo-Logo.png',
    )
  );

  // Add head meta and link rel tags
  drupal_add_html_head($apple_touch_icon, 'apple_touch_icon');
  drupal_add_html_head($facebook_post_img, 'facebook_post_img');
  if ($vars['is_front']) {
    drupal_add_html_head($meta_descr, 'meta_descr');
    drupal_add_html_head($meta_keywords, 'meta_keywords');
  }
}
