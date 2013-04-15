/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_PACKAGE_H_
#define UML_CORE_CONSTRUCTS_PACKAGE_H_

#include "internal_base.h"

#include "PackagableElement.h"

#include <Uml/Core/Abstractions/Namespace.h>

QUML_BEGIN_NAMESPACE_UCC

class Package : public QuUCA::Namespace, public PackageableElement {
public:

    const std::unordered_map<QString, Package*>& nestedPackages() const {
        return mNestedPackages;
    }

    QUML_CLONABLE(Package)
private:
    std::unordered_map<QString, Package*> mNestedPackages;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_PACKAGE_H_ */

