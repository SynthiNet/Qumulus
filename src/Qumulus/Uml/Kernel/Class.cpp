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
    NYI();
    mNestedClassifiers.append(c);
    addElement(std::move(c));
}

void Class::removeNestedClassifier(Classifier* c) {
    (void)c;
    NYI();
}

void Class::addOperation(Operation* c) {
    NYI();
    mOwnedOperations.append(c);
    addElement(c);
}

void Class::removeOperation(Operation* c) {
    (void)c;
    NYI();
}


QSet<Classifier*> Class::general() const {
    return QuLC::mapto<Classifier*>(mSuperClasses);
}

void Class::addSuperClass(Class* c) {
    mSuperClasses.insert(c);
}

void Class::removeSuperClass(Class* c) {
    mSuperClasses.remove(c);
}


QUML_END_NAMESPACE_UK
