--TEST--
H3\H3Index::getUnidirectionalEdge() Test
--EXTENSIONS--
h3
--FILE--
<?php
$origin = new \H3\H3Index(0x85283473fffffff);
$destination = new \H3\H3Index(0x85283477fffffff);
$edge = $origin->getUnidirectionalEdge($destination);

var_dump($edge->toString());
?>
--EXPECTF--
string(%d) "115283473fffffff"
