/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "SelectableShape.h"
#include <QtCore/QDebug>
#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsView>
#include <QtCore/QDebug>
#include <Uml/Kernel/Element.h>
#include <functional>

QUML_BEGIN_NAMESPACE_GD

SelectableShape::SelectableShape(QuUK::Element* e, DiagramElement* p) : 
    Shape(e, p) {
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
}

SelectableShape::SelectableShape(const SelectableShape& c) : Shape(c) {}

void SelectableShape::paint(QPainter* p, const QStyleOptionGraphicsItem* o, 
            QWidget* w) {
    (void) o;
    (void) w;

    if(isSelected()) {
        p->setBrush(QBrush({64, 193, 255}));
        p->drawEllipse(-6,-6,7,7);
        p->drawEllipse(-6,height()-1,7,7);
        p->drawEllipse(width()-1,-6,7,7);
        p->drawEllipse(width()-1,height()-1,7,7);
    }
}

bool SelectableShape::isInsideCircle(int x, int y, int cx, 
        int cy, int cw, int ch) const {
    QRegion region(cx, cy, cw, ch);
    return region.contains({x, y});
}

bool SelectableShape::shouldShowBDiag(QPointF p) const {
    int x = mapFromScene(p).x();
    int y = mapFromScene(p).y();

    if(isInsideCircle(x, y, -8, height(), 9, 9) || 
            isInsideCircle(x, y, width(), -8, 9, 9)) {
        return true;
    } else {
        return false;
    }
}

bool SelectableShape::shouldShowFDiag(QPointF p) const {
    int x = mapFromScene(p).x();
    int y = mapFromScene(p).y();

    if(isInsideCircle(x, y, -8, -8, 9, 9) || 
            isInsideCircle(x, y, width(), height(), 9, 9)) {
        return true;
    } else {
        return false;
    }
}


void SelectableShape::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    int x = e->pos().x();
    int y = e->pos().y();

    if(isInsideCircle(x, y, -8, -8, 9, 9)) {
        mDragPosition = DragPosition::TopLeft;
    } else if(isInsideCircle(x, y, -8, height(), 9, 9)) {
        mDragPosition = DragPosition::BottomLeft;
    } else if(isInsideCircle(x, y, width(), -8, 9, 9)) {
        mDragPosition = DragPosition::TopRight;
    } else if(isInsideCircle(x, y, width(), height(), 9, 9)) {
        mDragPosition = DragPosition::BottomRight;
    }

    Shape::mousePressEvent(e);
}

void SelectableShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *e) {
    mDragPosition = DragPosition::None;
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
            w += e->scenePos().x() - e->lastScenePos().x();
            h += e->scenePos().y() - e->lastScenePos().y();
            break;
        case DragPosition::TopRight:
            oldh = h;
            w += e->scenePos().x() - e->lastScenePos().x();
            h += -(e->scenePos().y() - e->lastScenePos().y());
            if(h > minimumSize().height()) {
                y += e->scenePos().y() - e->lastScenePos().y();
            } else {
                h = oldh;
            }
            break;
        case DragPosition::BottomLeft:
            oldw = w;
            w += -(e->scenePos().x() - e->lastScenePos().x());
            h += e->scenePos().y() - e->lastScenePos().y();
            if(w > minimumSize().width()) {
                x += e->scenePos().x() - e->lastScenePos().x();
            } else {
                w = oldw;
            }
            break;
        case DragPosition::TopLeft:
            oldw = w;
            oldh = h;
            w += -(e->scenePos().x() - e->lastScenePos().x());
            h += -(e->scenePos().y() - e->lastScenePos().y());
            if(h > minimumSize().height()) {
                y += e->scenePos().y() - e->lastScenePos().y();
            } else {
                h = oldh;
            }
            if(w > minimumSize().width()) {
                x += e->scenePos().x() - e->lastScenePos().x();
            } else {
                w = oldw;
            }
            break;
        default:
            break;
        }
        
        setPos(x, y);
        setWidth(w);
        setHeight(h);
        prepareGeometryChange();

        //FIXME: Call doesn't work, why?
        //modelElement()->updateDiagramElement(nullptr, {w, h});
    } else {
        Shape::mouseMoveEvent(e);
    }
}

QRectF SelectableShape::boundingRect() const {
    return {-7,-7,width()+14,height()+14};
}

QVariant SelectableShape::itemChange(GraphicsItemChange c, 
        const QVariant& v) {
    if(c == QGraphicsItem::ItemSelectedChange) {
        if(v.toBool()) {
            setZValue(zValue()+1);
        } else {
            setZValue(zValue()-1);
        }
    }
    return Shape::itemChange(c, v); 
}

QUML_END_NAMESPACE_GD
