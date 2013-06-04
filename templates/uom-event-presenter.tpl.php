<?php
/**
 * Template file to show an event presenter.
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
 *   $biography
 *   $biography_html
 *   $biography_text
 *   $country
 *   $content_approved_by_speaker
 *   $find_an_expert_url
 *   $photo_url
 *   $photo
 *   $original
 */
?>

<?php if ($photo): ?>
  <div style="float: right;"><a href="<?php print $original; ?>"><?php print $photo; ?></a></div>
<?php endif; ?>
<?php print $position_title; ?> <?php print $organisation; ?>
<?php print $biography_html; ?>
