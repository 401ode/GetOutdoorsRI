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
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_mo_cms_postal_address']);
      hide($content['field_trail_activity']);
      hide($content['field_url']);
      print render($button);
    ?>
    <div class="clearfix"></div>
    <?php
      if (!empty($admin_link) and $admin_link) {
        print $admin_link;
      }
    ?>
    <div id="group-data" class="grid-14 alpha omega">
      <div class="grid-7 alpha omega">
        <?php print render($members); ?>
      </div>
      <div class="grid-7 alpha omega">
        <?php print render($miles); ?>
      </div>
      <div class="grid-7 alpha omega">
        <?php print render($content['field_mo_cms_postal_address']); ?>
      </div>
      <div class="grid-7 alpha omega">
        <?php print render($content['field_trail_activity']); ?>
      </div>
      <div class="clearfix"></div>
      <?php if (isset($umbrellas)): ?>
        <div class="grid-14 alpha omega">
          <?php print render($umbrellas); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="clearfix"></div>
    <?php
      print render($content['body']);
      print render($leaderboard);
      print render($user_board);
      print render($content['group_privacy']);
      print render($content);
    ?>
    <p>Please read our <a href="/content/privacy-policy#group-policy">disclaimer</a>.</p>
  </div>  
</article>