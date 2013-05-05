/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MultiplicityElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

MultiplicityElement::MultiplicityElement() {

}

MultiplicityElement::MultiplicityElement(QuLC::Unlimited u) :
        mLower(QuLC::unltd(u) ? nullptr : u),
        mUpper(u) {

}
MultiplicityElement::MultiplicityElement(unsigned l, QuLC::Unlimited u) : 
        mLower(l),
        mUpper(u) {

}


bool MultiplicityElement::isMultivalued() const { 
    return mUpper && *mUpper > 1; 
}

bool MultiplicityElement::includesCardinality(unsigned i) const { 
    return mLower && mUpper && *mLower <= i && i <= *mUpper;
}

bool MultiplicityElement::includedMultiplicity(MultiplicityElement* m) const {
    return mLower && mUpper && m->mLower && m->mUpper &&
            *mLower <= *m->mLower && *m->mUpper <= *mUpper;
}

QUML_END_NAMESPACE_UK
