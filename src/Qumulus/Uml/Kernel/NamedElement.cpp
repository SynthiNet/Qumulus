/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "NamedElement.h"

#include "Namespace.h"

QUML_BEGIN_NAMESPACE_UK

QuLC::Optional<QString> NamedElement::qualifiedName() const {
    if(mName) {
        if(mNameSpace) {
            auto super = mNameSpace->qualifiedName();
            if(super) {
                return *super + separator() + *mName;
            } else {
                return nullptr;
            }
        } else {
            return mName;
        }
    } else {
        return nullptr;
    }
}


bool NamedElement::isDistinguishableFrom(NamedElement* n) const {
    return mName != n->mName;
}

QUML_END_NAMESPACE_UK
