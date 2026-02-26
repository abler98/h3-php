--TEST--
H3\GeoMultiPolygon::toGeoJson() Errors test
--EXTENSIONS--
h3
--FILE--
<?php
try {
    $multiPolygon = new \H3\GeoMultiPolygon([
        'invalid polygon',
    ]);
    $multiPolygon->toGeoJson();
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $multiPolygon = new \H3\GeoMultiPolygon([
        new \H3\GeoPolygon(new \H3\CellBoundary([new \H3\LatLng(0, 0)]), ['invalid hole']),
    ]);
    $multiPolygon->toGeoJson();
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $multiPolygon = new \H3\GeoMultiPolygon([
        new \H3\GeoPolygon(new \H3\CellBoundary(['invalid coord'])),
    ]);
    $multiPolygon->toGeoJson();
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $multiPolygon = new \H3\GeoMultiPolygon([
        new \H3\GeoPolygon(new \H3\CellBoundary([])),
    ]);
    $multiPolygon->toGeoJson();
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $multiPolygon = new \H3\GeoMultiPolygon([
        new \H3\GeoPolygon(new \H3\CellBoundary([new \H3\LatLng(0, 0)])),
        'invalid polygon',
    ]);
    $multiPolygon->toGeoJson();
} catch (\Throwable $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)
