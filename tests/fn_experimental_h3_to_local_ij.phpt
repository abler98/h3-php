--TEST--
H3\experimental_h3_to_local_ij() Test
--EXTENSIONS--
h3
--FILE--
<?php
$origin = new \H3\H3Index(0x85283473fffffff);
$h = new \H3\H3Index(0x8528342bfffffff);
$ij = \H3\experimental_h3_to_local_ij($origin, $h);

var_dump($ij->getI());
var_dump($ij->getJ());
?>
--EXPECT--
int(25)
int(13)
