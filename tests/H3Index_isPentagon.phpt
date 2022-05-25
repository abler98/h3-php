--TEST--
H3\H3Index::isPentagon() Test
--EXTENSIONS--
h3
--FILE--
<?php
$valid = new \H3\H3Index(0x85080003fffffff);
$invalid = new \H3\H3Index(0x85283473fffffff);

var_dump($valid->isPentagon());
var_dump($invalid->isPentagon());
?>
--EXPECTF--
bool(true)
bool(false)
