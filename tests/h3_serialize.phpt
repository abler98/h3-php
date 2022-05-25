--TEST--
serialize()/unserialize() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85119643fffffff);

/** @var \H3\H3Index $unserialized */
$unserialized = unserialize(serialize($h3));

var_dump($h3->toLong() === $unserialized->toLong());
var_dump($unserialized->toString());
?>
--EXPECTF--
bool(true)
string(%d) "85119643fffffff"
