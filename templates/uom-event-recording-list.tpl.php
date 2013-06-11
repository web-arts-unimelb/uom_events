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

<?php foreach($recordings as $recording): ?>
  <div class="uom-events-recording">
    <h3 class="title"><a href="<?php print $recording['link']; ?>"><?php print $recording['title']; ?></a></h3>
    <a href="<?php print $recording['watch_url']; ?>"><?php print $recording['thumbnail']; ?></a>
  </div>
<?php endforeach; ?>
