--TEST--
H3\GeoPolygon::getHoles() Test
--EXTENSIONS--
h3
--FILE--
<?php
$geofence = new \H3\CellBoundary([
    new \H3\LatLng(49.99185845731755, 36.24805297746707),
    new \H3\LatLng(49.58867959331382, 34.54863685742558),
]);

$holes = [$geofence, $geofence];

$polygon1 = new \H3\GeoPolygon($geofence, $holes);
$polygon2 = new \H3\GeoPolygon($geofence);

var_dump($polygon1->getHoles() === $holes);
var_dump(empty($polygon2->getHoles()));
?>
--EXPECT--
bool(true)
bool(true)
