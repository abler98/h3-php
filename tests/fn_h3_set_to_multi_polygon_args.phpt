--TEST--
H3\h3_set_to_multi_polygon() Arguments test
--EXTENSIONS--
h3
--FILE--
<?php
try {
    \H3\h3_set_to_multi_polygon([
        'test1' => new \H3\H3Index(0x872830828ffffff),
        'test2' => new \H3\H3Index(0x87283082effffff),
        'test3' => new \H3\H3Index(0x85119643fffffff),
    ]);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\h3_set_to_multi_polygon(['invalid data']);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(true)
bool(false)
