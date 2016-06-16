<?php
/**
 * @file
 * Template for the "2 Cols B" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-container columns-2-b">
    <div class="l-region columns-2-b-region--column-1">
      <?php print $content['column_1']; ?>
    </div>
    <div class="l-region columns-2-b-region--column-2">
      <?php print $content['column_2']; ?>
    </div>
  </div>
</div>
