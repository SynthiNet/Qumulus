/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "GraphEdge.h"

QUML_BEGIN_NAMESPACE_UD

GraphEdge::GraphEdge(GraphConnector* a, const std::list<QPoint>& p) :
        mAnchor(a),
        mWaypoints(p) {}


QUML_END_NAMESPACE_UD
