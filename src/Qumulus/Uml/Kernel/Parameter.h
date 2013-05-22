/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PARAMETER_H_
#define UML_KERNEL_PARAMETER_H_

#include "internal_base.h"

#include "MultiplicityElement.h"
#include "TypedElement.h"
#include "ParameterDirectionKind.h"

QUML_BEGIN_NAMESPACE_UK

class Operation;

class Parameter : 
        public virtual MultiplicityElement, 
        public virtual TypedElement {
public:
    Parameter(QString name, Operation* o = 0);

    QuLC::Optional<QString> defaultValue() const { return mDefaultValue; }
    void setDefaultValue(QuLC::Optional<QString> s) { mDefaultValue = s; }

    ParameterDirectionKind direction() const { return mDirection; }
    void setDirection(ParameterDirectionKind d) { mDirection = d; }

    Operation* operation() const { return mOperation; }
    void setOperation(Operation* o);

    // void updateDiagramElement(QuUD::Diagram*, QSizeF s = QSizeF()) override;

    QUML_CLONABLE(Parameter);
private:
    QuLC::Optional<QString> mDefaultValue;
    ParameterDirectionKind mDirection;
    Operation* mOperation;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETER_H_ */

