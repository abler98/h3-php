--TEST--
H3\hex_area() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\hex_area(8, H3_AREA_UNIT_KM));
var_dump(\H3\hex_area(8, H3_AREA_UNIT_M));
?>
--EXPECT--
float(0.7373276)
float(737327.6)
