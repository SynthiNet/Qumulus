/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveShape.h"

#include <Uml/Kernel/PrimitiveType.h>

#include <QtGui/QPainter>
#include <QtCore/QXmlStreamWriter>

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
    updateSizeConstraints();
    resize(size());
    CompartmentableShape::paint(painter, option, widget);

    QFont stereotypeFont = sharedStyle()->font();
    stereotypeFont.setItalic(true);
    painter->setFont(stereotypeFont);
    painter->drawText(0, 0, width(), height() / 2,
            Qt::AlignHCenter | Qt::AlignBottom,
            "\u00AB primitive \u00BB");

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

void PrimitiveShape::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("PrimitiveType");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("x", QString::number(pos().x()));
    writer.writeAttribute("y", QString::number(pos().y()));
    writer.writeAttribute("width", QString::number(width()));
    writer.writeAttribute("height", QString::number(height()));
    writer.writeAttribute("modelelement", modelElement()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD
