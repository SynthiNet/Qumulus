/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Enumeration.h"

QUML_BEGIN_NAMESPACE_UK

Enumeration::Enumeration() {

}

Enumeration::~Enumeration() {
    for(auto& x : mOwnedLiterals) {
        delete x;
    }
}

Enumeration::Enumeration(QString name, Package* p) :
        DataType(name, p) {

}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.removeAll(l);
}

QUML_END_NAMESPACE_UK
