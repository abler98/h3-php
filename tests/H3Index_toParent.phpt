--TEST--
H3\H3Index::toParent() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$parent = $h3->toParent(4);

var_dump($parent->toString());
?>
--EXPECTF--
string(%d) "8428347ffffffff"
