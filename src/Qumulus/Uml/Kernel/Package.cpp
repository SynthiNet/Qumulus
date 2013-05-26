/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Package.h"

#include "Type.h"

#include <QtWidgets/QGraphicsRectItem>

QUML_BEGIN_NAMESPACE_UK

Package::Package() {}

Package::Package(QString name, Package* p) :
        PackageableElement(name, p) {
}

Package::~Package() {
    for(auto& x : mPackagedElements) {
        delete x;
    }
}

void Package::addPackagedElement(PackageableElement* e) {
    mPackagedElements.insert(e);
}

void Package::removePackagedElement(PackageableElement* e) {
    mPackagedElements.remove(e);
}

QUML_END_NAMESPACE_UK
