/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Operation.h"

#include <Uml/Kernel/Class.h>

#include "Parameter.h"

#include "Class.h"

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Operation::Operation(QString name, Class* c) : 
        mClass(c), 
        mQuery(false) {
    setName(name);
    if(c) c->addOperation(this);
}

Parameter* Operation::returnResult() const {
    for(auto&& p : parameters()) {
        if(p->direction() == ParameterDirectionKind::Return)
            return p;
    }
    return nullptr;
}

Type* Operation::type() const {
    if(returnResult())
        return returnResult()->type();
    else
        return nullptr;
}

QString Operation::qualifiedName() const {
    if(!mClass) return "";
    QString s = mClass->qualifiedName();
    return s == "" ? s : s + separator() + name(); 
}

QString Operation::toString() const {
    QString str = "";

    str += QString(toChar(visibility()));
    str += " ";
    str += name();

    str += "(";

    for(Parameter* p : parameters()) {
        if(p->direction() == ParameterDirectionKind::Return) continue;

        str += p->toString();

        if(p != *(parameters().end()-1)) {
            str += ", ";
        }
    }

    str += ")";

    if(type()) {
        str += " : ";
        str += type()->name();
    }

    if(isQuery()) {
        str += " {query}";
    }

    return str;
}

void Operation::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Operation");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());
    writer.writeAttribute("visibility", QuUK::toString(visibility()));
    writer.writeAttribute("leaf", leaf() ? "true" : "false");
    writer.writeAttribute("static", isStatic() ? "true" : "false");

    for(auto& x : raisedExceptions()) {
        writer.writeStartElement("Exception");
        writer.writeAttribute("type", x->uniqueId());
        writer.writeEndElement();
    }

    for(auto& x : parameters()) {
        x->writeXml(writer);
    }

    writer.writeEndElement();
}

QUML_END_NAMESPACE_UK
