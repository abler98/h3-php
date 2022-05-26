--TEST--
H3\H3Index::toString() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);

var_dump($h3->toString());
?>
--EXPECTF--
string(%f) "85283473fffffff"
