/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Element.h"

QUML_BEGIN_NAMESPACE_UCA

Element::Element(const Element& other) {
    for(auto& x : other.mOwnedElements) {
        mOwnedElements.insert(uptr<Element>(x->clone()));
    }
}

QUML_END_NAMESPACE_UCA
