--TEST--
H3\H3Index::isValid() Test
--EXTENSIONS--
h3
--FILE--
<?php
$valid = new \H3\H3Index(0x8811964009fffff);
$invalid = new \H3\H3Index(0xffffff);

var_dump($valid->isValid());
var_dump($invalid->isValid());
?>
--EXPECTF--
bool(true)
bool(false)
