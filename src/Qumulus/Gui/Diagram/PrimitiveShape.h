/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_PRIMITIVESHAPE_H_
#define UML_DIAGRAM_PRIMITIVESHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

#include <Uml/Kernel/PrimitiveType.h>

QUML_BEGIN_NAMESPACE_GD

class PrimitiveShape : public CompartmentableShape {
public:
    PrimitiveShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    PrimitiveShape(const PrimitiveShape&);

    QuUK::PrimitiveType* modelElement() const override;

    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;

    QUML_CLONABLE(PrimitiveShape);
private:
    int primitiveNameWidth() const;

private:
    Compartment* mCompartment;
};

QUML_END_NAMESPACE_GD


#endif /* UML_DIAGRAM_PRIMITIVESHAPE_H_ */

