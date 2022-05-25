--TEST--
H3\compact() Test
--EXTENSIONS--
h3
--FILE--
<?php
$a = new \H3\H3Index(0x85283473fffffff);
$b = new \H3\H3Index(0x8528342bfffffff);

var_dump(\H3\distance($a, $b));
?>
--EXPECT--
int(2)
