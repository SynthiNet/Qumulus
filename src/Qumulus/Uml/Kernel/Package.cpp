/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Package.h"

#include "Type.h"

#include <QtWidgets/QGraphicsRectItem>
#include <Uml/Diagram/NameLabel.h>
#include <Uml/Diagram/PackageShape.h>

QUML_BEGIN_NAMESPACE_UK

struct PackageGraphics {
    PackageGraphics(Package* p);
    ~PackageGraphics();

    QuUD::NameLabel* mNameLabel;
};

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

QuUD::PackageShape* Package::diagramElement() const {
    return static_cast<QuUD::PackageShape*>(mDiagramElement);
}

void Package::updateDiagramElement(QuUD::Diagram* diagram, QSizeF newsize) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::PackageShape(this, diagram);
        mGraphics = new PackageGraphics(this);
    }

    auto g = mGraphics;
    auto d = static_cast<QuUD::Shape*>(mDiagramElement);

    d->setVisible(false);

    if(!newsize.isValid()) {
        newsize = d->size();
    }

    auto size = d->minimumSize();
    size.setWidth(std::max(g->mNameLabel->fullTextWidth(), 90) + 10);
    d->setMinimumSize(size);

    g->mNameLabel->setText(*name());
    g->mNameLabel->resize(size.width(), 0);

    d->resize(newsize);
}

PackageGraphics::PackageGraphics(Package* p) : 
        mNameLabel(new QuUD::NameLabel(*(p->name()), p, p->diagramElement())) {
    mNameLabel->setPos(0, 10);
    p->diagramElement()->setMinimumSize({100, 60});
} 

PackageGraphics::~PackageGraphics() {
    delete mNameLabel;
}

QUML_END_NAMESPACE_UK
