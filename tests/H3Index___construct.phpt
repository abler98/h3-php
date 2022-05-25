--TEST--
H3\H3Index::__construct() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x881e5dc8bbfffff);

var_dump($h3->toLong());
var_dump($h3->toString());
?>
--EXPECTF--
int(613023759699279871)
string(%d) "881e5dc8bbfffff"
