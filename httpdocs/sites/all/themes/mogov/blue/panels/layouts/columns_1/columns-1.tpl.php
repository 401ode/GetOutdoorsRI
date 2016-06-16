<?php
/**
 * @file
 * Template for the "1 Column" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-region columns-1-region--main-content">
    <?php print $content['column_1']; ?>
  </div>
</div>
