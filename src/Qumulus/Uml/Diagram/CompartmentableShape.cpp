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

CompartmentableShape::CompartmentableShape(const CompartmentableShape& c) :
        Shape(c) {

}

Compartment* CompartmentableShape::compartment(unsigned i) {
    return mCompartments[i];
}

void CompartmentableShape::addCompartment(Compartment* c) {
    mCompartments.append(c);
    addToGroup(c);
}

void CompartmentableShape::resize(double, double) {

}

QUML_END_NAMESPACE_UD
