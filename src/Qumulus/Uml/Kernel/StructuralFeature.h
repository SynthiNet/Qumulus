/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_STRUCTURALFEATURE_H_
#define UML_KERNEL_STRUCTURALFEATURE_H_

#include "internal_base.h"

#include "MultiplicityElement.h"
#include "TypedElement.h"
#include "Feature.h"

QUML_BEGIN_NAMESPACE_UK

class StructuralFeature : 
        public virtual MultiplicityElement,
        public virtual TypedElement, 
        public virtual Feature {
public:
    StructuralFeature();
    bool readOnly() const { return mReadOnly; }
    void setReadOnly(bool b) { mReadOnly = b; }

    QUML_CLONABLE_ABSTRACT(StructuralFeature);
private:
    bool mReadOnly;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_STRUCTURALFEATURE_H_ */

