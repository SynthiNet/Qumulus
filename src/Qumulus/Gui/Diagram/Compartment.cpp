/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Compartment.h"
#include "CompartmentableShape.h"

#include <QtWidgets/QGraphicsRectItem>
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_GD

Compartment::Compartment(CompartmentableShape* p) :
        DiagramElement(0, p) {}

Compartment::Compartment(const Compartment& c) :
        DiagramElement(c) {}

CompartmentableShape* Compartment::compartmentableShape() const {
    return static_cast<CompartmentableShape*>(owningElement());
}

void Compartment::setCompartimentableShape(CompartmentableShape* s) {
    setOwningElement(s);
}

QUML_END_NAMESPACE_GD
