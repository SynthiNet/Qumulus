/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#include "Property.h"

#include <Uml/Kernel/Class.h>
#include <Lib/Core/Nyi.h>

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

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
    writer.writeAttribute("visibility", QuUK::toString(visibility()));
    writer.writeAttribute("lower", QString::number(lowerBound()));
    writer.writeAttribute("upper", (QString)upperBound());
    writer.writeAttribute("default", getDefault());
    writer.writeAttribute("static", isStatic() ? "true" : "false");
    writer.writeAttribute("readonly", readOnly() ? "true" : "false");

    writer.writeEndElement();
}

void Property::readXml(QDomElement node, QuLC::XmlModelReader& reader) {

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));

    if(node.attribute("type") != "") {
        reader.ensureLoaded(node.attribute("type"));
        setType(dynamic_cast<Type*>(Element::byId(node.attribute("type"))));
    }

    setVisiblity(visibilityKindFromString(node.attribute("visibility")));
    setLowerBound(node.attribute("lower").toInt());
    setUpperBound(node.attribute("upper") == "*" ? QuLC::Unlimited("*") :
            QuLC::Unlimited(node.attribute("upper").toInt()));
    setDefault(node.attribute("default"));
    setStatic(node.attribute("static") == "true");
    setReadOnly(node.attribute("readonly") == "true");

}

QUML_END_NAMESPACE_UK

