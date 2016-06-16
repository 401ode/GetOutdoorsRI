<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
 $activity_v = taxonomy_vocabulary_machine_name_load('activities');
 $activity_tree = taxonomy_get_tree($activity_v->vid, 0, 1);
 $valid_tids = array();
 foreach ($activity_tree as $term) {
   $valid_tids[] = $term->tid;
 }
 $node = $row->_field_data['nid']['entity'];
 $field = field_get_items('node', $node, 'field_trail_activity');
 $tids = array();
 if (!empty($field)) {
   foreach ($field as $field_item) {
     if (!empty($field_item['tid'])) {
       $tids[] = $field_item['tid'];
     }
   }
 }
 $terms = entity_load('taxonomy_term', $tids);
 if (!empty($terms)) {
   $activities = array(
     'type' => 'ul',
     'title' => NULL,
     'attributes' => array(
       'class' => array(
         'activity-icons',
       ),
     ),
     'items' => array(),
   );
   foreach ($terms as $tid=>$term) {
     if (!in_array($tid, $valid_tids)) {
       continue;
     }
     $activities['items'][] = array(
       'data' => t($term->name),
       'class' => array(
         'activity-icon',
         drupal_clean_css_identifier(strtolower($term->name)),
         'ir',
       ),
     );
   }
   $output = theme_item_list($activities);
 }
?>
<?php print $output; ?>
