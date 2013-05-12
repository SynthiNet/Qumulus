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

struct ClassGraphics;

class Class : public Classifier {
public:
    Class();
    Class(QString name, Namespace* p = nullptr);
    
    const QList<Classifier*>& nestedClassifiers() const {
        return mNestedClassifiers;
    }

    void addNestedClassifier(Classifier* c);
    void removeNestedClassifier(Classifier* c);

    const QList<Operation*>& ownedOperations() const {
        return mOwnedOperations;
    }

    void addOperation(Operation* c);
    void removeOperation(Operation* c);

    const QSet<Class*>& superClasses() const {
        return mSuperClasses;
    }

    void addSuperClass(Class* c);
    void removeSuperClass(Class* c);

    void updateDiagramElement(QuUD::Diagram*, QSizeF s = QSizeF()) override;

    QUML_CLONABLE(Class);
private:
    QList<Classifier*> mNestedClassifiers;
    QList<Operation*> mOwnedOperations;
    QSet<Class*> mSuperClasses;
    ClassGraphics* mGraphics;
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_CLASS_H_ */

