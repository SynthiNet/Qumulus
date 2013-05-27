/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_KERNEL_VISIBILITYKIND_H_
#define UML_KERNEL_VISIBILITYKIND_H_

#include "internal_base.h"

#include <Lib/Core/Exception.h>

#include <QtCore/QString>

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

inline QString toString(VisibilityKind v) {
    switch(v) {
    case VisibilityKind::Public:
        return "public";
    case VisibilityKind::Private:
        return "private";
    case VisibilityKind::Protected:
        return "protected";
    }
}

inline VisibilityKind fromString(const QString& s) {
    if(s == "public")
        return VisibilityKind::Public;
    else if(s == "private")
        return VisibilityKind::Private;
    else if(s == "protected")
        return VisibilityKind::Protected;
    else
        throw QuLC::ParseException();
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_VISIBILITYKIND_H_ */
