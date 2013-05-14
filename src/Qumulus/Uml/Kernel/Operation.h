/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_KERNEL_OPERATION_H_
#define UML_KERNEL_OPERATION_H_

#include "internal_base.h"

#include <Uml/Diagram/FeatureLabel.h>

#include "BehavioralFeature.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Parameter;

class Operation : public BehavioralFeature {
public:
    Operation(QString name, Class* c = 0);

    Parameter* returnResult() const;
    Type* type() const;

    bool isQuery() const { return mQuery; }
    void setQuery(bool b) { mQuery = b; }

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; }

    QuUD::FeatureLabel* diagramElement() const override;
    void updateDiagramElement(QuUD::Diagram*, QSizeF s = QSizeF()) override;

    QUML_CLONABLE(Operation);
private:
    Class* mClass;
    QSet<Operation*> mRedefinedOperations;
    bool mQuery;

};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_OPERATION_H_ */

