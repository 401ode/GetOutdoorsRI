<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Sites that don't use the megamenu block will use the Main Menu block
 * in its place; disable all submenu display
 */
function mogov_blue_block_view_alter(&$data, $block) {
  if ($block->module == 'system' and $block->delta == 'main-menu') {
    foreach ($data['content'] as $key=>$item) {
      if (is_array($item) and array_key_exists('#below', $item)) {
        $data['content'][$key]['#below'] = array();
      }
    }
  }
}
function mogov_blue_feed_icon($vars) {
  $text = t('Subscribe to @feed-title', array('@feed-title' => $vars['title']));
  if ($image = theme('image', array('path' => 'misc/feed.png', 'width' => 16, 'height' => 16, 'alt' => $text))) {
    $link_text = $image . t('<span class="feed-link-text">Subscribe to @feed-title</span>', array('@feed-title' => $vars['title']));
    return l($link_text, $vars['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon'), 'title' => $text)));
  }
}
