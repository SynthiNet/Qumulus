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

#include "BehavioralFeature.h"
#include "Parameter.h"

QUML_BEGIN_NAMESPACE_UK

BehavioralFeature::~BehavioralFeature() {
    for(auto& x : mOwnedParameters) {
        delete x;
    }
}

void BehavioralFeature::addParameter(Parameter* p) {
    mOwnedParameters.append(p);

    elementChanged();
}

void BehavioralFeature::removeParameter(Parameter* p) {
    if(mOwnedParameters.contains(p)) {
        mOwnedParameters.removeAll(p);
        elementChanged();
    }
}

void BehavioralFeature::addException(Type* t) {
    if(mRaisedExceptions.contains(t)) return;
    mRaisedExceptions.append(t);

    elementChanged();
}

void BehavioralFeature::removeException(Type* t) {
    if(mRaisedExceptions.contains(t)) {
        mRaisedExceptions.removeAll(t);
        elementChanged();
    }
}

QUML_END_NAMESPACE_UK
