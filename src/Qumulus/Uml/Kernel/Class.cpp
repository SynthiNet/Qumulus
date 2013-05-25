/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Class.h"

#include "Property.h"
#include "Operation.h"

#include <Lib/Core/Functional.h>

QUML_BEGIN_NAMESPACE_UK

Class::Class() {

}

Class::Class(QString name, Namespace* p) :
        Classifier(name, p) {

}


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

void Class::addAttribute(Property* p) {
    mOwnedAttributes.append(p);
    addFeature(p);
}

void Class::removeAttribute(Property* p) {
    mOwnedAttributes.removeAll(p);
    removeFeature(p);
}

QUML_END_NAMESPACE_UK
