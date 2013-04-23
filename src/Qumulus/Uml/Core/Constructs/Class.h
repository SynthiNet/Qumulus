/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_CLASS_H_
#define UML_CORE_CONSTRUCTS_CLASS_H_

#include "internal_base.h"

#include "Classifier.h"

QUML_BEGIN_NAMESPACE_UCC

class Property;
class Operation;

class Class : public Classifier {
public:
    
    const std::set<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    const std::set<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    QUML_CLONABLE(Class);
private:
    std::list<Property*> mOwnedAttributes;
    std::list<Operation*> mOwnedOperations;
};

QUML_END_NAMESPACE_UCC


#endif /* UML_CORE_CONSTRUCTS_CLASS_H_ */

