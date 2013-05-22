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
        Shape(0, p) {
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
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    w = maximumSize().width() == -1 ? w : std::min(w, maximumSize().width());
    h = maximumSize().height() == -1 ? h :std::min(h, maximumSize().height());
    
    mRectItem->setRect(0, 0, w, h);

    setSize({w, h});
}


QRectF Compartment::boundingRect() const {
    return QRectF();
}
void Compartment::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {

}

QUML_END_NAMESPACE_GD
