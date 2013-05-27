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

QUML_BEGIN_NAMESPACE_GD

class AssociationShape : public Shape {
public:
    AssociationShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    AssociationShape(const AssociationShape&);

    AssociationShapeKind kind() const { return mKind; }
    void setKind(AssociationShapeKind k) { mKind = k; }

    void resize(double, double) override;
    QRectF boundingRect() const override { return QRectF(); }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;

    void writeXml(QXmlStreamWriter&) const override {}

    void updateSizeConstraints() override;

    QUML_CLONABLE(AssociationShape);
private:
    AssociationShapeKind mKind;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_ASSOCIATIONSHAPE_H_ */

