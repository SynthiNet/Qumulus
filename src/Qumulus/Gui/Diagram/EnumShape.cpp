/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumShape.h"

QUML_BEGIN_NAMESPACE_GD

EnumShape::EnumShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p), mHeader(new Compartment()),
        mBody(new Compartment()) {
    addCompartment(mHeader);
    addCompartment(mBody);
    updateSizeConstraints();
    resize(0, 0);
}

EnumShape::EnumShape(const EnumShape& s) :
        CompartmentableShape(s) {

}

void EnumShape::updateSizeConstraints() {

}

QUML_END_NAMESPACE_GD
