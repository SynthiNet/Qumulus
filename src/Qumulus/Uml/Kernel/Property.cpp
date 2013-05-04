/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Property.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

Property::Property(Class* c) : 
        mClass(c),
        mReadOnly(false),
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

std::set<Property*> Property::redefinedProperties() const {
    NYI();
    return std::set<Property*>();
}

std::set<Property*> Property::subsettedProperties() const {
    NYI();
    return std::set<Property*>();
}


QUML_END_NAMESPACE_UK

