/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Compartment.h"
#include "CompartmentableShape.h"

#include <QtWidgets/QGraphicsRectItem>

QUML_BEGIN_NAMESPACE_UD

Compartment::Compartment(CompartmentableShape* p) :
        Shape(0, p),
        mRectItem(new QGraphicsRectItem(this)) {
    p->addCompartment(this);
    addToGroup(mRectItem);
    mRectItem->setRect(0, 0, 100, 40);
}

Compartment::Compartment(const Compartment& c) :
        Shape(c) {

}

CompartmentableShape* Compartment::compartmentableShape() const {
    return static_cast<CompartmentableShape*>(owningElement());
}

void Compartment::setCompartimentableShape(CompartmentableShape* s) {
    setOwningElement(s);
}

void Compartment::resize(double w, double h) {
    if(minimumSize().isValid()) {
        w = std::max(w, minimumSize().width());
        h = std::max(h, minimumSize().height());
    }

    if(maximumSize().isValid()) {
        w = std::min(w, maximumSize().width());
        h = std::min(h, maximumSize().height());
    }
    
    mRectItem->setRect(0, 0, w, h);
}

QUML_END_NAMESPACE_UD
