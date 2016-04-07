<?php

// source: http://drupal.stackexchange.com/a/76419/41582

//$vid = 27;
$tax=taxonomy_vocabulary_machine_name_load("VOCAB_NAME_HERE");
$vid = $tax->vid;

$tree = taxonomy_get_tree($vid);

if (count($tree) == 0) {
  print "Nothing to delete.\n";
}
else {
  $tree = array_slice($tree, 0, 1000);

  foreach ($tree as $term) {
    print 'Deleting tid ' . $term->tid . "\n";
    taxonomy_term_delete($term->tid);
  }
}

?>
