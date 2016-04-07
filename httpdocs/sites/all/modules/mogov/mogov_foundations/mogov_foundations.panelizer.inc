<?php
/**
 * @file
 * mogov_foundations.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function mogov_foundations_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:mogov_page_panelized:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'mogov_page_panelized';
  $panelizer->no_blocks = TRUE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'columns_2_b';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
      'sidebar' => NULL,
      'column_1' => NULL,
      'column_2' => NULL,
      'row1_col1' => NULL,
      'row2_col1' => NULL,
      'row2_col2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '73ed9a5e-d686-467e-894a-18e55a384afb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-064ee8ff-5790-4055-bd30-9a5965227dea';
    $pane->panel = 'column_1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_mogov_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '064ee8ff-5790-4055-bd30-9a5965227dea';
    $display->content['new-064ee8ff-5790-4055-bd30-9a5965227dea'] = $pane;
    $display->panels['column_1'][0] = 'new-064ee8ff-5790-4055-bd30-9a5965227dea';
    $pane = new stdClass();
    $pane->pid = 'new-48c352cc-8fa1-4d80-89df-aa34bffed71e';
    $pane->panel = 'column_2';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '48c352cc-8fa1-4d80-89df-aa34bffed71e';
    $display->content['new-48c352cc-8fa1-4d80-89df-aa34bffed71e'] = $pane;
    $display->panels['column_2'][0] = 'new-48c352cc-8fa1-4d80-89df-aa34bffed71e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:mogov_page_panelized:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:mogov_page_panelized:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'mogov_page_panelized';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'columns_2_b';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_content' => NULL,
      'sidebar' => NULL,
      'column_1' => NULL,
      'column_2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3af1c7f0-07b9-41d1-895b-ef8c05837714';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1f942b6f-cb68-4cdf-9d8d-f98812832bb8';
    $pane->panel = 'column_1';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1f942b6f-cb68-4cdf-9d8d-f98812832bb8';
    $display->content['new-1f942b6f-cb68-4cdf-9d8d-f98812832bb8'] = $pane;
    $display->panels['column_1'][0] = 'new-1f942b6f-cb68-4cdf-9d8d-f98812832bb8';
    $pane = new stdClass();
    $pane->pid = 'new-f9a5960f-ba0b-4a8d-b544-ccd30985416d';
    $pane->panel = 'column_2';
    $pane->type = 'block';
    $pane->subtype = 'block-2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f9a5960f-ba0b-4a8d-b544-ccd30985416d';
    $display->content['new-f9a5960f-ba0b-4a8d-b544-ccd30985416d'] = $pane;
    $display->panels['column_2'][0] = 'new-f9a5960f-ba0b-4a8d-b544-ccd30985416d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:mogov_page_panelized:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:page:default:full';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'page';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'full';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'mogov_blue_16_8_24';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top_left' => NULL,
      'top_right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '24d521e7-3564-464f-94d1-2fd6107c6a4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a4f425c2-5bb3-442d-b602-6792b6c2d080';
    $pane->panel = 'top_left';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a4f425c2-5bb3-442d-b602-6792b6c2d080';
    $display->content['new-a4f425c2-5bb3-442d-b602-6792b6c2d080'] = $pane;
    $display->panels['top_left'][0] = 'new-a4f425c2-5bb3-442d-b602-6792b6c2d080';
    $pane = new stdClass();
    $pane->pid = 'new-852422a1-1ed9-4712-a637-f8522661e55b';
    $pane->panel = 'top_left';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '852422a1-1ed9-4712-a637-f8522661e55b';
    $display->content['new-852422a1-1ed9-4712-a637-f8522661e55b'] = $pane;
    $display->panels['top_left'][1] = 'new-852422a1-1ed9-4712-a637-f8522661e55b';
    $pane = new stdClass();
    $pane->pid = 'new-95091494-a5a3-471e-93f4-883553fa767f';
    $pane->panel = 'top_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_mo_cms_node_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'colorbox',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
        'colorbox_gallery' => 'none',
        'colorbox_gallery_custom' => '',
        'colorbox_image_style' => 'large',
        'colorbox_multivalue_index' => NULL,
        'colorbox_node_style' => 'grid_8',
        'edit' => array(
          'editor' => 'form',
        ),
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '95091494-a5a3-471e-93f4-883553fa767f';
    $display->content['new-95091494-a5a3-471e-93f4-883553fa767f'] = $pane;
    $display->panels['top_left'][2] = 'new-95091494-a5a3-471e-93f4-883553fa767f';
    $pane = new stdClass();
    $pane->pid = 'new-fd42161d-6c37-47df-ae54-e74bd235915e';
    $pane->panel = 'top_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'edit' => array(
          'editor' => 'direct',
        ),
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'fd42161d-6c37-47df-ae54-e74bd235915e';
    $display->content['new-fd42161d-6c37-47df-ae54-e74bd235915e'] = $pane;
    $display->panels['top_left'][3] = 'new-fd42161d-6c37-47df-ae54-e74bd235915e';
    $pane = new stdClass();
    $pane->pid = 'new-f90bf2d0-bb45-44ce-af41-7a46f6400fe0';
    $pane->panel = 'top_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_mo_cms_editorial_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hidden',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f90bf2d0-bb45-44ce-af41-7a46f6400fe0';
    $display->content['new-f90bf2d0-bb45-44ce-af41-7a46f6400fe0'] = $pane;
    $display->panels['top_right'][0] = 'new-f90bf2d0-bb45-44ce-af41-7a46f6400fe0';
    $pane = new stdClass();
    $pane->pid = 'new-0b5d57d1-10bc-490e-81e4-a4b623e90d6d';
    $pane->panel = 'top_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0b5d57d1-10bc-490e-81e4-a4b623e90d6d';
    $display->content['new-0b5d57d1-10bc-490e-81e4-a4b623e90d6d'] = $pane;
    $display->panels['top_right'][1] = 'new-0b5d57d1-10bc-490e-81e4-a4b623e90d6d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-fd42161d-6c37-47df-ae54-e74bd235915e';
  $panelizer->display = $display;
  $export['node:page:default:full'] = $panelizer;

  return $export;
}
