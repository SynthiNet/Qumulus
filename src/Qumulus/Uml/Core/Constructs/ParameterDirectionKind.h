/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_PARAMETERDIRECTIONKIND_H_
#define UML_CORE_CONSTRUCTS_PARAMETERDIRECTIONKIND_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_UCC

enum class ParameterDirectionKind {
    In,
    InOut,
    Out,
    Return
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_PARAMETERDIRECTIONKIND_H_ */

