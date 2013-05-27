/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Enumeration.h"

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Enumeration::Enumeration() {

}

Enumeration::~Enumeration() {
    for(auto& x : mOwnedLiterals) {
        delete x;
    }
}

Enumeration::Enumeration(QString name, Package* p) :
        DataType(name, p) {

}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.removeAll(l);
}

void Enumeration::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Enumeration");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());

    for(auto& l : literals()) {
        l->writeXml(writer);
    }

    writer.writeEndElement();
}

QUML_END_NAMESPACE_UK
