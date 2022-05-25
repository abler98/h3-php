--TEST--
H3\GeoCoord::__construct() Test
--EXTENSIONS--
h3
--FILE--
<?php
$geo = new \H3\GeoCoord(49.99185845731755, 36.24805297746707);

var_dump($geo->getLat());
var_dump($geo->getLon());
?>
--EXPECT--
float(49.99185845731755)
float(36.24805297746707)
