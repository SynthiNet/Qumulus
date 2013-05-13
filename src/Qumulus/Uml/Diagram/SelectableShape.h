/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_SELECTABLESHAPE_H_
#define UML_DIAGRAM_SELECTABLESHAPE_H_

#include "internal_base.h"
#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

class SelectableShape : public Shape {
public:
    SelectableShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    SelectableShape(const SelectableShape&);

    QUML_CLONABLE_ABSTRACT(SelectableShape);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant & value) override;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_SELECTABLESHAPE_H_ */

