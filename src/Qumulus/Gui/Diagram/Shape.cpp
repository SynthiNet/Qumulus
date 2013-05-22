/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Shape.h"

QUML_BEGIN_NAMESPACE_GD

Shape::Shape(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p),
        QGraphicsItemGroup(dynamic_cast<Shape*>(p)) {}

Shape::Shape(const Shape& s) :
        DiagramElement(s) {}

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

QSizeF Shape::optimalSize() const {
    return mSizeHint.isValid() ? mSizeHint : minimumSize();
}

void Shape::setOwningElement(DiagramElement* e) {
    DiagramElement::setOwningElement(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        setParentItem(p); 
}

QUML_END_NAMESPACE_GD
