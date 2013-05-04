/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PARAMETER_H_
#define UML_KERNEL_PARAMETER_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/MultiplicityElement.h>

#include "TypedElement.h"
#include "ParameterDirectionKind.h"

QUML_BEGIN_NAMESPACE_UK

class Operation;

class Parameter : 
        public virtual MultiplicityElement, 
        public virtual TypedElement{
public:

    QuLC::Optional<QString> defaultValue() const { return mDefaultValue; }
    ParameterDirectionKind direction() const { return mDirection; }
    Operation* operation() const { return mOperation; }

    QUML_CLONABLE(Parameter);
private:
    QuLC::Optional<QString> mDefaultValue;
    ParameterDirectionKind mDirection;
    Operation* mOperation;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETER_H_ */

