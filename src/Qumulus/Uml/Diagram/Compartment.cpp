/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Compartment.h"
#include "CompartmentableShape.h"

QUML_BEGIN_NAMESPACE_UD

Compartment::Compartment(CompartmentableShape* p) :
        Shape(0, p) {
    p->addCompartment(this);
}

CompartmentableShape* Compartment::compartmentableShape() const {
    return static_cast<CompartmentableShape*>(owningElement());
}

void Compartment::setCompartimentableShape(CompartmentableShape* s) {
    setOwningElement(s);
}



QUML_END_NAMESPACE_UD
