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
        mOwnedElements.insert(x->clone());
    }

    for(auto& x : mOwnedElements) {
        if(Comment* p = dynamic_cast<Comment*>(x)) {
            mOwnedComments.insert(p);
        }
    }
}

Element::~Element() {
    for(auto& x : mOwnedElements) {
        delete x;
    }
}

void Element::addComment(Comment* c) {
    mOwnedComments.insert(c);
    addElement(c);
}

void Element::removeComment(Comment* c) {
    mOwnedComments.remove(c);
    removeElement(c);
}


void Element::addElement(Element* other) {
    mOwnedElements.insert(other); 
}

void Element::removeElement(Element* other) {
    mOwnedElements.remove(other);
}

QUML_END_NAMESPACE_UK
