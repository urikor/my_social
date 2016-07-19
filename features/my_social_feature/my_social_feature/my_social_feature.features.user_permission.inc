<?php
/**
 * @file
 * my_social_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function my_social_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'user',
  );

  // Exported permission: 'edit any faculty_profile profile'.
  $permissions['edit any faculty_profile profile'] = array(
    'name' => 'edit any faculty_profile profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any preferences profile'.
  $permissions['edit any preferences profile'] = array(
    'name' => 'edit any preferences profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own faculty_profile profile'.
  $permissions['edit own faculty_profile profile'] = array(
    'name' => 'edit own faculty_profile profile',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own preferences profile'.
  $permissions['edit own preferences profile'] = array(
    'name' => 'edit own preferences profile',
    'roles' => array(
      'student' => 'student',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any faculty_profile profile'.
  $permissions['view any faculty_profile profile'] = array(
    'name' => 'view any faculty_profile profile',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any preferences profile'.
  $permissions['view any preferences profile'] = array(
    'name' => 'view any preferences profile',
    'roles' => array(
      'student' => 'student',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own faculty_profile profile'.
  $permissions['view own faculty_profile profile'] = array(
    'name' => 'view own faculty_profile profile',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own preferences profile'.
  $permissions['view own preferences profile'] = array(
    'name' => 'view own preferences profile',
    'roles' => array(
      'student' => 'student',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
