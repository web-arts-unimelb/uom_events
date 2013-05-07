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

/**
 * Filter page handler.
 */
function uom_events_filter_page($filter, $value) {
  drupal_set_title(t('@value Events', array('@value' => $value)));

  $api = new EventsAPI(variable_get('uom_events_token', ''));
  $api->setCallback('drupal_http_request', array());
  $api->setCallback('uom_events_fetcher');
  $api->setParser('uom_events_parser');

  switch($filter) {
    case 'tag':
      $data = $api->currentEventsByTag($value);
      break;

    case 'type':
      $data = $api->currentEventsByType($value);
      break;

    case 'host':
      $data = $api->currentEventsByHost($value);
      break;

    default:
      $data = $api->currentEvents();
      drupal_set_title(t('Events'));
      break;
  }

  return theme('uom_event_list', array('events' => $data));
}

/**
 * Debug page handler.
 */
function uom_events_page_devel($id = NULL) {
  drupal_set_title(t('Events'));

  $api = new EventsAPI(variable_get('uom_events_token', ''));
  $api->setCallback('drupal_http_request', array());
  $api->setCallback('uom_events_fetcher');
  $api->setParser('uom_events_parser');

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getEvent($id, TRUE);
    drupal_set_title($data->title);
  }
  else {
    $data = $api->currentEvents();
  }

  dpm($data);
  return '';
}
