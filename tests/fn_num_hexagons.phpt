--TEST--
H3\num_hexagons() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\num_hexagons(8));
?>
--EXPECT--
int(691776122)
