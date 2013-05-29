/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "AssociationEdge.h"

QUML_BEGIN_NAMESPACE_GD

AssociationEdge::AssociationEdge(QuUK::Element* e, DiagramElement* p) :
        Edge(e, p) {
}

AssociationEdge::AssociationEdge(const AssociationEdge& e) :
        Edge(e) {}

QUML_END_NAMESPACE_GD

