<?php

/**
 * @file
 * Options alter hooks.
 */

use Drupal\webform\Utility\WebformOptionsHelper;
use Drupal\Core\Locale\CountryManager;
use Drupal\Core\Language\LanguageManager;

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 *
 * @see config/install/webform.webform.example_options.yml
 */
function webform_webform_options_range_alter(array &$options, array $element = []) {
  $element += [
    '#min' => 1,
    '#max' => 100,
    '#step' => 1,
    '#pad_length' => NULL,
    '#pad_str' => 0,
  ];

  $options = WebformOptionsHelper::range(
    $element['#min'],
    $element['#max'],
    $element['#step'],
    $element['#pad_length'],
    $element['#pad_str']
  );
}

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 */
function webform_webform_options_time_zones_alter(array &$options, array $element = []) {
  if (empty($options)) {
    $options = system_time_zones();
  }
}

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 */

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
*/
 function webform_webform_options_country_names_alter(array &$options, array $element = []) {
  if (empty($options)) {
    $countries = CountryManager::getStandardList();
    $options = array_combine($countries, $countries);
  }
 }

 

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 */
function webform_webform_options_languages_alter(array &$options, array $element = []) {
  if (empty($options)) {
    $languages = LanguageManager::getStandardLanguageList();
    unset($languages['en-x-simple']);
    $options = [];
    foreach ($languages as $language) {
      $options[$language[0]] = $language[0];
    }
  }
}



/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 */
function webform_webform_options_country_codes_alter(array &$options, array $element = []) {
  $options=[];
$sql = "SELECT DISTINCT CountryName, CountryISO2Code FROM ircs_locationref where CountryISO2Code NOT LIKE 'UN' and CountryISO2Code NOT LIKE 'GO' and CountryISO2Code NOT LIKE 'IA' and CountryISO2Code NOT LIKE 'IC' and CountryISO2Code NOT LIKE 'OR' and CountryISO2Code NOT LIKE 'OT' and CountryISO2Code NOT LIKE 'RF' and CountryISO2Code NOT LIKE 'AB' and CountryISO2Code NOT LIKE 'RA' and CountryISO2Code NOT LIKE 'AP' and CountryISO2Code NOT LIKE 'CB' and CountryISO2Code NOT LIKE 'RC' and CountryISO2Code NOT LIKE 'RL' and CountryISO2Code NOT LIKE 'PC' ORDER BY CountryName ASC";
$results = db_query($sql);
while ($row = $results->fetchAssoc()) {
$options[$row['CountryISO2Code']] = $row['CountryName'];
  }
  
}

/**
 * Implements hook_webform_options_WEBFORM_OPTIONS_ID_alter().
 */
function webform_webform_options_state_province_codes_alter(array &$options, array $element = []) {
  $options=[];
$sql = "SELECT DISTINCT CntryDivISOCode, CntryDivName FROM ircs_locationref where  CntryDivISOCode !=''";
$results = db_query($sql);
while ($row = $results->fetchAssoc()) {
$options[$row['CntryDivISOCode']] = $row['CntryDivName'];
  }
  
}


