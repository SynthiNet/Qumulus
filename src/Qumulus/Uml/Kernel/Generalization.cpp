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

#include "Generalization.h"

#include "Classifier.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

Generalization::Generalization() {}

Generalization::Generalization(Classifier* general, Classifier* specific) :
        DirectedRelationship(general, specific) {
    specific->addGeneralization(this);

}

Classifier* Generalization::general() const {
    return dynamic_cast<Classifier*>(source());
}

void Generalization::setGeneral(Classifier* c) {
    setSource(c);
}

Classifier* Generalization::specific() const {
    return dynamic_cast<Classifier*>(target());
}

void Generalization::setSpecific(Classifier* c) {
    setTarget(c);
}

void Generalization::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Generalization");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("general", general()->uniqueId());

    writer.writeEndElement();
}

void Generalization::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    reader.ensureLoaded(node.attribute("general"));

    setUniqueId(node.attribute("id"));
    setGeneral(dynamic_cast<Classifier*>(Element::byId(node.attribute("id"))));

}


QUML_END_NAMESPACE_UK
