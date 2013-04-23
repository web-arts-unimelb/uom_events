<?php
/**
 * @file
 */

/**
 * Module settings.
 */
function uom_events_admin_form() {
  $form = array();

  $form['uom_events_api_uri'] = array(
    '#title' => t('API URI'),
    '#description' => t('Enter the events API site URI.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('uom_events_api_uri', ''),
  );

  $form['uom_events_api_token'] = array(
    '#title' => t('Authentication Token'),
    '#description' => t('Enter the events authentication token.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('uom_events_api_token', ''),
  );

  return system_settings_form($form);
}
