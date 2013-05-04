/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_LITERALSPECIFICATION_H_
#define UML_KERNEL_LITERALSPECIFICATION_H_

#include "internal_base.h"

#include "ValueSpecification.h"

QUML_BEGIN_NAMESPACE_UK

class LiteralSpecification : public ValueSpecification {
public:
    LiteralSpecification() = default;
    bool isComputable() const override { return true; }
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_LITERALSPECIFICATION_H_ */

