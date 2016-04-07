<?php

$title2 = 'Public Case No. R 2010-015';
$title1 = 'Public Case No. R 2013-007';

$r1nums = array();
preg_match('/(\d+)\-(\d+)$/', $title1, $r1nums);
if (count($r1nums) == 3) {
  $r1num = (int) $r1nums[1] . $r1nums[2];
}

$r2nums = array();
preg_match('/(\d+)\-(\d+)$/', $title2, $r2nums);
if (count($r2nums) == 3) {
  $r2num = (int) $r2nums[1] . $r2nums[2];
}

if ($r1num >= $r2num) {
  print 0;
} else {
  print 1;
}

/*$r1_array = explode(' ', $row1->title);
$r2_array = explode(' ', $row2->title);
$r1_array = preg_grep('/.*?(\\d+)([-+]\\d+)/is', $r1_array);
$r2_array = preg_grep('/.*?(\\d+)([-+]\\d+)/is', $r2_array);
$r1 = array_pop($r1_array);
$r2 = array_pop($r2_array);

if($r1 > $r2) {
  return 1;
} else {
  return -1;
}

*/
?>