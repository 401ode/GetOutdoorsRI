<?php
/**
 * @file
 * mogov_foundations.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function mogov_foundations_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<style> <section> <nav> <article> <aside> <h1> <h2> <h3> <h4> <h5> <h6>	<header> <footer> <address> <main> <p> <hr> <pre> <blockquote> <ol> <ul> <li> <dl> <dt> <dd> <figure> <figcaption> <div> <a> <em> <strong> <small> <s> <cite> <q> <dfn> <abbr> <data> <time> <code> <var> <samp> <kbd> <sub> <sup> <i> <b> <u> <mark> <ruby> <rt> <rp> <bdi> <bdo> <span> <br> <wbr> <ins> <del> <img> <map> <area> <svg> <math> <canvas> <video> <audio> <source> <track> <table> <caption> <colgroup> <col> <tbody> <thead> <tfoot> <tr> <td> <th> <output> <progress> <meter> <details> <summary> <menuitem> <menu>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'picture' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'picture' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
