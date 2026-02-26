--TEST--
H3\H3Index::getCellArea() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85119643fffffff);

var_dump($h3->getCellArea(H3_AREA_UNIT_M2));
?>
--EXPECTF--
float(234305268.4166%s)
