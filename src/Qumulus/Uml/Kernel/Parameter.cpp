/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Parameter.h"

#include "Operation.h"
#include "Type.h"

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Parameter::Parameter(QString name, Operation* o) :
    mDirection(ParameterDirectionKind::In) {
    setOperation(o);
    if(o) o->addParameter(this);
    setName(name);
}

void Parameter::setOperation(Operation* o) {
    mOperation = o;
    elementChanged();
}

QString Parameter::toString() const {
    QString str;

    // Parameter direction
    if(direction() == ParameterDirectionKind::Out) {
        str += "out ";
    }

    if(direction() == ParameterDirectionKind::InOut) {
        str += "inout ";
    }

    // XXX: This is normally not used (instead, append return type to
    // operation)
    if(direction() == ParameterDirectionKind::Return) {
        str += "return ";
    }

    // Parameter name
    str += name();

    // Parameter type
    if(type()) {
        str += " : ";
        str += type()->name();
    }

    // Parameter multiplicity
    if(multiplicityString() != "") {
        str += " ";
        str += multiplicityString();
    }

    // Parameter default
    if(defaultValue() != "") {
        str += " = ";
        str += defaultValue();
    }

    return str;
}

void Parameter::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Parameter");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());
    writer.writeAttribute("direction", QuUK::toString(direction()));
    writer.writeAttribute("type", type() ? type()->uniqueId() : "");
    writer.writeAttribute("lower", QString::number(lowerBound()));
    writer.writeAttribute("upper", (QString)upperBound());
    writer.writeAttribute("default", defaultValue());

    writer.writeEndElement();
}

void Parameter::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)node;
    (void)reader;

    NYI();
}

QUML_END_NAMESPACE_UK
