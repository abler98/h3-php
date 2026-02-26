--TEST--
H3\polyfill() Arguments test
--EXTENSIONS--
h3
--FILE--
<?php
$polygon = new \H3\GeoPolygon(
    new \H3\CellBoundary([
        'test1' => new \H3\LatLng(37.813318999983238, -122.4089866999972145),
        'test2' => new \H3\LatLng(37.7198061999978478, -122.3544736999993603),
        'test2' => new \H3\LatLng(37.8151571999998453, -122.4798767000009008),
    ])
);

try {
    \H3\polyfill($polygon, 7);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\polyfill(new \H3\GeoPolygon(new \H3\CellBoundary(['invalid data'])), 7);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\polyfill(new \H3\GeoPolygon(new \H3\CellBoundary([null])), 7);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(true)
bool(false)
bool(false)
