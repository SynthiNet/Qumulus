/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PACKAGE_H_
#define UML_KERNEL_PACKAGE_H_

#include "internal_base.h"

#include "PackagableElement.h"

#include "Namespace.h"


QUML_BEGIN_NAMESPACE_UK

class Package : public Namespace, public PackageableElement {
public:

    const umap<QString, Package*>& nestedPackages() const {
        return mNestedPackages;
    }

    QUML_CLONABLE(Package)
private:
    umap<QString, Package*> mNestedPackages;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PACKAGE_H_ */

