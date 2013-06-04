/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Property.h"

#include <Uml/Kernel/Class.h>
#include <Lib/Core/Nyi.h>

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Property::Property(QString name, Class* c) : 
        mClass(c),
        mAssociation(0) {
    if(c) c->addAttribute(this);
    setName(name);
}

Element* Property::parent() const {
    return getClass();
}

int Property::index() const {
    return getClass()->attributes().indexOf(
            const_cast<Property*>(this));
}

QString Property::qualifiedName() const {
    if(!mClass) return "";
    QString s = mClass->qualifiedName();
    return s == "" ? s : s + separator() + name(); 
}

QString Property::toString() const {
    QString str = "";

    str += QString(QuUK::toChar(visibility()));
    str += " ";
    str += name();

    if(type()) {
        str += " : ";
        str += type()->name();
    }

    if(multiplicityString() != "") {
        str += " ";
        str += multiplicityString();
    }

    if(getDefault() != "") {
        str += " = ";
        str += getDefault();
    }

    if(readOnly()) {
        str += " {readOnly}";
    }

    return str;
}

void Property::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Property");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());
    writer.writeAttribute("type", type() ? type()->uniqueId() : "");
    writer.writeAttribute("lower", QString::number(lowerBound()));
    writer.writeAttribute("upper", (QString)upperBound());
    writer.writeAttribute("default", getDefault());
    writer.writeAttribute("readonly", readOnly() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_UK

