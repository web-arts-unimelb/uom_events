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
<strong><span class="date-display-single"><?php print $date_start; ?></span>
  <?php if ($time_start): ?>
    <span class="date-display-start" property="dc:date" datatype="xsd:dateTime" content="<?php print $datestamp_start; ?>"><?php print $time_start; ?></span>
  <?php endif; ?>
  <?php if ($time_end): ?>
    –<span class="date-display-end" property="dc:date" datatype="xsd:dateTime" content="<?php print $datestamp_end; ?>"><?php print $time_end; ?></span>
  <?php endif; ?>
</strong>

  <?php if ($speaker): ?>
    <h4>Speaker: <?php print $speaker; ?></h4>
  <?php endif; ?>

  <?php if ($description_html): ?>
    <?php print $description_html; ?>
  <?php endif; ?>
  
  <?php if($information): ?>
    <?php print $information; ?>
  <?php endif; ?>  

  <?php if($type): ?>
    <h3>Event type</h3>
    <?php print $type; ?>
  <?php endif; ?>

	<?php
		if(!empty($location)) {
			print '<p>'. '<h3>Location</h3>'. $location. '</p>';
		} 
	?>
 	
	<?php print $booking; ?>
	<?php print $presenters; ?>
</div>

