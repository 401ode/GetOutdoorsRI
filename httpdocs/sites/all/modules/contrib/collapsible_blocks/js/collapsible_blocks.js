jQuery(document).ready(function($) {
  $(".collapsible-block .block-title a").live("click", function(e) {
    e.preventDefault();
    $(this).parents(".collapsible-block").find(".content").toggle(500, function() {
      $(this).parents(".collapsible-block").toggleClass("collapsible-block-collapsed");
    });
  });
});