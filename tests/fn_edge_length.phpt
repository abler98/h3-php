--TEST--
H3\edge_length() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\edge_length(8, H3_AREA_UNIT_KM));
var_dump(\H3\edge_length(8, H3_AREA_UNIT_M));
?>
--EXPECT--
float(0.461354684)
float(461.3546837)
