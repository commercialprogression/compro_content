<?php
/**
 * @file
 * compro_content.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function compro_content_filter_default_formats() {
  $formats = array();

  // Exported format: Passthrough.
  $formats['passthrough'] = array(
    'format' => 'passthrough',
    'name' => 'Passthrough',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
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

  // Exported format: Standard.
  $formats['standard'] = array(
    'format' => 'standard',
    'name' => 'Standard',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <br> <del> <em> <hr> <ins> <li> <mark> <noscript> <ol> <p> <q> <strong> <sub> <sup> <ul>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
