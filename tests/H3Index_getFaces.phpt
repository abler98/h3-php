--TEST--
H3\H3Index::getFaces() Test
--EXTENSIONS--
h3
--FILE--
<?php
$index1 = new \H3\H3Index(0x85283473fffffff);
$index2 = new \H3\H3Index(0x85119643fffffff);

var_dump($index1->getFaces());
var_dump($index2->getFaces());
?>
--EXPECTF--
array(1) {
  [0]=>
  int(7)
}
array(1) {
  [0]=>
  int(0)
}
