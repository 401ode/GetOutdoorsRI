<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['body']);
      hide($content['field_mo_cms_user_groups_memgrps']);
      hide($content['comments']);
      hide($content['links']);
    ?>
    <div class="clearfix"></div>
    <div class="clearfix"></div>
    <?php
      print render($content['body']);
      print render($total_mileage_leaderboard);
      print render($average_mileage_leaderboard);
      print render($content);
    ?>
  </div>  
</article>