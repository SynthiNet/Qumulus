/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PACKAGE_H_
#define UML_KERNEL_PACKAGE_H_

#include "internal_base.h"

#include "PackageableElement.h"

QUML_BEGIN_NAMESPACE_UK

class Type;

class Package : public PackageableElement {
public:
    Package();
    Package(QString name, Package* p = 0);
    ~Package();

    const QSet<PackageableElement*> packagedElements() const {
        return mPackagedElements;
    }

    void addPackagedElement(PackageableElement* e);
    void removePackagedElement(PackageableElement* e);

    QString sidebarIcon() const override { return "package"; }
    QString sidebarText() const override { return name(); }

    QUML_CLONABLE(Package)
private:
private:
    QSet<PackageableElement*> mPackagedElements;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PACKAGE_H_ */

