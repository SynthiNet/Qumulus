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

#ifndef UML_KERNEL_PROPERTY_H_
#define UML_KERNEL_PROPERTY_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>
// #include <Uml/Diagram/FeatureLabel.h>

#include "StructuralFeature.h"
#include "Type.h"
#include "AggregationKind.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Association;

class Property : public StructuralFeature {
public:
    Property(QString name, Class* c = 0);

    Element* parent() const override;
    int index() const override;

    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; elementChanged(); }

    Association* association() const { return mAssociation; }
    void setAssociation(Association* a) { mAssociation = a; elementChanged(); }

    const QString& getDefault() const { return mDefault; }
    void setDefault(const QString& d) { mDefault = d; elementChanged(); }

    QString qualifiedName() const override;

    QString sidebarIcon() const override { return "attribute"; }
    QString sidebarText() const override { return toString(); }

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QString toString() const;

    QUML_CLONABLE(Property);
private:
    Class* mClass;
    Association* mAssociation;
    QString mDefault;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PROPERTY_H_ */

