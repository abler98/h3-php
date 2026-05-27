# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A PHP extension (written in C) that wraps Uber's [H3 geospatial indexing library](https://github.com/uber/h3) in an OOP-style API under the `H3\` namespace.

- PHP: `^8.1` (CI matrix: 8.1, 8.2, 8.3)
- H3 C library: `^3.7.2` — must be installed on the system (headers expected at `/usr/local/include/h3/h3api.h` or `/usr/include/h3/h3api.h`; override with `--with-h3=<path>`).

## Build / test workflow

Standard PHP extension build cycle:

```bash
phpize
./configure --with-h3
make
sudo make install   # only needed to install system-wide; tests can run against the built .so directly
```

Run the test suite (mirrors `.github/workflows/build-and-test.yml`):

```bash
export NO_INTERACTION=1
export REPORT_EXIT_STATUS=1
export TEST_PHP_EXECUTABLE=$(which php)
php run-tests.php --show-diff -d extension=h3.so ./tests/*.phpt
```

Run a single test:

```bash
php run-tests.php --show-diff -d extension=h3.so ./tests/H3Index_fromGeo.phpt
```

Tests use PHP's standard `.phpt` format with `--EXPECTF--` for fuzzy floating-point output (`%d`, `%f` placeholders).

After modifying C sources, rerun `make` (no need to `phpize` again unless `config.m4` changed). After pulling, run `phpize --clean && phpize && ./configure --with-h3 && make` to be safe.

## Architecture

### Single-file C extension

All extension logic lives in `h3.c`. Layout:

1. **Globals & validation macros** — `H3_G(validate_res)` / `H3_G(validate_index)` gate the `VALIDATE_H3_RES` / `VALIDATE_H3_INDEX` / `VALIDATE_H3_UNI_EDGE` macros that wrap nearly every entry point. These are controlled by INI entries (see below).
2. **`zend_class_entry *` pointers** — one per exposed class (`H3_H3Index_ce`, `H3_H3UniEdge_ce`, `H3_GeoCoord_ce`, `H3_GeoBoundary_ce`, `H3_GeoPolygon_ce`, `H3_GeoMultiPolygon_ce`, `H3_CoordIJ_ce`, `H3_H3Exception_ce`).
3. **Conversion helpers** — `obj_to_h3` / `h3_to_obj`, `h3_array_to_zend_array`, GeoCoord/GeoBoundary/GeoPolygon ↔ zval converters. These are the glue between PHP objects and the C structs/`H3Index` (uint64) values the underlying H3 library consumes.
4. **`PHP_FUNCTION` / `PHP_METHOD` definitions** — one per binding, each preceded by validation macros. Throw via `H3_THROW(message, code)` (maps to `H3\H3Exception`); codes mirror the constants in `h3_consts.php`.
5. **Module bootstrap** — `MINIT` registers classes (from `h3_arginfo.h`), INI entries, and constants (`H3_AREA_UNIT_*`, `H3_LENGTH_UNIT_*`).

### Generated arginfo: `h3.stub.php` is the source of truth

`h3_arginfo.h` is generated from `h3.stub.php` by PHP's `build/gen_stub.php`. **Edit `h3.stub.php`, then regenerate**, e.g.:

```bash
php /path/to/php-src/build/gen_stub.php h3.stub.php
```

The header carries a stub hash at the top — if it drifts from `h3.stub.php`, runtime registration will mismatch. The stub also doubles as the canonical API documentation (PHPDoc with `@throws` / `H3Index[]` return shapes).

### `h3_consts.php`

User-space PHP file mirroring the `H3_ERR_CODE_*`, `H3_AREA_UNIT_*`, `H3_LENGTH_UNIT_*` constants that the extension registers in the **global** namespace (not `H3\`). The C definitions in `h3.c` and the values in `h3_consts.php` must stay in lockstep.

### Runtime validation toggles

Two INI entries change behavior of every binding:

- `h3.validate_res` (default `On`) — throws `H3Exception` with code `H3_ERR_CODE_INVALID_RES` when a resolution argument is outside `[0, 15]`.
- `h3.validate_index` (default `Off`) — throws with `H3_ERR_CODE_INVALID_INDEX` when an `H3Index` / `H3UniEdge` long fails `h3IsValid` / `h3UnidirectionalEdgeIsValid`.

Turning these off skips the precondition checks and lets the underlying H3 C library handle (or misbehave on) bad input. Tests that exercise error paths assume the defaults.

### Style

C code follows `.clang-format` (LLVM base, 4-space indent, Linux braces, no column limit, no short-if collapsing). Run `clang-format -i h3.c` before committing C changes.
