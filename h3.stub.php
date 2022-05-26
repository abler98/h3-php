<?php

/** @generate-class-entries */

namespace H3;

function degs_to_rads(float $degrees): float {}

function rads_to_degs(float $radians): float {}

function hex_area(int $res, int $unit): float {}

function edge_length(int $res, int $unit): float {}

function num_hexagons(int $res): int {}

/**
 * @return H3Index[]
 */
function get_res0_indexes(): array {}

/**
 * @return H3Index[]
 */
function get_pentagon_indexes(int $res): array {}

function point_dist(GeoCoord $a, GeoCoord $b, int $unit): float {}

/**
 * @param H3Index[] $indexes
 * @return H3Index[]
 * @throws H3Exception
 */
function compact(array $indexes): array {}

/**
 * @param H3Index[] $indexes
 * @return H3Index[]
 */
function uncompact(array $indexes, int $res): array {}

/**
 * @return H3Index[]
 * @throws H3Exception
 */
function line(H3Index $start, H3Index $end): array {}

function distance(H3Index $a, H3Index $b): int {}

function indexes_are_neighbors(H3Index $origin, H3Index $destination): bool {}

final class H3Exception extends \RuntimeException {}

final class H3Index {

    private int $index;

    public function __construct(int $index) {}

    public static function fromLong(int $index): H3Index {}

    public static function fromString(string $value): H3Index {}

    /**
     * @throws H3Exception
     */
    public static function fromGeo(GeoCoord $geo, int $res): H3Index {}

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

    public function getArea(int $unit): float {}

    public function getEdgeLength(int $unit): float {}

    public function isNeighborTo(H3Index $destination): bool {}

    /**
     * @return H3UniEdge[]
     */
    public function getUnidirectionalEdges(): array {}

    public function getUnidirectionalEdge(H3Index $destination): H3UniEdge {}

    public function toParent(int $res): H3Index {}

    /**
     * @return H3Index[]
     */
    public function toChildren(int $res): array {}

    public function toCenterChild(int $res): H3Index {}

    public function toLong(): int {}

    public function toString(): string {}

    public function toGeo(): GeoCoord {}

    public function toGeoBoundary(): GeoBoundary {}
}

final class H3UniEdge {

    private int $index;

    public function __construct(int $index) {}

    public static function fromLong(int $index): H3UniEdge {}

    public static function fromString(string $value): H3UniEdge {}

    public function isValid(): bool {}

    public function getOrigin(): H3Index {}

    public function getDestination(): H3Index {}

    /**
     * @return H3Index[]
     */
    public function getIndexes(): array {}

    public function getBoundary(): GeoBoundary {}

    public function toLong(): int {}

    public function toString(): string {}
}

final class GeoCoord {

    private float $lat;

    private float $lon;

    public function __construct(float $lat, float $lon) {}

    public function getLat(): float {}

    public function getLon(): float {}
}

final class GeoBoundary {

    /**
     * @var GeoCoord[]
     */
    private array $vertices;

    /**
     * @param GeoCoord[] $vertices
     */
    public function __construct(array $vertices) {}

    /**
     * @return GeoCoord[]
     */
    public function getVertices(): array {}
}
