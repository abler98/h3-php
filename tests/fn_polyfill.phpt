--TEST--
H3\polyfill() Test
--EXTENSIONS--
h3
--FILE--
<?php
$polygon = new \H3\GeoPolygon(
    new \H3\CellBoundary([
        new \H3\LatLng(37.813318999983238, -122.4089866999972145),
        new \H3\LatLng(37.7198061999978478, -122.3544736999993603),
        new \H3\LatLng(37.8151571999998453, -122.4798767000009008),
    ])
);

$indexes = \H3\polyfill($polygon, 7);

foreach ($indexes as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%d) "87283082bffffff"
string(%d) "872830870ffffff"
string(%d) "872830820ffffff"
string(%d) "87283082effffff"
string(%d) "872830828ffffff"
string(%d) "87283082affffff"
string(%d) "872830876ffffff"
