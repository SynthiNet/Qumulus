/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_CLASS_H_
#define UML_KERNEL_CLASS_H_

#include "internal_base.h"

#include "Classifier.h"

QUML_BEGIN_NAMESPACE_UK

class Property;
class Operation;

class Class : public Classifier {
public:
    
    const std::vector<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    const std::vector<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    const uset<Class*>& superClasses() const {
        return mSuperClasses;
    }

    QUML_CLONABLE(Class);
private:
    std::vector<Property*> mOwnedAttributes;
    std::vector<Operation*> mOwnedOperations;
    uset<Class*> mSuperClasses;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

