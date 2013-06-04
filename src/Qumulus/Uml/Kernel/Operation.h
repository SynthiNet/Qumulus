/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_KERNEL_OPERATION_H_
#define UML_KERNEL_OPERATION_H_

#include "internal_base.h"

#include "BehavioralFeature.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Parameter;

class Operation : public BehavioralFeature {
public:
    Operation(QString name, Class* c = 0);

    Parameter* returnResult() const;
    Type* type() const;

    Element* parent() const override;
    int index() const override;

    bool isQuery() const { return mQuery; }
    void setQuery(bool b) { mQuery = b; elementChanged(); }

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; elementChanged(); }

    QString qualifiedName() const override;

    QString sidebarIcon() const { return "operation"; }
    QString sidebarText() const { return toString(); }

    void writeXml(QXmlStreamWriter& writer) const override;

    QString toString() const;

    QUML_CLONABLE(Operation);
private:
    Class* mClass;
    bool mQuery;

};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_OPERATION_H_ */

