--TEST--
H3\H3Index::getDistanceTo() Test
--EXTENSIONS--
h3
--FILE--
<?php
$a = new \H3\H3Index(0x85283473fffffff);
$b = new \H3\H3Index(0x8528342bfffffff);

var_dump($a->getDistanceTo($b));
?>
--EXPECT--
int(2)
