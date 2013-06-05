/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Generalization.h"

#include "Classifier.h"

#include <QtCore/QXmlStreamWriter>

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

QUML_END_NAMESPACE_UK
