/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_EDGE_H_
#define UML_DIAGRAM_EDGE_H_

#include "internal_base.h"

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

class Edge : public DiagramElement {
public:
    Edge(QuUK::Element* e = 0, DiagramElement* p = 0);
private:
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_EDGE_H_ */

