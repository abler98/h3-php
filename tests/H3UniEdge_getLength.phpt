--TEST--
H3\H3UniEdge::getLength() Test
--EXTENSIONS--
h3
--FILE--
<?php
$edge = \H3\H3UniEdge::fromString('115283473fffffff');

var_dump($edge->getLength(H3_AREA_UNIT_KM2));
?>
--EXPECT--
float(10.29473608619955)
