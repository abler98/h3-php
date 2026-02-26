--TEST--
H3\H3Index::getDirectedEdges() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$edges = $h3->getDirectedEdges();

foreach ($edges as $edge) {
    var_dump($edge->toString());
}
?>
--EXPECTF--
string(%d) "115283473fffffff"
string(%d) "125283473fffffff"
string(%d) "135283473fffffff"
string(%d) "145283473fffffff"
string(%d) "155283473fffffff"
string(%d) "165283473fffffff"
