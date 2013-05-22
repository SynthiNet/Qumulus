/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "CompartmentableShape.h"

#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

CompartmentableShape::CompartmentableShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p) {}

CompartmentableShape::CompartmentableShape(const CompartmentableShape& c) :
        SelectableShape(c) {

}

Compartment* CompartmentableShape::compartment(unsigned i) {
    return mCompartments[i];
}

void CompartmentableShape::addCompartment(Compartment* c) {
    mCompartments.append(c);
}

void CompartmentableShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    unsigned totalh = 0;
    for(int i = 0; i < compartments().size(); ++i) {
        unsigned newh = h / (compartments().size() - i);

        compartment(i)->setHeight(newh);
        unsigned actualh = compartment(i)->height();

        // if(i < compartments().size() - 1)
        //     compartment(i + 1)->setPos(0, compartment(i)->pos().y() + actualh);
        
        h -= actualh;
        totalh += actualh;
    }

    setSize({w, totalh});
}

void CompartmentableShape::updateSizeConstraints() {

}

void CompartmentableShape::paint(QPainter* painter, 
        const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(Qt::white);

    float h = 0;
    for(auto& c : compartments()) {
        painter->drawRect(0, h, width(), c->height());
        h += c->height();
    }
}

QUML_END_NAMESPACE_GD
