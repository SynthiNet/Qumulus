/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "CompartmentableShape.h"

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
    // w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    // h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    // unsigned totalh = 0;
    // for(int i = 0; i < compartments().size(); ++i) {
    //     unsigned newh = h / (compartments().size() - i);

    //     compartment(i)->resize(w, newh);
    //     unsigned actualh = compartment(i)->height();

    //     if(i < compartments().size() - 1)
    //         compartment(i + 1)->setPos(0, compartment(i)->pos().y() + actualh);
    //     
    //     h -= actualh;
    //     totalh += actualh;
    // }

    // setSize({compartment(0)->size().width(), totalh});
}

QUML_END_NAMESPACE_GD
