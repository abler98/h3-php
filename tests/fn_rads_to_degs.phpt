--TEST--
H3\rads_to_degs() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\rads_to_degs(3.14159));
?>
--EXPECT--
float(179.9998479605043)
