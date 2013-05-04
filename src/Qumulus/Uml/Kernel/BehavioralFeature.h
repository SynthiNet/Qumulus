/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_BEHAVIORALFEATURE_H_
#define UML_KERNEL_BEHAVIORALFEATURE_H_

#include "internal_base.h"

#include "Feature.h"
#include "Namespace.h"

QUML_BEGIN_NAMESPACE_UK

class Parameter;
class Type;

class BehavioralFeature : 
        public Feature,
        public virtual Namespace {
public:
    
    const std::vector<Parameter*>& parameters() const { 
        return mOwnedParameters; 
    }

    void addParameter(uptr<Parameter> p);
    void removeParameter(Parameter* p);

    const std::vector<Type*>& raisedExceptions() const {
        return mRaisedExceptions;
    }

    void addException(Type* t);
    void removeParameter(Type* t);

    QUML_CLONABLE_ABSTRACT(BehavioralFeature);
private:
    std::vector<Parameter*> mOwnedParameters;
    std::vector<Type*> mRaisedExceptions;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_BEHAVIORALFEATURE_H_ */

