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

class Class;
class Association;

class Property : public StructuralFeature {
public:
    Property(Class* c = 0);

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; }

    bool readOnly() const override { return mReadOnly; }
    void setReadOnly(bool r) { mReadOnly = r; }

    // bool composite() const { NYI(); return false; }

    // bool derived() const { NYI(); return false; }
    // QuLC::Optional<QString> defaultValue() const { NYI(); return nullptr; }

    // bool isNavigable() const { return mOpposite; }

    Property* opposite() const;

    Association* association() const { return mAssociation; }
    void setAssociation(Association* a) { mAssociation = a; }

    Association* owningAssociation() const;

    std::set<Property*> redefinedProperties() const;
    std::set<Property*> subsettedProperties() const;

    QUML_CLONABLE(Property);
private:
    // Type* mOwningType;
    Class* mClass;
    bool mReadOnly;
    Association* mAssociation;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_PROPERTY_H_ */

