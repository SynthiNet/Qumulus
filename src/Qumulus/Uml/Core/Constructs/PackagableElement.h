/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_PACKAGABLEELEMENT_H_
#define UML_CORE_CONSTRUCTS_PACKAGABLEELEMENT_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/NamedElement.h>

QUML_BEGIN_NAMESPACE_UCC

class Package;

class PackageableElement : public virtual QuUCA::NamedElement {
public:
    virtual ~PackageableElement() = 0;

    Package* package() const {
        return mPackage;
    }
private:
    Package* mPackage;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_PACKAGABLEELEMENT_H_ */

