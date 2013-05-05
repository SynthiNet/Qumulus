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
    
    const QList<Parameter*>& parameters() const { 
        return mOwnedParameters; 
    }

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

