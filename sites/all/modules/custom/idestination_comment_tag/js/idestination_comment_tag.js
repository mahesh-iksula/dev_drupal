(function ($) {
    Drupal.behaviors.idestination_comment_tag = {
        attach: function (context, settings) {
            var start = /@/ig; // @ Match
            var word = /@(\w+)/ig; //@abc Match
            var drop_down = jQuery("#typeahead-dropdown");
            jQuery("#edit-comment-body-und-0-value").once().keyup(function () {
                var content = jQuery(this).val(); //Content Box Data
                
                var go = content.match(start); //find Content Matching @
                var name = content.match(word); //Content Matching @abc
                //console.log('go = '+ go);
                //console.log('name = ' + name);
                
//                if (name != null && name.length > 0)
//                {   
//                    var tmp_go = go.toString();
//                    var res_go = tmp_go.split(",");
//                    
//                    var tmp = name.toString();
//                    var res = tmp.split(",");
//                    name = res[res_go.length - 1];
//                    console.log('res = '+res[res_go.length - 1]);
//                }
                
                var dataString = 'count=10&searchword=' + name;
                
                //If @ available
                if (go != null && go.length > 0) {
                    //console.log('@ enter');
                    //if @abc avalable
                    if (name != null && name.length > 0)
                    {
                        //console.log('enter text after @');
                        jQuery.ajax({
                            type: "GET",
                            url: "http://localhost/des/typehead/json", // Database name search 
                            data: dataString,
                            cache: false,
                            success: function (data)
                            {
                                drop_down.html(data).show();
                            }
                        });
                    }
                    else {
                        //console.log('@ present but no text after @');
                        drop_down.html('').hide();
                    }
                }
                else{
                    //console.log('@ not present');
                }
            });
            jQuery(document).on("click", ".js-nav", function () {
                var first_name = jQuery(this).attr('data-fn');
                var last_name = jQuery(this).attr('data-ln');
                var search_key = jQuery(this).attr('data-search-query');
                var old = jQuery("#edit-comment-body-und-0-value").val();
                var content = old.replace('@' + search_key, '#' + first_name + '_' + last_name + ' ');
                jQuery("#edit-comment-body-und-0-value").val(content).focus();
                drop_down.html('').hide();
            });
        }
    };
})(jQuery);

