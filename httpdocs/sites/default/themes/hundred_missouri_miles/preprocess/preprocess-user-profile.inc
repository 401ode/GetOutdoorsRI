<?php

function hundred_missouri_miles_alpha_preprocess_user_profile(&$vars) {
//drupal_set_message('<pre>' . print_r($vars, TRUE) . '</pre>');

  // Get fields to display
  $account = menu_get_object('user');
  $user_email = $account->mail;
  $user_uname = $account->name;
  $user_twitter = '';
  
  if (!empty($account->field_user_twitter_handle)) {
    $lang = $account->language;
    if ($lang == NULL) {$lang = 'und';}
    $user_twitter = $account->field_user_twitter_handle[$lang][0]['value'];
  }
  if ($user_twitter == '') {
    $user_twitter = '<a href="/user/' . $account->uid . '/edit">Share</a> your twitter handle with GoRI!';
  }
  if (!empty($account->field_user_campus_name)) {
    $lang = $account->language;
    if ($lang == NULL) {$lang = 'und';}
    $user_campus = $account->field_user_campus_name[$lang][0]['entity']->title;
    
    // Add campus field
    $vars['user_profile']['field_user_campus_name'] = Array (
        '#theme' => 'field',
        '#weight' => 10,
        '#title' => 'I am currently enrolled or employed at',
        '#access' => 1,
        '#label_display' => 'above',
        '#view_mode' => 'full',
        '#language' => 'und',
        '#field_name' => 'field_user_campus_name',
        '#field_type' => 'text',
        '#field_translatable' => 0,
        '#entity_type' => 'user',
        '#bundle' => 'user',    
        '#object' => $account,     
        '#items' => Array(),
        '#formatter' => 'text_default',
        '#type' => 'user_profile_item',
    );

    $vars['user_profile']['field_user_campus_name']['#items'][0] = Array (
        'value' => $user_campus,
    );

    $vars['user_profile']['field_user_campus_name'][0] = Array (
        '#markup' => $user_campus,
    );
    $vars['elements']['#groups']['group_activity_info_item']->children[] = 'field_user_campus_name';
    $vars['elements']['#group_children']['field_user_campus_name'] = 'group_activity_info_item';    
  }

  // Add username field
  $vars['user_profile']['field_user_uname'] = Array (
      '#theme' => 'field',
      '#weight' => 1,
      '#title' => 'Username',
      '#access' => 1,
      '#label_display' => 'inline',
      '#view_mode' => 'full',
      '#language' => 'und',
      '#field_name' => 'field_user_uname',
      '#field_type' => 'text',
      '#field_translatable' => 0,
      '#entity_type' => 'user',
      '#bundle' => 'user',
      '#object' => $account,    
      '#items' => Array(),
      '#formatter' => 'text_default',
  );

  $vars['user_profile']['field_user_uname']['#items'][0] = Array (
      'value' => $user_uname,
  );

  $vars['user_profile']['field_user_uname'][0] = Array (
      '#markup' => $user_uname,
  );

  // Add user email field
  $vars['user_profile']['field_user_mail'] = Array (
      '#theme' => 'field',
      '#weight' => 2,
      '#title' => 'E-mail',
      '#access' => 1,
      '#label_display' => 'inline',
      '#view_mode' => 'full',
      '#language' => 'und',
      '#field_name' => 'field_user_mail',
      '#field_type' => 'text',
      '#field_translatable' => 0,
      '#entity_type' => 'user',
      '#bundle' => 'user',    
      '#object' => $account,     
      '#items' => Array(),
      '#formatter' => 'text_default',
      '#type' => 'user_profile_item',
  );

  $vars['user_profile']['field_user_mail']['#items'][0] = Array (
      'value' => $user_email,
  );

  $vars['user_profile']['field_user_mail'][0] = Array (
      '#markup' => $user_email,
  );
  
  // Add twitter handle field
  $vars['user_profile']['field_user_twitter_handle'] = Array (
      '#theme' => 'field',
      '#weight' => 3,
      '#title' => 'My twitter',
      '#access' => 1,
      '#label_display' => 'inline',
      '#view_mode' => 'full',
      '#language' => 'und',
      '#field_name' => 'field_user_twitter_handle',
      '#field_type' => 'text',
      '#field_translatable' => 0,
      '#entity_type' => 'user',
      '#bundle' => 'user',    
      '#object' => $account,     
      '#items' => Array(),
      '#formatter' => 'text_default',
      '#type' => 'user_profile_item',
  );

  $vars['user_profile']['field_user_twitter_handle']['#items'][0] = Array (
      'value' => $user_twitter,
  );

  $vars['user_profile']['field_user_twitter_handle'][0] = Array (
      '#markup' => $user_twitter,
  );
  $vars['elements']['#groups']['group_personal_information_item']->children[] = 'field_user_twitter_handle';
  $vars['elements']['#group_children']['field_user_twitter_handle'] = 'group_personal_information_item';
  
  // Add Request new password link
  $vars['user_profile']['field_user_pwd_link'] = Array (
    '#type' => 'link',
    '#weight' => 3,
    '#title' => t('Request new password'),
    '#href' => 'user/password',
  );

  // Populate the group_children arrays
  if ( (array_key_exists(0, $vars['elements']['#groups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#groups']['group_account_info_item']->children[0] != 'field_user_uname') 
  ) {
    $vars['elements']['#groups']['group_account_info_item']->children[] = 'field_user_uname';
  }
  if ( (array_key_exists(1, $vars['elements']['#groups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#groups']['group_account_info_item']->children[1] != 'field_user_mail') 
  ) {
    $vars['elements']['#groups']['group_account_info_item']->children[] = 'field_user_mail';
  }
  if ( (array_key_exists(2, $vars['elements']['#groups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#groups']['group_account_info_item']->children[2] != 'field_user_pwd_link') 
  ) {
    $vars['elements']['#groups']['group_account_info_item']->children[] = 'field_user_pwd_link';
  }

  if ( (array_key_exists(0, $vars['elements']['#fieldgroups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#fieldgroups']['group_account_info_item']->children[0] != 'field_user_uname') 
  ) {
    $vars['elements']['#fieldgroups']['group_account_info_item']->children[] = 'field_user_uname';
  }
  if ( (array_key_exists(1, $vars['elements']['#fieldgroups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#fieldgroups']['group_account_info_item']->children[1] != 'field_user_mail') 
  ) {
    $vars['elements']['#fieldgroups']['group_account_info_item']->children[] = 'field_user_mail';
  }
  if ( (array_key_exists(2, $vars['elements']['#fieldgroups']['group_account_info_item']->children)) 
    AND ($vars['elements']['#fieldgroups']['group_account_info_item']->children[2] != 'field_user_pwd_link') 
  ) {
    $vars['elements']['#fieldgroups']['group_account_info_item']->children[] = 'field_user_pwd_link';
  }

  $vars['elements']['#group_children']['field_user_uname'] = 'group_account_info_item';
  $vars['elements']['#group_children']['field_user_mail'] = 'group_account_info_item';
  $vars['elements']['#group_children']['field_user_pwd_link'] = 'group_account_info_item';


  // Activity Information
  if (!empty($vars['user_profile']['field_user_reasons']['#title'])) {
    $new_title = $vars['user_profile']['field_user_reasons']['#title'];
    $vars['user_profile']['field_user_reasons']['#title'] = substr($new_title, 0, -1);
  }
  if (!empty($vars['user_profile']['field_user_exercise']['#title'])) {
    $vars['user_profile']['field_user_exercise']['#title'] = 'I exercise approximately';
    $vars['user_profile']['field_user_exercise']['0']['#suffix'] = ' per week';
  }

  
  // Communication Preferences
  // Plaintext or HTML Email
  $vars['user_profile']['mimemail']['#title'] = NULL;
  $plaintext = $vars['user_profile']['mimemail']['textonly']['#markup'];
  if($plaintext == 'No') {
    $vars['user_profile']['mimemail']['textonly']['#title'] = t('HTML email');
    $vars['user_profile']['mimemail']['textonly']['#markup'] = t('I prefer to receive email with graphics and styles');
  } else {
    $vars['user_profile']['mimemail']['textonly']['#markup'] = t('I do not wish to receive email with graphics and styles');
  }

  // 100 Missouri Mile Challenge updates and information
  $notification1 = $vars['user_profile']['field_user_email_notification']['0']['#markup'];
  if($notification1 == 'Yes') {
    $vars['user_profile']['field_user_email_notification']['0']['#markup'] = $vars['user_profile']['field_user_email_notification']['#title'];
  } else {
    $vars['user_profile']['field_user_email_notification']['0']['#markup'] = str_replace('I wish', 'I do not wish', $vars['user_profile']['field_user_email_notification']['#title']);
  }
  $vars['user_profile']['field_user_email_notification']['#title'] = $notification1;
  
  // Miscellaneous
  if (array_key_exists('field_send_group_instructions', $vars['user_profile'])) {
    $new_title = $vars['user_profile']['field_send_group_instructions']['#title'];
    
    if ($vars['user_profile']['field_send_group_instructions']['#items']['0']['value'] == 1) {
      $vars['user_profile']['field_send_group_instructions']['#title'] = 'Yes';
      $vars['user_profile']['field_send_group_instructions']['0']['#markup'] = substr($new_title, 0, -1);
    } else {
      $vars['user_profile']['field_send_group_instructions']['#title'] = 'No';
      $new_title = substr($new_title, 0, -1);
      $vars['user_profile']['field_send_group_instructions']['0']['#markup'] = str_replace('would be', 'am not', $new_title);
    }
  }
  
  // Mileage
  $total_mileage = number_format(mo_project_get_total_mileage(array($account->uid), array(), 'all'), 2);
  $total_mileage_nodes = count(mo_project_get_mileage_nids($account->uid));
  
  if ($total_mileage_nodes > 0) {
    $average_mileage_per_node = number_format($total_mileage / $total_mileage_nodes, 2);
  } else {
    $average_mileage_per_node = 0;
  }
  $vars['user_profile']['field_user_mileage_total'] = array (
    '#theme' => 'field',
    '#weight' => 10,
    '#title' => 'Total mileage',
    '#access' => 1,
    '#label_display' => 'inline',
    '#view_mode' => 'full',
    '#language' => 'und',
    '#field_name' => 'field_user_mileage_total',
    '#field_type' => 'text',
    '#field_translatable' => 0,
    '#entity_type' => 'user',
    '#bundle' => 'user',    
    '#object' => $account,     
    '#items' => array(
      0 => array(
        'value' => $total_mileage,
      ),
    ),
    0 => array (
      '#markup' => $total_mileage,
    ),
    '#formatter' => 'text_default',
    '#type' => 'user_profile_item',
  );
  $vars['elements']['#groups']['group_personal_information_item']->children[] = 'field_user_mileage_total';
  $vars['elements']['#group_children']['field_user_mileage_total'] = 'group_personal_information_item';
  $vars['user_profile']['field_user_mileage_avg'] = array (
    '#theme' => 'field',
    '#weight' => 11,
    '#title' => 'Avg mi/entry',
    '#access' => 1,
    '#label_display' => 'inline',
    '#view_mode' => 'full',
    '#language' => 'und',
    '#field_name' => 'field_user_mileage_avg',
    '#field_type' => 'text',
    '#field_translatable' => 0,
    '#entity_type' => 'user',
    '#bundle' => 'user',    
    '#object' => $account,     
    '#items' => array(
      0 => array(
        'value' => $average_mileage_per_node,
      ),
    ),      
    0 => array (
      '#markup' => $average_mileage_per_node,
    ),
    '#formatter' => 'text_default',
    '#type' => 'user_profile_item',
  );
  $vars['elements']['#groups']['group_personal_information_item']->children[] = 'field_user_mileage_avg';
  $vars['elements']['#group_children']['field_user_mileage_avg'] = 'group_personal_information_item';
  
  
  // Badges
  $vars['elements']['#groups']['group_personal_information']->children[] = 'group_badge_info_item';
  $vars['elements']['#group_children']['group_badge_info_item'] = 'group_personal_information';

  $item = new stdClass ();
    $item->identifier = 'group_badge_info_item|user|user|default';
    $item->group_name = 'group_badge_info_item';
    $item->entity_type = 'user';
    $item->bundle = 'user';
    $item->mode = 'default';
    $item->parent_name = 'group_personal_information';
    $item->table = 'field_group';
    $item->type = 'Normal';
    $item->export_type = 1;
    $item->disabled = FALSE;
    $item->label = 'Badges';
    $item->weight = 15;
    $item->children = Array();
    $item->format_type = 'accordion-item';
    $item->format_settings = Array(
        'label' => 'Badges',
        'instance_settings' => Array(
          'classes' => '',
        ),
        'formatter' => 'closed',
    );

  $vars['elements']['#groups']['group_badge_info_item'] = $item;
  $vars['elements']['#fieldgroups']['group_badge_info_item'] = $item;

  $vars['user_profile']['field_user_badge_list'] = array (
    '#theme' => 'field',
    '#weight' => 11,
    '#title' => 'Badges earned',
    '#access' => 1,
    '#label_display' => 'above',
    '#view_mode' => 'full',
    '#language' => 'und',
    '#field_name' => 'field_user_badge_list',
    '#field_type' => 'text',
    '#field_translatable' => 0,
    '#entity_type' => 'user',
    '#bundle' => 'user',    
    '#object' => $account,     
    '#items' => array(
      0 => array(
        'value' => mo_project_build_profile_badge_accordian(),
      ),
    ),
    0 => array (
      '#markup' => mo_project_build_profile_badge_accordian(),
    ),
    '#formatter' => 'text_default',
    '#type' => 'user_profile_item',
  );

  $vars['elements']['#fieldgroups']['group_badge_info_item']->children[] = 'field_user_badge_list';
  $vars['elements']['#group_children']['field_user_badge_list'] = 'group_badge_info_item';

  // Tab Order
  $vars['elements']['#groups']['group_tab_main']->weight = -6;
  $vars['elements']['#groups']['group_account_info_item']->weight = -5;
  $vars['elements']['#groups']['group_personal_information_item']->weight = -4;
  $vars['elements']['#groups']['group_activity_info_item']->weight = -3;
  $vars['elements']['#groups']['group_tab_communication']->weight = -2;
  $vars['elements']['#groups']['group_badge_info_item']->weight = -1;

  // Add Recheck All Badges button
  if (!empty($account->field_user_first_name)) {
    $lang = $account->language;
    if ($lang == NULL) {$lang = 'und';}
    $user_first = ucwords(strtolower($account->field_user_first_name[$lang][0]['value']));
  } else {
    $user_first = 'This';
  }
  if (!empty($account->field_user_last_name)) {
    $lang = $account->language;
    if ($lang == NULL) {$lang = 'und';}
    $user_last = ucwords(strtolower($account->field_user_last_name[$lang][0]['value']));
  } else {
    $user_last = 'User';
  }
  
  $vars['elements']['badge_recheck'] = array (
    '#title' => 'Re-check badges',
    '#type' => 'item',
    '#markup' => '<a href="/admin/badge_recheck/' . $account->uid . '" class="btn">Re-check ALL badges for ' . $user_first . ' ' . $user_last . '</a>',
  );
  $vars['user_profile']['badge_recheck'] = array (
    '#type' => 'item',
    '#markup' => '<a href="/admin/badge_recheck/' . $account->uid . '" class="btn" style="float:right;margin:5px 0 0 5px;">Re-check ALL badges for ' . $user_first . ' ' . $user_last . '</a>',
  );

  unset($vars['user_profile']['login_one_time']['#title']);
  
  
/*  [field_send_group_instructions][#title] => I would be interested in starting a fitness group for my coworkers/friends.
    [#items] => Array (
        [0] => Array (
            [value] => 1
        )
    )
    [#formatter] => list_default
    [0] => Array (
            [#markup] => 
    )
*/
}
