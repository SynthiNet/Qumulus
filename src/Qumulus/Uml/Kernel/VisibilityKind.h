/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_KERNEL_VISIBILITYKIND_H_
#define UML_KERNEL_VISIBILITYKIND_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_UK

enum class VisibilityKind {
    Public,
    Private,
    Protected
};

inline char toChar(VisibilityKind v) {
    switch(v) {
    case VisibilityKind::Public:
        return '+';
    case VisibilityKind::Private:
        return '-';
    case VisibilityKind::Protected:
        return '#';
    }
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_VISIBILITYKIND_H_ */

