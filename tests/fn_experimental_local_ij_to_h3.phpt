--TEST--
H3\experimental_local_ij_to_h3() Test
--EXTENSIONS--
h3
--FILE--
<?php
$origin = new \H3\H3Index(0x85283473fffffff);
$ij = new \H3\CoordIJ(0, 0);
$h = \H3\experimental_local_ij_to_h3($origin, $ij);

var_dump($h->toString());
?>
--EXPECTF--
string(%d) "85280003fffffff"
