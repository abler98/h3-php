--TEST--
H3\H3Index::toChildren() Test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$children = $h3->toChildren(6);

foreach ($children as $child) {
    var_dump($child->toString());
}
?>
--EXPECTF--
string(%d) "862834707ffffff"
string(%d) "86283470fffffff"
string(%d) "862834717ffffff"
string(%d) "86283471fffffff"
string(%d) "862834727ffffff"
string(%d) "86283472fffffff"
string(%d) "862834737ffffff"
