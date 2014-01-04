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

#ifndef UML_KERNEL_ENUMERATIONLITERAL_H_
#define UML_KERNEL_ENUMERATIONLITERAL_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

class Enumeration;
struct EnumerationLiteralGraphics;

class EnumerationLiteral : public NamedElement {
public:
    EnumerationLiteral();
    EnumerationLiteral(QString name, Enumeration* o = nullptr);

    Element* parent() const override;
    int index() const override;

    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    Enumeration* enumeration() const { return mEnumeration; }
    void setEnumeration(Enumeration* e) { mEnumeration = e; }

    QString qualifiedName() const override;

    QString sidebarIcon() const override { return "literal"; }
    QString sidebarText() const override { return name(); }

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QUML_CLONABLE(EnumerationLiteral);
private:
    Enumeration* mEnumeration;
    EnumerationLiteralGraphics* mGraphics = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATIONLITERAL_H_ */

