--TEST--
H3\polyfill() Test
--EXTENSIONS--
h3
--FILE--
<?php
$multiPolygon = \H3\h3_set_to_multi_polygon([
    new \H3\H3Index(0x872830828ffffff),
    new \H3\H3Index(0x87283082effffff),
    new \H3\H3Index(0x85119643fffffff),
]);

foreach ($multiPolygon->getPolygons() as $i => $polygon) {
    var_dump($i);
    foreach ($polygon->getGeofence()->getVertices() as $geoCoord) {
        var_dump($geoCoord->getLat());
        var_dump($geoCoord->getLon());
    }
}
?>
--EXPECTF--
int(0)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
int(1)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
float(%f)
