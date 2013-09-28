jQuery(document).ready(function () {
  jQuery('.uom-events .part-events:not(:first)').hide();

  jQuery('.event-pager').jqPagination({
		page_string   : 'Event {current_page} of {max_page}',
    max_page : jQuery('.uom-events .part-events').length,
    paged : function(page) {
      jQuery('.uom-events .part-events').hide();
      jQuery(jQuery('.uom-events .part-events')[page - 1]).show();
    }
  });
});

