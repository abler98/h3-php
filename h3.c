/* h3 extension for PHP */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "ext/spl/spl_exceptions.h"
#include "ext/standard/info.h"
#include "h3_arginfo.h"
#include "php.h"
#include "php_h3.h"
#include "zend_exceptions.h"
#include <h3/h3api.h>

#define H3_STRVAL_LEN 17
#define H3_INVALID_INDEX 0
#define H3_HEX_NUM_EDGES 6
#define H3_EDGE_NUM_INDX 2
#define H3_MIN_RES 0
#define H3_MAX_RES 15

#define H3_AREA_UNIT_KM2 0
#define H3_AREA_UNIT_M2 1
#define H3_AREA_UNIT_RADS2 2

#define H3_LENGTH_UNIT_KM 0
#define H3_LENGTH_UNIT_M 1
#define H3_LENGTH_UNIT_RADS 2

#define H3_ERR_CODE_INVALID_RES 1
#define H3_ERR_CODE_UNSUPPORTED_UNIT 2
#define H3_ERR_CODE_COMPACT_ERROR 3
#define H3_ERR_CODE_UNCOMPACT_ERROR 4
#define H3_ERR_CODE_LINE_SIZE_ERROR 5
#define H3_ERR_CODE_PENTAGON_ENCOUNTERED 6

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE()  \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif

#define H3_THROW(message, code) zend_throw_exception(H3_H3Exception_ce, message, code)

#define VALIDATE_H3_RES(res)                                     \
    if (res < H3_MIN_RES || res > H3_MAX_RES) {                  \
        H3_THROW("Invalid resolution", H3_ERR_CODE_INVALID_RES); \
        RETURN_THROWS();                                         \
    }

typedef H3Index H3UniEdge;

zend_class_entry *H3_H3Exception_ce;
zend_class_entry *H3_H3Index_ce;
zend_class_entry *H3_H3UniEdge_ce;
zend_class_entry *H3_GeoCoord_ce;
zend_class_entry *H3_GeoBoundary_ce;

int max_hex_kring_size(int k)
{
    return k == 0 ? 1 : k * H3_HEX_NUM_EDGES;
}

H3Index obj_to_h3(zend_object *obj)
{
    zval *prop;
    zval rv;

    prop = zend_read_property(H3_H3Index_ce, obj, "index", sizeof("index") - 1, 1, &rv);

    return zval_get_long(prop);
}

zend_object *h3_to_obj(H3Index index)
{
    zend_object *obj = zend_objects_new(H3_H3Index_ce);
    object_properties_init(obj, H3_H3Index_ce);
    zend_update_property_long(H3_H3Index_ce, obj, "index", sizeof("index") - 1, index);

    return obj;
}

void h3_array_to_zend_array(H3Index *in, int size, zval *out)
{
    for (int i = 0; i < size; i++) {
        if (in[i] != H3_INVALID_INDEX) {
            add_next_index_object(out, h3_to_obj(in[i]));
        }
    }
}

H3UniEdge obj_to_h3ue(zend_object *obj)
{
    zval *prop;
    zval rv;

    prop = zend_read_property(H3_H3UniEdge_ce, obj, "index", sizeof("index") - 1, 1, &rv);

    return zval_get_long(prop);
}

zend_object *h3ue_to_obj(H3UniEdge index)
{
    zend_object *obj = zend_objects_new(H3_H3UniEdge_ce);
    object_properties_init(obj, H3_H3UniEdge_ce);
    zend_update_property_long(H3_H3UniEdge_ce, obj, "index", sizeof("index") - 1, index);

    return obj;
}

void h3ue_array_to_zend_array(H3UniEdge *in, int size, zval *out)
{
    for (int i = 0; i < size; i++) {
        if (in[i] != H3_INVALID_INDEX) {
            add_next_index_object(out, h3ue_to_obj(in[i]));
        }
    }
}

void obj_to_geo(zend_object *obj, GeoCoord *geo)
{
    zval *prop;
    zval rv;

    prop = zend_read_property(H3_GeoCoord_ce, obj, "lat", sizeof("lat") - 1, 1, &rv);
    geo->lat = degsToRads(zval_get_double(prop));
    prop = zend_read_property(H3_GeoCoord_ce, obj, "lon", sizeof("lon") - 1, 1, &rv);
    geo->lon = degsToRads(zval_get_double(prop));
}

zend_object *geo_to_obj(GeoCoord *geo)
{
    zend_object *obj = zend_objects_new(H3_GeoCoord_ce);
    object_properties_init(obj, H3_GeoCoord_ce);

    zend_update_property_double(H3_GeoCoord_ce, obj, "lat", sizeof("lat") - 1, radsToDegs(geo->lat));
    zend_update_property_double(H3_GeoCoord_ce, obj, "lon", sizeof("lon") - 1, radsToDegs(geo->lon));

    return obj;
}

zend_object *geo_boundary_to_obj(GeoBoundary *boundary)
{
    zval *val = emalloc(sizeof(zval));
    array_init_size(val, boundary->numVerts);

    for (int i = 0; i < boundary->numVerts; i++) {
        add_next_index_object(val, geo_to_obj(&boundary->verts[i]));
    }

    zend_object *obj = zend_objects_new(H3_GeoBoundary_ce);
    object_properties_init(obj, H3_GeoCoord_ce);

    zend_update_property(H3_GeoBoundary_ce, obj, "vertices", sizeof("vertices") - 1, val);

    efree(val);

    return obj;
}

PHP_FUNCTION(degs_to_rads)
{
    double degrees;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degrees)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    RETURN_DOUBLE(degsToRads(degrees));
}

PHP_FUNCTION(rads_to_degs)
{
    double radians;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(radians)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    RETURN_DOUBLE(radsToDegs(radians));
}

PHP_FUNCTION(hex_area)
{
    zend_long res;
    zend_long unit;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(res)
        Z_PARAM_LONG(unit)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    switch (unit) {
        case H3_AREA_UNIT_KM2:
            RETURN_DOUBLE(hexAreaKm2(res));
        case H3_AREA_UNIT_M2:
            RETURN_DOUBLE(hexAreaM2(res));
        default:
            H3_THROW("Unsupported unit (must be one of H3_AREA_UNIT_KM2, or H3_AREA_UNIT_M2)",
                     H3_ERR_CODE_UNSUPPORTED_UNIT);
            RETURN_THROWS();
    }
}

PHP_FUNCTION(edge_length)
{
    zend_long res;
    zend_long unit;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(res)
        Z_PARAM_LONG(unit)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    switch (unit) {
        case H3_LENGTH_UNIT_KM:
            RETURN_DOUBLE(edgeLengthKm(res));
        case H3_LENGTH_UNIT_M:
            RETURN_DOUBLE(edgeLengthM(res));
        default:
            H3_THROW("Unsupported unit (must be one of H3_LENGTH_UNIT_KM, or H3_LENGTH_UNIT_RADS)",
                     H3_ERR_CODE_UNSUPPORTED_UNIT);
            RETURN_THROWS();
    }
}

PHP_FUNCTION(num_hexagons)
{
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    RETURN_LONG(numHexagons(res));
}

PHP_FUNCTION(get_res0_indexes)
{
    ZEND_PARSE_PARAMETERS_NONE();

    int max = res0IndexCount();

    H3Index *indexes = ecalloc(max, sizeof(H3Index));
    getRes0Indexes(indexes);

    array_init_size(return_value, max);
    h3_array_to_zend_array(indexes, max, return_value);

    efree(indexes);
}

PHP_FUNCTION(get_pentagon_indexes)
{
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    int max = pentagonIndexCount();

    H3Index *indexes = ecalloc(max, sizeof(H3Index));
    getPentagonIndexes(res, indexes);

    array_init_size(return_value, max);
    h3_array_to_zend_array(indexes, max, return_value);

    efree(indexes);
}

PHP_FUNCTION(point_dist)
{
    zend_object *a;
    zend_object *b;
    zend_long unit;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJ_OF_CLASS(a, H3_GeoCoord_ce)
        Z_PARAM_OBJ_OF_CLASS(b, H3_GeoCoord_ce)
        Z_PARAM_LONG(unit)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    GeoCoord *geoA = emalloc(sizeof(GeoCoord));
    GeoCoord *geoB = emalloc(sizeof(GeoCoord));

    obj_to_geo(a, geoA);
    obj_to_geo(b, geoB);

    switch (unit) {
        case H3_LENGTH_UNIT_KM:
            RETVAL_DOUBLE(pointDistKm(geoA, geoB));
            break;
        case H3_LENGTH_UNIT_M:
            RETVAL_DOUBLE(pointDistM(geoA, geoB));
            break;
        case H3_LENGTH_UNIT_RADS:
            RETVAL_DOUBLE(pointDistRads(geoA, geoB));
            break;
        default:
            H3_THROW("Unsupported unit (must be one of H3_LENGTH_UNIT_KM, H3_LENGTH_UNIT_M, or H3_LENGTH_UNIT_RADS)",
                     H3_ERR_CODE_UNSUPPORTED_UNIT);
            break;
    }

    efree(geoA);
    efree(geoB);

    if (Z_TYPE_P(return_value) == IS_NULL) {
        RETURN_THROWS();
    }
}

PHP_FUNCTION(compact)
{
    zval *indexes;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(indexes)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_array *arr = Z_ARR_P(indexes);
    int count = zend_array_count(arr);

    H3Index *set = ecalloc(count, sizeof(H3Index));
    H3Index *compactedSet = ecalloc(count, sizeof(H3Index));

    for (int i = 0; i < count; i++) {
        set[i] = obj_to_h3(Z_OBJ_P(zend_hash_index_find(arr, i)));
    }

    if (compact(set, compactedSet, count) != 0) {
        H3_THROW("Failed to compact", H3_ERR_CODE_COMPACT_ERROR);
        efree(set);
        efree(compactedSet);
        RETURN_THROWS();
    }

    array_init(return_value);
    h3_array_to_zend_array(compactedSet, count, return_value);

    efree(set);
    efree(compactedSet);
}

PHP_FUNCTION(uncompact)
{
    zval *indexes;
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(indexes)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    zend_array *arr = Z_ARR_P(indexes);
    int count = zend_array_count(arr);

    H3Index *compactedSet = ecalloc(count, sizeof(H3Index));

    for (int i = 0; i < count; i++) {
        compactedSet[i] = obj_to_h3(Z_OBJ_P(zend_hash_index_find(arr, i)));
    }

    int max = maxUncompactSize(compactedSet, count, res);

    if (max < 0) {
        H3_THROW("Unknown uncompact error", H3_ERR_CODE_UNCOMPACT_ERROR);
        efree(compactedSet);
        RETURN_THROWS();
    }

    H3Index *set = ecalloc(max, sizeof(H3Index));

    if (uncompact(compactedSet, count, set, max, res) != 0) {
        H3_THROW("Failed to uncompact", H3_ERR_CODE_UNCOMPACT_ERROR);
        efree(compactedSet);
        efree(set);
        RETURN_THROWS();
    }

    array_init(return_value);
    h3_array_to_zend_array(set, max, return_value);

    efree(compactedSet);
    efree(set);
}

PHP_FUNCTION(line)
{
    zend_object *start;
    zend_object *end;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJ_OF_CLASS(start, H3_H3Index_ce)
        Z_PARAM_OBJ_OF_CLASS(end, H3_H3Index_ce)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index startIndex = obj_to_h3(start);
    H3Index endIndex = obj_to_h3(end);

    int size = h3LineSize(startIndex, endIndex);

    if (size < 0) {
        H3_THROW("Failed to caluclate line size", H3_ERR_CODE_LINE_SIZE_ERROR);
        RETURN_THROWS();
    }

    H3Index *out = ecalloc(size, sizeof(H3Index));
    h3Line(startIndex, endIndex, out);

    array_init(return_value);
    h3_array_to_zend_array(out, size, return_value);

    efree(out);
}

PHP_FUNCTION(distance)
{
    zend_object *a;
    zend_object *b;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJ_OF_CLASS(a, H3_H3Index_ce)
        Z_PARAM_OBJ_OF_CLASS(b, H3_H3Index_ce)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    RETURN_LONG(h3Distance(obj_to_h3(a), obj_to_h3(b)));
}

PHP_FUNCTION(indexes_are_neighbors)
{
    zend_object *org;
    zend_object *dest;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJ_OF_CLASS(org, H3_H3Index_ce)
        Z_PARAM_OBJ_OF_CLASS(dest, H3_H3Index_ce)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index origin = obj_to_h3(org);
    H3Index destination = obj_to_h3(dest);

    RETURN_BOOL(h3IndexesAreNeighbors(origin, destination));
}

PHP_METHOD(H3_H3Index, __construct)
{
    zend_ulong index;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_update_property_long(H3_H3Index_ce, Z_OBJ_P(ZEND_THIS), "index", sizeof("index") - 1, index);
}

PHP_METHOD(H3_H3Index, fromLong)
{
    zend_ulong index;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_object *obj = zend_objects_new(H3_H3Index_ce);
    object_properties_init(obj, H3_H3Index_ce);
    zend_update_property_long(H3_H3Index_ce, obj, "index", sizeof("index") - 1, index);

    RETURN_OBJ(obj);
}

PHP_METHOD(H3_H3Index, fromString)
{
    zend_string *value;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(value)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    RETURN_OBJ(h3_to_obj(stringToH3(ZSTR_VAL(value))));
}

PHP_METHOD(H3_H3Index, fromGeo)
{
    zend_object *geo_obj;
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJ_OF_CLASS(geo_obj, H3_GeoCoord_ce)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    GeoCoord *geo = emalloc(sizeof(GeoCoord));
    obj_to_geo(geo_obj, geo);
    H3Index index = geoToH3(geo, res);
    efree(geo);

    if (index == H3_INVALID_INDEX) {
        H3_THROW("Failed to create H3 index from geo coordinates", 0);
        RETURN_THROWS();
    }

    RETURN_OBJ(h3_to_obj(index));
}

PHP_METHOD(H3_H3Index, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(h3IsValid(obj_to_h3(Z_OBJ_P(ZEND_THIS))));
}

PHP_METHOD(H3_H3Index, isResClassIII)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(h3IsResClassIII(obj_to_h3(Z_OBJ_P(ZEND_THIS))));
}

PHP_METHOD(H3_H3Index, isPentagon)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(h3IsPentagon(obj_to_h3(Z_OBJ_P(ZEND_THIS))));
}

PHP_METHOD(H3_H3Index, getResolution)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(h3GetResolution(obj_to_h3(Z_OBJ_P(ZEND_THIS))));
}

PHP_METHOD(H3_H3Index, getBaseCell)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(h3GetBaseCell(obj_to_h3(Z_OBJ_P(ZEND_THIS))));
}

PHP_METHOD(H3_H3Index, getFaces)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    int max = maxFaceCount(index);

    int *out = ecalloc(max, sizeof(int));
    h3GetFaces(index, out);

    array_init(return_value);

    for (int i = 0; i < max; i++) {
        if (out[i] >= 0) {
            add_next_index_long(return_value, out[i]);
        }
    }

    efree(out);
}

PHP_METHOD(H3_H3Index, kRing)
{
    zend_long k;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(k)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    int max = maxKringSize(k);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(max, sizeof(H3Index));
    kRing(index, k, out);

    array_init(return_value);
    h3_array_to_zend_array(out, max, return_value);

    efree(out);
}

PHP_METHOD(H3_H3Index, kRingDistances)
{
    zend_long k;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(k)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    int max = maxKringSize(k);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(max, sizeof(H3Index));
    int *distances = ecalloc(max, sizeof(int));
    kRingDistances(index, k, out, distances);

    array_init_size(return_value, k + 1);

    zval *values = ecalloc(k + 1, sizeof(zval));

    for (int i = 0; i < (k + 1); i++) {
        array_init(&values[i]);
        add_next_index_zval(return_value, &values[i]);
    }

    for (int i = 0; i < max; i++) {
        if (out[i] != H3_INVALID_INDEX) {
            add_next_index_object(&values[distances[i]], h3_to_obj(out[i]));
        }
    }

    efree(out);
    efree(distances);
    efree(values);
}

PHP_METHOD(H3_H3Index, hexRange)
{
    zend_long k;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(k)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    int max = maxKringSize(k);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(max, sizeof(H3Index));

    if (hexRange(index, k, out) != 0) {
        H3_THROW("Pentagonal distortion is encountered", H3_ERR_CODE_PENTAGON_ENCOUNTERED);
        efree(out);
        RETURN_THROWS();
    }

    array_init(return_value);
    h3_array_to_zend_array(out, max, return_value);

    efree(out);
}

PHP_METHOD(H3_H3Index, hexRing)
{
    zend_long k;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(k)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    int max = max_hex_kring_size(k);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(max, sizeof(H3Index));

    if (hexRing(index, k, out) != 0) {
        H3_THROW("Pentagonal distortion is encountered", H3_ERR_CODE_PENTAGON_ENCOUNTERED);
        efree(out);
        RETURN_THROWS();
    }

    array_init(return_value);
    h3_array_to_zend_array(out, max, return_value);

    efree(out);
}

PHP_METHOD(H3_H3Index, hexRangeDistances)
{
    zend_long k;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(k)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    int max = maxKringSize(k);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(max, sizeof(H3Index));
    int *distances = ecalloc(max, sizeof(int));

    if (hexRangeDistances(index, k, out, distances) != 0) {
        H3_THROW("Pentagonal distortion is encountered", H3_ERR_CODE_PENTAGON_ENCOUNTERED);
        efree(out);
        efree(distances);
        RETURN_THROWS();
    }

    array_init_size(return_value, k + 1);

    zval *values = ecalloc(k + 1, sizeof(zval));

    for (int i = 0; i < (k + 1); i++) {
        array_init(&values[i]);
        add_next_index_zval(return_value, &values[i]);
    }

    for (int i = 0; i < max; i++) {
        if (out[i] != H3_INVALID_INDEX) {
            add_next_index_object(&values[distances[i]], h3_to_obj(out[i]));
        }
    }

    efree(out);
    efree(distances);
    efree(values);
}

PHP_METHOD(H3_H3Index, getArea)
{
    zend_long unit;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(unit)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));

    switch (unit) {
        case H3_AREA_UNIT_KM2:
            RETURN_DOUBLE(cellAreaKm2(index));
        case H3_AREA_UNIT_M2:
            RETURN_DOUBLE(cellAreaM2(index));
        case H3_AREA_UNIT_RADS2:
            RETURN_DOUBLE(cellAreaRads2(index));
        default:
            H3_THROW("Unsupported unit (must be one of H3_AREA_UNIT_KM2, H3_AREA_UNIT_M2, or H3_AREA_UNIT_RADS2)",
                     H3_ERR_CODE_UNSUPPORTED_UNIT);
            RETURN_THROWS();
    }
}

PHP_METHOD(H3_H3Index, getEdgeLength)
{
    zend_long unit;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(unit)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));

    switch (unit) {
        case H3_LENGTH_UNIT_KM:
            RETURN_DOUBLE(exactEdgeLengthKm(index));
        case H3_LENGTH_UNIT_M:
            RETURN_DOUBLE(exactEdgeLengthM(index));
        case H3_LENGTH_UNIT_RADS:
            RETURN_DOUBLE(exactEdgeLengthRads(index));
        default:
            H3_THROW("Unsupported unit (must be one of H3_LENGTH_UNIT_KM, H3_LENGTH_UNIT_M, or H3_LENGTH_UNIT_RADS)",
                     H3_ERR_CODE_UNSUPPORTED_UNIT);
            RETURN_THROWS();
    }
}

PHP_METHOD(H3_H3Index, isNeighborTo)
{
    zend_object *dest;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(dest, H3_H3Index_ce)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index origin = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index destination = obj_to_h3(dest);

    RETURN_BOOL(h3IndexesAreNeighbors(origin, destination));
}

PHP_METHOD(H3_H3Index, getUnidirectionalEdges)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3UniEdge *edges = ecalloc(H3_HEX_NUM_EDGES, sizeof(H3UniEdge));
    getH3UnidirectionalEdgesFromHexagon(index, edges);

    array_init_size(return_value, H3_HEX_NUM_EDGES);
    h3ue_array_to_zend_array(edges, H3_HEX_NUM_EDGES, return_value);

    efree(edges);
}

PHP_METHOD(H3_H3Index, getUnidirectionalEdge)
{
    zend_object *dest;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(dest, H3_H3Index_ce)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    H3Index origin = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index destination = obj_to_h3(dest);
    H3UniEdge edge = getH3UnidirectionalEdge(origin, destination);

    RETURN_OBJ(h3ue_to_obj(edge));
}

PHP_METHOD(H3_H3Index, toParent)
{
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index parent = h3ToParent(index, res);

    RETURN_OBJ(h3_to_obj(parent));
}

PHP_METHOD(H3_H3Index, toChildren)
{
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    int max = maxH3ToChildrenSize(index, res);

    H3Index *children = ecalloc(max, sizeof(H3Index));
    h3ToChildren(index, res, children);

    array_init(return_value);
    h3_array_to_zend_array(children, max, return_value);

    efree(children);
}

PHP_METHOD(H3_H3Index, toCenterChild)
{
    zend_long res;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(res)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    VALIDATE_H3_RES(res);

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));
    H3Index child = h3ToCenterChild(index, res);

    RETURN_OBJ(h3_to_obj(child));
}

PHP_METHOD(H3_H3Index, toLong)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(obj_to_h3(Z_OBJ_P(ZEND_THIS)));
}

PHP_METHOD(H3_H3Index, toString)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));

    char *out = emalloc(H3_STRVAL_LEN);
    h3ToString(index, out, H3_STRVAL_LEN);
    RETVAL_STRINGL(out, strlen(out));
    efree(out);
}

PHP_METHOD(H3_H3Index, toGeo)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));

    GeoCoord *geo = emalloc(sizeof(GeoCoord));
    h3ToGeo(index, geo);
    RETVAL_OBJ(geo_to_obj(geo));
    efree(geo);
}

PHP_METHOD(H3_H3Index, toGeoBoundary)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3Index index = obj_to_h3(Z_OBJ_P(ZEND_THIS));

    GeoBoundary *boundary = emalloc(sizeof(GeoBoundary));
    h3ToGeoBoundary(index, boundary);
    RETVAL_OBJ(geo_boundary_to_obj(boundary));
    efree(boundary);
}

PHP_METHOD(H3_H3UniEdge, __construct)
{
    zend_ulong index;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_update_property_long(H3_H3UniEdge_ce, Z_OBJ_P(ZEND_THIS), "index", sizeof("index") - 1, index);
}

PHP_METHOD(H3_H3UniEdge, fromLong)
{
    zend_ulong index;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_object *obj = zend_objects_new(H3_H3UniEdge_ce);
    object_properties_init(obj, H3_H3UniEdge_ce);
    zend_update_property_long(H3_H3UniEdge_ce, obj, "index", sizeof("index") - 1, index);

    RETURN_OBJ(obj);
}

PHP_METHOD(H3_H3UniEdge, fromString)
{
    zend_string *value;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(value)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    RETURN_OBJ(h3ue_to_obj(stringToH3(ZSTR_VAL(value))));
}

PHP_METHOD(H3_H3UniEdge, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));

    RETURN_BOOL(h3UnidirectionalEdgeIsValid(edge));
}

PHP_METHOD(H3_H3UniEdge, getOrigin)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));
    H3Index origin = getOriginH3IndexFromUnidirectionalEdge(edge);

    RETURN_OBJ(h3_to_obj(origin));
}

PHP_METHOD(H3_H3UniEdge, getDestination)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));
    H3Index destination = getDestinationH3IndexFromUnidirectionalEdge(edge);

    RETURN_OBJ(h3_to_obj(destination));
}

PHP_METHOD(H3_H3UniEdge, getIndexes)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));
    H3Index *out = ecalloc(H3_EDGE_NUM_INDX, sizeof(H3Index));
    getH3IndexesFromUnidirectionalEdge(edge, out);

    array_init_size(return_value, H3_EDGE_NUM_INDX);
    h3_array_to_zend_array(out, H3_EDGE_NUM_INDX, return_value);

    efree(out);
}

PHP_METHOD(H3_H3UniEdge, getBoundary)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));
    GeoBoundary *boundary = emalloc(sizeof(GeoBoundary));
    getH3UnidirectionalEdgeBoundary(edge, boundary);

    RETVAL_OBJ(geo_boundary_to_obj(boundary));

    efree(boundary);
}

PHP_METHOD(H3_H3UniEdge, toLong)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(obj_to_h3ue(Z_OBJ_P(ZEND_THIS)));
}

PHP_METHOD(H3_H3UniEdge, toString)
{
    ZEND_PARSE_PARAMETERS_NONE();

    H3UniEdge edge = obj_to_h3ue(Z_OBJ_P(ZEND_THIS));

    char *out = emalloc(H3_STRVAL_LEN);
    h3ToString(edge, out, H3_STRVAL_LEN);
    RETVAL_STRINGL(out, strlen(out));
    efree(out);
}

PHP_METHOD(H3_GeoCoord, __construct)
{
    double lat, lon;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(lat)
        Z_PARAM_DOUBLE(lon)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_update_property_double(H3_GeoCoord_ce, Z_OBJ_P(ZEND_THIS), "lat", sizeof("lat") - 1, lat);
    zend_update_property_double(H3_GeoCoord_ce, Z_OBJ_P(ZEND_THIS), "lon", sizeof("lon") - 1, lon);
}

PHP_METHOD(H3_GeoCoord, getLat)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zval *prop;
    zval rv;

    prop = zend_read_property(H3_GeoCoord_ce, Z_OBJ_P(ZEND_THIS), "lat", sizeof("lat") - 1, 1, &rv);

    RETURN_ZVAL(prop, 1, 0);
}

PHP_METHOD(H3_GeoCoord, getLon)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zval *prop;
    zval rv;

    prop = zend_read_property(H3_GeoCoord_ce, Z_OBJ_P(ZEND_THIS), "lon", sizeof("lon") - 1, 1, &rv);

    RETURN_ZVAL(prop, 1, 0);
}

PHP_METHOD(H3_GeoBoundary, __construct)
{
    zval *vertices;

    // clang-format off
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(vertices)
    ZEND_PARSE_PARAMETERS_END();
    // clang-format on

    zend_update_property(H3_GeoBoundary_ce, Z_OBJ_P(ZEND_THIS), "vertices", sizeof("vertices") - 1, vertices);
}

PHP_METHOD(H3_GeoBoundary, getVertices)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zval *prop;
    zval rv;

    prop = zend_read_property(H3_GeoBoundary_ce, Z_OBJ_P(ZEND_THIS), "vertices", sizeof("vertices") - 1, 1, &rv);

    RETURN_ARR(Z_ARR_P(prop));
}

PHP_MINIT_FUNCTION(h3)
{
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_INVALID_RES", H3_ERR_CODE_INVALID_RES, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_UNSUPPORTED_UNIT", H3_ERR_CODE_UNSUPPORTED_UNIT, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_COMPACT_ERROR", H3_ERR_CODE_COMPACT_ERROR, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_UNCOMPACT_ERROR", H3_ERR_CODE_UNCOMPACT_ERROR, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_LINE_SIZE_ERROR", H3_ERR_CODE_LINE_SIZE_ERROR, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_ERR_CODE_PENTAGON_ENCOUNTERED", H3_ERR_CODE_PENTAGON_ENCOUNTERED, CONST_PERSISTENT);

    REGISTER_LONG_CONSTANT("H3_AREA_UNIT_KM2", H3_AREA_UNIT_KM2, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_AREA_UNIT_M2", H3_AREA_UNIT_M2, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_AREA_UNIT_RADS2", H3_AREA_UNIT_RADS2, CONST_PERSISTENT);

    REGISTER_LONG_CONSTANT("H3_LENGTH_UNIT_KM", H3_LENGTH_UNIT_KM, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_LENGTH_UNIT_M", H3_LENGTH_UNIT_M, CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("H3_LENGTH_UNIT_RADS", H3_LENGTH_UNIT_RADS, CONST_PERSISTENT);

    H3_H3Exception_ce = register_class_H3_H3Exception(spl_ce_RuntimeException);
    H3_H3Index_ce = register_class_H3_H3Index();
    H3_H3UniEdge_ce = register_class_H3_H3UniEdge();
    H3_GeoCoord_ce = register_class_H3_GeoCoord();
    H3_GeoBoundary_ce = register_class_H3_GeoBoundary();

    return SUCCESS;
}

PHP_RINIT_FUNCTION(h3)
{
#if defined(ZTS) && defined(COMPILE_DL_H3)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}

PHP_MINFO_FUNCTION(h3)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "h3 support", "enabled");
    php_info_print_table_end();
}

// clang-format off
zend_module_entry h3_module_entry = {
    STANDARD_MODULE_HEADER,
    "h3",
    ext_functions,
    PHP_MINIT(h3),
    NULL,
    PHP_RINIT(h3),
    NULL,
    PHP_MINFO(h3),
    PHP_H3_VERSION,
    STANDARD_MODULE_PROPERTIES
};
// clang-format on

#ifdef COMPILE_DL_H3
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(h3)
#endif
