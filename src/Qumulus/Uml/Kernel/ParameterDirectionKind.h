/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PARAMETERDIRECTIONKIND_H_
#define UML_KERNEL_PARAMETERDIRECTIONKIND_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_UK

enum class ParameterDirectionKind {
    In,
    InOut,
    Out,
    Return
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETERDIRECTIONKIND_H_ */

