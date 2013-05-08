/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_COMPARTMENT_H_
#define UML_DIAGRAM_COMPARTMENT_H_

#include "internal_base.h"

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

class CompartmentableShape;

class Compartment : public Shape {
public:
    Compartment(CompartmentableShape* p = 0);

    CompartmentableShape* compartmentableShape() const;
    void setCompartimentableShape(CompartmentableShape* s);
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_COMPARTMENT_H_ */

