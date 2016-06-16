<?php
/**
 * @file
 * Template for the "Dashboard Main" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-container dashboard-main-col-1">
    <div class="l-region dashboard-main-region--col1">
      <?php print $content['col1']; ?>
    </div>
  </div>
  <div class="l-container dashboard-main-col-2">
    <div class="l-container dashboard-main-col-2-row-1">
      <div class="l-region dashboard-main-region--col2-row1-col1">
        <?php print $content['col2_row1_col1']; ?>
      </div>
    </div>
    <div class="l-container dashboard-main-col-2-row-2">
      <div class="l-region dashboard-main-region--col2-row2-col1">
        <?php print $content['col2_row2_col1']; ?>
      </div>
      <div class="l-region dashboard-main-region--col2-row2-col2">
        <?php print $content['col2_row2_col2']; ?>
      </div>
    </div>
  </div>
</div>
