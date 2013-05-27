/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PARAMETERDIRECTIONKIND_H_
#define UML_KERNEL_PARAMETERDIRECTIONKIND_H_

#include "internal_base.h"

#include <Lib/Core/Exception.h>

#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

enum class ParameterDirectionKind {
    In,
    InOut,
    Out,
    Return
};

inline QString toString(ParameterDirectionKind k) {
    switch(k) {
    case ParameterDirectionKind::In:
        return "in";
    case ParameterDirectionKind::InOut:
        return "inout";
    case ParameterDirectionKind::Out:
        return "out";
    case ParameterDirectionKind::Return:
        return "return";
    }
}

inline ParameterDirectionKind fromString(QString& s) {
    if(s == "in")
        return ParameterDirectionKind::In;
    else if(s == "inout")
        return ParameterDirectionKind::InOut;
    else if(s == "out")
        return ParameterDirectionKind::Out;
    else if(s == "return")
        return ParameterDirectionKind::Return;
    else
        throw QuLC::ParseException();
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETERDIRECTIONKIND_H_ */

