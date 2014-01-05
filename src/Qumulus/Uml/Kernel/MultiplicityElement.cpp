/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

    if(mLower == 0 && QuLC::unltd(mUpper)) {
        str += "[*]";
    } else if(QuLC::unltd(mUpper) || mLower != mUpper) {
        str += "[";
        str += QString::number(mLower);
        str += "..";
        str += QString(mUpper);
        str += "]";
    } else if(mLower != 1) {
        str += "[";
        str += QString::number(mLower);
        str += "]";
    }

    return str;
}

QUML_END_NAMESPACE_UK
