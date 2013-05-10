/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

Shape::Shape(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p) {
}

Shape::Shape(const Shape& s) :
        DiagramElement(s) {

}
QUML_END_NAMESPACE_UD
