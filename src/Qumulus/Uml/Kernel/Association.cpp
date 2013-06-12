/*
 * Qumulus UML editor
 * Author: Frank Erens
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
