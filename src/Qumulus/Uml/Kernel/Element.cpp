/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Element.h"

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UK

QHash<QString, Element*> Element::mElementsById;

Element::Element() {
    mElementsById.insert(uniqueId(), this);
}

Element::Element(const Element&) {
    NYI();
    mElementsById.insert(uniqueId(), this);
}

Element::~Element() {
    mElementsById.remove(uniqueId());
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
