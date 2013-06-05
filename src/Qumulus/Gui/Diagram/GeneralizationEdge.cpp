/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "GeneralizationEdge.h"
#include <QtGui/QPainter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

GeneralizationEdge::GeneralizationEdge(QuUK::Element* e, DiagramElement* p) :
        Edge(e, p) {
}

GeneralizationEdge::GeneralizationEdge(const GeneralizationEdge& e) :
        Edge(e) {}

void GeneralizationEdge::paint(QPainter* p, 
        const QStyleOptionGraphicsItem* o, 
        QWidget* w) {
    Edge::paint(p, o, w);
    Shape* t = target();
    Direction entry = targetEntry();
    QPointF origin = {t->pos().x() + t->width() / 2, 
            t->pos().y() + t->height() / 2};

    switch(entry) {
    case Up: {
        origin.ry() -= t->height() / 2;
        origin.rx() += 6;
        QPolygonF poly({ 
            {origin.x(), origin.y()},
            {origin.x()+5, origin.y()-10},
            {origin.x()-5, origin.y()-10}
        });
        p->setBrush(Qt::white);
        p->drawPolygon(poly);
        break;
    }
    case Down: {
        origin.ry() += t->height() / 2;
        origin.rx() += 6;
        QPolygonF poly({ 
            {origin.x(), origin.y()},
            {origin.x()+5, origin.y()+10},
            {origin.x()-5, origin.y()+10}
        });
        p->setBrush(Qt::white);
        p->drawPolygon(poly);
        break;
    }
    case Left: {
        origin.rx() -= t->width() / 2;
        origin.ry() += 6;
        QPolygonF poly({ 
            {origin.x(), origin.y()},
            {origin.x()-10, origin.y()+5},
            {origin.x()-10, origin.y()-5}
        });
        p->setBrush(Qt::white);
        p->drawPolygon(poly);
        break;
    }
    case Right: {
        origin.rx() += t->width() / 2;
        origin.ry() += 6;
        QPolygonF poly({ 
            {origin.x(), origin.y()},
            {origin.x()+10, origin.y()-5},
            {origin.x()+10, origin.y()+5}
        });
        p->setBrush(Qt::white);
        p->drawPolygon(poly);
        break;
    }
    }
}
QUML_END_NAMESPACE_GD

