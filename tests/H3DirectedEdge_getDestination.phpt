--TEST--
H3\H3DirectedEdge::getDestination() Test
--EXTENSIONS--
h3
--FILE--
<?php
$edge = \H3\H3DirectedEdge::fromString('115283473fffffff');
$destination = $edge->getDestination();

var_dump($destination->toString());
?>
--EXPECTF--
string(%d) "85283477fffffff"
