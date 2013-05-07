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
