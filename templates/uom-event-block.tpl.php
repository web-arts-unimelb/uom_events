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
    <div class="uom-event-date">
      <div class="uom-event-date-day"><span class="date-display-single"><?php print $event['dates']['start']['j']; ?></span></div>
      <div class="uom-event-date-my"><span class="date-display-single"><?php print $event['dates']['start']['M']; ?></span> <span class="date-display-single"><?php print $event['dates']['start']['Y']; ?></span></div>
    </div>
    <strong><a href="<?php print $event['link']; ?>"><?php print $event['title']; ?></a></strong>
  </div>
<?php endforeach; ?>

<?php if ($more): ?><?php print $more; ?><?php endif; ?>

