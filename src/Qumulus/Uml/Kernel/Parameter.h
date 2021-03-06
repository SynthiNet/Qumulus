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

#ifndef UML_KERNEL_PARAMETER_H_
#define UML_KERNEL_PARAMETER_H_

#include "internal_base.h"

#include "MultiplicityElement.h"
#include "TypedElement.h"
#include "ParameterDirectionKind.h"

QUML_BEGIN_NAMESPACE_UK

class Operation;

class Parameter :
        public virtual MultiplicityElement,
        public virtual TypedElement {
public:
    Parameter(QString name, Operation* o = 0);

    const QString& defaultValue() const { return mDefaultValue; }
    void setDefaultValue(const QString& s) {
        mDefaultValue = s;
        elementChanged();
    }

    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    ParameterDirectionKind direction() const { return mDirection; }
    void setDirection(ParameterDirectionKind d) {
        mDirection = d;
        elementChanged();
    }

    Operation* operation() const { return mOperation; }
    void setOperation(Operation* o);

    QString qualifiedName() const override { return name(); }

    int index() const override { return -1; }

    QString sidebarIcon() const override { return ""; }
    QString sidebarText() const override { return ""; }

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QString toString() const;

    QUML_CLONABLE(Parameter);
private:
    QString mDefaultValue = "";
    ParameterDirectionKind mDirection;
    Operation* mOperation;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETER_H_ */

