/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_ASSOCIATION_H_
#define UML_KERNEL_ASSOCIATION_H_

#include "internal_base.h"

#include "DirectedRelationship.h"
#include "AggregationKind.h"

QUML_BEGIN_NAMESPACE_UK

class Classifier;

class Association : public DirectedRelationship {
public:
    Association() = default;
    Association(Classifier* source, Classifier* target);

    Classifier* sourceType() const;
    void setSourceType(Classifier* c);

    Classifier* targetType() const;
    void setTargetType(Classifier* c);

    AggregationKind aggregation() const { return mAggregation; }
    void setAggregation(AggregationKind k) { mAggregation = k; }

    void writeXml(QXmlStreamWriter& writer) const override;
private:
    AggregationKind mAggregation = AggregationKind::None;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ASSOCIATION_H_ */

