/**
 * @file
 * JavaScript behaviors for options (admin) elements.
 */

(function ($, Drupal) {

  'use strict';


  /**
   * Attach handlers to options (admin) element.
   *
   * @type {Drupal~behavior}
   */
  Drupal.behaviors.webformOptionsAdmin = {
    attach: function (context) {
      $(context).find('.js-form-type-webform-options .js-webform-options-value').once('webform-options-value').each(function() {
        // Target input name and not id because the id will be changing via
        // Ajax callbacks.
        var name = this.name;

        var $value = $(this);
        var $text = $('input[name="' + name.replace(/\[value\]$/, '[text]') + '"]');

        // On focus, determine if option value and option text are in-sync.
        $value.on('focus', function () {
          var sync = $value.val() === $text.val();
          $value.data('webform_options_sync', sync);
          if (sync) {
            $text.prop('readonly', true).closest('.js-form-item, .js-form-wrapper').addClass('webform-readonly');
          }
        });

        // On blur, if option value and option text are in-sync remove readonly.
        $value.on('blur', function () {
          if ($value.data('webform_options_sync')) {
            $text.prop('readonly', false).closest('.js-form-item, .js-form-wrapper').removeClass('webform-readonly');
          }
        });

        // On keyup, if option value and option text are in-sync then set
        // option text to option value.
        $value.on('keyup', function () {
          if ($value.data('webform_options_sync')) {
            $text.val($value.val());
          }
        });

      })
    }
  };


})(jQuery, Drupal);
;
/**
 * @file
 * JavaScript behaviors for message element integration.
 */

(function ($, Drupal) {

  'use strict';

  /**
   * Move show weight to after the table.
   *
   * @type {Drupal~behavior}
   */
  Drupal.behaviors.webformMultiple = {
    attach: function (context, settings) {
      for (var base in settings.tableDrag) {
        if (settings.tableDrag.hasOwnProperty(base)) {
          var $tableDrag = $(context).find('#' + base);
          var $toggleWeight = $tableDrag.parent().find('.tabledrag-toggle-weight');
          $toggleWeight.addClass('webform-multiple-tabledrag-toggle-weight');
          $tableDrag.after($toggleWeight);
        }
      }
    }
  };

})(jQuery, Drupal);
;