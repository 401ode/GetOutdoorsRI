<?php

/**
 * Page callback to show links to add an entity of a specific bundle.
 *
 * Entity modules that provide a further description to their bundles may wish
 * to implement their own version of this to show these.
 *
 * @param $entity_type
 *   The type of the entity.
 */
function mogov_sliders_bundle_add_page($entity_type) {

  // Set the title, as we're a MENU_LOCAL_ACTION and hence just get tab titles.
  module_load_include('inc', 'entity', 'includes/entity.ui');
  drupal_set_title(entity_ui_get_action_title('add', $entity_type));

  // Get entity info for our bundles.
  $info = entity_get_info($entity_type);
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
  foreach ($info['bundles'] as $bundle_name => $bundle_info) {
    // Create an empty entity with just the bundle set to check for access.
    $dummy_entity = entity_create($entity_type, array(
      $info['entity keys']['bundle'] => $bundle_name,
    ));
    // If modules use a uid, they can default to the current-user
    // in their create() method on the storage controller.
    if (entity_access('create', $entity_type, $dummy_entity, $account = NULL)) {
      $add_path = $info['admin ui']['path'] . '/add/' . $bundle_name;
      $list['items'][] = l(t('Add @label', array('@label' => $bundle_info['label'])), $add_path);
    }
  }
  return theme_item_list($list);
}
