/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_ASSOCIATIONSHAPE_H_
#define UML_DIAGRAM_ASSOCIATIONSHAPE_H_

#include "internal_base.h"

#include "Shape.h"
#include "AssociationShapeKind.h"

QUML_BEGIN_NAMESPACE_UD

class AssociationShape : public Shape {
public:
    AssociationShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    AssociationShape(const AssociationShape&);

    AssociationShapeKind kind() const { return mKind; }
    void setKind(AssociationShapeKind k) { mKind = k; }

    void resize(double, double) override;

    QUML_CLONABLE(AssociationShape);
private:
    AssociationShapeKind mKind;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_ASSOCIATIONSHAPE_H_ */

