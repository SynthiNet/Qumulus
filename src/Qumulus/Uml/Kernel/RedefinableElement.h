/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_REDEFINABLEELEMENT_H_
#define UML_KERNEL_REDEFINABLEELEMENT_H_

#include "internal_base.h"

#include "NamedElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

class Classifier;

class RedefinableElement : public virtual NamedElement {
public:
    RedefinableElement(Classifier* c = 0, RedefinableElement* r = 0);

    virtual bool isConsistentWith(RedefinableElement*) {
        return false;
    } 

    bool isRedefinitionContextValid(RedefinableElement*) {
        NYI();
        return false;
    }

    Classifier* redefinitionContext() const { return mRedefinitionContext; }
    void setRedefinitionContext(Classifier* c) { mRedefinitionContext = c; }

    RedefinableElement* redefinedElement() const { return mRedefinedElement; }
    void setRedefinedElement(RedefinableElement* r) { mRedefinedElement = r; }

    bool leaf() const { return mLeaf; }
    void setLeaf(bool l) { mLeaf = l; }

    QUML_CLONABLE_ABSTRACT(RedefinableElement);
private:
    Classifier* mRedefinitionContext;
    RedefinableElement* mRedefinedElement;
    bool mLeaf;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_REDEFINABLEELEMENT_H_ */

