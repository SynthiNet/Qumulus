/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PackageableElement.h"

#include "Package.h"

QUML_BEGIN_NAMESPACE_UK

PackageableElement::PackageableElement() {
    setVisiblity(VisibilityKind::Public);
}

PackageableElement::PackageableElement(QString name, Package* p) : 
        NamedElement(name, p) {
    setVisiblity(VisibilityKind::Public);
}


QUML_END_NAMESPACE_UK
