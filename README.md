# H3 PHP

PHP extension that implements [H3 library](https://github.com/uber/h3) bindings in OOP style

# Requirements

* PHP: `^8.1`
* H3 Library: `^4.0`

# Examples

```php
<?php

use H3\LatLng;
use H3\H3Index;
use function H3\compact as h3_compact;
use function H3\edge_length;

$h3 = new H3Index(0x881196404bfffff);
// or
$h3 = H3Index::fromLong(0x881196404bfffff);
// or
$h3 = H3Index::fromString('881196404bfffff');
// or
$h3 = H3Index::fromGeo(geo: new LatLng(lat: 50.00572553034654, lon: 36.229191466601634), res: 8);

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
git checkout v4.2.1
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

# Binding table

## Indexing
| C                  | PHP                         |
|--------------------|-----------------------------|
| latLngToCell()     | H3\H3Index::fromGeo()       |
| cellToLatLng()     | H3\H3Index::toGeo()         |
| cellToBoundary()   | H3\H3Index::toGeoBoundary() |

## Inspection
| C                    | PHP                         |
|----------------------|-----------------------------|
| getResolution()      | H3\H3Index::getResolution() |
| getBaseCellNumber()  | H3\H3Index::getBaseCell()   |
| stringToH3()         | H3\H3Index::fromString()    |
| h3ToString()         | H3\H3Index::toString()      |
| isValidCell()        | H3\H3Index::isValid()       |
| isResClassIII()      | H3\H3Index::isResClassIII() |
| isPentagon()         | H3\H3Index::isPentagon()    |
| getIcosahedronFaces()| H3\H3Index::getFaces()      |
| maxFaceCount()       | -                           |

## Traversal
| C                    | PHP                                           |
|----------------------|-----------------------------------------------|
| gridDisk()           | H3\H3Index::kRing()                           |
| maxGridDiskSize()    | -                                             |
| gridDiskDistances()  | H3\H3Index::kRingDistances()                  |
| gridDiskUnsafe()     | H3\H3Index::hexRange()                        |
| gridDiskDistancesUnsafe() | H3\H3Index::hexRangeDistances()          |
| gridRingUnsafe()     | H3\H3Index::hexRing()                         |
| gridPathCells()      | H3\line()<br/>H3\H3Index::getLineTo()         |
| gridPathCellsSize()  | -                                             |
| gridDistance()        | H3\distance()<br/>H3\H3Index::getDistanceTo() |
| cellToLocalIj()      | H3\experimental_h3_to_local_ij                |
| localIjToCell()      | H3\experimental_local_ij_to_h3                |

## Hierarchy
| C                    | PHP                         |
|----------------------|-----------------------------|
| cellToParent()       | H3\H3Index::toParent()      |
| cellToChildren()     | H3\H3Index::toChildren()    |
| cellToChildrenSize() | -                           |
| cellToCenterChild()  | H3\H3Index::toCenterChild() |
| compactCells()       | H3\compact()                |
| uncompactCells()     | H3\uncompact()              |
| uncompactCellsSize() | -                           |

## Regions
| C                            | PHP                          |
|------------------------------|------------------------------|
| polygonToCells()             | H3\polyfill()                |
| maxPolygonToCellsSize()      | -                            |
| cellsToLinkedMultiPolygon()  | H3\h3_set_to_multi_polygon() |
| destroyLinkedMultiPolygon()  | -                            |

## Directed edges
| C                             | PHP                                                          |
|-------------------------------|--------------------------------------------------------------|
| areNeighborCells()            | H3\indexes_are_neighbors<br/>H3\H3Index::isNeighborTo()     |
| cellsToDirectedEdge()         | H3\H3Index::getDirectedEdge()                               |
| isValidDirectedEdge()         | H3\H3DirectedEdge::isValid()                                |
| getDirectedEdgeOrigin()       | H3\H3DirectedEdge::getOrigin()                              |
| getDirectedEdgeDestination()  | H3\H3DirectedEdge::getDestination()                         |
| directedEdgeToCells()         | H3\H3DirectedEdge::getIndexes()                             |
| originToDirectedEdges()       | H3\H3Index::getDirectedEdges()                              |
| directedEdgeToBoundary()      | H3\H3DirectedEdge::getBoundary()                            |

## Miscellaneous
| C                            | PHP                              |
|------------------------------|----------------------------------|
| degsToRads()                 | H3\degs_to_rads()                |
| radsToDegs()                 | H3\rads_to_degs()                |
| getHexagonAreaAvgKm2()       | H3\hex_area()                    |
| getHexagonAreaAvgM2()        | H3\hex_area()                    |
| cellAreaKm2()                | H3\H3Index::getCellArea()        |
| cellAreaM2()                 | H3\H3Index::getCellArea()        |
| cellAreaRads2()              | H3\H3Index::getCellArea()        |
| getHexagonEdgeLengthAvgKm()  | H3\edge_length()                 |
| getHexagonEdgeLengthAvgM()   | H3\edge_length()                 |
| edgeLengthKm()               | H3\H3DirectedEdge::getLength()   |
| edgeLengthM()                | H3\H3DirectedEdge::getLength()   |
| edgeLengthRads()             | H3\H3DirectedEdge::getLength()   |
| getNumCells()                | H3\num_hexagons()                |
| getRes0Cells()               | H3\get_res0_indexes()            |
| res0CellCount()              | -                                |
| getPentagons()               | H3\get_pentagon_indexes()        |
| pentagonCount()              | -                                |
| greatCircleDistanceKm()      | H3\point_dist()                  |
| greatCircleDistanceM()       | H3\point_dist()                  |
| greatCircleDistanceRads()    | H3\point_dist()                  |

# License

All contents of this package are licensed under the [MIT license].

[MIT license]: LICENSE
