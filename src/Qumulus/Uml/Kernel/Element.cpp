/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Element.h"

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UK

Element::Element(const Element& other) {
    for(auto& x : other.mOwnedElements) {
        mOwnedElements.insert(uptr<Element>(x->clone()));
    }

    for(auto& x : mOwnedElements) {
        if(Comment* p = dynamic_cast<Comment*>(x.get())) {
            mOwnedComments.insert(p);
        }
    }
}


Element::Element(Element&& other) {
    std::swap(mOwnedElements, other.mOwnedElements);
}

void Element::addComment(uptr<Comment> c) {
    QuLC::add(mOwnedComments, c.get());
    addElement(std::move(c));
}

void Element::removeComment(Comment* c) {
    QuLC::remove(mOwnedComments, c);
    removeElement(c);
}


void Element::addElement(uptr<Element> other) {
    mOwnedElements.insert(std::move(other)); 
}

void Element::removeElement(Element* other) {
    auto it = std::find_if(mOwnedElements.begin(), mOwnedElements.end(),
            [&](const uptr<Element>& e) { return e.get() == other;});
    mOwnedElements.erase(it); 
}

std::size_t Element::numElements() const {
    return mOwnedElements.size();
}

void Element::clearElements() {
    mOwnedElements.clear();
}

bool Element::contains(Element* other) const {
    return std::find_if(mOwnedElements.begin(), mOwnedElements.end(),
            [&](const uptr<Element>& e) { return e.get() == other;}) != 
            mOwnedElements.end();
}

bool Element::containsRecursive(Element* other) const {
    if(contains(other)) return true;

    for(const uptr<Element>& e : mOwnedElements) {
        if(e->containsRecursive(other)) return true;
    }

    return false;
}

QUML_END_NAMESPACE_UK
