/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_PROPERTY_H_
#define UML_CORE_CONSTRUCTS_PROPERTY_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>

#include "StructuralFeature.h"
#include "Type.h"

QUML_BEGIN_NAMESPACE_UCC

class Property : public StructuralFeature {

    Type* owningType() const { return mOwningType; }
    void setOwningType(Type* t) { mOwningType = t; }

    bool readOnly() const override { return mReadOnly; }
    bool composite() const { NYI(); return false; }
    bool derived() const { NYI(); return false; }
    QuLC::Optional<QString> defaultValue() const { NYI(); return nullptr; }

    bool isNavigable() const { NYI(); return false; }
    Property* opposite() const { NYI(); return nullptr; }
private:
    Type* mOwningType;
    bool mReadOnly;
    Property* mOpposite;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_PROPERTY_H_ */

