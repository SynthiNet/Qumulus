/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ClassShape.h"

#include "Compartment.h"

QUML_BEGIN_NAMESPACE_GD

ClassShape::ClassShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p),
        mHeadCompartment(new Compartment(this)),
        mAttributeCompartment(new Compartment(this)),
        mOperationCompartment(new Compartment(this)) {
    addCompartment(mHeadCompartment);
    addCompartment(mAttributeCompartment);
    addCompartment(mOperationCompartment);
    updateSizeConstraints();
    resize(0, 0);
}

ClassShape::ClassShape(const ClassShape& s) :
        CompartmentableShape(s) {

}

QuUK::Class* ClassShape::modelElement() const {
    return dynamic_cast<QuUK::Class*>(CompartmentableShape::modelElement());
}

void ClassShape::updateSizeConstraints() {
    setMinimumSize({std::max(190, classNameWidth()) + 10, 100});
    mHeadCompartment->setMinimumHeight(20);
    mHeadCompartment->setMaximumHeight(20);
    mAttributeCompartment->setMinimumHeight(40);
    mOperationCompartment->setMinimumHeight(40);
}

void ClassShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {
    CompartmentableShape::paint(painter, option, widget);

}

int ClassShape::classNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}
QUML_END_NAMESPACE_GD
