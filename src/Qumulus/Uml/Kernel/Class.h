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
    
    const std::vector<Classifier*>& nestedClassifiers() const {
        return mNestedClassifiers;
    }

    void addNestedClassifier(uptr<Classifier> c);
    void removeNestedClassifier(Classifier* c);

    const std::vector<Property*>& ownedAttributes() const {
        return mOwnedAttributes;
    }

    void addAttribute(uptr<Property> c);
    void removeAttribute(Property* c);

    const std::vector<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    void addOperation(uptr<Operation> c);
    void removeOperation(Operation* c);

    const uset<Class*>& superClasses() const {
        return mSuperClasses;
    }

    uset<Classifier*> general() const override;

    void addSuperClass(Class* c);
    void removeSuperClass(Class* c);

    QUML_CLONABLE(Class);
private:
    std::vector<Classifier*> mNestedClassifiers;
    std::vector<Property*> mOwnedAttributes;
    std::vector<Operation*> mOwnedOperations;
    uset<Class*> mSuperClasses;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

