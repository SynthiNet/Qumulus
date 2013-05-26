/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

NamedElement::NamedElement() :
        mName(""),
        mVisibility() {

}

NamedElement::NamedElement(QString name) :
        mName(name),
        mVisibility(VisibilityKind::Public) {

}

QUML_END_NAMESPACE_UK
