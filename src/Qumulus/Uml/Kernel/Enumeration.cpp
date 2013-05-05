/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Enumeration.h"

QUML_BEGIN_NAMESPACE_UK

Enumeration::Enumeration() {}

Enumeration::Enumeration(QString name, Namespace* p) :
        DataType(name, p) {

}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);
    addOwnedMember(l);
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.removeAll(l);
    removeOwnedMember(l);
}

QUML_END_NAMESPACE_UK
