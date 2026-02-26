--TEST--
H3\H3DirectedEdge::getOrigin() Test
--EXTENSIONS--
h3
--FILE--
<?php
$edge = \H3\H3DirectedEdge::fromString('115283473fffffff');
$origin = $edge->getOrigin();

var_dump($origin->toString());
?>
--EXPECTF--
string(%d) "85283473fffffff"
