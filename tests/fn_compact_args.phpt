--TEST--
H3\compact() Arguments test
--EXTENSIONS--
h3
--FILE--
<?php
$h3 = new \H3\H3Index(0x85283473fffffff);
$nearby = $h3->kRing(4);

try {
    \H3\compact($nearby);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    $keys = array_map(fn() => (string) rand(0, 10000), array_fill(0, count($nearby), 0));
    \H3\compact(array_combine($keys, $nearby));
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\compact([]);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\compact(['invalid data', null]);
    var_dump(true);
} catch (\Throwable $e) {
    var_dump(false);
}

try {
    \H3\compact(null);
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
