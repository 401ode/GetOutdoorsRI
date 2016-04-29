function update_block(selector, delta) {
    jQuery(selector).addClass('ajax-updating');
    var url = '/ajax/block_content/' + delta;
    jQuery.ajax({
        url : url,
        success : function(data) {
            jQuery(selector).html(data);
            if (jQuery("edit-date input").length) {
                jQuery(selector).find("#edit-date input").datepicker({dateFormat: "yy-mm-dd", maxDate: 0, changeYear: false});
            }
        }	
    });
    jQuery(selector).removeClass('ajax-updating');
}

function string_to_number(value) {
    return value.replace(/[^\d\.\-\ ]/g, '');
}

function update_counter_data(selector, old_mileage, new_mileage) {
    jQuery(selector).attr({
        'data-from': old_mileage,
        'data-to': new_mileage
    });
    animated_update(selector, old_mileage, new_mileage);
}

function animated_update(selector, old_mileage, new_mileage) {
    jQuery(selector).countTo({
        speed: 500,
        refreshInterval: 50,
        formatter: function (value, options) {
            return Math.round(value).toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
        }
    });
}

function get_user_dashboard_stats(mode) {
    mode = typeof mode !== 'undefined' ? mode : 'short';
    var url = '/ajax/user_current_stats.json';
    jQuery.ajax({
        url : url,
        dataType: 'json',
        success : function(data) {
            update_user_dashboard_stats(data, mode);
        }	
    });
}

function update_user_dashboard_stats(data, mode) {
    jQuery("#global-stats-total .missouri-total-mileage").html(data['total']);
    jQuery("#user-stats-challenge-mileage .mileage .value").html(data['user_challenge_total']);
    jQuery("#user-stats-total-mileage .mileage .value").html(data['user_total']);
    if (mode == 'full') {
        var activities = [
          'running',
          'walking',
          'hiking',
          'rolling',
          'cycling',
          'paddling',
          'riding',
          'swimming',
          'skating',
          'geocaching'
        ];
        var period_keys = {
          'user_total_': '.total',
          'user_30day_': '.user-thirty',
          'avg_30day_': '.avg-thirty',
          'leader_30day_': '.leader-thirty'
        };
        for (var i in activities) {
          var activity = activities[i];
          var key = 'user_total_' + activity;
          if (data.hasOwnProperty(key)) {
            for (var key_base in period_keys) {
              var period_key = key_base + activity;
              var selector = '.leaderboard-activity-stats.' + activity + ' ' + period_keys[key_base] + ' .mileage .value';
              jQuery(selector).html(data[period_key]);
            }
          }
        }
        jQuery(".pane-mo-project-upcoming-trophy .pane-content").html(data['upcoming_trophies']);
    }
}

function validate_date(date) {
    var currentTime = new Date();
    var curr_val = date;
    if(curr_val == '') {
        return false;
    }
    var date_patt = /^(\d{4})(\/|-)(\d{1,2})(\/|-)(\d{1,2})$/; 
    var date_array = curr_val.match(date_patt);
    if (date_array == null) {
        return false;
    }
    //Checks for mm/dd/yyyy format.
    var y = date_array[1];
    var m = date_array[3];
    var d = date_array[5];

    if (m < 1 || m > 12) {
        return false;
    } else if (d < 1 || d > 31) {
        return false;
    } else if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) {
        return false;
    } else if (m == 2) {
        var is_leap_year = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > 29 || (d == 29 && !is_leap_year)) {
            return false;
        }
    }
    
    //Checks for within date range of June 1 to today or December 31 of this year, whichever is sooner 
    if (y < 2013 || y > currentTime.getFullYear()) {
        return false;
    } else if (m < 6 && y == 2013) {
        return false;
    } else if ((m == currentTime.getMonth) && (d > currentTime.getDay() )) {
        return false;
    }
    
    return true;
}

function numberWithCommas(x) {
    return x.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

function display_message(message, type, share_buttons) {
    type = typeof type !== 'undefined' ? type : 'notification';
    share_buttons = typeof share_buttons !== 'undefined' ? share_buttons : false;
    if (share_buttons) {
         message = message + '<br>(share buttons here)';
    }
    message = '<div class="message ' + type + '"><div class="message-close" title="dismiss message"></div>' + message + '</div>';
    jQuery(message).hide().prependTo('#messages-content').fadeIn('slow');
}

jQuery(document).ready(function($) {
    $('.counter').countTo({
        speed: 1000,
        refreshInterval: 50,
        formatter: function (value, options) {
            return Math.round(value).toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
        }
    });
    $.ajaxSetup({ cache: false });
    $(".message-close").live("click", function(e) {
        $(this).parent('.message').fadeOut(250, function() {
            $(this).remove();
        });
    });
    $("#mo-project-add-mileage-form #submit-mileage").live("click", function(e) {

        $(".invalid-message").remove();
        e.preventDefault();
        var validated = true;
        $(".form-item-date").removeClass("invalid");
        var date = $("#edit-date-datepicker-popup-0").val();
        if (!validate_date(date)) {
            $(".form-item-date").addClass("invalid");
            display_message("Must be a valid date in the format YYYY-MM-DD.", 'warning');
            validated = false;
        }
        $(".form-item-distance").removeClass("invalid");
        var miles = $("#edit-distance").val();
        if (!miles || miles <= 0 || miles > 600 || isNaN(miles)) {
          alert(miles);
            $(".form-item-distance").addClass("invalid");
            display_message("Must be a number greater than zero and less than or equal to 600; decimals permitted.", 'warning');
            validated = false;
        }

        var congrats_all = new Array("A fine job, ", "Awesome, ", "Be proud, ", "Bravo, ", "Congrats, ", "Fantastic, ", "Good for you, ", "Good effort, ", "Good work, ", "Great going, ", "High five, ", "Impressive, ", "Keep it up, ", "Look at you go, ", "Nice job, ", "Outstanding, ", "Right on, ", "Super, ", "Terrific, ", "WOW, ", "Way to go, ", "Well done, ", "YAY, ", "You did it, ", "You're doing great, ");
        // Get a 'random' congratulations message
        var congrats = congrats_all[Math.floor(Math.random() * congrats_all.length)];
        var buddy = $('#mo-project-add-mileage-form #edit-subuser option:selected').text();
        var type = $('#mo-project-add-mileage-form #edit-subuser option:selected').val();
        if (type.indexOf("|")!=-1) {
          var buddy_class = type.split("|");
          buddy_class[1] = buddy_class[1] + ' notification';
        }
        var activity = $('#edit-activity option:selected').text();        
        var unit = $('#edit-units option:selected').text();
        switch(activity) {
          case "Running":
            activity = "ran";
            break;
          case "Walking":
            activity = "walked";
            break;
          case "Hiking":
            activity = "hiked";
            break;
          case "Geocaching":
            activity = "geocached";
            break;
          case "Rolling":
            activity = "rolled";
            break;
          case "Cycling":
            activity = "cycled";
            break;
          case "Paddling":
            activity = "paddled";
            break;
          case "Riding":
            activity = "rode";
            break;
          case "Swimming":
            activity = "swam";
            break;
          case "Skating":
            activity = "skated";
            break;
          default:
            activity = "logged";
        }
        switch(unit) {
          case "Km":
            unit = "kilometer";
            break;
          case "Mi":  
          default:
            unit = "mile";
        }
        var d_array = date.split("-");
        var us_date = d_array[1] + '/' + d_array[2] + '/' + d_array[0];
        
        if (validated) {
            offset = jQuery('#messages-content').offset();
            offsetTop = offset.top - 70;
            $('html, body').animate({
                scrollTop: offsetTop
            }, 500);
            
            $.ajax({
                type: "POST",
                url: "/ajax/submit_mileage",
                data: $("#mo-project-add-mileage-form").serialize(),
                success: function(data) {
                    $("#edit-distance").val("");
                    var pathname = window.location.pathname;
                    if (pathname == '/dashboard') {
                        get_user_dashboard_stats('full');
                    } else if (pathname == '/') {
                        get_user_dashboard_stats();
                    }
                    
                    //display_message('Congrats, Buddy! You activitied amount miles/kilometers on date.');
                    var $mile_message = congrats + buddy +'! You '+ activity +' '+ miles +' '+ unit; 
                    if (miles != 1) {
                      //Plural miles/kilometers
                      $mile_message = $mile_message +'s on '+ us_date +'.';
                    } else {
                      //Singular mile/kilometer
                      $mile_message = $mile_message +' on '+ us_date +'.';
                    }
                    if (typeof buddy_class[1] === 'undefined') {
                      display_message($mile_message);
                    }
                    else {
                      if (buddy_class[1] != 'Me') {
                        display_message($mile_message, buddy_class[1]);
                      }
                      else {
                        display_message($mile_message);
                      }
                    }

                    $.each(data, function(i, badge) {
                        display_message(badge);                        
                    });
                }
            });
        }
        return false;
    });
    $("#mo-project-add-mileage-form-mobile #submit-mileage-mobile").live("click", function(e) {

        $(".invalid-message").remove();
        e.preventDefault();
        var validated = true;
        $(".form-item-date").removeClass("invalid");
        var date = $("#edit-date-mobile-datepicker-popup-0").val();
        if (!validate_date(date)) {
            $(".form-item-date").addClass("invalid");
            display_message("Must be a valid date in the format YYYY-MM-DD.", 'warning');
            validated = false;
        }
        $(".form-item-distance").removeClass("invalid");
        var miles = $("#edit-distance-mobile").val();
        if (!miles || miles <= 0 || miles > 600 || isNaN(miles)) {
          alert(miles);
            $(".form-item-distance").addClass("invalid");
            display_message("Must be a number greater than zero and less than or equal to 600; decimals permitted.", 'warning');
            validated = false;
        }

        var congrats_all = new Array("A fine job, ", "Awesome, ", "Be proud, ", "Bravo, ", "Congrats, ", "Fantastic, ", "Good for you, ", "Good effort, ", "Good work, ", "Great going, ", "High five, ", "Impressive, ", "Keep it up, ", "Look at you go, ", "Nice job, ", "Outstanding, ", "Right on, ", "Super, ", "Terrific, ", "WOW, ", "Way to go, ", "Well done, ", "YAY, ", "You did it, ", "You're doing great, ");
        // Get a 'random' congratulations message
        var congrats = congrats_all[Math.floor(Math.random() * congrats_all.length)];
        var buddy = $('#edit-subuser-mobile option:selected').text();
        var type = $('#edit-subuser option:selected').val();
        if (type.indexOf("|")!=-1) {
          var buddy_class = type.split("|");
          buddy_class[1] = buddy_class[1] + ' notification';
        }
        var activity = $('#edit-activity-mobile option:selected').text();
        var unit = $('#edit-units-mobile option:selected').text();
        switch(activity) {
          case "Running":
            activity = "ran";
            break;
          case "Walking":
            activity = "walked";
            break;
          case "Hiking":
            activity = "hiked";
            break;
          case "Geocaching":
            activity = "geocached";
            break;
          case "Rolling":
            activity = "rolled";
            break;
          case "Cycling":
            activity = "cycled";
            break;
          case "Paddling":
            activity = "paddled";
            break;
          case "Riding":
            activity = "rode";
            break;
          case "Swimming":
            activity = "swam";
            break;
          case "Skating":
            activity = "skated";
            break;
          default:
            activity = "logged";
        }
        switch(unit) {
          case "Km":
            unit = "kilometer";
            break;
          case "Mi":  
          default:
            unit = "mile";
        }
        var d_array = date.split("-");
        var us_date = d_array[1] + '/' + d_array[2] + '/' + d_array[0];
        
        if (validated) {
            offset = jQuery('#messages-content').offset();
            offsetTop = offset.top - 70;
            $('html, body').animate({
                scrollTop: offsetTop
            }, 500);
            
            $.ajax({
                type: "POST",
                url: "/ajax/submit_mileage",
                data: $("#mo-project-add-mileage-form-mobile").serialize(),
                success: function(data) {
                    $("#edit-distance-mobile").val("");
                    var pathname = window.location.pathname;
                    if (pathname == '/dashboard') {
                        get_user_dashboard_stats('full');
                    } else if (pathname == '/') {
                        get_user_dashboard_stats();
                    }
                    
                    //display_message('Congrats, Buddy! You activitied amount miles/kilometers on date.');
                    var $mile_message = congrats + buddy +'! You '+ activity +' '+ miles +' '+ unit; 
                    if (miles != 1) {
                      //Plural miles/kilometers
                      $mile_message = $mile_message +'s on '+ us_date +'.';
                    } else {
                      //Singular mile/kilometer
                      $mile_message = $mile_message +' on '+ us_date +'.';
                    }
                    if (typeof buddy_class[1] === 'undefined') {
                      display_message($mile_message);
                    }
                    else {
                      if (buddy_class[1] != 'Me') {
                        display_message($mile_message, buddy_class[1]);
                      }
                      else {
                        display_message($mile_message);
                      }
                    }

                    $.each(data, function(i, badge) {
                        display_message(badge);
                    });
                }
            });
        }
        return false;
    });
    
    $("#convert-activity").live("click", function(e) {
        $(".convert-message").remove();
        e.preventDefault();
        var validated = true;
        $("#mo-project-activity-converter-form .form-item-activity").removeClass("invalid")
        var activity = $("#mo-project-activity-converter-form .form-item-activity select").val();
        $("#mo-project-activity-converter-form .form-item-time").removeClass("invalid")
        var time = $("#mo-project-activity-converter-form .form-item-time input").val();
        if (!time || time <= 0 || isNaN(time)) {
            $("#mo-project-activity-converter-form .form-item-time").addClass("invalid");
            display_message("Must be a number greater than zero; decimals permitted.", 'warning');
            validated = false;
        }
        if (validated) {
            $.post("/ajax/convert_activity", $("#mo-project-activity-converter-form").serialize(), function(data) {
                $("#mo-project-activity-converter-form .form-item-time input").val("");
                $("#activity-converter-results").html(data.text);
                if ($("#mo-project-add-mileage-form").length) {
                    $("#mo-project-add-mileage-form #edit-distance").val(data.mileage);
                    $("#mo-project-add-mileage-form #edit-activity").val(data.tid);
                }
            });
        }
        return false;
    });
    $("#calculate-calories").live("click", function(e) {
        $(".calculate-calories-message").remove();
        e.preventDefault();
        var validated = true;
        $("#mo-project-calories-calculator-form .form-item-activity").removeClass("invalid")
        var activity = $("#mo-project-calories-calculator-form .form-item-activity select").val();
        $("#mo-project-calories-calculator-form .form-item-time").removeClass("invalid")
        var time = $("#mo-project-calories-calculator-form .form-item-time input").val();
        if (!time || time <= 0 || isNaN(time)) {
            $("#mo-project-calories-calculator-form .form-item-time").addClass("invalid");
            display_message("Must be a number greater than zero; decimals permitted.", 'warning');
            validated = false;
        }
        $("#mo-project-calories-calculator-form .form-item-weight").removeClass("invalid")
        var weight = $("#mo-project-calories-calculator-form .form-item-weight input").val();
        if (!weight || weight <= 0 || isNaN(weight)) {
            $("#mo-project-calories-calculator-form .form-item-weight").addClass("invalid");
            display_message("Must be a number greater than zero; decimals permitted.", 'warning');
            validated = false;
        }
        if (validated) {
            $.post("/ajax/calculate_calories", $("#mo-project-calories-calculator-form").serialize(), function(data) {
                $("#mo-project-calories-calculator-form .form-item-time input").val("");
                $("#calorie-calculator-results").html(data);
            });
        }
        return false;
    });
    $("#convert-km").live("click", function(e) {
        $(".convert-km-message").remove();
        e.preventDefault();
        var validated = true;
        $("#mo-project-calories-calculator-form .form-item-activity").removeClass("invalid")
        var km = $("#mo-project-km-to-miles-converter-form .form-item-km input").val();
        if (!km || km <= 0 || isNaN(km)) {
            $("#mo-project-calories-calculator-form .form-item-km").addClass("invalid");
            display_message("Must be a number greater than zero; decimals permitted.", 'warning');
            validated = false;
        }
        if (validated) {
            $.post("/ajax/convert_km", $("#mo-project-km-to-miles-converter-form").serialize(), function(data) {
                $("#mo-project-km-to-miles-converter-form .form-item-km input").val("");
                $("#km-converter-results").html(data);
            });
        }
        return false;
    });
    $(".toggle-link").live("click", function(e) {
        e.preventDefault();
        $(this).next('.toggle-content').slideToggle();
    });
    var updateRows = function() {
        var rows = $(".view-trails .views-table tbody tr");
        rows.each(function(index) {
            if (index % 2 == 0) {
                $(this).unbind('click').click(function() {
                    $($(".view-trails .views-table tbody tr")[index + 1])
                     .toggle();
                });
            } else {
                // hide secondary rows
                $(this).css('display', 'none');
            }
        });
    }
    updateRows();
    $(document).on('infiniteScrollComplete', updateRows);

    $("#edit-submit-trails").click(function() {
        $("#views-exposed-form-trails-panel-pane-1").submit();
    });
});
