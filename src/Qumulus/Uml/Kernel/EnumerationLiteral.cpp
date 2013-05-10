/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumerationLiteral.h"

QUML_BEGIN_NAMESPACE_UK


EnumerationLiteral::EnumerationLiteral() {}
EnumerationLiteral::EnumerationLiteral(QString name, Enumeration* o) :
        NamedElement(name),
        mEnumeration(o) {

}

void EnumerationLiteral::updateDiagramElement() {

}

QUML_END_NAMESPACE_UK
