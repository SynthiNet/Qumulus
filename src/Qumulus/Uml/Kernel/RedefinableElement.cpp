/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "RedefinableElement.h"

QUML_BEGIN_NAMESPACE_UK

RedefinableElement::RedefinableElement(Classifier* c, RedefinableElement* r) :
        mRedefinitionContext(c),
        mRedefinedElement(r),
        mLeaf(false) {
    
}

QUML_END_NAMESPACE_UK
