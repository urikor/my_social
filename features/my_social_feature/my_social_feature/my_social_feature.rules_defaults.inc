<?php
/**
 * @file
 * my_social_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function my_social_feature_default_rules_configuration() {
  $items = array();
  $items['rules_new_private_message'] = entity_import('rules_config', '{ "rules_new_private_message" : {
      "LABEL" : "New Private Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "message", "new", "private message" ],
      "REQUIRES" : [ "rules", "my_social" ],
      "ON" : { "new_private_message" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "private_message",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "message_created" : "Created message" } }
          }
        }
      ]
    }
  }');
  return $items;
}
