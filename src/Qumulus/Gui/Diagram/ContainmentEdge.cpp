/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ContainmentEdge.h"
#include <QtGui/QPainter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

ContainmentEdge::ContainmentEdge(QuUK::Element* e, DiagramElement* p) :
        Edge(e, p) {
}

ContainmentEdge::ContainmentEdge(const ContainmentEdge& e) :
        Edge(e) {}

void ContainmentEdge::paint(QPainter* p,
        const QStyleOptionGraphicsItem* o,
        QWidget* w) {
    Edge::paint(p, o, w);
    Shape* t = target();
    Direction entry = targetEntry();
    QPointF origin = {t->pos().x() + t->width() / 2,
            t->pos().y() + t->height() / 2};

    if(target()->boundingRect().contains(source()->boundingRect()))
        return;

    switch(entry) {
    case Up: {
        origin.ry() -= t->height() / 2 + 11;
        origin.rx() -= 5;
        p->setBrush(Qt::white);
        p->drawEllipse(origin.x(), origin.y(), 20, 20);
        origin.rx() += 10;
        origin.ry() += 10;
        p->drawLine(origin.x() - 10, origin.y(), origin.x() + 10, origin.y());
        p->drawLine(origin.x(), origin.y() - 10, origin.x(), origin.y() + 10);
        break;
    }
    case Down: {
        origin.ry() += t->height() / 2;
        origin.rx() -= 5;
        p->setBrush(Qt::white);
        p->drawEllipse(origin.x(), origin.y(), 20, 20);
        origin.rx() += 10;
        origin.ry() += 10;
        p->drawLine(origin.x() - 10, origin.y(), origin.x() + 10, origin.y());
        p->drawLine(origin.x(), origin.y() - 10, origin.x(), origin.y() + 10);
        break;
    }
    case Left: {
        origin.rx() -= t->width() / 2 + 20;
        origin.ry() -= 5;
        p->setBrush(Qt::white);
        p->drawEllipse(origin.x(), origin.y(), 20, 20);
        origin.rx() += 10;
        origin.ry() += 10;
        p->drawLine(origin.x() - 10, origin.y(), origin.x() + 10, origin.y());
        p->drawLine(origin.x(), origin.y() - 10, origin.x(), origin.y() + 10);
        break;
    }
    case Right: {
        origin.rx() += t->width() / 2;
        origin.ry() -= 5;
        p->setBrush(Qt::white);
        p->drawEllipse(origin.x(), origin.y(), 20, 20);
        origin.rx() += 10;
        origin.ry() += 10;
        p->drawLine(origin.x() - 10, origin.y(), origin.x() + 10, origin.y());
        p->drawLine(origin.x(), origin.y() - 10, origin.x(), origin.y() + 10);
        break;
    }
    }
}
QUML_END_NAMESPACE_GD

