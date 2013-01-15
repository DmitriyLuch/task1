<?php
/**
 * @file
 * premuim_publishing.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function premuim_publishing_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_confirm'] = entity_import('rules_config', '{ "rules_link_condition_confirm" : {
      "LABEL" : "Rules link: Confirm condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "AND" : [
            { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } },
            { "OR" : [
                { "data_is" : { "data" : [ "node:field-status" ], "value" : "1" } },
                { "data_is" : { "data" : [ "node:field-status" ], "value" : "3" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_condition_reject'] = entity_import('rules_config', '{ "rules_link_condition_reject" : {
      "LABEL" : "Rules link: Reject condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "AND" : [
            { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } },
            { "OR" : [
                { "data_is" : { "data" : [ "node:field-status" ], "value" : "1" } },
                { "data_is" : { "data" : [ "node:field-status" ], "value" : "2" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_link_set_confirm'] = entity_import('rules_config', '{ "rules_link_set_confirm" : {
      "LABEL" : "Rules link: Confirm rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "2" } },
              { "node_publish" : { "node" : [ "node" ] } }
            ],
            "LABEL" : "Confirm rule"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_reject'] = entity_import('rules_config', '{ "rules_link_set_reject" : {
      "LABEL" : "Rules link: Reject rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "3" } },
              { "node_unpublish" : { "node" : [ "node" ] } }
            ],
            "LABEL" : "reject rule"
          }
        }
      ]
    }
  }');
  $items['rules_premium_publish'] = entity_import('rules_config', '{ "rules_premium_publish" : {
      "LABEL" : "Publish news of premium user",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Premium publishing" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "AND" : [
            { "NOT data_is_empty" : { "data" : [ "site:current-user:field-premium" ] } },
            { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
          ]
        }
      ],
      "DO" : [
        { "node_publish" : { "node" : [ "node" ] } },
        { "data_set" : { "data" : [ "node:field-status" ], "value" : "2" } }
      ]
    }
  }');
  $items['rules_unpublish_news_of_unpremiuim_user'] = entity_import('rules_config', '{ "rules_unpublish_news_of_unpremiuim_user" : {
      "LABEL" : "Unpublish news of unpremiuim user",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Premium publishing" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "AND" : [
            { "data_is_empty" : { "data" : [ "site:current-user:field-premium" ] } },
            { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
          ]
        }
      ],
      "DO" : [
        { "node_unpublish" : { "node" : [ "node" ] } },
        { "data_set" : { "data" : [ "node:field-status" ], "value" : "1" } }
      ]
    }
  }');
  return $items;
}
