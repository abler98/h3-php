<?php

/** @generate-class-entries */

namespace H3;

function degs_to_rads(float $degrees): float {}

function rads_to_degs(float $radians): float {}

/**
 * @throws H3Exception if invalid resolution given
 */
function hex_area(int $res, int $unit): float {}

/**
 * @throws H3Exception if invalid resolution given
 */
function edge_length(int $res, int $unit): float {}

/**
 * @throws H3Exception if invalid resolution given
 */
function num_hexagons(int $res): int {}

/**
 * @return H3Index[]
 */
function get_res0_indexes(): array {}

/**
 * @return H3Index[]
 * @throws H3Exception
 */
function get_pentagon_indexes(int $res): array {}

function point_dist(LatLng $a, LatLng $b, int $unit): float {}

/**
 * @param H3Index[] $indexes
 * @return H3Index[]
 * @throws H3Exception
 */
function compact(array $indexes): array {}

/**
 * @param H3Index[] $indexes
 * @return H3Index[]
 * @throws H3Exception if invalid resolution given
 */
function uncompact(array $indexes, int $res): array {}

/**
 * @return H3Index[]
 * @throws H3Exception
 */
function line(H3Index $start, H3Index $end): array {}

function distance(H3Index $a, H3Index $b): int {}

function indexes_are_neighbors(H3Index $origin, H3Index $destination): bool {}

/**
 * @return H3Index[]
 * @throws H3Exception
 */
function polyfill(GeoPolygon $polygon, int $res): array {}

/**
 * @param H3Index[] $indexes
 * @throws H3Exception
 */
function h3_set_to_multi_polygon(array $indexes): GeoMultiPolygon {}

function experimental_h3_to_local_ij(H3Index $origin, H3Index $h): CoordIJ {}

function experimental_local_ij_to_h3(H3Index $origin, CoordIJ $ij): H3Index {}

final class H3Exception extends \RuntimeException {}

final class H3Index {

    private int $index;

    public function __construct(int $index) {}

    public static function fromLong(int $index): H3Index {}

    public static function fromString(string $value): H3Index {}

    /**
     * @throws H3Exception
     */
    public static function fromGeo(LatLng $geo, int $res): H3Index {}

    public function isValid(): bool {}

    public function isResClassIII(): bool {}

    public function isPentagon(): bool {}

    public function getResolution(): int {}

    public function getBaseCell(): int {}

    /**
     * @return int[]
     */
    public function getFaces(): array {}

    /**
     * @return H3Index[]
     */
    public function kRing(int $k): array {}

    /**
     * @return H3Index[][]
     */
    public function kRingDistances(int $k): array {}

    /**
     * @return H3Index[]
     * @throws H3Exception if pentagonal distortion is encountered
     */
    public function hexRange(int $k): array {}

    /**
     * @return H3Index[]
     * @throws H3Exception if pentagonal distortion is encountered
     */
    public function hexRing(int $k): array {}

    /**
     * @return H3Index[][]
     * @throws H3Exception if pentagonal distortion is encountered
     */
    public function hexRangeDistances(int $k): array {}

    public function getCellArea(int $unit): float {}

    public function isNeighborTo(H3Index $destination): bool {}

    /**
     * @return H3Index[]
     */
    public function getLineTo(H3Index $destination): array {}

    public function getDistanceTo(H3Index $destination): int {}

    /**
     * @return H3DirectedEdge[]
     */
    public function getDirectedEdges(): array {}

    public function getDirectedEdge(H3Index $destination): H3DirectedEdge {}

    /**
     * @throws H3Exception if invalid resolution given
     */
    public function toParent(int $res): H3Index {}

    /**
     * @return H3Index[]
     * @throws H3Exception if invalid resolution given
     */
    public function toChildren(int $res): array {}

    /**
     * @throws H3Exception if invalid resolution given
     */
    public function toCenterChild(int $res): H3Index {}

    public function toLong(): int {}

    public function toString(): string {}

    public function toGeo(): LatLng {}

    public function toGeoBoundary(): CellBoundary {}

    public function __toString(): string {}
}

final class H3DirectedEdge {

    private int $index;

    public function __construct(int $index) {}

    public static function fromLong(int $index): H3DirectedEdge {}

    public static function fromString(string $value): H3DirectedEdge {}

    public function isValid(): bool {}

    public function getOrigin(): H3Index {}

    public function getDestination(): H3Index {}

    /**
     * @return H3Index[]
     */
    public function getIndexes(): array {}

    public function getBoundary(): CellBoundary {}

    public function getLength(int $unit): float {}

    public function toLong(): int {}

    public function toString(): string {}

    public function __toString(): string {}
}

final class LatLng {

    private float $lat;

    private float $lon;

    public function __construct(float $lat, float $lon) {}

    public function getLat(): float {}

    public function getLon(): float {}
}

final class CellBoundary {

    /**
     * @var LatLng[]
     */
    private array $vertices;

    /**
     * @param LatLng[] $vertices
     */
    public function __construct(array $vertices) {}

    /**
     * @return LatLng[]
     */
    public function getVertices(): array {}
}

final class GeoPolygon {

    private CellBoundary $geofence;

    /**
     * @var CellBoundary[]
     */
    private array $holes;

    /**
     * @param CellBoundary[] $holes
     */
    public function __construct(CellBoundary $geofence, array $holes = []) {}

    public function getGeofence(): CellBoundary {}

    /**
     * @return CellBoundary[]
     */
    public function getHoles(): array {}
}

final class GeoMultiPolygon {

    /**
     * @var GeoPolygon[]
     */
    private array $polygons;

    /**
     * @param GeoPolygon[] $polygons
     */
    public function __construct(array $polygons) {}

    /**
     * @return GeoPolygon[]
     */
    public function getPolygons(): array {}

    /**
     * @return float[][][][]
     * @throws H3Exception if this object is not valid
     */
    public function toGeoJson(): array {}
}

final class CoordIJ {

    private int $i;

    private int $j;

    public function __construct(int $i, int $j) {}

    public function getI(): int {}

    public function getJ(): int {}
}
