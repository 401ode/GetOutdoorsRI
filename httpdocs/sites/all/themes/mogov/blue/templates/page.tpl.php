<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">
  <header class="l-zone l-header" role="banner">
    <div class="l-container">
      <div class="l-branding">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>  
        <?php if ($site_name || $site_slogan): ?>
          <?php if ($site_name): ?>
            <h1 class="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
            <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        <?php endif; ?>
        <?php print render($page['branding']); ?>
      </div>
      <div class="l-header-content">
        <?php print render($page['header_content_1']); ?>
        <?php print render($page['header_content_2']); ?>
      </div>
    </div>
  </header>
  
  <?php if ($page['premenu']): ?>
    <div class="l-zone l-menus l-premenu">
      <div class="l-container">
        <?php print render($page['premenu']); ?>
      </div>
    </div>
  <?php endif; ?>
  
  <?php if ($page['menu']): ?>
    <div class="l-zone l-menus l-main-menu">
      <div class="l-container">
        <?php print render($page['menu']); ?>
      </div>
    </div>
  <?php endif; ?>
  
  <?php if ($page['submenu']): ?>
    <div class="l-zone l-menus l-submenu">
      <div class="l-container">
        <?php print render($page['submenu']); ?>
      </div>
    </div>
  <?php endif; ?>
  
  <?php if ($page['alert']): ?>
    <div class="l-zone l-alerts">
      <div class="l-container">
        <?php print render($page['alert']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($page['warning']): ?>
    <div class="l-zone l-warnings">
      <div class="l-container">
        <?php print render($page['warning']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($page['advisory']): ?>
    <div class="l-zone l-advisories">
      <div class="l-container">
        <?php print render($page['advisory']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($page['notice']): ?>
    <div class="l-zone l-notices">
      <div class="l-container">
        <?php print render($page['notice']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php print render($page['help']); ?>

  <div class="l-zone l-main">
    <div class="l-container">
      <div class="l-content" role="main">
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title and !$hide_title): ?>
          <h1><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['content']); ?>
      </div>
      <?php print render($page['sidebar']); ?>
    </div>
  </div>

  <footer class="l-zone l-footer" role="contentinfo">
    <div class="l-container">
      <?php print render($page['footer']); ?>
    </div>
  </footer>
</div>

<?php print render($page['bottom']); ?>
