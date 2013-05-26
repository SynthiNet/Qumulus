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
}

void BehavioralFeature::removeParameter(Parameter* p) {
    mOwnedParameters.removeAll(p);
}

void BehavioralFeature::addException(Type* t) {
    mRaisedExceptions.append(t);
}

void BehavioralFeature::removeException(Type* t) {
    mRaisedExceptions.removeAll(t);
}

QUML_END_NAMESPACE_UK
