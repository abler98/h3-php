--TEST--
H3\get_pentagon_indexes() Test
--EXTENSIONS--
h3
--FILE--
<?php
$indexes5 = \H3\get_pentagon_indexes(5);
$indexes6 = \H3\get_pentagon_indexes(6);

var_dump(count($indexes5));
var_dump(count($indexes6));

try {
    \H3\get_pentagon_indexes(123);
} catch (\H3\H3Exception $e) {
    var_dump($e->getCode() === H3_ERR_CODE_INVALID_RES);
}
?>
--EXPECT--
int(12)
int(12)
bool(true)
