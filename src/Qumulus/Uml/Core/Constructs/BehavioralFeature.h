/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_BEHAVIORALFEATURE_H_
#define UML_CORE_CONSTRUCTS_BEHAVIORALFEATURE_H_

#include "internal_base.h"

#include "Feature.h"

#include <unordered_set>

QUML_BEGIN_NAMESPACE_UCC

class Parameter;
class Type;

class BehavioralFeature : public Feature {
public:
    QUML_CLONABLE_ABSTRACT(BehavioralFeature);
private:
    std::unordered_set<Parameter*> mOwnedParameters;
    std::unordered_set<Type*> mRaisedExceptions;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_BEHAVIORALFEATURE_H_ */

