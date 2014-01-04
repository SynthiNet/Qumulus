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

#ifndef UML_KERNEL_BEHAVIORALFEATURE_H_
#define UML_KERNEL_BEHAVIORALFEATURE_H_

#include "internal_base.h"

#include "Feature.h"

QUML_BEGIN_NAMESPACE_UK

class Parameter;
class Type;

class BehavioralFeature : public Feature {
public:
    ~BehavioralFeature();

    const QList<Parameter*>& parameters() const {
        return mOwnedParameters;
    }

    /**
     * @note This function takes ownership
     */
    void addParameter(Parameter* p);
    void removeParameter(Parameter* p);

    const QList<Type*>& raisedExceptions() const {
        return mRaisedExceptions;
    }

    void addException(Type* t);
    void removeException(Type* t);

    QUML_CLONABLE_ABSTRACT(BehavioralFeature);
private:
    QList<Parameter*> mOwnedParameters;
    QList<Type*> mRaisedExceptions;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_BEHAVIORALFEATURE_H_ */

