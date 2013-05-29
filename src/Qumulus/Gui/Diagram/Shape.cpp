/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Shape.h"
#include <libavoid/shape.h>
#include <libavoid/router.h>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

Shape::Shape(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p),
        QGraphicsItemGroup(dynamic_cast<Shape*>(p)),
        mRoutingBox({0, 0}, {1, 1}) {
    setVisible(false);
}

Shape::Shape(const Shape& s) :
        DiagramElement(s),
        mRoutingBox(s.mRoutingBox){}


Shape::~Shape() {
    if(mRouter && mShapeRef) {
        mRouter->deleteShape(mShapeRef);
    }
}

double Shape::width() const {
    return mSize.width();
}

double Shape::height() const {
    return mSize.height();
}

void Shape::setWidth(double w) {
    resize(w, height());
}

void Shape::setHeight(double h) {
    resize(width(), h);
}

void Shape::passRouter(Avoid::Router* r) {
    mRouter = r;
    mShapeRef = new Avoid::ShapeRef(mRouter, mRoutingBox);
    new Avoid::ShapeConnectionPin(mShapeRef, 1, 
            Avoid::ATTACH_POS_CENTRE, Avoid::ATTACH_POS_CENTRE);
}

void Shape::setSize(QSizeF s) {
    mSize = s;


    if(mRouter && mShapeRef) {
        mRoutingBox = {{pos().x()-10, pos().y()-10}, 
                {pos().x() + width()+20, pos().y() + height()+20}};
        mRouter->moveShape(mShapeRef, mRoutingBox);
        mRouter->processTransaction();
    }
}

QSizeF Shape::optimalSize() const {
    return mSizeHint.isValid() ? mSizeHint : minimumSize();
}

void Shape::setOwningElement(DiagramElement* e) {
    DiagramElement::setOwningElement(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        setParentItem(p);
}

QUML_END_NAMESPACE_GD
