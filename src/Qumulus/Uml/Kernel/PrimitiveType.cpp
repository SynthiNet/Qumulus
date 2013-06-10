/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveType.h"

#include <QtCore/QDebug>

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

struct PrimitiveTypeGraphics {
    PrimitiveTypeGraphics(PrimitiveType* p);
    ~PrimitiveTypeGraphics();
};

PrimitiveType::PrimitiveType() {

}

void PrimitiveType::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("PrimitiveType");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());

    writer.writeEndElement();
}

void PrimitiveType::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)node;
    (void)reader;

    NYI();
}

QUML_END_NAMESPACE_UK
