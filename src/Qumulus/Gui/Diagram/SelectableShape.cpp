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

#include "SelectableShape.h"
#include "Diagram.h"

#include <QtCore/QDebug>
#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QApplication>

#include <Uml/Kernel/Element.h>
#include <Gui/Core/QumulusApplication.h>
#include <Gui/Core/MoveUndoCommand.h>
#include <Gui/Core/ResizeUndoCommand.h>
#include <Gui/Widgets/EditorView.h>

#include <functional>

QUML_BEGIN_NAMESPACE_GD

SelectableShape::SelectableShape(QuUK::Element* e, DiagramElement* p) :
    Shape(e, p) {
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

SelectableShape::SelectableShape(const SelectableShape& c) : Shape(c) {}

void SelectableShape::paint(QPainter* p, const QStyleOptionGraphicsItem*,
            QWidget*) {

    if(isSelected()) {
        p->setBrush(QBrush({64, 193, 255}));
        p->drawEllipse(-3,-3,7,7);
        p->drawEllipse(-3,height()-3,7,7);
        p->drawEllipse(width()-3,-3,7,7);
        p->drawEllipse(width()-3,height()-3,7,7);
    }
}

bool SelectableShape::isInsideCircle(int x, int y, int cx,
        int cy, int cw, int ch) const {
    QRegion region(cx, cy, cw, ch);
    return region.contains({x, y});
}

bool SelectableShape::shouldShowBDiag(QPointF p) const {
    // TODO: Figure out why this cursor stays on
    // switch(mDragPosition) {
    // case DragPosition::TopRight:
    // case DragPosition::BottomLeft:
    //     return true;
    // default:;
    // }

    int x = mapFromScene(p).x();
    int y = mapFromScene(p).y();

    if(isInsideCircle(x, y, -4, height()-2, 9, 9) ||
            isInsideCircle(x, y, width()-2, -4, 9, 9)) {
        return true;
    } else {
        return false;
    }
}

bool SelectableShape::shouldShowFDiag(QPointF p) const {
    // TODO: Figure out why this cursor stays on
    // switch(mDragPosition) {
    // case DragPosition::TopLeft:
    // case DragPosition::BottomRight:
    //     return true;
    // default:;
    // }

    int x = mapFromScene(p).x();
    int y = mapFromScene(p).y();

    if(isInsideCircle(x, y, -4, -4, 9, 9) ||
            isInsideCircle(x, y, width()-2, height()-2, 9, 9)) {
        return true;
    } else {
        return false;
    }
}


void SelectableShape::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    int x = e->pos().x();
    int y = e->pos().y();

    if(isInsideCircle(x, y, -4, -4, 9, 9)) {
        mDragPosition = DragPosition::TopLeft;
    } else if(isInsideCircle(x, y, -4, height()-2, 9, 9)) {
        mDragPosition = DragPosition::BottomLeft;
    } else if(isInsideCircle(x, y, width()-2, -4, 9, 9)) {
        mDragPosition = DragPosition::TopRight;
    } else if(isInsideCircle(x, y, width()-2, height()-2, 9, 9)) {
        mDragPosition = DragPosition::BottomRight;
    }

    Shape::mousePressEvent(e);
}

void SelectableShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) {
    mDragPosition = DragPosition::None;
    QApplication::restoreOverrideCursor();
    Shape::mouseReleaseEvent(e);
}

void SelectableShape::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
    if(mDragPosition != DragPosition::None) {
        qreal x = pos().x();
        qreal y = pos().y();
        qreal w = width();
        qreal h = height();
        qreal oldw, oldh;

        switch(mDragPosition) {
        case DragPosition::BottomRight:
            w = e->scenePos().x() - pos().x();
            h = e->scenePos().y() - pos().y();
            break;
        case DragPosition::TopRight:
            oldh = h;
            w = e->scenePos().x() - pos().x();
            h += pos().y() - e->scenePos().y();
            if(h > minimumSize().height()) {
                y += e->scenePos().y() - pos().y();
            } else {
                h = oldh;
            }
            break;
        case DragPosition::BottomLeft:
            oldw = w;
            w += pos().x() - e->scenePos().x();
            h = e->scenePos().y() - pos().y();
            if(w > minimumSize().width()) {
                x += e->scenePos().x() - pos().x();
            } else {
                w = oldw;
            }
            break;
        case DragPosition::TopLeft:
            oldw = w;
            oldh = h;
            w += pos().x() - e->scenePos().x();
            h += pos().y() - e->scenePos().y();
            if(h > minimumSize().height()) {
                y += e->scenePos().y() - pos().y();
            } else {
                h = oldh;
            }
            if(w > minimumSize().width()) {
                x += e->scenePos().x() - pos().x();
            } else {
                w = oldw;
            }
            break;
        default:
            break;
        }

        if(qApp->activeWindow())
            qApp->activeWindow()->undoStack()->push(
                    new QuGC::ResizeUndoCommand(this, pos(), {x, y},
                        size(), {w, h}));
    } else {
        Shape::mouseMoveEvent(e);
    }
}

QRectF SelectableShape::boundingRect() const {
    return {-7,-7,width()+14,height()+14};
}

QVariant SelectableShape::itemChange(GraphicsItemChange c,
        const QVariant& v) {
    switch(c) {
    case QGraphicsItem::ItemSelectedChange:
        if(v.toBool()) {
            setZValue(zValue()+1);
        } else {
            setZValue(zValue()-1);
        }
        break;
    case QGraphicsItem::ItemPositionChange:
        if(mDragPosition == DragPosition::None) {
            if(qApp->activeWindow())
                qApp->activeWindow()->undoStack()->push(
                        new QuGC::MoveUndoCommand(
                            diagram()->scene()->selectedItems(),
                            this, pos(), v.toPointF()));
        }

        break;
    case QGraphicsItem::ItemPositionHasChanged:
        diagram()->editorView()->updateButtonsPosition();
        break;
    default:;
    }


    return Shape::itemChange(c, v);
}

QUML_END_NAMESPACE_GD
