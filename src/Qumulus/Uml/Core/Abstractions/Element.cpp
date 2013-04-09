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


Element::Element(Element&& other) {
    std::swap(mOwnedElements, other.mOwnedElements);
}

void Element::addElement(uptr<Element> other) {
    mOwnedElements.insert(std::move(other)); 
}

void Element::removeElement(const uptr<Element>& other) {
    mOwnedElements.erase(other); 
}

std::size_t Element::size() const {
    return mOwnedElements.size();
}

void Element::clear() {
    mOwnedElements.clear();
}

bool Element::contains(const uptr<Element>& other) const {
    return mOwnedElements.find(other) != mOwnedElements.end();
}

bool Element::containsRecursive(const uptr<Element>& other) const {
    if(contains(other)) return true;

    for(const uptr<Element>& e : mOwnedElements) {
        if(e->containsRecursive(other)) return true;
    }

    return false;
}

QUML_END_NAMESPACE_UCA
