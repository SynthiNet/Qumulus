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

Classifier::Classifier(QString name, Package* p) : Type(name, p) {

}

void Classifier::addAttribute(Property* p) {
    mAttributes.append(p);
    addFeature(p);
}

void Classifier::removeAttribute(Property* p) {
    mAttributes.removeAll(p);
    removeFeature(p);
}

void Classifier::addFeature(Feature* p) {
    mFeatures.insert(p);
    addOwnedMember(p);
}

void Classifier::removeFeature(Feature* f) {
    mFeatures.remove(f);
    removeOwnedMember(f);
}

QUML_END_NAMESPACE_UK
