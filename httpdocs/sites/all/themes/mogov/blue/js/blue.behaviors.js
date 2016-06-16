/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.add_icons = {
    attach: function(context, settings) {
      
      // Add pdf icons to pdf links
      $('a[href$=".pdf"],.pdf').once('add-icons', function() {
        $(this).append("<span class='pdf-label'><b class='hide'>PDF Document</b></span>");
      });
    
      // Add xls icons to excel links (xls, xlsx)
      $("a[href$='.xls'], a[href$='.xlsx'],.xls").once('add-icons', function() {
        $(this).append("<span class='xls-label'><b class='hide'>Excel Spreadsheet</b></span>");
      });
    
      // Add doc icons to word links (doc, docx, txt)
      $("a[href$='.doc'], a[href$='.docx'], a[href$='.txt'],.doc").once('add-icons', function() {
        $(this).append("<span class='doc-label'><b class='hide'>Word Document</b></span>");
      });
    
      //Add icons to powerpoint links (ppt, pptx)
      $("a[href$='.ppt'], a[href$='.pptx'],.ppt").once('add-icons', function() {
        $(this).append("<span class='ppt-label'><b class='hide'>Powerpoint Presentation</b></span>");
      });
      
      // Add icons to compressed files (zip, gzip, 7zip)
      $("a[href$='.zip'], a[href$='.gzip'], a[href$='.rar'],.zip").once('add-icons', function() {
        $(this).append("<span class='zip-label'><b class='hide'>Compressed Archive</b></span>");
      });
      
      // Add icons to XML files (xml)
      $("a[href$='.xml'],.xml").once('add-icons', function() {
        $(this).append("<span class='xml-label'><b class='hide'>XML Document</b></span>");
      });
                      
      $("a.external:has(img) .external-link, #connect:has('.external') .external-link, #toolbar:has('.external') .external-link, a.pdf:has(img) .pdf-label, a.xls:has(img) .xls-label, a.doc:has(img) .doc-label, .share-container ul li .external-link, a.rss .xml-label").remove();
  
    }
  };
  
  Drupal.behaviors.support_details = {
    attach: function(context, settings) {
      // Run the jQuery details script
      $('details').once('support-details', function() {
        $(this).details();
      });
    }
  };

})(jQuery, Drupal, this, this.document);
