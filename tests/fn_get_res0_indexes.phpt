--TEST--
H3\get_res0_indexes() Test
--EXTENSIONS--
h3
--FILE--
<?php
$indexes = \H3\get_res0_indexes();

var_dump(count($indexes));
var_dump($indexes[0]->toString());
?>
--EXPECTF--
int(122)
string(%d) "8001fffffffffff"
