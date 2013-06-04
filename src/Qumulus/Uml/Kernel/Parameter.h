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
    Q_OBJECT
public:
    Parameter(QString name, Operation* o = 0);

    const QString& defaultValue() const { return mDefaultValue; }
    void setDefaultValue(const QString& s) { mDefaultValue = s; }

    ParameterDirectionKind direction() const { return mDirection; }
    void setDirection(ParameterDirectionKind d) { mDirection = d; }

    Operation* operation() const { return mOperation; }
    void setOperation(Operation* o);

    QString qualifiedName() const override { return name(); }

    QString sidebarIcon() const override { return ""; }
    QString sidebarText() const override { return ""; }

    void writeXml(QXmlStreamWriter& writer) const override;

    QString toString() const;

    QUML_CLONABLE(Parameter);
private:
    QString mDefaultValue = "";
    ParameterDirectionKind mDirection;
    Operation* mOperation;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PARAMETER_H_ */

