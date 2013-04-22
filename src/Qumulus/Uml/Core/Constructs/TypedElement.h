/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_TYPEDELEMENT_H_
#define UML_CORE_CONSTRUCTS_TYPEDELEMENT_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/NamedElement.h>

QUML_BEGIN_NAMESPACE_UCC

class Classifier;

class TypedElement : public virtual QuUCA::NamedElement {
public:
    TypedElement() {}
    virtual ~TypedElement() = 0;

    Classifier* type() const { return mType; }
    void setType(Classifier* c) { mType = c; }

    QUML_CLONABLE_ABSTRACT(TypedElement);
private:
    Classifier* mType;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_TYPEDELEMENT_H_ */

