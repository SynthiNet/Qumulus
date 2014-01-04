/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

inline ParameterDirectionKind directionKindFromString(const QString& s) {
    if(s == "in" || s == "")
        return ParameterDirectionKind::In;
    else if(s == "inout")
        return ParameterDirectionKind::InOut;
    else if(s == "out")
        return ParameterDirectionKind::Out;
    else if(s == "return")
        return ParameterDirectionKind::Return;
    else
        throw QuLC::ParseException(qPrintable(
                    "Unknown direction kind: " + s));
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETERDIRECTIONKIND_H_ */

