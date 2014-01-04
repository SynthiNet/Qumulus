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

inline VisibilityKind visibilityKindFromString(const QString& s) {
    if(s == "public" || s == "")
        return VisibilityKind::Public;
    else if(s == "private")
        return VisibilityKind::Private;
    else if(s == "protected")
        return VisibilityKind::Protected;
    else
        throw QuLC::ParseException(qPrintable(
                    "Unknown visibility kind: " + s));
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_VISIBILITYKIND_H_ */
