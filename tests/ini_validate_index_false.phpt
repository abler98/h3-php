--TEST--
h3.validate_index=0 Test
--EXTENSIONS--
h3
--INI--
h3.validate_index=0
--FILE--
<?php
try {
    \H3\H3Index::fromLong(0x115283473fffffff);
    var_dump(true);
} catch (\H3\H3Exception $e) {
    var_dump(false);
}

try {
    \H3\H3Index::fromLong(0x85283473fffffff);
    var_dump(true);
} catch (\H3\H3Exception $e) {
    var_dump(false);
}

try {
    \H3\H3DirectedEdge::fromLong(0x85283473fffffff);
    var_dump(true);
} catch (\H3\H3Exception $e) {
    var_dump(false);
}

try {
    \H3\H3DirectedEdge::fromLong(0x115283473fffffff);
    var_dump(true);
} catch (\H3\H3Exception $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
