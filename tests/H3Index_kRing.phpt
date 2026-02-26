--TEST--
H3\H3Index::kRing() Test
--EXTENSIONS--
h3
--FILE--
<?php
$geo = new \H3\LatLng(49.99185845731755, 36.24805297746707);
$h3 = \H3\H3Index::fromGeo($geo, 8);
$kRing = $h3->kRing(1);

foreach ($kRing as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%d) "8811964009fffff"
string(%d) "8811964047fffff"
string(%d) "881196400dfffff"
string(%d) "8811964001fffff"
string(%d) "881196400bfffff"
string(%d) "8811964055fffff"
string(%d) "8811964043fffff"
