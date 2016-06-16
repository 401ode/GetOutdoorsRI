<?php
/**
 * @file
 * mo_cms.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function mo_cms_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-editor-resources.
  $menus['menu-editor-resources'] = array(
    'menu_name' => 'menu-editor-resources',
    'title' => 'Editor Resources',
    'description' => 'Links to resource material for content editors.',
  );
  // Exported menu: menu-menu-site-info.
  $menus['menu-menu-site-info'] = array(
    'menu_name' => 'menu-menu-site-info',
    'title' => 'Site Info',
    'description' => 'Standard set of links that appear in the page footer. Only the main-level links will be displayed; do not nest links in this menu.',
  );
  // Exported menu: menu-mo-cms-utility-bar.
  $menus['menu-mo-cms-utility-bar'] = array(
    'menu_name' => 'menu-mo-cms-utility-bar',
    'title' => 'Utility Bar',
    'description' => 'Standard set of links that appears in the utility bar at the top of the page. Only the main-level links will be displayed; do not nest links in this menu.',
  );
  // Exported menu: menu-social-links.
  $menus['menu-social-links'] = array(
    'menu_name' => 'menu-social-links',
    'title' => 'Social Links',
    'description' => 'Add/edit/remove links to social media accounts as desired. This menu will typically be rendered as icons.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add/edit/remove links to social media accounts as desired. This menu will typically be rendered as icons.');
  t('Editor Resources');
  t('Links to resource material for content editors.');
  t('Site Info');
  t('Social Links');
  t('Standard set of links that appear in the page footer. Only the main-level links will be displayed; do not nest links in this menu.');
  t('Standard set of links that appears in the utility bar at the top of the page. Only the main-level links will be displayed; do not nest links in this menu.');
  t('Utility Bar');


  return $menus;
}
