<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function php_code_in_view_views_data() {
  $data =array();

  $data['php_code_in_view']['table']['group'] = t('View Php Module');
  $data['php_code_in_view']['table']['base'] = array(
    'field' => 'fname', //primary key
    'title' => t('View Php table'),
    'help' => t('View Php'),
    'weight' => 0,
  );
 $data['php_code_in_view']['name'] = array(
    'title' => t('View Name'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['php_code_in_view']['code'] = array(
    'title' => t('Views Php Code'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  

  return $data;
}