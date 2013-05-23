/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Classifier.h"
#include "Feature.h"
#include "Property.h"

QUML_BEGIN_NAMESPACE_UK

Classifier::Classifier() {

}

Classifier::Classifier(QString name, Namespace* p)  {
    setName(name);
    setNameSpace(p);
}

void Classifier::addFeature(Feature* p) {
    mFeatures.insert(p);
    addOwnedMember(p);
}

void Classifier::removeFeature(Feature* f) {
    mFeatures.remove(f);
    removeOwnedMember(f);
}

const QSet<Classifier*> Classifier::general() const {
    QSet<Classifier*> toReturn;
    for(Generalization* g : mGeneralizations) {
        toReturn.insert(g->general());
    }

    return toReturn;
}

void Classifier::addGeneralization(Generalization* c) {
    mGeneralizations.insert(c);
}

void Classifier::removeGeneralization(Generalization* c) {
    mGeneralizations.remove(c);
}

#if 0
QuUD::ClassifierShape* Classifier::diagramElement() const {
    return static_cast<QuUD::ClassifierShape*>(mDiagramElement);
}
#endif

QUML_END_NAMESPACE_UK
