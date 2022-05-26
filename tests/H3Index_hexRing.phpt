--TEST--
H3\H3Index::hexRing() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$indexes = $h3->hexRing(1);

foreach ($indexes as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%d) "8528340bfffffff"
string(%d) "85283447fffffff"
string(%d) "8528347bfffffff"
string(%d) "85283463fffffff"
string(%d) "85283477fffffff"
string(%d) "8528340ffffffff"
