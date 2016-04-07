<?php
/**
 * @file
 * Template for the "8 Panes A" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-container panes-8-a-row-1">
    <div class="panes-8-a-region--row1">
      <?php print $content['row1']; ?>
    </div>
  </div>
  <div class="l-container panes-8-a-row-2">
    <div class="panes-8-a-region--row2-col1">
      <?php print $content['row2_col1']; ?>
    </div>
    <div class="panes-8-a-region--row2-col2">
      <?php print $content['row2_col2']; ?>
    </div>
    <div class="panes-8-a-region--row2-col3">
      <?php print $content['row2_col3']; ?>
    </div>
  </div>
  <div class="l-container panes-8-a-row-3">
    <div class="panes-8-a-region--row3">
      <?php print $content['row3']; ?>
    </div>
  </div>
  <div class="l-container panes-8-a-row-4">
    <div class="panes-8-a-region--row4-col1">
      <?php print $content['row4_col1']; ?>
    </div>
    <div class="panes-8-a-region--row4-col2">
      <?php print $content['row4_col2']; ?>
    </div>
  </div>
  <div class="l-container panes-8-a-row-5">
    <div class="panes-8-a-region--row5">
      <?php print $content['row5']; ?>
    </div>
  </div>
</div>
