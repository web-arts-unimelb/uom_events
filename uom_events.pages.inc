<?php
/**
 * @file
 */

/**
 * Page handler.
 */
function uom_events_page($id = NULL) {
  drupal_set_title(t('Events'));

  $api = uom_events_api();

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
  drupal_set_title(t('@value Events', array('@value' => ucwords($value))));

  $api = uom_events_api();

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

function uom_events_presenters_page($id = NULL) {
  drupal_set_title(t('Presenters'));

  $api = uom_events_api();

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getPresenter($id, TRUE);
    $title = t('@title @given @family @post', array(
      '@title' => $data->title,
      '@given' => $data->first_name,
      '@family' => $data->last_name,
      '@post' => $data->post_nominal
    ));
    drupal_set_title($title);
    $output = theme('uom_event_presenter', array('presenter' => $data));
  }
  else {
    $data = $api->allPresenters();
    $output = theme('uom_event_presenter_list', array('presenters' => $data));
  }

  return $output;
}

function uom_events_recordings_page($id = NULL) {
  drupal_set_title(t('Events'));

  $api = uom_events_api();

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getRecording($id, TRUE);
    drupal_set_title($data->title);
    $output = theme('uom_event', array('event' => $data));
  }
  else {
    $data = $api->allRecordings();
    $output = theme('uom_event_list', array('events' => $data));
  }

  return $output;
}

function uom_events_tags_page($id = NULL) {
  drupal_set_title(t('Events'));

  $api = uom_events_api();

  $api->displayFull();
  $data = $api->alltags();
  $output = theme('uom_event_list', array('events' => $data));

  return $output;
}

function uom_events_hosts_page($id = NULL) {
  drupal_set_title(t('Events'));

  $api = uom_events_api();

  $api->displayFull();
  $data = $api->allHosts();
  $output = theme('uom_event_list', array('events' => $data));

  return $output;
}


/**
 * Debug page handler.
 */
function uom_events_page_devel($id = NULL) {
  drupal_set_title(t('Events'));

  $api = uom_events_api();

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
