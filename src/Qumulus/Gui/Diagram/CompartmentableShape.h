/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_COMPARTMENTABLESHAPE_H_
#define UML_DIAGRAM_COMPARTMENTABLESHAPE_H_

#include "internal_base.h"

#include "SelectableShape.h"

#include "Compartment.h"

class QPainter;

QUML_BEGIN_NAMESPACE_GD

class CompartmentableShape : public SelectableShape {
public:
    CompartmentableShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    CompartmentableShape(const CompartmentableShape&);

    Compartment* compartment(unsigned i);
    const QList<Compartment*> compartments() const { return mCompartments; }

    void addCompartment(Compartment* c);

    using Shape::resize;
    void resize(double, double) override;
    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;

    QUML_CLONABLE_ABSTRACT(CompartmentableShape);
private:
    QList<Compartment*> mCompartments;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMPARTMENTABLESHAPE_H_ */

