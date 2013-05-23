/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveShape.h"

#include <Uml/Kernel/PrimitiveType.h>

#include <QPainter>

QUML_BEGIN_NAMESPACE_GD

PrimitiveShape::PrimitiveShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p),
        mCompartment(new Compartment(this)) {
    addCompartment(mCompartment);
    updateSizeConstraints();
    resize(0, 0);
}

QuUK::PrimitiveType* PrimitiveShape::modelElement() const {
    return dynamic_cast<QuUK::PrimitiveType*>(
            CompartmentableShape::modelElement());
}

PrimitiveShape::PrimitiveShape(const PrimitiveShape& s) :
        CompartmentableShape(s) {

}

void PrimitiveShape::updateSizeConstraints() {
    setMinimumSize({10 + std::max(90, primitiveNameWidth()), 40});
}

void PrimitiveShape::paint(QPainter* painter, 
        const QStyleOptionGraphicsItem* option, QWidget* widget) {
    CompartmentableShape::paint(painter, option, widget);

    QFont stereotypeFont = sharedStyle()->font();
    stereotypeFont.setItalic(true);
    painter->setFont(stereotypeFont);
    painter->drawText(0, 0, width(), height() / 2,
            Qt::AlignHCenter | Qt::AlignBottom,
            "« primitive »");

    QFont nameFont = sharedStyle()->font();
    nameFont.setBold(true);
    painter->setFont(nameFont);
    painter->drawText(0, height() / 2, width(), height() / 2, 
            Qt::AlignHCenter | Qt::AlignTop,
            modelElement()->name());

}

int PrimitiveShape::primitiveNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}

QUML_END_NAMESPACE_GD
