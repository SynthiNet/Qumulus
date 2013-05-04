/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_CLASS_H_
#define UML_KERNEL_CLASS_H_

#include "internal_base.h"

#include "Classifier.h"

#include <list>

QUML_BEGIN_NAMESPACE_UK

class Property;
class Operation;

class Class : public Classifier {
public:
    
    const std::list<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    const std::list<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    const std::unordered_set<Class*>& superClasses() const {
        return mSuperClasses;
    }

    QUML_CLONABLE(Class);
private:
    std::list<Property*> mOwnedAttributes;
    std::list<Operation*> mOwnedOperations;
    std::unordered_set<Class*> mSuperClasses;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

