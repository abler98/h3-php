/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 84eb39aeea3aca52ebb3ed4881dfdec930c79c4c */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_degs_to_rads, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_rads_to_degs, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_hex_area, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, unit, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_H3_edge_length arginfo_H3_hex_area

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_num_hexagons, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_get_res0_indexes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_get_pentagon_indexes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_point_dist, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, a, H3\\GeoCoord, 0)
	ZEND_ARG_OBJ_INFO(0, b, H3\\GeoCoord, 0)
	ZEND_ARG_TYPE_INFO(0, unit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_compact, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, indexes, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_uncompact, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, indexes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_line, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, start, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, end, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_distance, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, a, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, b, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_H3Index___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_fromLong, 0, 1, H3\\H3Index, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_fromString, 0, 1, H3\\H3Index, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_fromGeo, 0, 2, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, geo, H3\\GeoCoord, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_isValid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_isResClassIII arginfo_class_H3_H3Index_isValid

#define arginfo_class_H3_H3Index_isPentagon arginfo_class_H3_H3Index_isValid

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_getResolution, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_getBaseCell arginfo_class_H3_H3Index_getResolution

#define arginfo_class_H3_H3Index_getFaces arginfo_H3_get_res0_indexes

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_kRing, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, k, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_kRingDistances arginfo_class_H3_H3Index_kRing

#define arginfo_class_H3_H3Index_hexRange arginfo_class_H3_H3Index_kRing

#define arginfo_class_H3_H3Index_hexRing arginfo_class_H3_H3Index_kRing

#define arginfo_class_H3_H3Index_hexRangeDistances arginfo_class_H3_H3Index_kRing

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_getArea, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, unit, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_getEdgeLength arginfo_class_H3_H3Index_getArea

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toParent, 0, 1, H3\\H3Index, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_toChildren arginfo_H3_get_pentagon_indexes

#define arginfo_class_H3_H3Index_toCenterChild arginfo_class_H3_H3Index_toParent

#define arginfo_class_H3_H3Index_toLong arginfo_class_H3_H3Index_getResolution

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toGeo, 0, 0, H3\\GeoCoord, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toGeoBoundary, 0, 0, H3\\GeoBoundary, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_GeoCoord___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, lat, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, lon, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_GeoCoord_getLat, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_GeoCoord_getLon arginfo_class_H3_GeoCoord_getLat

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_GeoBoundary___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, vertices, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_GeoBoundary_getVertices arginfo_H3_get_res0_indexes


ZEND_FUNCTION(degs_to_rads);
ZEND_FUNCTION(rads_to_degs);
ZEND_FUNCTION(hex_area);
ZEND_FUNCTION(edge_length);
ZEND_FUNCTION(num_hexagons);
ZEND_FUNCTION(get_res0_indexes);
ZEND_FUNCTION(get_pentagon_indexes);
ZEND_FUNCTION(point_dist);
ZEND_FUNCTION(compact);
ZEND_FUNCTION(uncompact);
ZEND_FUNCTION(line);
ZEND_FUNCTION(distance);
ZEND_METHOD(H3_H3Index, __construct);
ZEND_METHOD(H3_H3Index, fromLong);
ZEND_METHOD(H3_H3Index, fromString);
ZEND_METHOD(H3_H3Index, fromGeo);
ZEND_METHOD(H3_H3Index, isValid);
ZEND_METHOD(H3_H3Index, isResClassIII);
ZEND_METHOD(H3_H3Index, isPentagon);
ZEND_METHOD(H3_H3Index, getResolution);
ZEND_METHOD(H3_H3Index, getBaseCell);
ZEND_METHOD(H3_H3Index, getFaces);
ZEND_METHOD(H3_H3Index, kRing);
ZEND_METHOD(H3_H3Index, kRingDistances);
ZEND_METHOD(H3_H3Index, hexRange);
ZEND_METHOD(H3_H3Index, hexRing);
ZEND_METHOD(H3_H3Index, hexRangeDistances);
ZEND_METHOD(H3_H3Index, getArea);
ZEND_METHOD(H3_H3Index, getEdgeLength);
ZEND_METHOD(H3_H3Index, toParent);
ZEND_METHOD(H3_H3Index, toChildren);
ZEND_METHOD(H3_H3Index, toCenterChild);
ZEND_METHOD(H3_H3Index, toLong);
ZEND_METHOD(H3_H3Index, toString);
ZEND_METHOD(H3_H3Index, toGeo);
ZEND_METHOD(H3_H3Index, toGeoBoundary);
ZEND_METHOD(H3_GeoCoord, __construct);
ZEND_METHOD(H3_GeoCoord, getLat);
ZEND_METHOD(H3_GeoCoord, getLon);
ZEND_METHOD(H3_GeoBoundary, __construct);
ZEND_METHOD(H3_GeoBoundary, getVertices);


static const zend_function_entry ext_functions[] = {
	ZEND_NS_FE("H3", degs_to_rads, arginfo_H3_degs_to_rads)
	ZEND_NS_FE("H3", rads_to_degs, arginfo_H3_rads_to_degs)
	ZEND_NS_FE("H3", hex_area, arginfo_H3_hex_area)
	ZEND_NS_FE("H3", edge_length, arginfo_H3_edge_length)
	ZEND_NS_FE("H3", num_hexagons, arginfo_H3_num_hexagons)
	ZEND_NS_FE("H3", get_res0_indexes, arginfo_H3_get_res0_indexes)
	ZEND_NS_FE("H3", get_pentagon_indexes, arginfo_H3_get_pentagon_indexes)
	ZEND_NS_FE("H3", point_dist, arginfo_H3_point_dist)
	ZEND_NS_FE("H3", compact, arginfo_H3_compact)
	ZEND_NS_FE("H3", uncompact, arginfo_H3_uncompact)
	ZEND_NS_FE("H3", line, arginfo_H3_line)
	ZEND_NS_FE("H3", distance, arginfo_H3_distance)
	ZEND_FE_END
};


static const zend_function_entry class_H3_H3Exception_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_H3_H3Index_methods[] = {
	ZEND_ME(H3_H3Index, __construct, arginfo_class_H3_H3Index___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, fromLong, arginfo_class_H3_H3Index_fromLong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(H3_H3Index, fromString, arginfo_class_H3_H3Index_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(H3_H3Index, fromGeo, arginfo_class_H3_H3Index_fromGeo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(H3_H3Index, isValid, arginfo_class_H3_H3Index_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, isResClassIII, arginfo_class_H3_H3Index_isResClassIII, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, isPentagon, arginfo_class_H3_H3Index_isPentagon, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getResolution, arginfo_class_H3_H3Index_getResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getBaseCell, arginfo_class_H3_H3Index_getBaseCell, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getFaces, arginfo_class_H3_H3Index_getFaces, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, kRing, arginfo_class_H3_H3Index_kRing, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, kRingDistances, arginfo_class_H3_H3Index_kRingDistances, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, hexRange, arginfo_class_H3_H3Index_hexRange, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, hexRing, arginfo_class_H3_H3Index_hexRing, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, hexRangeDistances, arginfo_class_H3_H3Index_hexRangeDistances, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getArea, arginfo_class_H3_H3Index_getArea, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getEdgeLength, arginfo_class_H3_H3Index_getEdgeLength, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toParent, arginfo_class_H3_H3Index_toParent, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toChildren, arginfo_class_H3_H3Index_toChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toCenterChild, arginfo_class_H3_H3Index_toCenterChild, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toLong, arginfo_class_H3_H3Index_toLong, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toString, arginfo_class_H3_H3Index_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toGeo, arginfo_class_H3_H3Index_toGeo, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toGeoBoundary, arginfo_class_H3_H3Index_toGeoBoundary, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_GeoCoord_methods[] = {
	ZEND_ME(H3_GeoCoord, __construct, arginfo_class_H3_GeoCoord___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoCoord, getLat, arginfo_class_H3_GeoCoord_getLat, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoCoord, getLon, arginfo_class_H3_GeoCoord_getLon, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_GeoBoundary_methods[] = {
	ZEND_ME(H3_GeoBoundary, __construct, arginfo_class_H3_GeoBoundary___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoBoundary, getVertices, arginfo_class_H3_GeoBoundary_getVertices, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_H3_H3Exception(zend_class_entry *class_entry_RuntimeException)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "H3Exception", class_H3_H3Exception_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_RuntimeException);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

static zend_class_entry *register_class_H3_H3Index(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "H3Index", class_H3_H3Index_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_index_default_value;
	ZVAL_UNDEF(&property_index_default_value);
	zend_string *property_index_name = zend_string_init("index", sizeof("index") - 1, 1);
	zend_declare_typed_property(class_entry, property_index_name, &property_index_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_GeoCoord(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "GeoCoord", class_H3_GeoCoord_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_lat_default_value;
	ZVAL_UNDEF(&property_lat_default_value);
	zend_string *property_lat_name = zend_string_init("lat", sizeof("lat") - 1, 1);
	zend_declare_typed_property(class_entry, property_lat_name, &property_lat_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lat_name);

	zval property_lon_default_value;
	ZVAL_UNDEF(&property_lon_default_value);
	zend_string *property_lon_name = zend_string_init("lon", sizeof("lon") - 1, 1);
	zend_declare_typed_property(class_entry, property_lon_name, &property_lon_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_lon_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_GeoBoundary(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "GeoBoundary", class_H3_GeoBoundary_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_vertices_default_value;
	ZVAL_UNDEF(&property_vertices_default_value);
	zend_string *property_vertices_name = zend_string_init("vertices", sizeof("vertices") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertices_name, &property_vertices_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_vertices_name);

	return class_entry;
}
