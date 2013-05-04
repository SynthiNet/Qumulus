/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_TYPE_H_
#define UML_KERNEL_TYPE_H_

#include "internal_base.h"

#include "PackagableElement.h"

QUML_BEGIN_NAMESPACE_UK

class Type : public PackageableElement {
public:
    virtual ~Type() = 0;

    virtual bool conformsTo(Type* other) const {
        return false;
    }
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_TYPE_H_ */

