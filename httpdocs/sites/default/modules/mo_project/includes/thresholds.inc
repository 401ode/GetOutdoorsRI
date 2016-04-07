<?php
/**
 *  @file thresholds.inc
 *  @brief  Functions for Mileage Threshold Emails
 *
 *  @details
 *  mo_project_get_threshold_email_nids = Get node ids for threshold emails
 *  mo_project_total_mileage_threshold_alert_mail = Create the email to send to site admins when the all time total mileage threshold is exceeded
 *  mo_project_total_mileage_threshold_alert = Send the email to send to site admins when the all time total mileage threshold is exceeded
 *  mo_project_mileage_threshold_notification_mail = Create the email to send to users upon reaching a mileage threshold
 *  mo_project_send_new_notifications = Send the email to send to users upon reaching a mileage threshold
 *  
 */
 
/**
 *  @brief  Get node ids for threshold emails
 *  
 *  @return  array of threshold distances and nids
 *  
 *  @details  2013
 */
function mo_project_get_threshold_email_nids() {
  $query = db_select('node', 'n');
  $query->join('field_data_field_achievement_threshold', 'm', 'n.nid = m.entity_id AND (m.entity_type = :type AND m.deleted = :deleted)', array(':type' => 'node', ':deleted' => 0));
  $query->addField('n', 'nid');
  $query->addField('m', 'field_achievement_threshold_value', 'threshold');
  $query->condition('n.type', 'mileage_threshold_email');
  $query->condition('n.status', 0, '<>');
  $result = $query->execute();
  $nids = array();
  foreach ($result as $row) {
    $nids[$row->threshold] = $row->nid;
  }
  return $nids;
}


/**
 *  @brief Create the email to send to site admins when the all time total mileage threshold is exceeded
 *  
 *  @param [in] $key     The type of email to send
 *  @param [in] $message The message array
 *  @param [in] $params  The variables to insert into the message
 *  @return  void
 *  
 *  @details  2013
 */
function mo_project_total_mileage_threshold_alert_mail($key, &$message, $params) {
  $language = $message['language'];
  switch($key) {
    //switching on $key lets you create variations of the email based on the $key parameter
    case 'threshold_alert':
      $message['subject'] = t('ALERT 100momiles exceeded current mileage threshold');
      $message['body'][] = t('Users on 100missourimiles.com have logged more than @threshold miles. If this is unexpected, you should immediately check the site for spam mileage entries.', array('@threshold' => $params['threshold']));
      break;
  }
}


/**
 *  @brief  Send the email to send to site admins when the all time total mileage threshold is exceeded
 *  
 *  @return  Boolean. FALSE if failed to send
 *  
 *  @details  2013
 */
function mo_project_total_mileage_threshold_alert() {
  $to = 'emailaddress1@mail.com, emailaddress2@mail.com';
  $params = array(
      'threshold' => variable_get_value('total_mileage_threshold'),
  ); 
  $from = 'emailaddress@mail.com';
  $sent = drupal_mail('mo_project_total_mileage_threshold_alert', 'threshold_alert', $to, language_default(), $params, $from, TRUE);
  return $sent;
}


/**
 *  @brief Create the email to send to users upon reaching a mileage threshold
 *  
 *  @param [in] $key     The type of email to send
 *  @param [in] $message The message array
 *  @param [in] $params  The variables to insert into the message
 *  @return  void
 *  
 *  @details  2013
 */
function mo_project_mileage_threshold_notification_mail($key, &$message, $params) {
  $message['subject'] = t($params['subject']['value'], array());
  $message['body'][] = t($params['html_body']['value']);
}


/**
 *  @brief  Send the email to send to users upon reaching a mileage threshold
 *  
 *  @param [in] $node  Mileage node entity
 *  @return  void (FALSE on failure)
 *  
 *  @details  2013
 */
if (!function_exists('mo_project_send_new_notifications')) {
  function mo_project_send_new_notifications($node) {
    
    $user = user_load($node->uid);
    $user_changed = FALSE;
    $email_notifications_field = field_get_items('user', $user, 'field_user_email_notification');
    if (empty($email_notifications_field[0]['value']) or !$email_notifications_field[0]['value']) {
      return FALSE;
    }
    $threshold_mail_nids = mo_project_get_threshold_email_nids();
    $thresholds = array_keys($threshold_mail_nids);
    sort($thresholds);
    $user_mileage = mo_project_get_total_mileage(array($user->uid));
    $sent_notifications_field = field_get_items('user', $user, 'field_user_sent_notifications');
    // Check to see if current mileage is lower than a threshold for an email already
    // sent. If so, remove it from the list. Possible to happen if user mis-entered
    // miles and later revised.
    $last_notification_sent = FALSE;
    if (!empty($sent_notifications_field[0]['value'])) {
      foreach ($sent_notifications_field as $key=>$instance) {
        if ($instance['value'] == end($thresholds)) {
          $last_notification_sent = TRUE;
          break;
        }
        if ($user_mileage < $instance['value'] or !in_array($instance['value'], $thresholds)) {
          unset($sent_notifications_field[$key]);
          $user_changed = TRUE;
        } else {
          unset($threshold_mail_nids[$instance['value']]);
        }
      }
    }
    if ($last_notification_sent and $user_mileage >= end($thresholds)) {
      return FALSE;
    }
    foreach (array_keys($threshold_mail_nids) as $threshold) {
      if ($user_mileage < $threshold) {
        unset($threshold_mail_nids[$threshold]);
      }
    }
    foreach ($threshold_mail_nids as $threshold=>$nid) {
      $threshold_node = node_load($nid);
      $to = $user->mail;
      $from = 'emailaddress@mail.com';
      $params = array(
        'subject' => array(
          'field' => 'field_threshold_email_subject',
          'value' => NULL,
        ),
        'html_body' => array(
          'field' => 'body',
          'value' => NULL,
        ),
      );
      foreach (array_keys($params) as $key) {
        $field = field_get_items('node', $threshold_node, $params[$key]['field']);
        if (!empty($field[0]['value'])) {
          $params[$key]['value'] = t($field[0]['value']);
        } else {
          return FALSE;
        }
      }
      $sent = drupal_mail('mo_project_mileage_threshold_notification', 'threshold', $to, language_default(), $params, $from, TRUE);
      $sent_notifications_field[]['value'] = $threshold;
      $user_changed = TRUE;
    }
    if ($user_changed) {
      $edit = array(
        'field_user_sent_notifications' => array(
          'und' => array_values($sent_notifications_field),
        ),
      );
      user_save($user, $edit);
    }
  }
}
