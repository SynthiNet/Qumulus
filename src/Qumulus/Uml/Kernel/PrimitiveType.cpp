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

void PrimitiveType::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));
}

QUML_END_NAMESPACE_UK
