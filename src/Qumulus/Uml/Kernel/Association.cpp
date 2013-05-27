/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Association.h"

#include "Classifier.h"

#include <QtCore/QXmlStreamWriter>

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
    (void)writer;
    NYI();
}

QUML_END_NAMESPACE_UK
