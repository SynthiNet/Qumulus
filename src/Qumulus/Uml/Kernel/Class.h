/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
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
    Class();
    Class(QString name, Namespace* p = nullptr);
    
    const QList<Classifier*>& nestedClassifiers() const {
        return mNestedClassifiers;
    }

    void addNestedClassifier(Classifier* c);
    void removeNestedClassifier(Classifier* c);

    const QList<Operation*>& operations() const {
        return mOwnedOperations;
    }

    const QList<Property*>& attributes() const {
        return mOwnedAttributes;
    }

    void addAttribute(Property* p);
    void removeAttribute(Property* p);

    void addOperation(Operation* c);
    void removeOperation(Operation* c);

    QString sidebarIcon() const override { return "class"; }

    QUML_CLONABLE(Class);
private:
    QList<Classifier*> mNestedClassifiers;
    QList<Operation*> mOwnedOperations;
    QList<Property*> mOwnedAttributes;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

