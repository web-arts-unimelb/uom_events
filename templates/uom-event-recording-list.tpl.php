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

dpm(get_defined_vars());
?>

<ul class="uom-event-recording">
<?php foreach($recordings as $recording): ?>
  <li><a href="<?php print $recording['link']; ?>"><?php print $recording['title']; ?></a></li>
<?php endforeach; ?>
</ul>
