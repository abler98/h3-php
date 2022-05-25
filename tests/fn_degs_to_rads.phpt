--TEST--
H3\degs_to_rads() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\degs_to_rads(45));
?>
--EXPECT--
float(0.7853981633974483)
