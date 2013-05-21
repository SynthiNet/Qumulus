###############################################################################
#
# Qumulus UML editor
# Author: Frank Erens
#
###############################################################################

set(LIBAVOID_SRC
    actioninfo.cpp
    connectionpin.cpp
    connector.cpp
    connend.cpp
    geometry.cpp
    geomtypes.cpp
    graph.cpp
    hyperedge.cpp
    hyperedgetree.cpp
    junction.cpp
    makepath.cpp
    mtst.cpp
    obstacle.cpp
    orthogonal.cpp
    router.cpp
    scanline.cpp
    shape.cpp
    timer.cpp
    vertices.cpp
    viscluster.cpp
    visibility.cpp
    vpsc.cpp
)

include_directories(..)
add_library(avoid SHARED ${LIBAVOID_SRC})
