/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PROPERTY_H_
#define UML_KERNEL_PROPERTY_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>

#include "StructuralFeature.h"
#include "Type.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Association;

class Property : public StructuralFeature {
public:
    Property(Class* c = 0);

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; }

    bool composite() const { NYI(); return false; }

    // bool derived() const { NYI(); return false; }
    // QuLC::Optional<QString> defaultValue() const { NYI(); return nullptr; }

    // bool isNavigable() const { return mOpposite; }

    Property* opposite() const;

    Association* association() const { return mAssociation; }
    void setAssociation(Association* a) { mAssociation = a; }

    Association* owningAssociation() const;

    QSet<Property*> redefinedProperties() const;
    QSet<Property*> subsettedProperties() const;

    QUML_CLONABLE(Property);
private:
    // Type* mOwningType;
    Class* mClass;
    Association* mAssociation;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PROPERTY_H_ */

