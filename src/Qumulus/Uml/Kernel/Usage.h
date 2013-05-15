/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_USAGE_H_
#define UML_KERNEL_USAGE_H_

#include "internal_base.h"

#include "DirectedRelationship.h"

QUML_BEGIN_NAMESPACE_UK

class Usage : public DirectedRelationship {
public:
    Usage() {}
    Usage(Element* e1, Element* e2) : DirectedRelationship(e1, e2) {}

    void updateDiagramElement(QuUD::Diagram*, QSizeF) override {}

    QUML_CLONABLE(Usage);
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_USAGE_H_ */

