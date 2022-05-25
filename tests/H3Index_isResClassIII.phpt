--TEST--
H3\H3Index::isResClassIII() Test
--EXTENSIONS--
h3
--FILE--
<?php
$valid = new \H3\H3Index(0x85283473fffffff);
$invalid = new \H3\H3Index(0x8001fffffffffff);

var_dump($valid->isResClassIII());
var_dump($invalid->isResClassIII());
?>
--EXPECTF--
bool(true)
bool(false)
