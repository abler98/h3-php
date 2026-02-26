--TEST--
H3\CellBoundary::__construct() Test
--EXTENSIONS--
h3
--FILE--
<?php
$boundary = new \H3\CellBoundary([
    new \H3\LatLng(49.99185845731755, 36.24805297746707),
    new \H3\LatLng(49.58867959331382, 34.54863685742558),
]);

var_dump(count($boundary->getVertices()));
var_dump($boundary->getVertices()[0]->getLat());
var_dump($boundary->getVertices()[1]->getLat());
?>
--EXPECT--
int(2)
float(49.99185845731755)
float(49.58867959331382)
