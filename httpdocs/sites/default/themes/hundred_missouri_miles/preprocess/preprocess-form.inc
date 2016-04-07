<?php
/**
* Implements hook_form_FORM_ID_alter().
*/
function hundred_missouri_miles_alpha_preprocess_form_user_login_block_alter(&$form) {
  // Remove the links provided by Drupal.
  unset($form['links']);

  // Set a weight for form actions so other elements can be placed
  // beneath them.
  $form['actions']['#weight'] = 5;

  // Shorter, inline request new password link.
  $form['actions']['request_password'] = array(
    '#markup' => l(t('Lost password'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.')))),
  );  

  // New sign up link, with 'cuter' text.
  if (variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL)) {
    $form['signup'] = array(
      '#markup' => l(t('Register - it’s free!'), 'user/register', array('attributes' => array('class' => 'button', 'id' => 'create-new-account', 'title' => t('Create a new user account.')))),
      '#weight' => 10, 
    );  
  }
}
?>