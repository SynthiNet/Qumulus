/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "NamedElement.h"

#include "Namespace.h"

QUML_BEGIN_NAMESPACE_UK

NamedElement::NamedElement() :
        mName(nullptr),
        mVisibility(nullptr),
        mNameSpace(0) {

}

NamedElement::NamedElement(QString name, Namespace* n) :
        mName(name),
        mVisibility(nullptr),
        mNameSpace(n) {

}



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
