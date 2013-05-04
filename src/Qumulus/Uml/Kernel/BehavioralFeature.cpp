/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "BehavioralFeature.h"
#include "Parameter.h"

QUML_BEGIN_NAMESPACE_UK

void BehavioralFeature::addParameter(uptr<Parameter> p) {
    mOwnedParameters.push_back(p.get());
    addElement(std::move(p));
}

void BehavioralFeature::removeParameter(Parameter* p) {
    removeElement(p);
    mOwnedParameters.erase(std::find(
                mOwnedParameters.begin(), mOwnedParameters.end(), p));

}

void BehavioralFeature::addException(Type* t) {
    mRaisedExceptions.push_back(t);
}

void BehavioralFeature::removeParameter(Type* t) {
    mRaisedExceptions.erase(std::find(
                mRaisedExceptions.begin(), mRaisedExceptions.end(), t));
}

QUML_END_NAMESPACE_UK
