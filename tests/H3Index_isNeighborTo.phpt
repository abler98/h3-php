--TEST--
H3\H3Index::isNeighborTo() Test
--EXTENSIONS--
h3
--FILE--
<?php
$origin1 = new \H3\H3Index(0x85283473fffffff);
$destination1 = new \H3\H3Index(0x85283477fffffff);

var_dump($origin1->isNeighborTo($destination1));

$origin2 = new \H3\H3Index(0x85119643fffffff);
$destination2 = new \H3\H3Index(0x85283477fffffff);

var_dump($origin2->isNeighborTo($destination2));
?>
--EXPECT--
bool(true)
bool(false)
