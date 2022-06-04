--TEST--
H3\uncompact() Arguments test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$nearby = $h3->kRing(4);
$compacted = \H3\compact($nearby);

try {
    \H3\uncompact($compacted, 5);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $keys = array_map(fn() => (string) rand(0, 10000), array_fill(0, count($compacted), 0));
    \H3\uncompact(array_combine($keys, $compacted), 5);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\uncompact([], 5);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\uncompact(['invalid data', null], 5);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\uncompact(null, 5);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\uncompact([], '5');
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)
