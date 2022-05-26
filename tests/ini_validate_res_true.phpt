--TEST--
h3.validate_res=1 Test
--EXTENSIONS--
h3
--INI--
h3.validate_res=1
--FILE--
<?php
try {
    \H3\edge_length(99, H3_LENGTH_UNIT_KM);
    var_dump(true);
} catch (\H3\H3Exception $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(false)
