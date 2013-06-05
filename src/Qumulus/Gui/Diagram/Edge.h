/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_EDGE_H_
#define UML_DIAGRAM_EDGE_H_

#include "internal_base.h"
#include "DiagramElement.h"
#include "Shape.h"
#include <QtWidgets/QGraphicsItemGroup>
#include <libavoid/geomtypes.h>

namespace Avoid { 
    class ConnRef; 
    class Router;
    class ConnEnd;
}

QUML_BEGIN_NAMESPACE_GD

enum Direction {
    Up,
    Down,
    Left,
    Right
};

class Edge : public DiagramElement, public QGraphicsItemGroup {
public:
    Edge(QuUK::Element* e = 0, DiagramElement* p = 0);
    Edge(const Edge&);

    Shape* source() const { return mSource; }
    void setSource(Shape* e); 

    Shape* target() const { return mTarget; }
    void setTarget(Shape* e);

    Direction targetEntry() { return mTargetEntry; }
    Direction sourceExit() { return mSourceExit; }

    void resize(double, double) {}

    QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    void updateSizeConstraints();

    void connect();
    void passRouter(Avoid::Router* r) { mRouter = r; };

    QUML_CLONABLE_ABSTRACT(Edge);
private:
    Shape* mSource;
    Shape* mTarget;
    Direction mTargetEntry;
    Direction mSourceExit;
    Avoid::ConnEnd* mSrc = nullptr;
    Avoid::ConnEnd* mEnd = nullptr;
    Avoid::ConnRef* mConnectionReference = nullptr;
    Avoid::Router* mRouter = nullptr;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_EDGE_H_ */

