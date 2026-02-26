--TEST--
H3\rads_to_degs() Test
--EXTENSIONS--
h3
--FILE--
<?php
$a = new \H3\LatLng(49.994234091029305, 36.22137428545844);
$b = new \H3\LatLng(50.52939824963117, 30.521389130156102);

var_dump(\H3\point_dist($a, $b, H3_LENGTH_UNIT_KM));
var_dump(\H3\point_dist($a, $b, H3_LENGTH_UNIT_M));
var_dump(\H3\point_dist($a, $b, H3_LENGTH_UNIT_RADS));
?>
--EXPECT--
float(409.4233686756975)
float(409423.3686756975)
float(0.06426352334085315)
