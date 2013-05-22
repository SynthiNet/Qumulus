/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_COMMENTSHAPE_H_
#define UML_DIAGRAM_COMMENTSHAPE_H_

#include "internal_base.h"

#include "SelectableShape.h"

#include <QtWidgets/QGraphicsPolygonItem>
#include <QtWidgets/QGraphicsLineItem>

QUML_BEGIN_NAMESPACE_GD

class CommentShape : public SelectableShape {
public:
    CommentShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    CommentShape(const CommentShape&);

    using Shape::resize;
    void resize(double, double) override;

    QUML_CLONABLE(CommentShape);
private:
    QGraphicsPolygonItem* mPolygon;
    QGraphicsLineItem* mLine1;
    QGraphicsLineItem* mLine2;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMMENTSHAPE_H_ */

