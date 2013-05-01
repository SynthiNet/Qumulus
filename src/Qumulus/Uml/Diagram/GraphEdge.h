/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_GRAPHEDGE_H_
#define UML_DIAGRAM_GRAPHEDGE_H_

#include "internal_base.h"

#include "GraphElement.h"

#include <QtCore/QPoint>

QUML_BEGIN_NAMESPACE_UD

class GraphConnector;

class GraphEdge : public GraphElement {
public:
    GraphEdge(GraphConnector* a, const std::list<QPoint>& p);

    const std::list<QPoint>& waypoints() const { return mWaypoints; }
    std::list<QPoint>& waypoints() { return mWaypoints; }

    GraphConnector* anchor() const { return mAnchor; }
    void setAnchor(GraphConnector* c) { mAnchor = c; }
private:
    std::list<QPoint> mWaypoints;
    GraphConnector* mAnchor;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_GRAPHEDGE_H_ */

