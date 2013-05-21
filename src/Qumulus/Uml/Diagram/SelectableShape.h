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

enum class DragPosition {
    None,
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight
};

class SelectableShape : public Shape {
public:
    SelectableShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    SelectableShape(const SelectableShape&);
    QRectF boundingRect() const override;
    bool shouldShowBDiag(QPointF p) const;
    bool shouldShowFDiag(QPointF p) const;

    QUML_CLONABLE_ABSTRACT(SelectableShape);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, 
            QWidget *widget) override;
   void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
   void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant & value) override;

private:
    bool isInsideCircle(int x, int y, int cx, int cy, int cw, int ch) const;
private:
    DragPosition mDragPosition = DragPosition::None;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_SELECTABLESHAPE_H_ */

