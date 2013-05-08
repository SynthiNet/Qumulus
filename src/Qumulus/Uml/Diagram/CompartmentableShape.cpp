/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "CompartmentableShape.h"

QUML_BEGIN_NAMESPACE_UD

CompartmentableShape::CompartmentableShape(QuUK::Element* e, 
        DiagramElement* p) :
        Shape(e, p) {

}

Compartment* CompartmentableShape::compartment(unsigned i) {
    return mCompartments[i];
}

void CompartmentableShape::addCompartment(Compartment* c) {
    mCompartments.append(c);
    addToGroup(c);
}

QUML_END_NAMESPACE_UD
