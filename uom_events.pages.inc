<?php
/**
 * @file
 */

/**
 * Page handler.
 */
function uom_events_page($id = NULL) {

  $output = '';

  if (empty($id)) {
    $uri = uom_events_api_uri(array('events' => 'current') );
    $data = uom_events_api_fetch($uri);

    // Make a table or list or whatever.
  }
  else {
    $uri = uom_events_api_uri(array('events' => $id));
    $data = uom_events_api_fetch($uri);
  }

  dpm($data);

  return $output;
}
