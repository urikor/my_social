<?php
/**
 * @file
 * My Social message create form.
 */

/*=================================
              HOOKS
 ================================*/

/**
 * Implements hook_form().
 */
function my_social_form() {
  global $user;
  $form = array();

  $form['message_from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => $user->name,
    '#size' => 30,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('form-control'),
    ),
  );
  $form['message_to'] = array(
    '#type' => 'textfield',
    '#title' => t('To'),
    '#size' => 30,
    '#required' => TRUE,
    '#autocomplete_path' => 'user/autocomplete',
    '#attributes' => array(
      'class' => array('form-control'),
      'placeholder' => t('Start to print...'),
    ),
  );
  $form['message_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#cols' => 30,
    '#rows' => 3,
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('form-control'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#prefix' => '<div class="modal-footer">',
    '#suffix' => '</div>',
  );
  $form['#attached']['js'] = array(
    drupal_get_path('theme', 'my_social_theme') . 'js/jquery.validate.min.js',
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function my_social_form_submit() {
  rules_invoke_event('new_private_message');
}
