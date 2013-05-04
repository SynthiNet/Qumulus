/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_TYPEDELEMENT_H_
#define UML_KERNEL_TYPEDELEMENT_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

class Classifier;

class TypedElement : public virtual NamedElement {
public:
    TypedElement() {}
    virtual ~TypedElement() = 0;

    Classifier* type() const { return mType; }
    void setType(Classifier* c) { mType = c; }

    QUML_CLONABLE_ABSTRACT(TypedElement);
private:
    Classifier* mType;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_TYPEDELEMENT_H_ */

