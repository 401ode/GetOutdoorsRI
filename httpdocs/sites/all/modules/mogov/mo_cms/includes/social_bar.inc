<?php

function mo_cms_social_bar() {

  $block = array();
  $block['subject'] = t('Social Bar');
  $block['content'] = mo_cms_social_bar_build();
  return $block;

}

function mo_cms_social_bar_build() {
  
  $content = array();
  $content['rss'] = mo_cms_social_bar_build_rss();
  if ($mailto = variable_get_value('mo_cms_social_bar_mailto')) {
    $content['mailto'] = mo_cms_social_bar_build_mailto($mailto);
  }
  if ($youtube = variable_get_value('mo_cms_social_bar_youtube')) {
    $content['youtube'] = mo_cms_social_bar_build_youtube($youtube);
  }
  if ($twitter = variable_get_value('mo_cms_social_bar_twitter')) {
    $content['twitter'] = mo_cms_social_bar_build_twitter($twitter);
  }
  return render($content);
  
}

function mo_cms_social_bar_build_rss() {
  $link_options = array(
    'attributes' => array(
      'class' => array(
        'ir',
        'rss',
      ),
    ),
  );
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'mo-cms-social-bar-rss',
      'class' => array(
        'mo-cms-social-bar-item',
      ),
    ),
    'content' => array(
      '#markup' => l('RSS', 'rss.xml', $link_options),
    ),
  );
  return $content;
}

function mo_cms_social_bar_build_mailto($mailto) {
  $link_options = array(
    'absolute' => TRUE,
    'attributes' => array(
      'class' => array(
        'ir',
        'email',
      ),
    ),
  );
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'mo-cms-social-bar-mailto',
      'class' => array(
        'mo-cms-social-bar-item',
      ),
    ),
    'content' => array(
      '#markup' => l('Send Email', 'mailto:' . $mailto, $link_options),
    ),
  );
  return $content;
}

function mo_cms_social_bar_build_twitter($twitter) {
  $link_options = array(
    'external' => TRUE,
    'attributes' => array(
      'class' => array(
        'ir',
        'twitter',
      ),
    ),
  );
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'mo-cms-social-bar-twitter',
      'class' => array(
        'mo-cms-social-bar-item',
      ),
    ),
    'content' => array(
      '#markup' => l('Follow @' . $twitter . ' on Twitter', 'http://twitter.com/' . $twitter, $link_options),
    ),
  );
  return $content;
}

function mo_cms_social_bar_build_youtube($youtube) {
  $link_options = array(
    'external' => TRUE,
    'attributes' => array(
      'class' => array(
        'ir',
        'youtube',
      ),
    ),
  );
  $content = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'mo-cms-social-bar-youtube',
      'class' => array(
        'mo-cms-social-bar-item',
      ),
    ),
    'content' => array(
      '#markup' => l('Watch videos on YouTube', 'http://youtube.com/' . $youtube, $link_options),
    ),
  );
  return $content;
}