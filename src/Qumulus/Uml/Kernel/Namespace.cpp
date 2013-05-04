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
        if(NamedElement* p = dynamic_cast<NamedElement*>(x.get())) {
            mOwnedMembers.insert(p);
        }
    }
}

void Namespace::addOwnedMember(uptr<NamedElement> e) {
    QuLC::add(mOwnedMembers, e.get());
    addElement(std::move(e));
}

void Namespace::removeOwnedMember(NamedElement* e) {
    QuLC::remove(mOwnedMembers, e);
    removeElement(e);
}


QUML_END_NAMESPACE_UK
