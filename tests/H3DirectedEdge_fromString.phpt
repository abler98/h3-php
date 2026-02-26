--TEST--
H3\H3DirectedEdge::fromString() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = \H3\H3DirectedEdge::fromString('115283473fffffff');

var_dump($h3->toString());
?>
--EXPECTF--
string(%d) "115283473fffffff"
