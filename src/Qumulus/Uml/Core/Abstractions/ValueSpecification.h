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

class ValueSpecification : public Element {
public:
    virtual bool isComputable() const = 0;

    virtual QuLC::Optional<int> intValue() {
        return nullptr;
    }

    virtual QuLC::Optional<double> realValue() {
        return nullptr;
    }

    virtual QuLC::Optional<bool> boolValue() {
        return nullptr;
    }

    virtual QuLC::Optional<QString> stringValue() {
        return nullptr;
    }

    virtual QuLC::Optional<QuLC::Unlimited> unlimitedValue() {
        return nullptr;
    }

    virtual bool isNull() = 0;
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_VALUESPECIFICATION_H_ */

