/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_DATATYPE_H_
#define UML_KERNEL_DATATYPE_H_

#include "internal_base.h"

#include "Classifier.h"

#include <list>

class Property;
class Operation;

QUML_BEGIN_NAMESPACE_UK

class DataType : public Classifier {
public:

    const std::list<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    const std::list<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    QUML_CLONABLE(DataType);

private:
    std::list<Property*> mOwnedAttributes;
    std::list<Operation*> mOwnedOperations;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_DATATYPE_H_ */

