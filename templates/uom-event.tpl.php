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

<div class="uom-event">
  <span class="date-display-single"><?php print $date_start; ?></span>
  <?php if ($time_start): ?>
    <span class="date-display-start" property="dc:date" datatype="xsd:dateTime" content="<?php print $timestamp_start; ?>"><?php print $time_start; ?></span>
  <?php endif; ?>
  <?php if ($time_end): ?>
    –<span class="date-display-end" property="dc:date" datatype="xsd:dateTime" content="<?php print $timestamp_end; ?>"><?php print $time_end; ?></span>
  <?php endif; ?>

  <?php if ($speaker): ?>
    <h4>Speaker: <?php print $speaker; ?></h4>
  <?php endif; ?>

  <?php if ($description_html): ?>
    <?php print $description_html; ?>
  <?php endif; ?>

  <?php print $information; ?>
  <?php print $location; ?>
  <?php print $booking; ?>

</div>

