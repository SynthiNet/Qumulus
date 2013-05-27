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

    bool rootPackage() const { return mRootPackage; }
    void setRootPackage(bool b) { mRootPackage = b; }

    QString sidebarIcon() const override { return "package"; }
    QString sidebarText() const override { return name(); }

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(Package)
private:
    QSet<PackageableElement*> mPackagedElements;
    bool mRootPackage = false;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PACKAGE_H_ */

