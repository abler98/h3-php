--TEST--
H3\GeoMultiPolygon::toGeoJson() Test
--EXTENSIONS--
h3
--FILE--
<?php
$multiPolygon = \H3\h3_set_to_multi_polygon([
    new \H3\H3Index(0x872830828ffffff),
    new \H3\H3Index(0x87283082effffff),
    new \H3\H3Index(0x85119643fffffff),
]);

foreach ($multiPolygon->toGeoJson() as $i => $polygon) {
    var_dump($i);
    foreach ($polygon as $i => $boundary) {
        var_dump($i);
        foreach ($boundary as [$lon, $lat]) {
            var_dump("$lon,$lat");
        }
    }
}

$multiPolygon = \H3\h3_set_to_multi_polygon(\H3\H3Index::fromLong(0x85119643fffffff)->hexRing(3));

$geojson = [];

foreach ($multiPolygon->getPolygons() as $polygon) {
    $geojson_polygon = [];

    $geofence = [];

    $vertices = $polygon->getGeofence()->getVertices();

    foreach ($vertices as $coord) {
        $geofence[] = [$coord->getLon(), $coord->getLat()];
    }
    $geofence[] = [$vertices[0]->getLon(), $vertices[0]->getLat()];

    $geojson_polygon[] = $geofence;

    foreach ($polygon->getHoles() as $hole) {
        $geofence = [];
        foreach ($hole->getVertices() as $coord) {
            $geofence[] = [$coord->getLon(), $coord->getLat()];
        }
        $geofence[] = [$hole->getVertices()[0]->getLon(), $hole->getVertices()[0]->getLat()];
        $geojson_polygon[] = $geofence;
    }

    $geojson[] = $geojson_polygon;
}

var_dump(json_encode($multiPolygon->toGeoJson()) === json_encode($geojson));
?>
--EXPECTF--
int(0)
int(0)
string(%d) "-122.42708872508,37.784046222599"
string(%d) "-122.43458610785,37.772267349852"
string(%d) "-122.42576908738,37.761735733922"
string(%d) "-122.40945463242,37.762981847664"
string(%d) "-122.40063951171,37.752446474756"
string(%d) "-122.38432356238,37.753688825354"
string(%d) "-122.37681938644,37.765467684343"
string(%d) "-122.38563455404,37.776004200674"
string(%d) "-122.40195385158,37.77476071449"
string(%d) "-122.41077092288,37.785293473597"
string(%d) "-122.42708872508,37.784046222599"
int(1)
int(0)
string(%d) "36.245217108097,49.90326311143"
string(%d) "36.361235368941,49.938567075021"
string(%d) "36.374554973477,50.027215420247"
string(%d) "36.271418600041,50.080492203526"
string(%d) "36.155219293416,50.045027767475"
string(%d) "36.142337275528,49.956447234438"
string(%d) "36.245217108097,49.90326311143"
bool(true)
