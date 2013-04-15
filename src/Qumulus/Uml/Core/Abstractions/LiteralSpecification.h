/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_ABSTRACTIONS_LITERALSPECIFICATION_H_
#define UML_CORE_ABSTRACTIONS_LITERALSPECIFICATION_H_

#include "internal_base.h"

#include "ValueSpecification.h"

QUML_BEGIN_NAMESPACE_UCA

class LiteralSpecification : public ValueSpecification {
public:
    bool isComputable() const override { return true; }
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_LITERALSPECIFICATION_H_ */

