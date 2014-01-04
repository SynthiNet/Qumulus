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

#include "EnumerationLiteral.h"

#include "Enumeration.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

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

void EnumerationLiteral::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));
}

QUML_END_NAMESPACE_UK
