<?php
/**
 * Template file to show a list of events.
 *
 * Variables:
 *   $id
 *   $title
 *   $link
 *   $date
 *   $date_start
 *   $date_end
 *   $time_start
 *   $time_end
 *   $timestamp_start
 *   $timestamp_end
 *   $speaker
 *   $location
 */

?>

<?php
	_add_pagination_script();
?>

<?php if($total_items > $items_per_page): ?>
	<div class="event-pager">
		<a href="#" class="first" data-action="first">&laquo;</a>
		<a href="#" class="previous" data-action="previous">&lsaquo;</a>
		<input type="text" readonly="readonly" data-max-page="40" disabled="disabled"/>
		<a href="#" class="next" data-action="next">&rsaquo;</a>
		<a href="#" class="last" data-action="last">&raquo;</a>
	</div>
<?php endif; ?>

<?php
	$total_html = "<div class=\"uom-events\">";
	for($offset = 0; $offset < $total_items; $offset += $items_per_page) {
		$part_events = array_slice($events, $offset, $items_per_page);
		
		$part_html = "<div class=\"part-events\">";
		foreach($part_events as $event) {
			$e_link = $event['link'];
			$e_title = $event['title'];
			
			$e_date_start = empty($event['date_start']) ? "" : "<strong>Date: </strong><span>". $event['date_start']. "</span>";
			$e_time_start = empty($event['time_start']) ? "" : " <span>". $event['time_start']. "</span>";
			$e_time_end = empty($event['time_end']) ? "" : " - <span>". $event['time_end']. "</span>";
			$e_speaker = empty($event['speaker']) ? "" : "<h4>Speaker: ". $event['speaker']. "</h4>";
			$e_location = empty($event['location']) ? "" : "<br/><strong>Location: </strong>". $event['location'];
			
			$event_html = "
				<div class=\"uom-event\">
					<h3><a href=\"$e_link\">$e_title</a></h3>
					$e_date_start $e_time_start $e_time_end
					$e_speaker
					$e_location
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

<?php if($total_items > $items_per_page): ?>
	<div class="event-pager">
		<a href="#" class="first" data-action="first">&laquo;</a>
		<a href="#" class="previous" data-action="previous">&lsaquo;</a>
		<input type="text" readonly="readonly" data-max-page="40" disabled="disabled"/>
		<a href="#" class="next" data-action="next">&rsaquo;</a>
		<a href="#" class="last" data-action="last">&raquo;</a>
	</div>
<?php endif; ?>
