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
#include "AggregationKind.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Association;

class Property : public StructuralFeature {
public:
    Property(Class* c = 0);

    AggregationKind aggregation() const { return mAggregation; }
    void setAggregation(AggregationKind a) { mAggregation = a; }

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; }

    bool composite() const { 
        return mAggregation == AggregationKind::Composite;
    }

    Property* opposite() const;

    Association* association() const { return mAssociation; }
    void setAssociation(Association* a) { mAssociation = a; }

    Association* owningAssociation() const;

    QuLC::Optional<QString> getDefault() const { return mDefault; }
    void setDefault(QuLC::Optional<QString> d) { mDefault = d; }

    QSet<Property*> redefinedProperties() const;
    QSet<Property*> subsettedProperties() const;

    void updateDiagramElement() override;

    QUML_CLONABLE(Property);
private:
    AggregationKind mAggregation;
    Class* mClass;
    Association* mAssociation;
    QuLC::Optional<QString> mDefault;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PROPERTY_H_ */

