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
  $tag = variable_get('uom_events_tag', '');

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getEvent($id, TRUE);
    drupal_set_title($data->title);
    $output = theme('uom_event', array('event' => $data));
  }
  else {
		$api->displayFull();

    if(!empty($tag)) {
    	$tmp_data = array();
    	$tag_array = _build_tag_array($tag);
			foreach($tag_array as $single_tag) {
		  	$single_tag_data = $api->currentEventsByTag($single_tag, TRUE);
		  	if(count($single_tag_data) > 0) {
		  		foreach($single_tag_data as $single_event) {
		  			if(!_is_event_included($single_event->id, $tmp_data)) {
		  				$tmp_data[] = $single_event;
		  			}
		  		}
		  	}
		  }
			usort($tmp_data, "_my_event_compare_asc");
			// Remove non public events
			// Non public means showing on school site, but not on events.unimelb.edu.au
      //$tmp_data = array_filter($tmp_data, '_uom_events_filter_public_event_callback');

      //drupal_set_title(t('@tag Events', array('@tag' => ucwords($tag))));
			drupal_set_title(t('Upcoming events'));
    }
    else {
      $tmp_data = $api->currentEvents(TRUE);
    }

		$output = theme('uom_event_list', array('events' => $tmp_data));
  }

  return $output;
}

/**
 * Past event page handler.
 */
function uom_events_past_page() {
  drupal_set_title(t('Past events'));

	$api = uom_events_api();
	$api->displayFull();
	
  $tag = variable_get('uom_events_tag', '');
  $past_event_caching_time = variable_get('uom_events_past_event_cache', 86400);
	$num_of_years = variable_get('uom_events_past_num_of_years', 1);
	$tag_array = _build_tag_array($tag);
	
	$data = array();
	
  if( 
  		($cache = cache_get('uom_events_past_events_data')) && 
  		($past_event_caching_time != 0)
  ) {
    $data = $cache->data;
  }
  else {
    $tag_events = array();
		foreach($tag_array as $single_tag) {
			$tmp_tag_events = $api->pastEventsByTag($single_tag, $num_of_years, TRUE);
			if(count($tmp_tag_events) > 0) {
				foreach($tmp_tag_events as $tmp_tag_event) {
					if(!_is_event_included($tmp_tag_event->id, $tag_events)) {
						$tag_events[] = $tmp_tag_event;
					}
				} 
			}
		}

		usort($tag_events, "_my_event_compare_desc");
		// Remove non public events
    //$tag_events = array_filter($tag_events, '_uom_events_filter_public_event_callback');
    cache_set('uom_events_past_events_data', $tag_events, 'cache', time() + $past_event_caching_time);
		$data = $tag_events;
  }
  
	$output = theme('uom_event_past_list', array('events' => $data));
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
  drupal_set_title(t('Event Recordings'));

  $api = uom_events_api();

  if (is_numeric($id)) {
    $api->displayFull();
    $data = $api->getRecording($id, TRUE);
    drupal_set_title($data->title);
    $output = theme('uom_event_recording', array('recording' => $data));
  }
  else {
    $data = $api->allRecordings();
    $output = theme('uom_event_recording_list', array('recordings' => $data));
  }

  return $output;
}

function uom_events_tags_page($id = NULL) {
  drupal_set_title(t('Event Tags'));

  $api = uom_events_api();

  $api->displayFull();
  $data = $api->alltags();
  $output = theme('uom_event_tag_list', array('tags' => $data));

  return $output;
}

function uom_events_hosts_page($id = NULL) {
  drupal_set_title(t('Event Hosts'));

  $api = uom_events_api();

  $api->displayFull();
  $data = $api->allHosts();
  $output = theme('uom_event_host_list', array('hosts' => $data));

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

