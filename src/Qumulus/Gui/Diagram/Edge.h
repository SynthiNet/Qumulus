/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_EDGE_H_
#define UML_DIAGRAM_EDGE_H_

#include "internal_base.h"

#include "Shape.h"

namespace Avoid { 
    class ConnRef; 
    class Router;
}

QUML_BEGIN_NAMESPACE_GD

class Edge : public Shape {
public:
    Edge(QuUK::Element* e = 0, DiagramElement* p = 0);
    Edge(const Edge&);

    Shape* source() const { return mSource; }
    void setSource(Shape* e) { mSource = e; } 

    Shape* target() const { return mTarget; }
    void setTarget(Shape* e) { mTarget = e; } 

    void resize(double, double) override {}

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    void updateSizeConstraints() override;

    QUML_CLONABLE_ABSTRACT(Edge);
private:
    Shape* mSource;
    Shape* mTarget;
    Avoid::Router* mRouter;
    Avoid::ConnRef* mConnectionReference;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_EDGE_H_ */

