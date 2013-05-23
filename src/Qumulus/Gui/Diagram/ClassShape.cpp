/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ClassShape.h"

QUML_BEGIN_NAMESPACE_GD

ClassShape::ClassShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p) {
}

ClassShape::ClassShape(const ClassShape& s) :
        CompartmentableShape(s) {

}

QuUK::Class* ClassShape::modelElement() const {
    return dynamic_cast<QuUK::Class*>(CompartmentableShape::modelElement());
}

void ClassShape::updateSizeConstraints() {

}

void ClassShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {

    CompartmentableShape::paint(painter, option, widget);

}

QUML_END_NAMESPACE_GD
