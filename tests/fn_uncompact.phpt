--TEST--
H3\uncompact() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$nearby = $h3->kRing(4);
$compacted = \H3\compact($nearby);
$uncompacted = \H3\uncompact($compacted, 5);

foreach ($uncompacted as $index) {
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
string(%d) "852836a3fffffff"
string(%d) "852836a7fffffff"
string(%d) "852836abfffffff"
string(%d) "852836affffffff"
string(%d) "852836b3fffffff"
string(%d) "852836b7fffffff"
string(%d) "852836bbfffffff"
string(%d) "85283463fffffff"
string(%d) "85283467fffffff"
string(%d) "8528346bfffffff"
string(%d) "8528346ffffffff"
string(%d) "85283473fffffff"
string(%d) "85283477fffffff"
string(%d) "8528347bfffffff"
string(%d) "85283443fffffff"
string(%d) "85283447fffffff"
string(%d) "8528344bfffffff"
string(%d) "8528344ffffffff"
string(%d) "85283453fffffff"
string(%d) "85283457fffffff"
string(%d) "8528345bfffffff"
string(%d) "85283423fffffff"
string(%d) "85283427fffffff"
string(%d) "8528342bfffffff"
string(%d) "8528342ffffffff"
string(%d) "85283433fffffff"
string(%d) "85283437fffffff"
string(%d) "8528343bfffffff"
string(%d) "85283403fffffff"
string(%d) "85283407fffffff"
string(%d) "8528340bfffffff"
string(%d) "8528340ffffffff"
string(%d) "85283413fffffff"
string(%d) "85283417fffffff"
string(%d) "8528341bfffffff"
