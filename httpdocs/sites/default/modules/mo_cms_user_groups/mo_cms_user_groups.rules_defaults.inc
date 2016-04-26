<?php
/**
 * @file
 * mo_cms_user_groups.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function mo_cms_user_groups_default_rules_configuration() {
  $items = array();
  $items['rules_group_approval_notification'] = entity_import('rules_config', '{ "rules_group_approval_notification" : {
      "LABEL" : "Group Approval Notification",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "mimemail" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "mo_cms_user_group" : "mo_cms_user_group" } }
          }
        },
        { "NOT data_is" : { "data" : [ "node-unchanged:status" ], "value" : "1" } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "new-group-approval",
            "to" : "\\u003C?php\\r\\n$result = db_select(\\u0027users\\u0027, \\u0027u\\u0027);\\r\\n$result-\\u003Efields(\\u0027u\\u0027, array(\\u0027mail\\u0027));\\r\\n$result-\\u003Econdition(\\u0027uid\\u0027, $node_unchanged-\\u003Euid, \\u0027=\\u0027);\\r\\n$value = $result-\\u003Eexecute()-\\u003EfetchField();\\r\\necho $value;\\r\\n?\\u003E",
            "subject" : "Approved! [node:title] 100MissouriMiles.com Group has been created.",
            "body" : "\\u003Ctable width=\\u0022640\\u0022 cellspacing=\\u00220\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd\\u003E\\u003Cimg alt=\\u0022100 Missouri Miles Header\\u0022  src=\\u0022http:\\/\\/greatoutdoorsri.com\\/sites\\/default\\/themes\\/hundred_missouri_miles\\/img\\/100-mile-email-header.jpg\\u0022 width=\\u0022640\\u0022 height=\\u0022105\\u0022\\u003E\\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd cellpadding=\\u002220\\u0022\\u003E\\r\\n\\r\\n\\u003Cdiv style=\\u0022padding: 20px;\\u0022\\u003E\\r\\n\\u003Ch1 style=\\u0022font-size: 18px\\u0022\\u003EWelcome, [node:title]\\u003C\\/h1\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThank you for suggesting that we create a Group for [node:title].  After review, we were happy to create this Group for you.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can now join this group at [node:url] and share your progress toward your 100 Missouri Miles goal.  It\\u0027s great that you are getting active with your friends, family, organizations, clubs and teams; please share this link with others you would like to invite to this Group!  Being active with friends helps keep you motivated, and it just makes it more fun!\\u003Cp\\u003E\\r\\n\\r\\n\\u003Cp\\u003EOur lovely state of Missouri has thousands of miles of award winning trails to explore, and we look forward to seeing members of the [node:title] Group on the trail.  Don\\u0027t forget to log your miles!\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E- 100 Missouri Miles Team\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EShare your progress with us on \\u003Ca href=\\u0022http:\\/\\/www.facebook.com\\/100momiles\\u0022\\u003EFacebook\\u003C\\/a\\u003E or \\u003Ca href=\\u0022http:\\/\\/www.twitter.com\\/100momiles\\u0022\\u003ETwitter\\u003C\\/a\\u003E with \\u003Ca href=\\u0022http:\\/\\/www.tagboard.com\\/100momiles\\u0022\\u003E#100MoMiles\\u003C\\/a\\u003E!\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd\\u003E\\u003Cimg src=\\u0022http:\\/\\/greatoutdoorsri.com\\/sites\\/default\\/themes\\/hundred_missouri_miles\\/img\\/100-email-footer.gif\\u0022 alt=\\u0022\\u0022 width=\\u0022640\\u0022 height=\\u0022173\\u0022 border=\\u00220\\u0022\\u003E\\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd align=\\u0022center\\u0022\\u003E\\u003Cp\\u003E\\u003Ca href=\\u0022http:\\/\\/greatoutdoorsri.com\\/dashboard\\u0022\\u003ELog Your Miles\\u003C\\/a\\u003E | \\u003Ca href=\\u0022http:\\/\\/greatoutdoorsri.com\\/dashboard\\u0022\\u003EView Leaderboard\\u003C\\/a\\u003E | \\u003Ca href=\\u0022http:\\/\\/greatoutdoorsri.com\\/user\\/20\\/edit\\u0022\\u003EUnsubscribe\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n      \\u003Cp\\u003EOur Partners: \\u003Cbr\\u003E\\r\\n      \\u003Ca href=\\u0022http:\\/\\/health.mo.gov\\u0022\\u003EMissouri Department of Health \\u0026amp; Senior Services\\u003C\\/a\\u003E | \\u003Ca href=\\u0022http:\\/\\/mostateparks.com\\u0022\\u003EMissouri State Parks\\u003C\\/a\\u003E | \\u003Ca href=\\u0022http:\\/\\/www.mchcp.org\\/statemembers\\/striveforwellness\\u0022\\u003EStrive for Wellness\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n    \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n",
            "plaintext" : "Thank you for suggesting that we create a Group for [node:title].  After review, we were happy to create this Group for you.\\r\\n\\r\\nYou can now join this group at [node:url] and share your progress toward your 100 Missouri Miles goal. It\\u0027s great that you are getting active with your friends, family, organizations, clubs and teams; please share this link with others you would like to invite to this Group!  Being active with friends helps keep you motivated, and it just makes it more fun!\\r\\n\\r\\nOur lovely state of Missouri has thousands of miles of award winning trails to explore, and we look forward to seeing members of the [node:title] Group on the trail.  Don\\u0027t forget to log your miles!\\r\\n\\r\\n- 100 Missouri Miles Team"
          }
        }
      ]
    }
  }');
  $items['rules_new_group_request_notification'] = entity_import('rules_config', '{ "rules_new_group_request_notification" : {
      "LABEL" : "New Group Request Notification",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "mo_cms_user_group" : "mo_cms_user_group" } }
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : {
                "3" : "3",
                "5" : "5",
                "4" : "4",
                "7" : "7",
                "6" : "6",
                "8" : "8",
                "11" : "11",
                "10" : "10",
                "12" : "12"
              }
            },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3", "12" : "12" } },
            "subject" : "New group request at 100MissouriMiles.com: [node:title]",
            "message" : "\\u003Cp\\u003EPlease review the following requested group:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[node:title]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can edit the group directly here: [node:edit-url]\\u003Cbr\\u003E\\r\\nOr you may view an overview of groups pending approval here: https:\\/\\/[site:url-brief]\\/admin\\/groups\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ENote that in either case, if you do not already have an active session open with the site, you will be redirected to the login page.\\u003C\\/p\\u003E"
          }
        },
        { "redirect" : { "url" : "groups\\/directory", "force" : 0 } }
      ]
    }
  }');
  return $items;
}
