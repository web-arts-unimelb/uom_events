<?php
/**
 * Template file to show a list of presenters.
 *
 * Variables:
 *   $link
 *   $tag
 *   $title
 *   $count_events
 */
?>

<ul class="uom-event-tag">
<?php foreach($tags as $tag): ?>
<li><a href="<?php print $tag['link']; ?>"><?php print $tag['title']; ?></a> (<?php print $tag['count_events']; ?>)</li>
<?php endforeach; ?>
</ul>
