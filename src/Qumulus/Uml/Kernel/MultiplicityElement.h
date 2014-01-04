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

#ifndef UML_KERNEL_MULTIPLICITYELEMENT_H_
#define UML_KERNEL_MULTIPLICITYELEMENT_H_

#include "internal_base.h"

#include "Element.h"

#include <Lib/Core/Optional.h>
#include <Lib/Core/Unlimited.h>

QUML_BEGIN_NAMESPACE_UK

class MultiplicityElement : public virtual Element {
public:
    MultiplicityElement();
    MultiplicityElement(unsigned l, QuLC::Unlimited u);

    bool isMultivalued() const;
    bool includesCardinality(unsigned i) const;
    bool includedMultiplicity(MultiplicityElement* m) const;

    unsigned lowerBound() const {
        return mLower;
    }

    void setLowerBound(unsigned u) {
        mLower = u;
        elementChanged();
    }

    QuLC::Unlimited upperBound() const {
        return mUpper;
    }

    void setUpperBound(QuLC::Unlimited u) {
        mUpper = u;
        elementChanged();
    }

    QString multiplicityString() const;

    QUML_CLONABLE_ABSTRACT(MultiplicityElement)
private:
    unsigned mLower;
    QuLC::Unlimited mUpper;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_MULTIPLICITYELEMENT_H_ */

