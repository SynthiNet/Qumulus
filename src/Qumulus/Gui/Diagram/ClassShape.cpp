/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ClassShape.h"

QUML_BEGIN_NAMESPACE_GD

ClassShape::ClassShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p) {

}

ClassShape::ClassShape(const ClassShape& s) :
        CompartmentableShape(s) {

}

QUML_END_NAMESPACE_GD
