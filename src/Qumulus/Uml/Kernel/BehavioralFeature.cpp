/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "BehavioralFeature.h"
#include "Parameter.h"

QUML_BEGIN_NAMESPACE_UK

void BehavioralFeature::addParameter(Parameter* p) {
    mOwnedParameters.append(p);
    addElement(std::move(p));
}

void BehavioralFeature::removeParameter(Parameter* p) {
    mOwnedParameters.removeAll(p);
    removeElement(p);
}

void BehavioralFeature::addException(Type* t) {
    mRaisedExceptions.append(t);
}

void BehavioralFeature::removeParameter(Type* t) {
    mRaisedExceptions.removeAll(t);
}

QUML_END_NAMESPACE_UK
