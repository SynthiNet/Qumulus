/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
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

