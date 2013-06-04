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

<ul class="uom-event-host">
<?php foreach($hosts as $host): ?>
  <li><a href="<?php print $host['link']; ?>"><?php print $host['title']; ?></a></li>
<?php endforeach; ?>
</ul>
