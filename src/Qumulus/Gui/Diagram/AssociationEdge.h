/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_ASSOCIATIONEDGE_H_
#define UML_DIAGRAM_ASSOCIATIONEDGE_H_

#include "internal_base.h"

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

class AssociationEdge : public Edge {
public:
    AssociationEdge(QuUK::Element* e = 0, DiagramElement* p = 0);
    AssociationEdge(const AssociationEdge&);

    void writeXml(QXmlStreamWriter&) const override {}

    QUML_CLONABLE(AssociationEdge);
private:
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_ASSOCIATIONEDGE_H_ */

