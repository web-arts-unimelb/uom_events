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

  $title = t('Contact');
  $attributes = array('class' => array('uom-event-information'));
  $type = 'ul';

  if (!empty($information->email)) {
		$data = '<strong>'. t('Email: '). '</strong>'. l($information->email, 'mailto:' . $information->email);
    $items[] = array(
      'data'  => $data,
      'class' => array('email'),
    );
  }
  if (!empty($information->phone)) {
		$data = '<strong>'. t('Phone: '). '</strong>'. ( (module_exists('unimelb_formatters')) ? unimelb_formatters_field_formatter_unimelb_html5_phone_link(array('safe_value' => $information->phone)) : $information->phone );
    $items[] = array(
      'data'  => $data, 
      'class' => array('phone'),
    );
  }
  if (!empty($information->url)) {
		$data = '<strong>'. t('URL: '). '</strong>'. l($information->url, $information->url); 
    $items[] = array(
      'data'  => $data,
      'class' => array('url'),
    );
  }

  return (empty($items)) ? '' : theme_item_list(array('items' => $items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
}

/**
 * Basic theme function to list presenters within an event. 
 */
function theme_uom_event_presenters_in_event($variables) {
	$return_html = '';
	$presenters = $variables['presenters'];

	$items = array();
	$title = t('Presenters');
	$attributes = array('class' => array('uom-event-presenter'));
  $type = 'ul';

	if(is_array($presenters) && count($presenters) > 0) {
		foreach($presenters as $presenter) {
			$full_name = t('@title @first @last @post', array('@title' => $presenter->title, '@first' => $presenter->first_name, '@last' => $presenter->last_name, '@post' => $presenter->post_nominal));
			$link = $presenter->link;
			$data = l($full_name, $link);

			$items[] = array(
				'data' => $data,
				'class' => array('presenter'),
			);
		}
		
		$return_html = theme_item_list(array('items' => $items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
	}
	else {
		$return_html = '';		
	}

	return $return_html;
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

