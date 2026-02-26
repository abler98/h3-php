--TEST--
H3\hex_area() Test
--EXTENSIONS--
h3
--FILE--
<?php
var_dump(\H3\hex_area(8, H3_AREA_UNIT_KM2));
var_dump(\H3\hex_area(8, H3_AREA_UNIT_M2));

try {
    \H3\hex_area(18, H3_AREA_UNIT_KM2);
} catch (\H3\H3Exception $e) {
    var_dump($e->getCode() === H3_ERR_CODE_INVALID_RES);
}

try {
    \H3\hex_area(8, 123);
} catch (\H3\H3Exception $e) {
    var_dump($e->getCode() === H3_ERR_CODE_UNSUPPORTED_UNIT);
}
?>
--EXPECT--
float(0.7373275975944177)
float(737327.5975944188)
bool(true)
bool(true)
