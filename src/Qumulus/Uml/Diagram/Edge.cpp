/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Edge.h"

QUML_BEGIN_NAMESPACE_UD

Edge::Edge(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p) {
}

Edge::Edge(const Edge& e) :
        DiagramElement(e) {

}
QUML_END_NAMESPACE_UD
