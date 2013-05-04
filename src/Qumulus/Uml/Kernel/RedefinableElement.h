/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_REDEFINABLEELEMENT_H_
#define UML_KERNEL_REDEFINABLEELEMENT_H_

#include "internal_base.h"

#include "Namespace.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

class Classifier;

class RedefinableElement : public Namespace {
public:

    virtual bool isConsistentWith(RedefinableElement*) {
        return false;
    } 

    bool isRedefinitionContextValid(RedefinableElement*) {
        NYI();
        return false;
    }

    virtual bool leaf() {
        return false;
    }


    QUML_CLONABLE_ABSTRACT(RedefinableElement);
private:
    RedefinableElement* mRedefinedElement;
    Classifier* mRedefinitionContext;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_REDEFINABLEELEMENT_H_ */

