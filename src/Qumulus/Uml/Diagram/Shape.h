/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_SHAPE_H_
#define UML_DIAGRAM_SHAPE_H_

#include "internal_base.h"

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

class Shape : public DiagramElement {
public:
    Shape(QuUK::Element* e = 0, DiagramElement* p = 0);
private:
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_SHAPE_H_ */

