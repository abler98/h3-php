--TEST--
H3\H3Index::getResolution() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85119643fffffff);

var_dump($h3->getResolution());
?>
--EXPECT--
int(5)
