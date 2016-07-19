<?php
/**
 * @file
 * My Social test content functions.
 */

/*=================================
              HOOKS
 ================================*/

/**
 * Implements social settings form.
 */
function my_social_settings_form() {
  $form = array();
  $form['generate_test_users'] = array(
    '#type' => 'fieldset',
    '#title' => t('Test users'),
  );
  $form['generate_test_users']['create_users'] = array(
    '#type' => 'submit',
    '#value' => t('Generate users'),
  );
  $form['generate_test_users']['delete_users'] = array(
    '#type' => 'submit',
    '#value' => t('Delete users'),
  );
  $form['generate_test_messages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Test messages'),
  );
  $form['generate_test_messages']['create_messages'] = array(
    '#type' => 'submit',
    '#value' => t('Generate messages'),
  );
  $form['generate_test_messages']['delete_messages'] = array(
    '#type' => 'submit',
    '#value' => t('Delete messages'),
  );

  return $form;
}

/**
 * Implements submit for social settings form.
 */
function my_social_settings_form_submit() {
  if ($_POST['op'] == 'Generate users') {
    _create_test_users('teacher', 20);
    _create_test_users('student', 20);
  }
  if ($_POST['op'] == 'Delete users') {
    _delete_test_users();
  }
  if ($_POST['op'] == 'Generate messages') {
    _create_test_messages(40);
  }
  if ($_POST['op'] == 'Delete messages') {
    _messages_delete();
  }
}

/*=================================
            FUNCTIONS
 ================================*/

/**
 * Deletes test users.
 */
function _delete_test_users() {
  // Delete test users.
  $rids = array();
  $rids[] = array_search('student', user_roles());
  $rids[] = array_search('teacher', user_roles());

  if (!empty($rids)) {
    $query = db_select('users', 'u');
    $query->join('users_roles', 'ur', 'u.uid = ur.uid');
    $query->fields('u', array('uid'))
      ->condition('ur.rid', $rids, 'IN');
    $result = $query->execute();

    if ($result) {
      $uids = array();
      foreach ($result as $user) {
        $uids[] = $user->uid;
      }
      if (!empty($uids)) {
        user_delete_multiple($uids);
        drupal_set_message(count($uids) . t(' Test users have been deleted'));
      } else {
        drupal_set_message(t('Teachers or Students users not found.'));
      }
    }
  }
}

/**
 * Creates test users and their profiles.
 *
 * @param $role
 *   Role users being created.
 * @param $n
 *   Users number.
 */
function _create_test_users($role, $n) {
  $roles = user_roles();
  if (in_array($role, $roles)) {
    $rid = array_search($role, $roles);

    for ($i = 1; $i <= $n; $i++) {
      $name = $role . $i;
      $email = $name . '@mail.com';

      $newUser = entity_create('user', array());
      $newUser->name = $name;
      $newUser->mail = $email;
      $newUser->pass = $role;
      $newUser->status = 1;
      $newUser->init = $email;
      $newUser->roles = array(
        DRUPAL_AUTHENTICATED_RID => 'authenticated user',
        $rid => $role,
      );
      entity_save('user', $newUser);


      $profile = entity_create('profile2', array('type' => 'faculty_profile'));
      $profile->uid = $newUser->uid;
      $profile->field_first_name[LANGUAGE_NONE][0]['value'] = $name . ' first';
      $profile->field_last_name [LANGUAGE_NONE][0]['value'] = $name . ' last';
      $profile->field_address [LANGUAGE_NONE][0]['value'] = 'Address, ' . $i;
      $profile->field_school [LANGUAGE_NONE][0]['value'] = 'School #' . $i;
      $profile->save();

      $newUser->profiles['faculty_profile'] = $profile;

      if ($role == 'student') {
        $profile = entity_create('profile2', array('type' => 'preferences'));
        $profile->uid = $newUser->uid;
        $profile->field_likes[LANGUAGE_NONE][0]['value'] = $name . '\'s likes';
        $profile->field_dislikes [LANGUAGE_NONE][0]['value'] = $name . '\'s dislikes';
        $profile->save();

        $newUser->profiles['preferences'] = $profile;
      }
    }
    drupal_set_message($n . t(' Users have been created, role is ') . $role);
  }
}

function _create_test_messages($n = 40) {
  for ($i = 1; $i <= $n; $i++) {

    $from = _random_user();
    $to = _random_user();
    while ($from == $to) {
      $to = _random_user();
    }

    $message = message_create('private_message');
    $message->field_message_from['und'][0]['target_id'] = $from;
    $message->field_message_to['und'][0]['target_id'] = $to;
    $message->field_message_text['und'][0]['value'] = 'Text of message from ' . $from . ' to ' . $to;
    message_save($message);
  }
  drupal_set_message($n . t(' Messages have been created.'));
}

/**
 * Deletes all the private messages.
 */
function _messages_delete() {
  $query = db_select('message', 'm')
    ->fields('m', array('mid'));
  $result = $query->execute();

  $mids = array();
  if ($result) {
    foreach ($result as $msg) {
      $mids[] = $msg->mid;
    }
    if (!empty($mids)) {
      message_delete_multiple($mids);
      drupal_set_message(count($mids) . t(' Private messages have been deleted'));
    } else {
      drupal_set_message(t('Messages not found.'));
    }
  }
}

function _random_user() {
  $query = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->orderRandom();
  $result = $query->execute()->fetchField();

  return $result;
}
