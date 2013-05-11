/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

Shape::Shape(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p) {
}

Shape::Shape(const Shape& s) :
        DiagramElement(s) {

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

QUML_END_NAMESPACE_UD
