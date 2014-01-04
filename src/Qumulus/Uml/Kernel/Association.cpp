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

#include "Association.h"

#include "Classifier.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

Association::Association(Classifier* source, Classifier* target) :
        DirectedRelationship(source, target) {

}

Classifier* Association::sourceType() const {
    return dynamic_cast<Classifier*>(source());
}

void Association::setSourceType(Classifier* c) {
    setSource(c);
}

Classifier* Association::targetType() const {
    return dynamic_cast<Classifier*>(target());
}

void Association::setTargetType(Classifier* c) {
    setTarget(c);
}

void Association::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Association");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("source", source()->uniqueId());
    writer.writeAttribute("target", target()->uniqueId());
    writer.writeAttribute("aggregation", toString(aggregation()));

    writer.writeEndElement();
}

void Association::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    reader.ensureLoaded(node.attribute("source"));
    reader.ensureLoaded(node.attribute("target"));

    setUniqueId(node.attribute("id"));
    setSource(dynamic_cast<Classifier*>(
                Element::byId(node.attribute("source"))));
    setTarget(dynamic_cast<Classifier*>(
                Element::byId(node.attribute("target"))));
    setAggregation(aggregationKindFromString(node.attribute("aggregation")));
}


QUML_END_NAMESPACE_UK
