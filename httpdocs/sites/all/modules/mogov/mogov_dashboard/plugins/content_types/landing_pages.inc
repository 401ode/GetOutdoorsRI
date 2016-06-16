<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Landing pages'),
  'description' => t('List of panel pages available for editing.'),
  'category' => t('Dashboard'),
  'edit form' => 'mogov_dashboard_landing_pages_pane_edit_form',
  'render callback' => 'mogov_dashboard_landing_pages_pane_render',
  'admin info' => 'mogov_dashboard_landing_pages_pane_admin_info',
  'defaults' => array(
    'no_permissions_message' => 'You do not have the permissions necessary to edit landing pages.',
  ),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function mogov_dashboard_landing_pages_pane_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $defaults = $form_state['plugin']['defaults'];
  $default = $conf['no_permissions_message'] ? $conf['no_permissions_message'] : $defaults['no_permissions_message'];
  $form['no_permissions_message'] = array(
    '#type' => 'textarea',
    '#title' => t('"No permissions" message'),
    '#description' => t('This text will be displayed in the pane if the user doesn\'t have permission to use anything in it. If desired, you may enter a custom message here. For example, you may wish to include the name and email address of whomever should be contacted to make such changes.'),
    '#default_value' => $default,
  );

  return $form;
}
 
/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function mogov_dashboard_landing_pages_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    // Some items must not be empty, so if the field has been blanked, we'll populate it with the default
    switch($key) {
      case 'no_permissions_message':
        $form_state['conf'][$key] = $form_state['values'][$key] ? $form_state['values'][$key] : $form_state['plugin']['defaults']['no_permissions_message'];
        break;
      default:
        $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the pane
 * See ctools_plugin_examples for more advanced info
 */
function mogov_dashboard_landing_pages_pane_render($subtype, $conf, $args, $contexts) {
 
  if (!module_exists('page_manager')) {
    return FALSE;
  }
  $pane = new stdClass();
  $pane->title = t('Landing pages');
  if (!user_access('use page manager')) {
    $pane->content = mogov_dashboard_no_permissions($conf['no_permissions_message']);
  } else {
    $list = array(
      'type' => 'ul',
      'title' => NULL,
      'attributes' => array(
        'class' => array(
          'admin-list',
        ),
      ),
      'items' => array(),
    );
    $link_options = array(
      'attributes' => array(),
    );
    $page_names = mogov_dashboard_landing_pages_get_ids();
    foreach ($page_names as $page_name) {
      $page = page_manager_page_load($page_name);
      if ($page->type == 'Normal') {
        $view_path = $page->path;
        $edit_path = 'admin/structure/pages/edit/page-' . $page_name;
        $link_options['attributes']['title'] = $page->admin_title;
        $view_link = l($page->admin_title, $view_path, $link_options);
        $edit_link = l('edit', $edit_path, $link_options);
        $list['items'][] = t($view_link . '<span class="edit-link">' . $edit_link . '</span>');
      }
    }
    if ($list['items']) {
      $pane->content = theme_item_list($list);
    } else {
      $pane->content = t('No landing pages have been created.');
    }
  }
  return $pane;
}

/**
 * 'admin info' callback for panel pane.
 */
function mogov_dashboard_landing_pages_pane_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $pane = new stdClass;
    $pane->title = $conf['override_title'] ? $conf['override_title_text'] : t('Landing pages');
    $pane->content = '';
    return $pane;
  }
}

/**
 * Gets a list of page manager ids
 */
function mogov_dashboard_landing_pages_get_ids() {
  $query = db_select('page_manager_pages', 'p');
  $query->condition('p.task', 'page');
  $query->addField('p', 'name');
  $query->orderBy('p.admin_title', 'ASC');
  $result = $query->execute();
  $ids = array();
  foreach ($result as $row) {
    $ids[] = $row->name;
  }
  return $ids;
}