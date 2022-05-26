--TEST--
H3\H3Index::hexRange() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85119643fffffff);
$range = $h3->hexRange(1);

foreach ($range as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%d) "85119643fffffff"
string(%d) "8511965bfffffff"
string(%d) "8511964bfffffff"
string(%d) "8511964ffffffff"
string(%d) "85119647fffffff"
string(%d) "85119657fffffff"
string(%d) "85119653fffffff"
