/*
 * Qumulus UML editor
 * Author: Frank Erens
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
    QUML_CLONABLE_ABSTRACT(BehavioralFeature);
private:
    uset<Parameter*> mOwnedParameters;
    uset<Type*> mRaisedExceptions;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_BEHAVIORALFEATURE_H_ */

