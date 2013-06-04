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
    Q_OBJECT
public:
    DataType() {}
    DataType(QString name, Package* p = 0) : Classifier(name, p) {}

    QUML_CLONABLE_ABSTRACT(DataType);
private:
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_DATATYPE_H_ */

