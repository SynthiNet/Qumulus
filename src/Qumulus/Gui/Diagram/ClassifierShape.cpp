/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ClassifierShape.h"

QUML_BEGIN_NAMESPACE_GD

ClassifierShape::ClassifierShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p) {

}

ClassifierShape::ClassifierShape(const ClassifierShape& s) :
        CompartmentableShape(s) {

}

QUML_END_NAMESPACE_GD
