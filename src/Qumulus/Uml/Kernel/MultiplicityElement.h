/*
 * Qumulus UML editor
 * Author: Frank Erens
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
    bool isMultivalued() const;
    bool includesCardinatity(unsigned i) const;
    bool includedMultiplicity(MultiplicityElement* m) const;

    QuLC::Optional<unsigned> lowerBound() const {
        return mLower;
    }

    void setLowerBound(QuLC::Optional<unsigned> u) {
        mLower = u;
    }

    QuLC::Optional<QuLC::Unlimited> upperBound() const {
        return mUpper;
    }

    void setUpperBound(QuLC::Optional<QuLC::Unlimited> u) {
        mUpper = u;
    }

    QUML_CLONABLE(MultiplicityElement)
private:
    QuLC::Optional<unsigned> mLower;
    QuLC::Optional<QuLC::Unlimited> mUpper;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_MULTIPLICITYELEMENT_H_ */

