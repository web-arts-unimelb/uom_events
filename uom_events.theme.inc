<?php
/**
 * @file
 */

/**
 * Basic theme function for an event related location.
 */
function theme_uom_event_location($variables) {
  $location = $variables['location'];
  $items = array();

  $title = t('Location');
  $attributes = array('class' => array('uom-event-location'));
  $type = 'ul';

  if (!empty($location->room_or_theatre)) {
    $items[] = array(
      'data'  => check_plain($location->room_or_theatre),
      'class' => array('room'),
    );
  }

  if (!empty($location->building)) {
    $items[] = array(
      'data'  => check_plain($location->building),
      'class' => array('building'),
    );
  }

  if (!empty($location->address)) {
    $items[] = array(
      'data'  => check_plain($location->address),
      'class' => array('address'),
    );
  }

  return (empty($items)) ? '' : theme_item_list(array('items' => $items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
}

function theme_uom_event_location_inline($variables) {
	$location = $variables['location'];
  $items = array();

	if(!empty($location->room_or_theatre)) {
		$items[] = check_plain($location->room_or_theatre);
	}

	if(!empty($location->building)) {
		$items[] = check_plain($location->building);
	}
	
	if(!empty($location->address)) {
		$items[] = check_plain($location->address);
	}

	if(empty($items)) {
		$output = "";
	}
	else {
		$output = implode(", ", $items);
	}	

	return $output;
}

/**
 * Basic theme function for event related contact information.
 */
function theme_uom_event_information($variables) {
  $information = $variables['information'];
  $items       = array();

  $title = t('Information');
  $attributes = array('class' => array('uom-event-information'));
  $type = 'ul';

  if (!empty($information->email)) {
    $items[] = array(
      'data'  => l($information->email, 'mailto:' . $information->email),
      'class' => array('email'),
    );
  }
  if (!empty($information->phone)) {
    $items[] = array(
      'data'  => (module_exists('unimelb_formatters')) ? unimelb_formatters_field_formatter_unimelb_html5_phone_link(array('safe_value' => $information->phone)) : $information->phone,
      'class' => array('phone'),
    );
  }
  if (!empty($information->url)) {
    $items[] = array(
      'data'  => l($information->url, $information->url),
      'class' => array('url'),
    );
  }

  return (empty($items)) ? '' : theme_item_list(array('items' => $items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
}

/**
 * Basic theme function for event related booking information.
 */
function theme_uom_event_booking($variables) {
  $booking = $variables['booking'];
  $items   = array();

  $title = t('Booking');
  $attributes = array('class' => array('uom-event-booking'));
  $type = 'ul';

  if (!empty($booking->email)) {
    $items[] = array(
      'data'  => l($booking->email, 'mailto:' . $booking->email),
      'class' => array('email'),
    );
  }
  if (!empty($booking->phone)) {
    $items[] = array(
      'data'  => (module_exists('unimelb_formatters')) ? unimelb_formatters_field_formatter_unimelb_html5_phone_link(array('safe_value' => $booking->phone)) : $booking->phone,
      'class' => array('phone'),
    );
  }
  if (!empty($booking->url)) {
    $items[] = array(
      'data'  => l($booking->url, $booking->url),
      'class' => array('url'),
    );
  }

  return (empty($items)) ? '' : theme_item_list(array('items' => $items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
}

