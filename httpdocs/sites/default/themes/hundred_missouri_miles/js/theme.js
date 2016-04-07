jQuery(document).ready(function($) {
  $('.menu-toggle').append('<span class="arrow"></span>');
  $('#navigate').click(function() {
    $('#block-menu-block-3').slideToggle("slow");
    $('#block-menu-menu-secondary-menu').slideToggle("slow");
    $('#navigate .menu-toggle span.arrow').toggleClass("down_png"); return false;
  });
  $('.panel-pane.collapsible h2.pane-title').click(function() {
    $(this).parent('.panel-pane').toggleClass('collapsed');
  });
});

if(Modernizr.mq('only all and (max-width: 739px)')) {
  jQuery(document).ready(function($) {
    $('.view').wrap('<div class="table-container"></div>');  	
  });
} else {
  // Do something for bigger screens
}