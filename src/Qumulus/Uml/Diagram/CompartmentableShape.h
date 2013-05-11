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
    CompartmentableShape(const CompartmentableShape&);

    Compartment* compartment(unsigned i);
    const QList<Compartment*> compartments() const { return mCompartments; }

    void addCompartment(Compartment* c);

    void resize(double, double) override;

    QUML_CLONABLE(CompartmentableShape);
private:
    QList<Compartment*> mCompartments;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_COMPARTMENTABLESHAPE_H_ */

