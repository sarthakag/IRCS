(function ($, Drupal)  {
  Drupal.behaviors.backLinks = {
    attach: function(context, settings) {
      $('a.back').bind('click', function() {
                 parent.history.back();
                return false;
            });

    }
  }
}) (jQuery, Drupal);
