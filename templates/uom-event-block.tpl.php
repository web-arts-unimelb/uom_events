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

<?php foreach($events as $event): ?>
  <div class="uom-event">
    <div class="uom-event-date">
      <div class="uom-event-date-day"><span class="date-display-single"><?php print $event['dates']['start']['j']; ?></span></div>
      <div class="uom-event-date-my"><span class="date-display-single"><?php print $event['dates']['start']['M']; ?></span> <span class="date-display-single"><?php print $event['dates']['start']['Y']; ?></span></div>
    </div>
    <strong><a href="<?php print $event['link']; ?>"><?php print $event['title']; ?></a></strong>
  </div>
<?php endforeach; ?>

<?php if ($more): ?><?php print $more; ?><?php endif; ?>
