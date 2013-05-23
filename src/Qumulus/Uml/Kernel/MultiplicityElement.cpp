/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "MultiplicityElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

MultiplicityElement::MultiplicityElement() :
        mLower(1),
        mUpper(1) {

}

MultiplicityElement::MultiplicityElement(unsigned l, QuLC::Unlimited u) : 
        mLower(l),
        mUpper(u) {

}


bool MultiplicityElement::isMultivalued() const { 
    return mUpper > 1; 
}

bool MultiplicityElement::includesCardinality(unsigned i) const { 
    return mLower <= i && i <= mUpper;
}

bool MultiplicityElement::includedMultiplicity(MultiplicityElement* m) const {
    return mLower <= m->mLower && m->mUpper <= mUpper;
}

QString MultiplicityElement::multiplicityString() const {
    QString str = "";

    if(mLower == 0 || QuLC::unltd(mUpper)) {
        str += "[*]";
    } else if(QuLC::unltd(mUpper) || mLower != mUpper) {
        str += "[";
        str += mLower;
        str += "..";
        str += mUpper;
        str += "]";
    } else if(mLower != 1) {
        str += "[";
        str += mLower;
        str += "]";
    }

    return str;
}

QUML_END_NAMESPACE_UK
