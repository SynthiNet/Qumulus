/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Property.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

Property::Property(Class* c) : 
        mAggregation(AggregationKind::None),
        mClass(c),
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

QSet<Property*> Property::redefinedProperties() const {
    NYI();
    return QSet<Property*>();
}

QSet<Property*> Property::subsettedProperties() const {
    NYI();
    return QSet<Property*>();
}


QUML_END_NAMESPACE_UK

