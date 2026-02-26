--TEST--
H3\H3DirectedEdge::getIndexes() Test
--EXTENSIONS--
h3
--FILE--
<?php
$edge = \H3\H3DirectedEdge::fromString('115283473fffffff');
$indexes = $edge->getIndexes();
[$origin, $destination] = $indexes;

var_dump(count($indexes));
var_dump($origin->toString());
var_dump($destination->toString());
?>
--EXPECTF--
int(2)
string(%d) "85283473fffffff"
string(%d) "85283477fffffff"
