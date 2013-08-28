<?php
/**
 * Template file to show a list of events.
 *
 * Variables:
 *   $events:  A an array of events containing the following keys:
 *   - id:              The unique API event ID.
 *   - title:           The event title.
 *   - link:            Relative url to the event detail page.
 *   - date_start:      The formatted event start date.
 *   - date_end:        The formatted event end date.
 *   - time_start:      The formatted event start time.
 *   - time_end:        The formatted event end time.
 *   - timestamp_start: The event start unix timestamp.
 *   - timestamp_end:   The event end unix timestamp.
 *   - dates:           An array containing two sub-arrays:
 *     + start:         A keyed array containing date parts for the event start date.
 *     + end:           A keyed array containing date parts for the event end date.
 *   - speaker:         The event speaker.
 *   - location:        The themed event location.
 *   - more:            A themed link to the event detail page.
 *   - original:        A link to the event on the API site.
 */
?>

<?php
	drupal_add_js(drupal_get_path('module', 'uom_events') . '/js/jquery.jqpagination.js');

	drupal_add_js("
		jQuery(document).ready(function () {
    	jQuery('.uom-events .part-events:not(:first)').hide();

    	jQuery('.event-pager').jqPagination({
        max_page : jQuery('.uom-events .part-events').length,
        paged : function(page) {
        	jQuery('.uom-events .part-events').hide();
          jQuery(jQuery('.uom-events .part-events')[page - 1]).show();
        }
    	});
   }); 	
	", 'inline');
?>

<?php
	$total_html = "<div class=\"uom-events\">";
	for($offset = 0; $offset < $total_items; $offset += $items_per_page) {
		$part_events = array_slice($events, $offset, $items_per_page);
		
		$part_html = "<div class=\"part-events\">";
		foreach($part_events as $event) {
			$e_date = $event['dates']['start']['j'];
			$e_month = $event['dates']['start']['M'];
			$e_year = $event['dates']['start']['Y'];
			$e_link = $event['link'];
			$e_title = $event['title'];
			
			$event_html = "
				<div class=\"uom-event\">
					<div class=\"uom-event-date\">
						<div class=\"uom-event-date-day\">
							<span class=\"date-display-single\">$e_date</span>
						</div>
						<div class=\"uom-event-date-my\">
							<span class=\"date-display-single\">$e_month</span> 
							<span class=\"date-display-single\">$e_year</span>
						</div>
					</div>
					<strong><a href=\"$e_link\">$e_title</a></strong>
				</div>
			";
			$part_html .= $event_html;
		}
		$part_html .= "</div>";
		$total_html .= $part_html;
	}
	$total_html .= "</div>";
	
	echo $total_html;
?>

<?php if($total_items > 0): ?>
	<div class="event-pager">
		  <a href="#" class="first" data-action="first">&laquo;</a>
		  <a href="#" class="previous" data-action="previous">&lsaquo;</a>
		  <input type="text" readonly="readonly" data-max-page="40" />
		  <a href="#" class="next" data-action="next">&rsaquo;</a>
		  <a href="#" class="last" data-action="last">&raquo;</a>
	</div>
<?php endif; ?>

