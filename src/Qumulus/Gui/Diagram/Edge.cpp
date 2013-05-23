/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

Edge::Edge(QuUK::Element* e, DiagramElement* p) :
        Shape(e, p) {
}

Edge::Edge(const Edge& e) :
        Shape(e) {

}

QRectF Edge::boundingRect() const {
    return QRectF();
}

void Edge::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {

}

void Edge::updateSizeConstraints() {

}

QUML_END_NAMESPACE_GD
