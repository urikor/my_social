<?php
/**
 * @file
 * Social blocks.
 */

/*=================================
              HOOKS
 ================================*/

/**
 * Implements hook_block_info().
 */
function my_social_block_info() {
  $blocks = array();

  $blocks['faculty_block'] = array(
    'info' => t('Faculty block'),
    'status' => 1,
    'region' => 'content',
    'weight' => -12,
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => '<front>',
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function my_social_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'faculty_block':
      $block['subject'] = t('FACULTY');
      $block['content'] = _faculty_content();
      break;
  }

  return $block;
}

/*=================================
            FUNCTIONS
 ================================*/

/**
 * Return rendered views tables.
 *
 * @return mixed
 *   Teachers & students table views.
 */
function _faculty_content() {
  $teachers = social_get_view('faculty_table', 'block_teachers');
  $students = social_get_view('faculty_table', 'block_students');

  $out = theme('faculty_block',
    array(
      'teachers' => $teachers,
      'students' => $students
    ));

  return $out;
}

/**
 * Gets views.
 *
 * @param string $view_name
 *   views name
 * @param string $display
 *   views display name
 * @return string
 *   rendered views
 */
function social_get_view($view_name, $display) {
  $view = views_get_view($view_name);
  if (is_object($view)) {
    $view->set_display($display);
    $view->pre_execute();
    $title = '<h3>' . $view->get_title() . '</h3>';
    return  $title . $view->render($display);
  }
}
