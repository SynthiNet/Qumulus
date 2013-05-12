/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PACKAGE_H_
#define UML_KERNEL_PACKAGE_H_

#include "internal_base.h"

#include "PackageableElement.h"
#include "Namespace.h"

#include <Uml/Diagram/PackageShape.h>

QUML_BEGIN_NAMESPACE_UK

class Type;

struct PackageGraphics;

class Package : public Namespace, public PackageableElement {
public:
    Package();
    Package(QString name, Package* p = 0);

    bool mustBeOwned() const override {
        return false;
    }

    const QSet<PackageableElement*> packagedElements() const {
        return mPackagedElements;
    }

    const QSet<Package*>& nestedPackages() const {
        return mNestedPackages;
    }

    void addNestedPackage(Package* p);
    void removeNestedPackage(Package* p);

    const QSet<Type*> ownedTypes() const {
        return mOwnedTypes;
    }

    void addOwnedType(Type* t);
    void removeOwnedType(Type* t);

    QuUD::PackageShape* diagramElement() const override;

    void updateDiagramElement(QuUD::Diagram*, QSizeF s = QSizeF()) override;

    QUML_CLONABLE(Package)
private:
    void addPackagedElement(PackageableElement* e);
    void removePackagedElement(PackageableElement* e);
private:
    QSet<PackageableElement*> mPackagedElements;
    QSet<Package*> mNestedPackages;
    QSet<Type*> mOwnedTypes;
    PackageGraphics* mGraphics = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PACKAGE_H_ */

