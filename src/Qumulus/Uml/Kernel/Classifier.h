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

#ifndef UML_KERNEL_CLASSIFIER_H_
#define UML_KERNEL_CLASSIFIER_H_

#include "internal_base.h"

#include "Type.h"
#include "RedefinableElement.h"
#include "Generalization.h"

QUML_BEGIN_NAMESPACE_UK

class Property;
class Feature;

class Classifier : public Type, public RedefinableElement {
public:
    Classifier();
    Classifier(QString name, Package* p = 0);

    bool abstract() const { return mAbstract; }
    void setAbstract(bool a) { mAbstract = a; }

    bool final() const { return mFinal; }
    void setFinal(bool f) { mFinal = f; }

    const QSet<Classifier*> general() const;

    QSet<Generalization*> generalizations() const { return mGeneralizations; }

    void addGeneralization(Generalization* g);
    void removeGeneralization(Generalization* g);

    QString sidebarText() const override { return name(); }

    QUML_CLONABLE_ABSTRACT(Classifier);

private:
    bool mAbstract = false;
    bool mFinal = false;
    QSet<Generalization*> mGeneralizations;

};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_CLASSIFIER_H_ */

