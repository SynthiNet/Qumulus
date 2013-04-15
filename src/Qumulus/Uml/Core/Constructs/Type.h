/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_TYPE_H_
#define UML_CORE_CONSTRUCTS_TYPE_H_

#include "internal_base.h"

#include "PackagableElement.h"

QUML_BEGIN_NAMESPACE_UCC

class Type : public PackageableElement {
public:
    virtual ~Type() = 0;

    virtual bool conformsTo(Type* other) const {
        return false;
    }
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_TYPE_H_ */

