/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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
    void readXml(QDomElement node, QuLC::XmlModelReader& reader) override;

    QUML_CLONABLE(Association);
private:
    AggregationKind mAggregation = AggregationKind::None;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ASSOCIATION_H_ */

