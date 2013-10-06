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
 
  $form['uom_events_blocks'] = array(
    '#title' => t('Event blocks'),
    '#description' => t('Enter the number of event blocks you want use. Each event blok can be configured with its own tag filter'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('uom_events_blocks', 1),
  );

	$form['uom_events_past_event_items_per_page'] = array(
    '#title' => t('Past events: how many events to display on pagination listing'),
    '#description' => t('How many events to display on pagination listing'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('uom_events_past_event_items_per_page', 10),
  );

	$form['uom_events_past_num_of_years'] = array(
    '#title' => t('Past events: how many years from today to past'),
    '#description' => t('Enter number of years from today to past. e.g. This year is 2013, and you want to go back to 2011, so it will be 3.'),
    '#type' => 'textfield',
    '#size' => 3,
    '#default_value' => variable_get('uom_events_past_num_of_years', 1),
  );

	$form['uom_events_past_event_cache'] = array(
    '#title' => t('Past event: caching (If you change any setting on this page, you may need to refresh the past events listing page a few times)'),
    '#description' => t('Define your past event caching time'),
    '#type' => 'select',
    '#options' => array(0 => 'none', 21600 => '6 hours', 86400 => '1 day'),
    '#default_value' => variable_get('uom_events_past_event_cache', 86400), // 1 day
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
