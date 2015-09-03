<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Implements hook_views_data().
 */
function my_view_views_data() {

  $data = array();

  $data['person_details']['table']['group'] = t('Person Details');

  $data['person_details']['table']['base'] = array(
    'title' => t('Person Details'),
    'help' => t('Contains records we want person_details to Views.'),
  );
  $data['person_details']['pid'] = array(
    'title' => t('Peson ID'),
    'help' => t('The Person Record ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  $data['person_details']['person_name'] = array(
    'title' => t('Person Name'),
    'help' => t('The Personal Name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  $data['person_details']['age'] = array(
    'title' => t('Person Age'),
    'help' => t('The Person Age.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  $data['person_details']['mobile_no'] = array(
    'title' => t('Person Mobile No.'),
    'help' => t('The Person Mobile Number.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  return $data;
}
