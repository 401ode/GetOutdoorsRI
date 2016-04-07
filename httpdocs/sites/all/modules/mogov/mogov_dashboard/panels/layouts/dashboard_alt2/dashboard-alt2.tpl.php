<?php
/**
 * @file
 * Template for the "Dashboard Alt 2" layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div<?php print $attributes ?>>
  <div class="l-container dashboard-alt2-col-1">
    <div class="l-region dashboard-alt2-region--col1">
      <?php print $content['col1']; ?>
    </div>
  </div>
  <div class="l-container dashboard-alt2-col-2">
    <div class="l-container dashboard-alt2-col-2-row-1">
      <div class="l-region dashboard-alt2-region--col2-row1-col1">
        <?php print $content['col2_row1_col1']; ?>
      </div>
      <div class="l-region dashboard-alt2-region--col2-row1-col2">
        <?php print $content['col2_row1_col2']; ?>
      </div>
    </div>
    <div class="l-container dashboard-alt2-col-2-row-2">
      <div class="l-region dashboard-alt2-region--col2-row2-col1">
        <?php print $content['col2_row2_col1']; ?>
      </div>
      <div class="l-region dashboard-alt2-region--col2-row2-col2">
        <?php print $content['col2_row2_col2']; ?>
      </div>
    </div>
    <div class="l-container dashboard-alt2-col-2-row-3">
      <div class="l-region dashboard-alt2-region--col2-row3-col1">
        <?php print $content['col2_row3_col1']; ?>
      </div>
      <div class="l-region dashboard-alt2-region--col2-row3-col2">
        <?php print $content['col2_row3_col2']; ?>
      </div>
    </div>
  </div>
</div>
