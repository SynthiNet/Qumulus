/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Property.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UCC

Property::Property(Class* c) : 
        mClass(c),
        mReadOnly(false),
        mOpposite(0),
        mAssociation(0) {

}

Property* Property::opposite() const {
    NYI();
    return nullptr;
}


Association* Property::owningAssociation() const {
    NYI();
    return nullptr;
}

std::set<Property*> redefinedProperties() const {
    NYI();
    return {};
}

std::set<Property*> subsettedProperties() const {
    NYI();
    return {};
}


QUML_END_NAMESPACE_UCC

