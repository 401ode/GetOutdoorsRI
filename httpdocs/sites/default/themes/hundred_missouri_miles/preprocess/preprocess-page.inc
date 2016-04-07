<?php

function hundred_missouri_miles_alpha_preprocess_page(&$vars) {
  $dest = drupal_get_destination();
  
  if (strpos($dest['destination'], '?') === FALSE) {
    $alias = drupal_get_path_alias($dest['destination']);
  } else {
    $pos = strpos($dest['destination'], '?');
    $alias = drupal_get_path_alias(substr($dest['destination'], 0, $pos));
    $params = substr($dest['destination'], $pos+1);
  }

  switch($alias) {
    case 'home':
    case 'dashboard':
      // New panels-based dashboard and home pages
      // Set the title
//      global $user;
//      $vars['title'] = t('Welcome ' . format_username($user));
      $vars['title'] = t('');
      break;
    case 'blog/blog-results':
      if (!empty($params)) {
        $pos2 = strpos($params, 'combine=');
        $searched = urldecode(substr($params, $pos2+8));
        $vars['title'] = check_plain($vars['node']->title . ": " . $searched);
        drupal_set_title(check_plain($vars['node']->title . ": " . $searched), PASS_THROUGH);
      }
      break;    
  }

  if (substr($alias, 0, 10) == "blog-tags/") {
    $vars['title'] = t('Tag Archives: ' . $vars['page']['content']['content']['content']['system_main']['term_heading']['term']['#term']->name);
  }

  
  // Manage messages Drupal displays to users
  // Remove the "[node title] has been created." message for user-submitted,
  // unpublished nodes

  //Get current messages.
  $messages = drupal_get_messages();

  if(!empty($messages)) {
    switch($alias) {
    case 'trails/share':
    case 'events/share':
    case 'groups/create':
      // Remove only the "... has been created" message, other messages should remain.

      foreach($messages as $type => $type_messages) {
        foreach ($type_messages as $message) {
          if( ($type != 'status') OR (substr($message, -17) != 'has been created.') ) {
            drupal_set_message($message, $type);
          }
        }
      }  
      break;
      
/*    case 'node/38243':
      // node/38243 == content/request-medal-status
      // Remove the "... has been created" message and/or 
      // the "You may not submit another entry at this time." message, 
      // other messages should remain.
      foreach($messages as $type => $type_messages) {
        foreach ($type_messages as $message) {

          if ($type == 'warning') {
            drupal_set_message($message, $type);
            
          } else if( ($type == 'status') AND (substr($message, -17) != 'has been created.') ) {
            drupal_set_message($message, $type);
            
          } else if( ($type == 'error') AND ($message != 'You may not submit another entry at this time.') ) {
            drupal_set_message($message, $type);
          }
        }
      }  
      break;
*/       
/*    case 'user/register':
      // Regular drupal_set_messages are hidden from anonymous users.
      // Users who are trying to register are anonymous.
      // Messages about data entry errors on the registration form still need to be displayed to these users.
      $container = '';
      $content = '';      
      foreach($messages as $type => $type_messages) {
        foreach ($type_messages as $message) {
          if ($type == 'error') {
            if( (substr($message, -12) == 'is required.') OR
                (substr($message, -18) == 'illegal character.') OR
                (substr($message, -13) == 'is not valid.')
            ) {
              if ($container == '') {
                $container = "<div id=\"messages\" class=\"grid-24\"><div class=\"messages error\">";
              }
              $content .= $message . "<br>";
            }
          }
        }
      }
      
      if ($content != '') {
        $vars['page']['content']['messages']['messages']['block_17']['#markup'] = $container . $content . "</div></div>";
      }
      break;
      
    case 'home':
    case 'user':    
      // Regular drupal_set_messages are hidden from anonymous users.
      // Users who are trying to register are anonymous.
      // Messages about further instructions were sent to your email box still need to be displayed to these users.
      $container_s = '';
      $container_e = '';      
      $content_s = '';
      $content_e = '';      
      foreach($messages as $type => $type_messages) {
        foreach ($type_messages as $message) {
          if ($type == 'status') {
            if (substr($message, -18) == 'set your password.') {
              if ($container_s == '') {
                $container_s = "<div id=\"messages\" class=\"grid-24\"><div class=\"messages status\">";
              }
              $content_s .= $message;
            }
          }
          if ($type == 'error') {
            if( (substr($message, 0, 7) == 'Sorry, ') OR
                (substr($message, -11) == 'is blocked.') OR
                (substr($message, -12) == 'is required.') OR
                (substr($message, -18) == 'illegal character.') OR
                (substr($message, -13) == 'is not valid.')
            ) {
              if ($container_e == '') {
                $container_e = "<div id=\"messages\" class=\"grid-24\"><div class=\"messages error\">";
              }
              $content_e .= $message . " ";
            }              
          }
        }
      }
      $markup = '';
      if ($content_s != '') {
        $markup = $container_s . $content_s;
      }
      if ($content_e != '') {
        $markup .= $container_e . $content_e;        
      }
      if ($markup != '') {
        $markup .= "</div></div>";
        $vars['page']['content']['messages']['messages']['block_17']['#markup'] = $markup;
      }
      break;
*/    
    default:
      foreach($messages as $type => $type_messages) {
        foreach ($type_messages as $message) {
          drupal_set_message($message, $type);
        }
      }  
      break;
    }  
  } 
}
