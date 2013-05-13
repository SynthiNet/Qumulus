/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_EDGE_H_
#define UML_DIAGRAM_EDGE_H_

#include "internal_base.h"

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

class Edge : public Shape {
public:
    Edge(QuUK::Element* e = 0, DiagramElement* p = 0);
    Edge(const Edge&);

    QuUK::Element* source() const { return mSource; }
    void setSource(QuUK::Element* e) { mSource = e; } 

    QuUK::Element* target() const { return mTarget; }
    void setTarget(QuUK::Element* e) { mTarget = e; } 

    void resize(double, double) override {}

    QUML_CLONABLE(Edge);
private:
    QuUK::Element* mSource;
    QuUK::Element* mTarget;

    QList<QPoint> mWaypoints;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_EDGE_H_ */

