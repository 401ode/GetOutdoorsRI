<p>
  <a href="<?php print $governor_url; ?>" title="Governor <?php print $governor; ?> Official Website" class="gov">Governor<br>
  <?php print $governor; ?></a>
</p>
<p class="mogov">
  <a href="http://mo.gov/" title="Mo.gov | Official State of Missouri Website" class="state"><span class="hide">MO.gov State of Missouri</span></a>
</p>
<?php if ($agency_head): ?>
<p>
  <a href="<?php print $agency_url; ?>" title="<?php print $agency_name; ?> Website" class="agency"><?php print $agency_head_title; ?><br>
  <?php print $agency_head; ?></a>
</p>
<?php endif; ?>
