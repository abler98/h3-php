--TEST--
H3\H3Index::fromLong() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = \H3\H3Index::fromLong(613023759699279871);

var_dump($h3->toLong());
?>
--EXPECT--
int(613023759699279871)
