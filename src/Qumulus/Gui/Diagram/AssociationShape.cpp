/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "AssociationShape.h"

QUML_BEGIN_NAMESPACE_GD
AssociationShape::AssociationShape(QuUK::Element* e, DiagramElement* p) :
        Shape(e, p),
        mKind(AssociationShapeKind::Triangle) {
    
}

AssociationShape::AssociationShape(const AssociationShape& s) :
        Shape(s) {

}

void AssociationShape::resize(double, double) {

}

void AssociationShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {

}

void AssociationShape::updateSizeConstraints() {

}

QUML_END_NAMESPACE_GD
