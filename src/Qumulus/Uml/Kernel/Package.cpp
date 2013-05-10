/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Package.h"

#include "Type.h"

QUML_BEGIN_NAMESPACE_UK

Package::Package() {}

Package::Package(QString name, Package* p) :
        PackageableElement(name, p) {

}

void Package::addNestedPackage(Package* p) {
    mNestedPackages.insert(p);
    addPackagedElement(p);
}

void Package::removeNestedPackage(Package* p) {
    mNestedPackages.remove(p);
    removePackagedElement(p);
}

void Package::addOwnedType(Type* t) {
    mOwnedTypes.insert(t);
    addPackagedElement(t);
}

void Package::removeOwnedType(Type* t) {
    mOwnedTypes.remove(t);
    addPackagedElement(t);
}

void Package::addPackagedElement(PackageableElement* e) {
    mPackagedElements.insert(e);
    addOwnedMember(e);
}

void Package::removePackagedElement(PackageableElement* e) {
    mPackagedElements.insert(e);
    addOwnedMember(e);
}

void Package::updateDiagramElement() {

}

QUML_END_NAMESPACE_UK
