<?php
/**
 * @file
 */

/**
 * Page handler.
 */
function uom_events_page($id = NULL) {
  drupal_set_title(t('Events'));

  $api = new EventsAPI(variable_get('uom_events_token', ''));
  $api->setCallback('drupal_http_request', array());
  $api->setCallback('uom_events_fetcher');
  $api->setParser('uom_events_parser');

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getEvent($id, TRUE);
    drupal_set_title($data->title);
    $output = theme('uom_event', array('event' => $data));
  }
  else {
    $data = $api->currentEvents();
    $output = theme('uom_event_list', array('events' => $data));
  }

  return $output;
}
