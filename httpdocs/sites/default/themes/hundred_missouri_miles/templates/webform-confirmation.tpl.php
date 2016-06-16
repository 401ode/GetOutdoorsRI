<?php

/**
 * @file
 * Customize confirmation screen after successful submission.
 *
 * This file may be renamed "webform-confirmation-[nid].tpl.php" to target a
 * specific webform e-mail on your site. Or you can leave it
 * "webform-confirmation.tpl.php" to affect all webform confirmations on your
 * site.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $confirmation_message: The confirmation message input by the webform author.
 * - $sid: The unique submission ID of this submission.
 */
?>

<div class="webform-confirmation">
  <?php if ($confirmation_message): ?>
    <?php print $confirmation_message ?>
  <?php else: ?>
    <p><?php print t('Thank you, your submission has been received.'); ?></p>
  <?php endif; ?>
</div>
<div class="redirect-timer">
</div>

<div class="links">
  <a href="<?php print url('node/'. $node->nid) ?>"><?php print t('Go back to the form') ?></a>
</div>

<script type="text/javascript">
  jQuery(document).ready(function($) {
    var delay = 5;
    var url = "http://100missourimiles.com/<?php print drupal_get_path_alias('node/' . $node->nid); ?>";
    function countdown() {
      setTimeout(countdown, 1000);
      $('.redirect-timer').html("Redirecting in "  + delay  + " seconds.");
      delay --;
      if (delay < 0 ) {
        window.location = url;
        delay = 0;
      }
    }
    countdown() ;
  });
</script>
