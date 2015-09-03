<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * This function check the query string from url and validate using webservice and 
 * do the auto-login for currosponding drupal user.
 * @global type $user
 * @return string
 */
function bbd_multilink_callback() {
  $parameters = drupal_get_query_parameters();
  
  if (!isset($parameters['Data']) || empty($parameters['Data'])) {
    return "Oops! Query String Missing";
  }
  $str = str_replace(" ", "+", $parameters['Data']);
  try {
    $client = new SoapClient("http://updation.biz-solutionz.com/MOSService.asmx?op=Decryption&WSDL");
    $params = new stdClass();
    $params->MerchantID = "BIG017BZR";
//    $params->EncryptedString = "yYHKXDW6UZUkhhwVBpWT7fJlewxmr+0UwPibVbgchgdfL8PDcStNoYoTs4bnOVUK";
    $params->EncryptedString = $str;
    $result = $client->Decryption($params)->DecryptionResult;
//    dpm($result);

    switch ($result) {
      case "Invalid MerchantID":
        $login_status = false;
        break;
      case "Error":
        $login_status = false;
        break;
      default:
        $exp_res = explode("|", $result);
        if (count($exp_res) >= 3) {
          //if array legth less than or equal to 3 then validate agent id,email fields.
          if (ctype_alnum($exp_res[0]) && filter_var($exp_res[1], FILTER_VALIDATE_EMAIL)) {
            // All details are validated
            $login_status = true;
          }
          else {
            //Validation failed
            $login_status = false;
          }
        }
        else {
          // array length is less tahan 3 then return false
          $login_status = false;
        }

        break;
    }
//    dpm($exp_res);
    if ($login_status) {
      // all creadiatials are valid make autologin for currosponding user
      global $user;
      $user = user_load(1);
      drupal_session_regenerate();
//      drupal_goto('user');
      $output = "Successful Login in BigBazzar Portal.";
      return $output;
    }
    else {
      // crediantisals are not valid display error message
      watchdog('bbof_alliance_error', '<pre>' . print_r($result, TRUE) . '</pre>');
      return $result;
    }
  }
  catch (SoapFault $fault) {

//    return "SOAP Fault: (faultcode: {$fault->faultcode}, faultstring: {$fault->faultstring})";

    return ("Something Wrong with SOAP Webservice ");
  }
}
