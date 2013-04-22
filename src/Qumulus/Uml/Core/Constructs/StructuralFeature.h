/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_STRUCTURALFEATURE_H_
#define UML_CORE_CONSTRUCTS_STRUCTURALFEATURE_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/MultiplicityElement.h>

#include "TypedElement.h"
#include "Feature.h"

QUML_BEGIN_NAMESPACE_UCC

class StructuralFeature : 
        public virtual QuUCA::MultiplicityElement,
        public virtual TypedElement, 
        public virtual Feature {
public:
    StructuralFeature() {}
    StructuralFeature(const StructuralFeature&) {}
    virtual bool readOnly() const = 0;

    QUML_CLONABLE_ABSTRACT(StructuralFeature);
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_STRUCTURALFEATURE_H_ */

