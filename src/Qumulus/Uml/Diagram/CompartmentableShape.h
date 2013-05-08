/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_COMPARTMENTABLESHAPE_H_
#define UML_DIAGRAM_COMPARTMENTABLESHAPE_H_

#include "internal_base.h"

#include "Shape.h"

#include "Compartment.h"

QUML_BEGIN_NAMESPACE_UD

class CompartmentableShape : public Shape {
public:
    CompartmentableShape(QuUK::Element* e = 0, DiagramElement* p = 0);

    Compartment* compartment(unsigned i);

    void addCompartment(Compartment* c);

private:
    QList<Compartment*> mCompartments;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_COMPARTMENTABLESHAPE_H_ */

