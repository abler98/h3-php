/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: h3v4-upgrade */

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
	ZEND_ARG_OBJ_INFO(0, a, H3\\LatLng, 0)
	ZEND_ARG_OBJ_INFO(0, b, H3\\LatLng, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_indexes_are_neighbors, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, origin, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, destination, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_H3_polyfill, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, polygon, H3\\GeoPolygon, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_H3_h3_set_to_multi_polygon, 0, 1, H3\\GeoMultiPolygon, 0)
	ZEND_ARG_TYPE_INFO(0, indexes, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_H3_experimental_h3_to_local_ij, 0, 2, H3\\CoordIJ, 0)
	ZEND_ARG_OBJ_INFO(0, origin, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, h, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_H3_experimental_local_ij_to_h3, 0, 2, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, origin, H3\\H3Index, 0)
	ZEND_ARG_OBJ_INFO(0, ij, H3\\CoordIJ, 0)
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
	ZEND_ARG_OBJ_INFO(0, geo, H3\\LatLng, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_getCellArea, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, unit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_isNeighborTo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, destination, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_getLineTo, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, destination, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_getDistanceTo, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, destination, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_getDirectedEdges arginfo_H3_get_res0_indexes

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_getDirectedEdge, 0, 1, H3\\H3DirectedEdge, 0)
	ZEND_ARG_OBJ_INFO(0, destination, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toParent, 0, 1, H3\\H3Index, 0)
	ZEND_ARG_TYPE_INFO(0, res, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index_toChildren arginfo_H3_get_pentagon_indexes

#define arginfo_class_H3_H3Index_toCenterChild arginfo_class_H3_H3Index_toParent

#define arginfo_class_H3_H3Index_toLong arginfo_class_H3_H3Index_getResolution

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_H3Index_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toGeo, 0, 0, H3\\LatLng, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3Index_toGeoBoundary, 0, 0, H3\\CellBoundary, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3Index___toString arginfo_class_H3_H3Index_toString

#define arginfo_class_H3_H3DirectedEdge___construct arginfo_class_H3_H3Index___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3DirectedEdge_fromLong, 0, 1, H3\\H3DirectedEdge, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3DirectedEdge_fromString, 0, 1, H3\\H3DirectedEdge, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3DirectedEdge_isValid arginfo_class_H3_H3Index_isValid

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_H3_H3DirectedEdge_getOrigin, 0, 0, H3\\H3Index, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_H3DirectedEdge_getDestination arginfo_class_H3_H3DirectedEdge_getOrigin

#define arginfo_class_H3_H3DirectedEdge_getIndexes arginfo_H3_get_res0_indexes

#define arginfo_class_H3_H3DirectedEdge_getBoundary arginfo_class_H3_H3Index_toGeoBoundary

#define arginfo_class_H3_H3DirectedEdge_getLength arginfo_class_H3_H3Index_getCellArea

#define arginfo_class_H3_H3DirectedEdge_toLong arginfo_class_H3_H3Index_getResolution

#define arginfo_class_H3_H3DirectedEdge_toString arginfo_class_H3_H3Index_toString

#define arginfo_class_H3_H3DirectedEdge___toString arginfo_class_H3_H3Index_toString

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_LatLng___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, lat, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, lon, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_H3_LatLng_getLat, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_LatLng_getLon arginfo_class_H3_LatLng_getLat

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_CellBoundary___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, vertices, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_CellBoundary_getVertices arginfo_H3_get_res0_indexes

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_GeoPolygon___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, geofence, H3\\CellBoundary, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, holes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

#define arginfo_class_H3_GeoPolygon_getGeofence arginfo_class_H3_H3Index_toGeoBoundary

#define arginfo_class_H3_GeoPolygon_getHoles arginfo_H3_get_res0_indexes

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_GeoMultiPolygon___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, polygons, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_GeoMultiPolygon_getPolygons arginfo_H3_get_res0_indexes

#define arginfo_class_H3_GeoMultiPolygon_toGeoJson arginfo_H3_get_res0_indexes

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_H3_CoordIJ___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, i, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, j, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_H3_CoordIJ_getI arginfo_class_H3_H3Index_getResolution

#define arginfo_class_H3_CoordIJ_getJ arginfo_class_H3_H3Index_getResolution


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
ZEND_FUNCTION(indexes_are_neighbors);
ZEND_FUNCTION(polyfill);
ZEND_FUNCTION(h3_set_to_multi_polygon);
ZEND_FUNCTION(experimental_h3_to_local_ij);
ZEND_FUNCTION(experimental_local_ij_to_h3);
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
ZEND_METHOD(H3_H3Index, getCellArea);
ZEND_METHOD(H3_H3Index, isNeighborTo);
ZEND_METHOD(H3_H3Index, getLineTo);
ZEND_METHOD(H3_H3Index, getDistanceTo);
ZEND_METHOD(H3_H3Index, getDirectedEdges);
ZEND_METHOD(H3_H3Index, getDirectedEdge);
ZEND_METHOD(H3_H3Index, toParent);
ZEND_METHOD(H3_H3Index, toChildren);
ZEND_METHOD(H3_H3Index, toCenterChild);
ZEND_METHOD(H3_H3Index, toLong);
ZEND_METHOD(H3_H3Index, toString);
ZEND_METHOD(H3_H3Index, toGeo);
ZEND_METHOD(H3_H3Index, toGeoBoundary);
ZEND_METHOD(H3_H3Index, __toString);
ZEND_METHOD(H3_H3DirectedEdge, __construct);
ZEND_METHOD(H3_H3DirectedEdge, fromLong);
ZEND_METHOD(H3_H3DirectedEdge, fromString);
ZEND_METHOD(H3_H3DirectedEdge, isValid);
ZEND_METHOD(H3_H3DirectedEdge, getOrigin);
ZEND_METHOD(H3_H3DirectedEdge, getDestination);
ZEND_METHOD(H3_H3DirectedEdge, getIndexes);
ZEND_METHOD(H3_H3DirectedEdge, getBoundary);
ZEND_METHOD(H3_H3DirectedEdge, getLength);
ZEND_METHOD(H3_H3DirectedEdge, toLong);
ZEND_METHOD(H3_H3DirectedEdge, toString);
ZEND_METHOD(H3_H3DirectedEdge, __toString);
ZEND_METHOD(H3_LatLng, __construct);
ZEND_METHOD(H3_LatLng, getLat);
ZEND_METHOD(H3_LatLng, getLon);
ZEND_METHOD(H3_CellBoundary, __construct);
ZEND_METHOD(H3_CellBoundary, getVertices);
ZEND_METHOD(H3_GeoPolygon, __construct);
ZEND_METHOD(H3_GeoPolygon, getGeofence);
ZEND_METHOD(H3_GeoPolygon, getHoles);
ZEND_METHOD(H3_GeoMultiPolygon, __construct);
ZEND_METHOD(H3_GeoMultiPolygon, getPolygons);
ZEND_METHOD(H3_GeoMultiPolygon, toGeoJson);
ZEND_METHOD(H3_CoordIJ, __construct);
ZEND_METHOD(H3_CoordIJ, getI);
ZEND_METHOD(H3_CoordIJ, getJ);


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
	ZEND_NS_FE("H3", indexes_are_neighbors, arginfo_H3_indexes_are_neighbors)
	ZEND_NS_FE("H3", polyfill, arginfo_H3_polyfill)
	ZEND_NS_FE("H3", h3_set_to_multi_polygon, arginfo_H3_h3_set_to_multi_polygon)
	ZEND_NS_FE("H3", experimental_h3_to_local_ij, arginfo_H3_experimental_h3_to_local_ij)
	ZEND_NS_FE("H3", experimental_local_ij_to_h3, arginfo_H3_experimental_local_ij_to_h3)
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
	ZEND_ME(H3_H3Index, getCellArea, arginfo_class_H3_H3Index_getCellArea, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, isNeighborTo, arginfo_class_H3_H3Index_isNeighborTo, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getLineTo, arginfo_class_H3_H3Index_getLineTo, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getDistanceTo, arginfo_class_H3_H3Index_getDistanceTo, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getDirectedEdges, arginfo_class_H3_H3Index_getDirectedEdges, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, getDirectedEdge, arginfo_class_H3_H3Index_getDirectedEdge, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toParent, arginfo_class_H3_H3Index_toParent, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toChildren, arginfo_class_H3_H3Index_toChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toCenterChild, arginfo_class_H3_H3Index_toCenterChild, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toLong, arginfo_class_H3_H3Index_toLong, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toString, arginfo_class_H3_H3Index_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toGeo, arginfo_class_H3_H3Index_toGeo, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, toGeoBoundary, arginfo_class_H3_H3Index_toGeoBoundary, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3Index, __toString, arginfo_class_H3_H3Index___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_H3DirectedEdge_methods[] = {
	ZEND_ME(H3_H3DirectedEdge, __construct, arginfo_class_H3_H3DirectedEdge___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, fromLong, arginfo_class_H3_H3DirectedEdge_fromLong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(H3_H3DirectedEdge, fromString, arginfo_class_H3_H3DirectedEdge_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(H3_H3DirectedEdge, isValid, arginfo_class_H3_H3DirectedEdge_isValid, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, getOrigin, arginfo_class_H3_H3DirectedEdge_getOrigin, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, getDestination, arginfo_class_H3_H3DirectedEdge_getDestination, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, getIndexes, arginfo_class_H3_H3DirectedEdge_getIndexes, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, getBoundary, arginfo_class_H3_H3DirectedEdge_getBoundary, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, getLength, arginfo_class_H3_H3DirectedEdge_getLength, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, toLong, arginfo_class_H3_H3DirectedEdge_toLong, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, toString, arginfo_class_H3_H3DirectedEdge_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_H3DirectedEdge, __toString, arginfo_class_H3_H3DirectedEdge___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_LatLng_methods[] = {
	ZEND_ME(H3_LatLng, __construct, arginfo_class_H3_LatLng___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_LatLng, getLat, arginfo_class_H3_LatLng_getLat, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_LatLng, getLon, arginfo_class_H3_LatLng_getLon, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_CellBoundary_methods[] = {
	ZEND_ME(H3_CellBoundary, __construct, arginfo_class_H3_CellBoundary___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_CellBoundary, getVertices, arginfo_class_H3_CellBoundary_getVertices, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_GeoPolygon_methods[] = {
	ZEND_ME(H3_GeoPolygon, __construct, arginfo_class_H3_GeoPolygon___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoPolygon, getGeofence, arginfo_class_H3_GeoPolygon_getGeofence, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoPolygon, getHoles, arginfo_class_H3_GeoPolygon_getHoles, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_GeoMultiPolygon_methods[] = {
	ZEND_ME(H3_GeoMultiPolygon, __construct, arginfo_class_H3_GeoMultiPolygon___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoMultiPolygon, getPolygons, arginfo_class_H3_GeoMultiPolygon_getPolygons, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_GeoMultiPolygon, toGeoJson, arginfo_class_H3_GeoMultiPolygon_toGeoJson, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_H3_CoordIJ_methods[] = {
	ZEND_ME(H3_CoordIJ, __construct, arginfo_class_H3_CoordIJ___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_CoordIJ, getI, arginfo_class_H3_CoordIJ_getI, ZEND_ACC_PUBLIC)
	ZEND_ME(H3_CoordIJ, getJ, arginfo_class_H3_CoordIJ_getJ, ZEND_ACC_PUBLIC)
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

static zend_class_entry *register_class_H3_H3DirectedEdge(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "H3DirectedEdge", class_H3_H3DirectedEdge_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_index_default_value;
	ZVAL_UNDEF(&property_index_default_value);
	zend_string *property_index_name = zend_string_init("index", sizeof("index") - 1, 1);
	zend_declare_typed_property(class_entry, property_index_name, &property_index_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_LatLng(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "LatLng", class_H3_LatLng_methods);
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

static zend_class_entry *register_class_H3_CellBoundary(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "CellBoundary", class_H3_CellBoundary_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_vertices_default_value;
	ZVAL_UNDEF(&property_vertices_default_value);
	zend_string *property_vertices_name = zend_string_init("vertices", sizeof("vertices") - 1, 1);
	zend_declare_typed_property(class_entry, property_vertices_name, &property_vertices_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_vertices_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_GeoPolygon(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "GeoPolygon", class_H3_GeoPolygon_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zend_string *property_geofence_class_H3_CellBoundary = zend_string_init("H3\\CellBoundary", sizeof("H3\\CellBoundary")-1, 1);
	zval property_geofence_default_value;
	ZVAL_UNDEF(&property_geofence_default_value);
	zend_string *property_geofence_name = zend_string_init("geofence", sizeof("geofence") - 1, 1);
	zend_declare_typed_property(class_entry, property_geofence_name, &property_geofence_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_geofence_class_H3_CellBoundary, 0, 0));
	zend_string_release(property_geofence_name);

	zval property_holes_default_value;
	ZVAL_UNDEF(&property_holes_default_value);
	zend_string *property_holes_name = zend_string_init("holes", sizeof("holes") - 1, 1);
	zend_declare_typed_property(class_entry, property_holes_name, &property_holes_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_holes_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_GeoMultiPolygon(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "GeoMultiPolygon", class_H3_GeoMultiPolygon_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_polygons_default_value;
	ZVAL_UNDEF(&property_polygons_default_value);
	zend_string *property_polygons_name = zend_string_init("polygons", sizeof("polygons") - 1, 1);
	zend_declare_typed_property(class_entry, property_polygons_name, &property_polygons_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_polygons_name);

	return class_entry;
}

static zend_class_entry *register_class_H3_CoordIJ(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "H3", "CoordIJ", class_H3_CoordIJ_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval property_i_default_value;
	ZVAL_UNDEF(&property_i_default_value);
	zend_string *property_i_name = zend_string_init("i", sizeof("i") - 1, 1);
	zend_declare_typed_property(class_entry, property_i_name, &property_i_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_i_name);

	zval property_j_default_value;
	ZVAL_UNDEF(&property_j_default_value);
	zend_string *property_j_name = zend_string_init("j", sizeof("j") - 1, 1);
	zend_declare_typed_property(class_entry, property_j_name, &property_j_default_value, ZEND_ACC_PRIVATE, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_j_name);

	return class_entry;
}
