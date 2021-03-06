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

#include "Package.h"

#include "Type.h"

#include <QtWidgets/QGraphicsRectItem>

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

Package::Package() {}

Package::Package(QString name, Package* p) :
        PackageableElement(name, p) {
}

Package::~Package() {
    for(auto& x : mPackagedElements) {
        delete x;
    }
}

size_t Package::size() const {
    return mPackagedElements.size();
}

Element* Package::operator[](size_t idx) const {
    return mPackagedElements[idx];
}

void Package::addPackagedElement(PackageableElement* e) {
    if(mPackagedElements.contains(e)) return;
    mPackagedElements.append(e);

    elementChanged();
}

void Package::removePackagedElement(PackageableElement* e) {
    if(mPackagedElements.contains(e)) {
        mPackagedElements.removeAll(e);
        elementChanged();
    }
}

void Package::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Package");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());

    for(auto& x : mPackagedElements) {
        x->writeXml(writer);
    }

    writer.writeEndElement();
}

void Package::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));

    QDomNodeList children = node.childNodes();
    for(int i = 0; i < children.size(); ++i) {
        auto e = children.at(i).toElement();

        auto p = reader.loadElement(e);
        dynamic_cast<PackageableElement*>(p)->setPackage(this);
    }

}

QUML_END_NAMESPACE_UK
