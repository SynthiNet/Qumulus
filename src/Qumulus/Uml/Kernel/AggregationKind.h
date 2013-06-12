/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_AGGREGATIONKIND_H_
#define UML_KERNEL_AGGREGATIONKIND_H_

#include "internal_base.h"

#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

enum class AggregationKind {
    None,
    Shared,
    Composite
};

inline QString toString(AggregationKind k) {
    switch(k) {
    case AggregationKind::None:
        return "none";
    case AggregationKind::Shared:
        return "shared";
    case AggregationKind::Composite:
        return "composite";
    }
}

inline AggregationKind aggregationKindFromString(const QString& s) {
    if(s == "none" || s == "")
        return AggregationKind::None;
    else if(s == "shared")
        return AggregationKind::Shared;
    else if(s == "composite")
        return AggregationKind::Composite;
    else
        throw QuLC::ParseException(qPrintable(
                    "Unknown aggregation kind: " + s));
}

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_AGGREGATIONKIND_H_ */

