--TEST--
H3\H3Index::toLong() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);

var_dump($h3->toLong() === 0x85283473fffffff);
?>
--EXPECT--
bool(true)
