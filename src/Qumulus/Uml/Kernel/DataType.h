/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_DATATYPE_H_
#define UML_KERNEL_DATATYPE_H_

#include "internal_base.h"

#include "Classifier.h"

class Property;
class Operation;

QUML_BEGIN_NAMESPACE_UK

class DataType : public Classifier {
public:
    DataType() {}
    DataType(QString name, Namespace* p = 0) : Classifier(name, p) {}

    const QList<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    const QList<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    QUML_CLONABLE_ABSTRACT(DataType);

private:
    QList<Property*> mOwnedAttributes;
    QList<Operation*> mOwnedOperations;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_DATATYPE_H_ */

