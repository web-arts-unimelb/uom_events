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

<?php foreach($events as $event): ?>
  <div class="uom-event">
    <h3><a href="<?php print $event['link']; ?>"><?php print $event['title']; ?></a></h3>
    <strong>Date:</strong> <span class="date-display-single"><?php print $event['date_start']; ?></span>
    <?php if ($event['time_start']): ?>
      <span class="date-display-start" property="dc:date" datatype="xsd:dateTime" content="<?php print $event['datestamp_start']; ?>"><?php print $event['time_start']; ?></span>
    <?php endif; ?>
    <?php if ($event['time_end']): ?>
      – <span class="date-display-end" property="dc:date" datatype="xsd:dateTime" content="<?php print $event['datestamp_end']; ?>"><?php print $event['time_end']; ?></span>
    <?php endif; ?>

    <?php if ($event['speaker']): ?>
      <h4>Speaker: <?php print $event['speaker']; ?></h4>
    <?php endif; ?>

		<br/><strong>Location:</strong> <?php print $event['location']; ?>
	</div>

<?php endforeach; ?>

