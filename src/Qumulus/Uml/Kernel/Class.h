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

#ifndef UML_KERNEL_CLASS_H_
#define UML_KERNEL_CLASS_H_

#include "internal_base.h"

#include "Classifier.h"

QUML_BEGIN_NAMESPACE_UK

class Property;
class Operation;

class Class : public Classifier {
public:
    Class();
    Class(QString name, Package* p = nullptr);
    ~Class();

    // TODO: nested classifiers
    // const QList<Classifier*>& nestedClassifiers() const {
    //     return mNestedClassifiers;
    // }

    // void addNestedClassifier(Classifier* c);
    // void removeNestedClassifier(Classifier* c);

    size_t size() const override;
    Element* operator[](size_t idx) const override;

    const QList<Operation*>& operations() const {
        return mOwnedOperations;
    }

    const QList<Property*>& attributes() const {
        return mOwnedAttributes;
    }

    /**
     * @note This function takes ownership
     */
    void addAttribute(Property* p);
    void removeAttribute(Property* p);

    /**
     * @note This function takes ownership
     */
    void addOperation(Operation* c);
    void removeOperation(Operation* c);

    QString sidebarIcon() const override { return "class"; }

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QUML_CLONABLE(Class);
private:
    // QList<Classifier*> mNestedClassifiers;
    QList<Operation*> mOwnedOperations;
    QList<Property*> mOwnedAttributes;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

