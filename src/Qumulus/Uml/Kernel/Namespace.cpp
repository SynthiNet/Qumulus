/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Namespace.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

Namespace::Namespace(const Namespace& n) : NamedElement(n) {
    for(auto&& x : ownedElements()) {
        if(NamedElement* p = dynamic_cast<NamedElement*>(x)) {
            mOwnedMembers.insert(p);
        }
    }
}

void Namespace::addOwnedMember(NamedElement* e) {
    mOwnedMembers.insert(e);
    addElement(e);
}

void Namespace::removeOwnedMember(NamedElement* e) {
    mOwnedMembers.remove(e);
    removeElement(e);
}


QUML_END_NAMESPACE_UK
