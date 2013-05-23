/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ClassShape.h"

#include "Compartment.h"

#include <Uml/Kernel/Property.h>
#include <Uml/Kernel/Operation.h>

#include <QtGui/QPainter>

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
    float fheight = QFontMetrics(sharedStyle()->font()).height() * 1.2; 
    float aheight = std::max(30.0f, 
            modelElement()->attributes().size() * fheight) + 10;
    float oheight = std::max(30.0f, 
            modelElement()->operations().size() * fheight) + 10;

    setMinimumSize({std::max(190, classNameWidth()) + 10, 
            20 + aheight + oheight});
    mHeadCompartment->setMinimumHeight(20);
    mHeadCompartment->setMaximumHeight(20);
    mAttributeCompartment->setMinimumHeight(aheight);
    mOperationCompartment->setMinimumHeight(oheight);
}

void ClassShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {
    updateSizeConstraints();
    resize(size());

    CompartmentableShape::paint(painter, option, widget);

    QFont nameFont = sharedStyle()->font();
    nameFont.setBold(true);
    if(modelElement()->abstract()) 
        nameFont.setItalic(true);

    painter->setFont(nameFont);
    painter->drawText(0, 0, width(), 20,
            Qt::AlignHCenter | Qt::AlignVCenter,
            modelElement()->name());

    QFont featureFont = sharedStyle()->font();
    QFont staticFeatureFont = featureFont;
    staticFeatureFont.setUnderline(true);
    QFontMetrics met(featureFont);

    float th = 20;
    float delta = met.height() * 1.2;

    for(auto& a : modelElement()->attributes()) {
        painter->setFont(a->isStatic() ? staticFeatureFont : featureFont);
        painter->drawText(2, th, width() - 2, delta,
                Qt::AlignLeft | Qt::AlignVCenter,
                met.elidedText(a->toString(), 
                        Qt::ElideRight, width() - 4));
        th += delta;
    }

    th = 20 + mAttributeCompartment->height();

    for(auto& o : modelElement()->operations()) {
        painter->setFont(o->isStatic() ? staticFeatureFont : featureFont);
        painter->drawText(2, th, width() - 2, delta,
                Qt::AlignLeft | Qt::AlignVCenter,
                met.elidedText(o->toString(), 
                        Qt::ElideRight, width() - 4));
        th += delta;
    }
}

int ClassShape::classNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}
QUML_END_NAMESPACE_GD
