--TEST--
H3\H3UniEdge::fromString() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = \H3\H3UniEdge::fromString('115283473fffffff');

var_dump($h3->toString());
?>
--EXPECTF--
string(%d) "115283473fffffff"
