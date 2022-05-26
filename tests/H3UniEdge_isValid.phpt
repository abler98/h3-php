--TEST--
H3\H3UniEdge::isValid() Test
--EXTENSIONS--
h3
--FILE--
<?php
$valid = \H3\H3UniEdge::fromString('115283473fffffff');
$invalid = \H3\H3UniEdge::fromString('85119643fffffff');

var_dump($valid->isValid());
var_dump($invalid->isValid());
?>
--EXPECT--
bool(true)
bool(false)
