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

#include "Enumeration.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

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

size_t Enumeration::size() const {
    return mOwnedLiterals.size();
}

Element* Enumeration::operator[](size_t idx) const {
    return mOwnedLiterals[idx];
}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);

    elementChanged();
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    if(mOwnedLiterals.contains(l)) {
        mOwnedLiterals.removeAll(l);
        elementChanged();
    }
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

void Enumeration::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));

    // LOAD LITERALS
    QDomNodeList children = node.childNodes();

    for(int i = 0; i < children.size(); ++i) {
        auto e = children.at(i).toElement();

        if(e.tagName() == "Literal") {
            auto p = reader.loadElement(e);
            dynamic_cast<EnumerationLiteral*>(p)->setEnumeration(this);
            addLiteral(dynamic_cast<EnumerationLiteral*>(p));
        } else {
            throw QuLC::ParseException(qPrintable(
                        "Enumerations cannot contain a"+e.tagName()));
        }
    }

}

QUML_END_NAMESPACE_UK
