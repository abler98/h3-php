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
--EXPECT--
int(0)
float(37.784046222598775)
float(-122.42708872508095)
float(37.77226734985152)
float(-122.43458610784575)
float(37.76173573392154)
float(-122.42576908738396)
float(37.76298184766419)
float(-122.40945463242252)
float(37.75244647475627)
float(-122.40063951171167)
float(37.75368882535418)
float(-122.38432356237523)
float(37.76546768434345)
float(-122.37681938644465)
float(37.77600420067386)
float(-122.38563455403627)
float(37.7747607144902)
float(-122.4019538515761)
float(37.78529347359727)
float(-122.41077092287512)
int(1)
float(49.9032631114296)
float(36.245217108096654)
float(49.93856707502108)
float(36.36123536894076)
float(50.02721542024701)
float(36.374554973476705)
float(50.0804922035258)
float(36.27141860004053)
float(50.04502776747484)
float(36.15521929341623)
float(49.956447234438116)
float(36.14233727552816)
