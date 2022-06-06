--TEST--
H3\H3Index::getLineTo() Test
--EXTENSIONS--
h3
--FILE--
<?php
$start = new \H3\H3Index(0x85283473fffffff);
$end = new \H3\H3Index(0x8528342bfffffff);
$line = $start->getLineTo($end);

foreach ($line as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%f) "85283473fffffff"
string(%f) "85283477fffffff"
string(%f) "8528342bfffffff"
