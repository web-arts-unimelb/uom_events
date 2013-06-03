<?php
/**
 * Template file to show a list of presenters.
 *
 * Variables:
 *   $id
 *   $link
 *   $title
 *   $first_name
 *   $last_name
 *   $post_nominal
 *   $full_name
 *   $organisation
 *   $position_title
 *   $photo_url
 *   $photo
 *   $original
 */
?>

<ul class="uom-event-presenter">
<?php foreach($presenters as $presenter): ?>
  <li><a href="<?php print $presenter['link']; ?>"><?php print $presenter['full_name']; ?></a></li>
<?php endforeach; ?>
</ul>
