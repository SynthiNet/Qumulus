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

Class::Class(QString name, Package* p) :
        Classifier(name, p) {

}

Class::~Class() {
    for(auto& x : mOwnedAttributes) {
        delete x;
    }

    for(auto& x : mOwnedOperations) {
        delete x;
    }
}

// void Class::addNestedClassifier(Classifier* c) {
//     mNestedClassifiers.append(c);
// }

// void Class::removeNestedClassifier(Classifier* c) {
//     mNestedClassifiers.removeAll(c);
// }

void Class::addOperation(Operation* c) {
    mOwnedOperations.append(c);
}

void Class::removeOperation(Operation* c) {
    mOwnedOperations.append(c);
}

void Class::addAttribute(Property* p) {
    mOwnedAttributes.append(p);
}

void Class::removeAttribute(Property* p) {
    mOwnedAttributes.removeAll(p);
}

QUML_END_NAMESPACE_UK
