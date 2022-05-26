--TEST--
H3\H3Index::toCenterChild() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$child = $h3->toCenterChild(7);

var_dump($child->toString());
?>
--EXPECTF--
string(%d) "872834700ffffff"
