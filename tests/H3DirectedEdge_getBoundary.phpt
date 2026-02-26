--TEST--
H3\H3DirectedEdge::getBoundary() Test
--EXTENSIONS--
h3
--FILE--
<?php
$edge = \H3\H3DirectedEdge::fromString('115283473fffffff');
$boundary = $edge->getBoundary();

var_dump(count($boundary->getVertices()));
var_dump($boundary->getVertices()[0]->getLat());
var_dump($boundary->getVertices()[0]->getLon());
var_dump($boundary->getVertices()[1]->getLat());
var_dump($boundary->getVertices()[1]->getLon());
?>
--EXPECT--
int(2)
float(37.42012867767779)
float(-122.03773496427027)
float(37.33755608435299)
float(-122.090428929044)
