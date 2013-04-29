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

  return system_settings_form($form);
}
