/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Edge.h"
#include <QtGui/QPainter>
#include <libavoid/connend.h>
#include <libavoid/router.h>
#include <libavoid/connector.h>

#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

Edge::Edge(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p),
        QGraphicsItemGroup(dynamic_cast<Shape*>(p)) {
    setVisible(false);
    setZValue(-9001);
}

Edge::Edge(const Edge& e) :
        DiagramElement(e) {}

QRectF Edge::boundingRect() const {
    return QRectF(-1000, -1000, 2000, 2000);
}

void Edge::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*) {
    if(!mConnectionReference)
        return;

    auto route = mConnectionReference->displayRoute();
    for(size_t i = 1; i < route.size(); ++i) {
        p->drawLine(route.at(i-1).x, route.at(i-1).y,
                route.at(i).x, route.at(i).y);
    }

}

void Edge::updateSizeConstraints() {}

void Edge::setTarget(Shape* e) { 
    mTarget = e;
    if(mEnd == nullptr)
        mEnd = new Avoid::ConnEnd(e->shapeRef(), 1);
} 

void Edge::setSource(Shape* e) { 
    mSource = e;
    if(mSrc == nullptr)
        mSrc = new Avoid::ConnEnd(e->shapeRef(), 1);
} 

void Edge::connect() {
    mConnectionReference = new Avoid::ConnRef(mRouter, *mSrc, *mEnd); 
    mRouter->processTransaction();
}

QUML_END_NAMESPACE_GD
