--TEST--
H3\get_pentagon_indexes() Test
--EXTENSIONS--
h3
--FILE--
<?php
$indexes5 = \H3\get_pentagon_indexes(5);
$indexes6 = \H3\get_pentagon_indexes(6);

var_dump(count($indexes5));
var_dump(count($indexes6));
?>
--EXPECTF--
int(12)
int(12)
