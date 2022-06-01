--TEST--
H3\H3UniEdge::__toString() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3UniEdge(0x115283473fffffff);

var_dump((string) $h3);
?>
--EXPECTF--
string(%d) "115283473fffffff"
