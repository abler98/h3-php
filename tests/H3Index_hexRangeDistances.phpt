--TEST--
H3\H3Index::hexRangeDistances() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85119643fffffff);
$ranges = $h3->hexRangeDistances(2);

foreach ($ranges as $distance => $range) {
    var_dump($distance);
    foreach ($range as $index) {
        var_dump($index->toString());
    }
}
?>
--EXPECTF--
int(0)
string(%d) "85119643fffffff"
int(1)
string(%d) "8511965bfffffff"
string(%d) "8511964bfffffff"
string(%d) "8511964ffffffff"
string(%d) "85119647fffffff"
string(%d) "85119657fffffff"
string(%d) "85119653fffffff"
int(2)
string(%d) "851e69b7fffffff"
string(%d) "851e69a7fffffff"
string(%d) "852d6597fffffff"
string(%d) "852d6587fffffff"
string(%d) "852d65b3fffffff"
string(%d) "852d65b7fffffff"
string(%d) "8511967bfffffff"
string(%d) "85119673fffffff"
string(%d) "8511960bfffffff"
string(%d) "8511961bfffffff"
string(%d) "851196cffffffff"
string(%d) "851196cbfffffff"
