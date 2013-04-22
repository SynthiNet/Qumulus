/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_FEATURE_H_
#define UML_CORE_CONSTRUCTS_FEATURE_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/NamedElement.h>

#include <unordered_set>

QUML_BEGIN_NAMESPACE_UCC

class Classifier;

class Feature : public virtual QuUCA::NamedElement {
public:
private:
    std::unordered_set<Classifier*> mFeaturingClassifiers;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_FEATURE_H_ */

