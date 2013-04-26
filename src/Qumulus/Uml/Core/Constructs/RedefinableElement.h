/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_REDEFINABLEELEMENT_H_
#define UML_CORE_CONSTRUCTS_REDEFINABLEELEMENT_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/Namespace.h>
#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UCC

class Classifier;

class RedefinableElement : public QuUCA::Namespace {
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

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_REDEFINABLEELEMENT_H_ */

