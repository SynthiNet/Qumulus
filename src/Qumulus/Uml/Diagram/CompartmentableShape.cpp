/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "CompartmentableShape.h"
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UD

CompartmentableShape::CompartmentableShape(QuUK::Element* e, 
        DiagramElement* p) :
        Shape(e, p) {
    setFlag(QGraphicsItem::ItemIsSelectable);
}

CompartmentableShape::CompartmentableShape(const CompartmentableShape& c) :
        Shape(c) {

}

Compartment* CompartmentableShape::compartment(unsigned i) {
    return mCompartments[i];
}

void CompartmentableShape::addCompartment(Compartment* c) {
    mCompartments.append(c);
    addToGroup(c);
}

void CompartmentableShape::resize(double w, double h) {
    if(minimumSize().isValid()) {
        w = std::max(w, minimumSize().width());
        h = std::max(h, minimumSize().height());
    }

    unsigned totalh = 0;
    for(int i = 0; i < compartments().size(); ++i) {
        unsigned newh = h / (compartments().size() - i);

        compartment(i)->resize(w, newh);
        unsigned actualh = compartment(i)->height();

        if(i < compartments().size() - 1)
            compartment(i + 1)->setPos(0, compartment(i)->pos().y() + actualh);
        
        h -= actualh;
        totalh += actualh;
    }

    setSize({compartment(0)->size().width(), totalh});
}

QVariant CompartmentableShape::itemChange(GraphicsItemChange c, 
        const QVariant& v) {
    if(c == QGraphicsItem::ItemSelectedChange) {
        if(v.toBool()) {
            qDebug() << "Selected";
        } else {
            qDebug() << "Deselected";
        }
    }
    return Shape::itemChange(c, v); 
}

QRectF CompartmentableShape::boundingRect() const {
    return QRectF(0, 0, width(), height());
}

QUML_END_NAMESPACE_UD
