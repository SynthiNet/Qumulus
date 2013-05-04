/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_AGGREGATIONKIND_H_
#define UML_KERNEL_AGGREGATIONKIND_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_UK

enum class AggregationKind {
    None,
    Shared,
    Composite
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_AGGREGATIONKIND_H_ */

