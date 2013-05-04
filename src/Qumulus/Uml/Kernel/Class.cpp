/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Class.h"

#include "Property.h"
#include "Operation.h"

QUML_BEGIN_NAMESPACE_UK

void Class::addNestedClassifier(uptr<Classifier> c) {
    NYI();
    mNestedClassifiers.push_back(c.get());
    addElement(std::move(c));
}

void Class::removeNestedClassifier(Classifier* c) {
    (void)c;
    NYI();
}


void Class::addAttribute(uptr<Property> c) {
    NYI();
    mOwnedAttributes.push_back(c.get());
    addElement(std::move(c));
}

void Class::removeAttribute(Property* c) {
    (void)c;
    NYI();
}


void Class::addOperation(uptr<Operation> c) {
    NYI();
    mOwnedOperations.push_back(c.get());
    addElement(std::move(c));
}

void Class::removeOperation(Operation* c) {
    (void)c;
    NYI();
}


uset<Classifier*> Class::general() const {
    uset<Classifier*> toReturn;
    for(auto p : superClasses()) {
        toReturn.insert(p);
    }

    return toReturn;
}

void Class::addSuperClass(Class* c) {
    mSuperClasses.insert(c);
}

void Class::removeSuperClass(Class* c) {
    mSuperClasses.erase(c);
}


QUML_END_NAMESPACE_UK
