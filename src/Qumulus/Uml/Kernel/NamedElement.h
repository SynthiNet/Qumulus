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

#ifndef UML_KERNEL_NAMEDELEMENT_H_
#define UML_KERNEL_NAMEDELEMENT_H_

#include "internal_base.h"

#include "Element.h"
#include "VisibilityKind.h"

#include <Lib/Core/Optional.h>

#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

class NamedElement : public virtual Element {
public:
    NamedElement();
    NamedElement(QString name);

    QString separator() const {
        // TODO: do not assume C++.
        return "::";
    }

    virtual QString qualifiedName() const = 0;

    // bool isDistinguishableFrom(NamedElement* n) const;

    const QString& name() const { return mName; }
    void setName(const QString& n) { mName = n; elementChanged(); }

    VisibilityKind visibility() const { return mVisibility; }
    // TODO: 2013-06-11 Frank Erens
    // This should be called setVisibility. Oops.
    void setVisiblity(VisibilityKind v) { mVisibility = v; elementChanged(); }

    QUML_CLONABLE_ABSTRACT(NamedElement)
private:
    QString mName;
    VisibilityKind mVisibility;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_NAMEDELEMENT_H_ */

