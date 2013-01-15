<?php
/**
 * @file
 * premuim_publishing.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function premuim_publishing_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:news-publishing
  $menu_links['navigation:news-publishing'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'news-publishing',
    'router_path' => 'news-publishing',
    'link_title' => 'News publishing',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('News publishing');


  return $menu_links;
}
