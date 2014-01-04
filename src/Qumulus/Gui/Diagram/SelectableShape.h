/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#ifndef UML_DIAGRAM_SELECTABLESHAPE_H_
#define UML_DIAGRAM_SELECTABLESHAPE_H_

#include "internal_base.h"
#include "Shape.h"

QUML_BEGIN_NAMESPACE_GD

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

    using Shape::prepareGeometryChange;

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

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_SELECTABLESHAPE_H_ */

