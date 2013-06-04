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

PackageableElement::PackageableElement(QString name, Package* p) {
    setPackage(p);
    setName(name);
    setVisiblity(VisibilityKind::Public);
}

Element* PackageableElement::parent() const {
    return package();
}

int PackageableElement::index() const {
    return package()->packagedElements().indexOf(
            const_cast<PackageableElement*>(this));
}

QString PackageableElement::qualifiedName() const {
    if(name() != "") {
        if(package()) {
            if(package()->rootPackage()) 
                return name();
            QString s = package()->qualifiedName();
            if(s != "") {
                return s + separator() + name();
            } else {
                return "";
            }
        } else {
            return name();
        }
    }

    return "";
}

void PackageableElement::setPackage(Package* p) {
    if(mPackage)
        mPackage->removePackagedElement(this);
    mPackage = p;
    if(p)
        p->addPackagedElement(this);
}


QUML_END_NAMESPACE_UK
