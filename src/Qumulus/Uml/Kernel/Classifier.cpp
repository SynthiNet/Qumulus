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

Classifier::Classifier(QString name, Package* p)  {
    setName(name);
    setPackage(p);
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

    elementChanged();
}

void Classifier::removeGeneralization(Generalization* c) {
    if(mGeneralizations.contains(c)) {
        mGeneralizations.remove(c);
        elementChanged();
    }
}

QUML_END_NAMESPACE_UK
