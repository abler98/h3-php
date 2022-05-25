--TEST--
H3\compact() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$nearby = $h3->kRing(4);
$compacted = \H3\compact($nearby);

foreach ($compacted as $index) {
    var_dump($index->toString());
}
?>
--EXPECTF--
string(%d) "852834cffffffff"
string(%d) "852830d3fffffff"
string(%d) "852830d7fffffff"
string(%d) "8528309bfffffff"
string(%d) "85283093fffffff"
string(%d) "852834abfffffff"
string(%d) "852834c7fffffff"
string(%d) "852834c3fffffff"
string(%d) "852834cbfffffff"
string(%d) "8529a927fffffff"
string(%d) "8529a92ffffffff"
string(%d) "85283697fffffff"
string(%d) "85283687fffffff"
string(%d) "852830dbfffffff"
string(%d) "852830c3fffffff"
string(%d) "852830c7fffffff"
string(%d) "8528308bfffffff"
string(%d) "85283083fffffff"
string(%d) "85283097fffffff"
string(%d) "8528355bfffffff"
string(%d) "852834affffffff"
string(%d) "852834a3fffffff"
string(%d) "852834bbfffffff"
string(%d) "8528348ffffffff"
string(%d) "8528348bfffffff"
string(%d) "852834d7fffffff"
string(%d) "842836bffffffff"
string(%d) "8428347ffffffff"
string(%d) "8428345ffffffff"
string(%d) "8428343ffffffff"
string(%d) "8428341ffffffff"
