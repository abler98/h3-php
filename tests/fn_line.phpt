--TEST--
H3\line() Test
--EXTENSIONS--
h3
--FILE--
<?php
$start = new \H3\H3Index(0x85283473fffffff);
$end = new \H3\H3Index(0x8528342bfffffff);
$line = \H3\line($start, $end);

foreach ($line as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%f) "85283473fffffff"
string(%f) "85283477fffffff"
string(%f) "8528342bfffffff"
