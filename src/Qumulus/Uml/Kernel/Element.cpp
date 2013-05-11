/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Element.h"

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UK

QHash<QString, Element*> Element::mElementsById;

Element::Element() :
        mDiagramElement(0) {
    mElementsById.insert(uniqueId(), this);
}

Element::Element(const Element& other) :
        mDiagramElement(0) {
    for(auto& x : other.mOwnedElements) {
        mOwnedElements.insert(x->clone());
    }

    for(auto& x : mOwnedElements) {
        if(Comment* p = dynamic_cast<Comment*>(x)) {
            mOwnedComments.insert(p);
        }
    }

    mElementsById.insert(uniqueId(), this);
}

Element::~Element() {
    for(auto& x : mOwnedElements) {
        delete x;
    }

    mElementsById.remove(uniqueId());

    delete mDiagramElement;
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

QString Element::uniqueId() const {
    return mUniqueId.toString();
}

void Element::setUniqueId(const QString& s) {
    mElementsById.remove(uniqueId());
    mUniqueId = s;
    mElementsById.insert(s, this);
}

Element* Element::byId(const QString& s) {
    auto it = mElementsById.find(s);
    return it == mElementsById.end() ? nullptr : *it;
}

QUML_END_NAMESPACE_UK
