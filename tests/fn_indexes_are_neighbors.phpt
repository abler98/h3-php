--TEST--
H3\indexes_are_neighbors() Test
--EXTENSIONS--
h3
--FILE--
<?php
$origin1 = new \H3\H3Index(0x85283473fffffff);
$destination1 = new \H3\H3Index(0x85283477fffffff);

var_dump(\H3\indexes_are_neighbors($origin1, $destination1));

$origin2 = new \H3\H3Index(0x85119643fffffff);
$destination2 = new \H3\H3Index(0x85283477fffffff);

var_dump(\H3\indexes_are_neighbors($origin2, $destination2));
?>
--EXPECT--
bool(true)
bool(false)
