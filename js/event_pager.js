jQuery(document).ready(function () {
  jQuery('.uom-events .part-events:not(:first)').hide();

  jQuery('.event-pager').jqPagination({
    max_page : jQuery('.uom-events .part-events').length,
    paged : function(page) {
      jQuery('.uom-events .part-events').hide();
      jQuery(jQuery('.uom-events .part-events')[page - 1]).show();
    }
  });
});

