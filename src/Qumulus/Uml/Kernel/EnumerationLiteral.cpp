/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumerationLiteral.h"

#include "Enumeration.h"

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

EnumerationLiteral::EnumerationLiteral() {}
EnumerationLiteral::EnumerationLiteral(QString name, Enumeration* o) :
        NamedElement(name),
        mEnumeration(o) {
    if(o) o->addLiteral(this);
}

Element* EnumerationLiteral::parent() const {
    return enumeration();
}

int EnumerationLiteral::index() const {
    return enumeration()->literals().indexOf(
            const_cast<EnumerationLiteral*>(this));
}

QString EnumerationLiteral::qualifiedName() const {
    if(!mEnumeration) return "";
    QString s = mEnumeration->qualifiedName();
    return s == "" ? s : s + separator() + name();
}

void EnumerationLiteral::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Literal");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());
    writer.writeEndElement();
}

void EnumerationLiteral::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)node;
    (void)reader;

    NYI();
}

QUML_END_NAMESPACE_UK
