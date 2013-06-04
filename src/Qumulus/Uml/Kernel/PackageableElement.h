/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PACKAGABLEELEMENT_H_
#define UML_KERNEL_PACKAGABLEELEMENT_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

class Package;

class PackageableElement : public virtual NamedElement {
public:
    PackageableElement();
    PackageableElement(QString name, Package* p = 0);

    Package* package() const {
        return mPackage;
    }

    Element* parent() const override;

    QString qualifiedName() const;

    void setPackage(Package* p);

    bool isTopLevel() const override { return package() == 0; }

    QUML_CLONABLE_ABSTRACT(PackageableElement);
private:
    Package* mPackage = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PACKAGABLEELEMENT_H_ */

