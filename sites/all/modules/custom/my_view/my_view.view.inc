<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * Implements hook_views_data().
 */
function my_view_data()
{

    $data = array();
    
    

    $data['person_details']['table']['group'] = t('Exposed');

    $data['person_details']['table']['base'] = array(
        'title' => t('Exposed'),
        'help' => t('Contains records we want person_details to Views.'),
    );

    return $data;

}

