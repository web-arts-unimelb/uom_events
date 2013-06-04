<?php
/**
 * @file
 */

/**
 * Module settings.
 */
function uom_events_admin_form() {
  $form = array();

  $form['uom_events_token'] = array(
    '#title' => t('Authentication Token'),
    '#description' => t('Enter the events authentication token.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('uom_events_token', ''),
  );

  $form['uom_events_path'] = array(
    '#title' => t('Menu path'),
    '#description' => t('Enter the menu path where the events page should be displayed.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('uom_events_path', 'events'),
  );

  $form['uom_events_tag'] = array(
    '#title' => t('Events tag'),
    '#description' => t('Enter the tag to filter events on the main events page.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('uom_events_tag', ''),
  );

  $form['uom_event_blocks'] = array(
    '#title' => t('Event blocks'),
    '#description' => t('Enter the number of event blocks you want use. Each event blok can be configured with its own tag filter'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('uom_events_blocks', 1),
  );

  $cache = variable_get('cache_lifetime', 0);
  if (!empty($cache)) {
    $form['uom_events_cache'] = array(
      '#markup' => t('Caching is enabled. Drupal will cache API responses for at least @interval.', array('@interval' => format_interval($cache))),
    );
  }
  else {
    $form['uom_events_cache'] = array(
      '#markup' => t('Caching is disabled. You can enable it by setting a minimum cache lifetime at !link.', array('!link' => l('performance settings', 'admin/config/development/performance'))),
    );
  }

  return system_settings_form($form);
}

/**
 * Validate admin screen input.
 */
function uom_events_admin_form_validate($form, &$form_state) {

}

/**
 * Rebuild the menu cache on submit.
 */
function uom_events_admin_form_submit($form, &$form_state) {
  variable_set('menu_rebuild_needed', TRUE);
}
