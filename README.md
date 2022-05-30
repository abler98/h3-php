# H3 PHP

PHP extension that implements [H3 library](https://github.com/uber/h3) bindings in OOP style

# Requirements

* PHP: `^8.1`
* H3 Library: `^3.7.2`

# Examples

```php
<?php

use H3\GeoCoord;
use H3\H3Index;
use function H3\compact as h3_compact;
use function H3\edge_length;

$h3 = new H3Index(0x881196404bfffff);
// or
$h3 = H3Index::fromLong(0x881196404bfffff);
// or
$h3 = H3Index::fromString('881196404bfffff');
// or
$h3 = H3Index::fromGeo(geo: new GeoCoord(lat: 50.00572553034654, lon: 36.229191466601634), res: 8);

$resolution = $h3->getResolution(); // 8
$kRing = $h3->kRing(k: 3); // H3Index[]
$kRingCount = count($kRing); // 37
$compacted = h3_compact($kRing); // H3Index[]
$compactedCount = count($compacted); // 19
$parentString = $h3->toParent(res: 5)->toString(); // "85119643fffffff"

$edgeLength = edge_length(res: 8, unit: H3_LENGTH_UNIT_M); // 461.3546837
```

# Building from source

## H3 Library

```bash
git clone https://github.com/uber/h3.git
cd h3
git checkout v3.7.2
cmake -DBUILD_SHARED_LIBS=ON .
make -j "$(nproc)"
sudo make install
```

## PHP Extension

```bash
git clone https://github.com/abler98/h3-php.git
cd h3-php
phpize
./configure
make
sudo make install
```

# Mapping table

| C                                             | PHP                                  |
| --------------------------------------------- | ------------------------------------ |
| geoToH3()                                     | H3\H3Index::fromGeo()                |
| h3ToGeo()                                     | H3\H3Index::toGeo()                  |
| h3ToGeoBoundary()                             | H3\H3Index::toGeoBoundary()          |
| h3GetResolution()                             | H3\H3Index::getResolution()          |
| h3GetBaseCell()                               | H3\H3Index::getBaseCell()            |
| stringToH3()                                  | H3\H3Index::fromString()             |
| h3ToString()                                  | H3\H3Index::toString()               |
| h3IsValid()                                   | H3\H3Index::isValid()                |
| h3IsResClassIII()                             | H3\H3Index::isResClassIII()          |
| h3IsPentagon()                                | H3\H3Index::isPentagon()             |
| h3GetFaces()                                  | H3\H3Index::getFaces()               |
| maxFaceCount()                                | -                                    |
| kRing()                                       | H3\H3Index::kRing()                  |
| maxKringSize()                                | -                                    |
| kRingDistances()                              | H3\H3Index::kRingDistances()         |
| hexRange()                                    | H3\H3Index::hexRange()               |
| hexRangeDistances()                           | H3\H3Index::hexRangeDistances()      |
| hexRanges()                                   | H3\H3Index::hexRanges()              |
| hexRing()                                     | H3\H3Index::hexRing()                |
| h3Line()                                      | H3\line()                            |
| h3LineSize()                                  | -                                    |
| h3Distance()                                  | H3\distance()                        |
| experimentalH3ToLocalIj()                     | Not implemented                      |
| experimentalLocalIjToH3()                     | Not implemented                      |
| h3ToParent()                                  | H3\H3Index::toParent()               |
| h3ToChildren()                                | H3\H3Index::toChildren()             |
| maxH3ToChildrenSize()                         | -                                    |
| h3ToCenterChild()                             | H3\H3Index::toCenterChild()          |
| compact()                                     | H3\compact()                         |
| uncompact()                                   | H3\uncompact()                       |
| maxUncompactSize()                            | -                                    |
| polyfill()                                    | Not implemented                      |
| maxPolyfillSize()                             | -                                    |
| h3SetToLinkedGeo()                            | Not implemented                      |
| destroyLinkedPolygon()                        | -                                    |
| h3IndexesAreNeighbors()                       | H3\H3Index::isNeighborTo()           |
| getH3UnidirectionalEdge()                     | H3\H3Index::getUnidirectionalEdge()  |
| h3UnidirectionalEdgeIsValid()                 | H3\UniEdge::isValid()                |
| getOriginH3IndexFromUnidirectionalEdge()      | H3\UniEdge::getOrigin()              |
| getDestinationH3IndexFromUnidirectionalEdge() | H3\UniEdge::getDestination()         |
| getH3IndexesFromUnidirectionalEdge()          | H3\UniEdge::getIndexes()             |
| getH3UnidirectionalEdgesFromHexagon()         | H3\H3Index::getUnidirectionalEdges() |
| getH3UnidirectionalEdgeBoundary()             | H3\UniEdge::getBoundary()            |
| degsToRads()                                  | H3\degs_to_rads()                    |
| radsToDegs()                                  | H3\rads_to_degs()                    |
| hexAreaKm2()                                  | H3\hex_area()                        |
| hexAreaM2()                                   | H3\hex_area()                        |
| cellAreaM2()                                  | H3\H3Index::getCellArea()            |
| cellAreaRads2()                               | H3\H3Index::getCellArea()            |
| edgeLengthKm()                                | H3\edge_length()                     |
| edgeLengthM()                                 | H3\edge_length()                     |
| exactEdgeLengthKm()                           | H3\UniEdge::getLength()          |
| exactEdgeLengthM()                            | H3\UniEdge::getLength()          |
| exactEdgeLengthRads()                         | H3\UniEdge::getLength()          |
| numHexagons()                                 | H3\num_hexagons()                    |
| getRes0Indexes()                              | H3\get_res0_indexes()                |
| res0IndexCount()                              | -                                    |
| getPentagonIndexes()                          | H3\get_pentagon_indexes()            |
| pentagonIndexCount()                          | -                                    |
| pointDistKm()                                 | H3\point_dist()                      |
| pointDistM()                                  | H3\point_dist()                      |
| pointDistRads()                               | H3\point_dist()                      |
