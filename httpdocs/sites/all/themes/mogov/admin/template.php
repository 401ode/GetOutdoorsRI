<?php

/*function admin_form_alter(&$form, &$form_state, $form_id) {
  foreach ($form as $key=>$item) {
    if (is_array($item) and !empty($item['#attributes']['class']) and in_array('field-type-field-collection', $item['#attributes']['class'])) {
      $title = '<span class="field-collection-main-title">' . $item['und'][0]['#title'] . '</span>';
      $form[$key]['und'][0]['#title'] = t($title);
    }
  }
}
*/