--TEST--
H3\H3Index::kRingDistances() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = \H3\H3Index::fromLong(0x8811964009fffff);
$kRings = $h3->kRingDistances(2);

foreach ($kRings as $distance => $kRing) {
    var_dump($distance);
    foreach ($kRing as $index) {
        var_dump($index->toString());
    }
}
?>
--EXPECTF--
int(0)
string(%d) "8811964009fffff"
int(1)
string(%d) "8811964047fffff"
string(%d) "881196400dfffff"
string(%d) "8811964001fffff"
string(%d) "881196400bfffff"
string(%d) "8811964055fffff"
string(%d) "8811964043fffff"
int(2)
string(%d) "8811964041fffff"
string(%d) "8811964045fffff"
string(%d) "881196406bfffff"
string(%d) "8811964063fffff"
string(%d) "8811964005fffff"
string(%d) "8811964007fffff"
string(%d) "8811964003fffff"
string(%d) "881196401dfffff"
string(%d) "8811964057fffff"
string(%d) "8811964051fffff"
string(%d) "881196405dfffff"
string(%d) "881196404bfffff"
