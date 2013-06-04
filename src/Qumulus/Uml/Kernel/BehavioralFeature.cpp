/*
 * Qumulus UML editor
 * Author: Frank Erens
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
