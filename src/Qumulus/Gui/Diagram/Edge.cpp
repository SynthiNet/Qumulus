/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

Edge::Edge(QuUK::Element* e, DiagramElement* p) :
        Shape(e, p) {
}

Edge::Edge(const Edge& e) :
        Shape(e) {

}
QUML_END_NAMESPACE_GD
