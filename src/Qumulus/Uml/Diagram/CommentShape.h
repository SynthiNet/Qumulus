/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_COMMENTSHAPE_H_
#define UML_DIAGRAM_COMMENTSHAPE_H_

#include "internal_base.h"

#include "Shape.h"

#include <QtWidgets/QGraphicsPolygonItem>

QUML_BEGIN_NAMESPACE_UD

class CommentShape : public Shape {
public:
    CommentShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    CommentShape(const CommentShape&);

    using Shape::resize;
    void resize(double, double) override;

    QUML_CLONABLE(CommentShape);
private:
    QGraphicsPolygonItem* mPolygon;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_COMMENTSHAPE_H_ */

