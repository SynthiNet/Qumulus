/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Class.h"

#include "Property.h"
#include "Operation.h"

QUML_BEGIN_NAMESPACE_UK

void Class::addNestedClassifier(Classifier* c) {
    mNestedClassifiers.append(c);
    addOwnedMember(c);
}

void Class::removeNestedClassifier(Classifier* c) {
    mNestedClassifiers.removeAll(c);
    removeOwnedMember(c);
}

void Class::addOperation(Operation* c) {
    mOwnedOperations.append(c);
    addFeature(c);
}

void Class::removeOperation(Operation* c) {
    mOwnedOperations.append(c);
    removeFeature(c);
}

void Class::addSuperClass(Class* c) {
    mSuperClasses.insert(c);
    addGeneralization(c);
}

void Class::removeSuperClass(Class* c) {
    mSuperClasses.remove(c);
    removeGeneralization(c);
}


QUML_END_NAMESPACE_UK
