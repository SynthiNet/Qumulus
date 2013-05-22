/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveShape.h"

QUML_BEGIN_NAMESPACE_GD

PrimitiveShape::PrimitiveShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p) {

}

PrimitiveShape::PrimitiveShape(const PrimitiveShape& s) :
        CompartmentableShape(s) {

}

void PrimitiveShape::updateSizeConstraints() {

}

QUML_END_NAMESPACE_GD
