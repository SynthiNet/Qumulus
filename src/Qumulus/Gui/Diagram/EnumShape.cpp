/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumShape.h"

#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

EnumShape::EnumShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p), mHeader(new Compartment()),
        mBody(new Compartment()) {
    addCompartment(mHeader);
    addCompartment(mBody);
    updateSizeConstraints();
    resize(0, 0);
}

EnumShape::EnumShape(const EnumShape& s) :
        CompartmentableShape(s) {

}

QuUK::Enumeration* EnumShape::modelElement() const {
    return dynamic_cast<QuUK::Enumeration*>(
            CompartmentableShape::modelElement());
}

void EnumShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {
    updateSizeConstraints();
    resize(size());

    CompartmentableShape::paint(painter, option, widget);

    QFont stereotypeFont = sharedStyle()->font();
    stereotypeFont.setItalic(true);
    painter->setFont(stereotypeFont);
    painter->drawText(0, 0, width(), 20,
            Qt::AlignHCenter | Qt::AlignBottom,
            "« enumeration »");

    QFont nameFont = sharedStyle()->font();
    nameFont.setBold(true);
    painter->setFont(nameFont);
    painter->drawText(0, 20, width(), 40, 
            Qt::AlignHCenter | Qt::AlignTop,
            modelElement()->name());

    QFont literalFont = sharedStyle()->font();
    QFontMetrics met(literalFont);

    float th = mHeader->height();
    float delta = met.height() * 1.2;
    painter->setFont(literalFont);

    for(auto& a : modelElement()->ownedLiterals()) {
        painter->drawText(2, th, width() - 2, delta,
                Qt::AlignLeft | Qt::AlignVCenter,
                met.elidedText("• " + a->name(), Qt::ElideRight, width() - 4));
        th += delta;
    }
}

void EnumShape::updateSizeConstraints() {
    float fheight = QFontMetrics(sharedStyle()->font()).height() * 1.2; 
    float bheight = std::max(30.0f, 
            modelElement()->ownedLiterals().size() * fheight);

    setMinimumSize({std::max(190, enumNameWidth()) + 10, 20 + bheight});
    mHeader->setMinimumHeight(40);
    mHeader->setMaximumHeight(40);
    mBody->setMinimumHeight(bheight);
}

int EnumShape::enumNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}

QUML_END_NAMESPACE_GD
