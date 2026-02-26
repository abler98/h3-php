--TEST--
H3\H3DirectedEdge::isValid() Test
--EXTENSIONS--
h3
--FILE--
<?php
$valid = \H3\H3DirectedEdge::fromString('115283473fffffff');
$invalid = \H3\H3DirectedEdge::fromString('85119643fffffff');

var_dump($valid->isValid());
var_dump($invalid->isValid());
?>
--EXPECT--
bool(true)
bool(false)
