/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_ABSTRACTIONS_VALUESPECIFICATION_H_
#define UML_CORE_ABSTRACTIONS_VALUESPECIFICATION_H_

#include "internal_base.h"

#include "Element.h"

#include <Lib/Core/Optional.h>
#include <Lib/Core/Unlimited.h>

QUML_BEGIN_NAMESPACE_UCA

class ValueSpecification : public virtual Element {
public:
    ValueSpecification() = default;

    virtual bool isComputable() const = 0;

    virtual QuLC::Optional<int> intValue() const {
        return nullptr;
    }

    virtual QuLC::Optional<double> realValue() const {
        return nullptr;
    }

    virtual QuLC::Optional<bool> boolValue() const {
        return nullptr;
    }

    virtual QuLC::Optional<QString> stringValue() const {
        return nullptr;
    }

    virtual QuLC::Optional<QuLC::Unlimited> unlimitedValue() const {
        return nullptr;
    }

    virtual bool isNull() const = 0;

    QUML_CLONABLE_ABSTRACT(ValueSpecification);
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_VALUESPECIFICATION_H_ */

