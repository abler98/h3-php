--TEST--
H3\GeoPolygon::getGeofence() Test
--EXTENSIONS--
h3
--FILE--
<?php
$geofence = new \H3\CellBoundary([
    new \H3\LatLng(49.99185845731755, 36.24805297746707),
    new \H3\LatLng(49.58867959331382, 34.54863685742558),
]);

$polygon = new \H3\GeoPolygon($geofence, []);

var_dump($polygon->getGeofence() === $geofence);
?>
--EXPECT--
bool(true)
