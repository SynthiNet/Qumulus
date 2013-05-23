/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_ENUMSHAPE_H_
#define UML_DIAGRAM_ENUMSHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

#include <Uml/Kernel/Enumeration.h>

QUML_BEGIN_NAMESPACE_GD

class EnumShape : public CompartmentableShape {
public:
    EnumShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    EnumShape(const EnumShape&);

    QuUK::Enumeration* modelElement() const override;

    void updateSizeConstraints() override;
    int enumNameWidth() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) override;

    QUML_CLONABLE(EnumShape);

private:
    Compartment* mHeader;
    Compartment* mBody;
};

QUML_END_NAMESPACE_GD


#endif /* UML_DIAGRAM_ENUMSHAPE_H_ */

