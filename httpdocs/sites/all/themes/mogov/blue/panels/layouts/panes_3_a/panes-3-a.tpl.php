<?php
/**
 * @file
 * Template for the "3 Pane A" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-container panes-3-a-row-1">
    <div class="l-region panes-3-a-region--row1-col1">
      <?php print $content['row1_col1']; ?>
    </div>
  </div>
  <div class="l-container panes-3-a-row-2">
    <div class="l-region panes-3-a-region--row2-col1">
      <?php print $content['row2_col1']; ?>
    </div>
    <div class="l-region panes-3-a-region--row2-col2">
      <?php print $content['row2_col2']; ?>
    </div>
  </div>
</div>
