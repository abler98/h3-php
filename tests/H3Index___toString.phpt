--TEST--
H3\H3Index::__toString() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);

var_dump((string) $h3);
?>
--EXPECTF--
string(%f) "85283473fffffff"
