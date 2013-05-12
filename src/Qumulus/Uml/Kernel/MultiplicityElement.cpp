/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
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

QString MultiplicityElement::multiplicityString() const {
    QString str = "";
    if(mLower || mUpper) {
        unsigned lower = mLower ? *(mLower) : 0;
        QuLC::Unlimited upper = mUpper ? *(mUpper) : "*";

        if(lower == 0 || QuLC::unltd(upper)) {
            str += "[*]";
        } else if(QuLC::unltd(upper) || lower != upper) {
            str += "[";
            str += lower;
            str += "..";
            str += upper;
            str += "]";
        } else if(lower != 1) {
            str += "[";
            str += lower;
            str += "]";
        }
    }

    return str;
}

QUML_END_NAMESPACE_UK
