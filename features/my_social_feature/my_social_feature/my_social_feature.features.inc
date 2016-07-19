<?php
/**
 * @file
 * my_social_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function my_social_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function my_social_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function my_social_feature_default_message_type() {
  $items = array();
  $items['private_message'] = entity_import('message_type', '{
    "name" : "private_message",
    "description" : "Private message",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : [],
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0022[message:field-message-from:url:absolute]\\u0022\\u003E[message:field-message-from:name]\\u003C\\/a\\u003E sent message to \\u003Ca href=\\u0022[message:field-message-to:url:absolute]\\u0022\\u003E[message:field-message-to:name]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-message-from:url:absolute]\\u0022\\u003E[message:field-message-from:name]\\u003C\\/a\\u003E sent message to \\u003Ca href=\\u0022[message:field-message-to:url:absolute]\\u0022\\u003E[message:field-message-to:name]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function my_social_feature_default_profile2_type() {
  $items = array();
  $items['faculty_profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "faculty_profile",
    "label" : "Faculty profile",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  $items['preferences'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "preferences",
    "label" : "Preferences",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
