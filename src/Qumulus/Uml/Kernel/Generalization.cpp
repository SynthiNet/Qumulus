/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Generalization.h"

#include "Classifier.h"

QUML_BEGIN_NAMESPACE_UK

Generalization::Generalization() {}

Generalization::Generalization(Classifier* general, Classifier* specific) :
        DirectedRelationship(general, specific) {

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

QUML_END_NAMESPACE_UK
