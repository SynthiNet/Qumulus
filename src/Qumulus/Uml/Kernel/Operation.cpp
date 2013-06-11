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

Element* Operation::parent() const {
    return getClass();
}

int Operation::index() const {
    int i = getClass()->operations().indexOf(
            const_cast<Operation*>(this));
    if(i == -1) return -1;
    else return getClass()->attributes().size() + i;
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
    writer.writeAttribute("query", isQuery() ? "true" : "false");

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

void Operation::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));
    setVisiblity(visibilityKindFromString(node.attribute("visibility")));
    setLeaf(node.attribute("leaf") == "true");
    setStatic(node.attribute("static") == "true");
    setQuery(node.attribute("query") == "true");

    // LOAD PARAMETERS
    QDomNodeList children = node.childNodes();

    for(int i = 0; i < children.size(); ++i) {
        auto e = children.at(i).toElement();

        if(e.tagName() == "Parameter") {
            auto p = reader.loadElement(e);
            addParameter(dynamic_cast<Parameter*>(p));
        } else {
            throw QuLC::ParseException(qPrintable(
                        "Operations cannot contain a "+e.tagName()));
        }
    }
}

QUML_END_NAMESPACE_UK
