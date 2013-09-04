jQuery(document).ready(function () {
	jQuery('.uom-events .part-events:not(:first)').hide();

	jQuery('#event-pager-top').jqPagination({
		page_string : '{current_page} of {max_page}',
    max_page : jQuery('.uom-events .part-events').length,
    paged : function(page) {
    	jQuery('.uom-events .part-events').hide();
      jQuery(jQuery('.uom-events .part-events')[page - 1]).show();
      jQuery('.event-pager-current-page-num').attr('value', page);
    }
	});
	
	
	jQuery('#event-pager-bottom').jqPagination({
		page_string : '{current_page} of {max_page}',
    max_page : jQuery('.uom-events .part-events').length,
    paged : function(page) {
    	jQuery('.uom-events .part-events').hide();
      jQuery(jQuery('.uom-events .part-events')[page - 1]).show();
      jQuery('.event-pager-current-page-num').attr('value', page);
    }
	});
	
	// Start event-pager-top ------------------------------------------------------------------
	jQuery('#event-pager-top a.first').on('click', function(){
		var curr_page_num = 1;
		jQuery('#event-pager-bottom').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Next
	jQuery('#event-pager-top a.next').on('click', function(){
		var curr_page_num = jQuery('.event-pager-current-page-num').attr('value');
		curr_page_num = parseInt(curr_page_num, 10) + 1;
		var max_page_num = parseInt(jQuery('.uom-events .part-events').length, 10);
		
		if(curr_page_num >= max_page_num)
			curr_page_num = max_page_num;

		jQuery('#event-pager-bottom').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Previous
	jQuery('#event-pager-top a.previous').on('click', function(){
		var curr_page_num = jQuery('.event-pager-current-page-num').attr('value');
		curr_page_num = parseInt(curr_page_num, 10) - 1;
		
		if(curr_page_num <= 0)
			curr_page_num = 1;
		
		jQuery('#event-pager-bottom').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Last
	jQuery('#event-pager-top a.last').on('click', function(){
		var curr_page_num = parseInt(jQuery('.uom-events .part-events').length, 10);
		jQuery('#event-pager-bottom').jqPagination('option', {current_page : curr_page_num});	
	});
	// End event-pager-top ------------------------------------------------------------------
	
	
	// Start event-pager-bottom ------------------------------------------------------------------
	jQuery('#event-pager-bottom a.first').on('click', function(){
		var curr_page_num = 1;
		jQuery('#event-pager-top').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Next
	jQuery('#event-pager-bottom a.next').on('click', function(){
		var curr_page_num = jQuery('.event-pager-current-page-num').attr('value');
		curr_page_num = parseInt(curr_page_num, 10) + 1;
		var max_page_num = parseInt(jQuery('.uom-events .part-events').length, 10);
		
		if(curr_page_num >= max_page_num)
			curr_page_num = max_page_num;

		jQuery('#event-pager-top').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Previous
	jQuery('#event-pager-bottom a.previous').on('click', function(){
		var curr_page_num = jQuery('.event-pager-current-page-num').attr('value');
		curr_page_num = parseInt(curr_page_num, 10) - 1;
		
		if(curr_page_num <= 0)
			curr_page_num = 1;
		
		jQuery('#event-pager-top').jqPagination('option', {current_page : curr_page_num});	
	});
	
	// Last
	jQuery('#event-pager-bottom a.last').on('click', function(){
		var curr_page_num = parseInt(jQuery('.uom-events .part-events').length, 10);
		jQuery('#event-pager-top').jqPagination('option', {current_page : curr_page_num});	
	});
	// End event-pager-bottom ------------------------------------------------------------------
});
