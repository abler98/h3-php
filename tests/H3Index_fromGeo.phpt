--TEST--
H3\H3Index::fromGeo() Test
--EXTENSIONS--
h3
--FILE--
<?php
$geo = new \H3\LatLng(49.99185845731755, 36.24805297746707);
$h3 = \H3\H3Index::fromGeo($geo, 8);

var_dump($h3->toString());

$h3Geo = $h3->toGeo();
var_dump($h3Geo->getLat());
var_dump($h3Geo->getLon());
?>
--EXPECTF--
string(%d) "8811964009fffff"
float(49.9954909242234%s)
float(36.2475135805156%s)
