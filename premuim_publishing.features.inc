<?php
/**
 * @file
 * premuim_publishing.features.inc
 */

/**
 * Implements hook_views_api().
 */
function premuim_publishing_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function premuim_publishing_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function premuim_publishing_default_rules_link() {
  $items = array();
  $items['confirm'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Confirm",
      "link_type" : "token",
      "bundles" : { "news" : "news" },
      "entity_link" : 1
    },
    "name" : "confirm",
    "label" : "Confirm",
    "path" : "confirm",
    "entity_type" : "node",
    "rdf_mapping" : [  ]
  }');
  $items['reject'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Reject",
      "link_type" : "token",
      "bundles" : { "news" : "news" },
      "entity_link" : 1
    },
    "name" : "reject",
    "label" : "Reject",
    "path" : "reject",
    "entity_type" : "node",
    "rdf_mapping" : [  ]
  }');
  return $items;
}
