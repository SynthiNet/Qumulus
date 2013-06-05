/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "AssociationEdge.h"
#include <Uml/Kernel/Association.h>
#include <Uml/Kernel/Element.h>
#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

AssociationEdge::AssociationEdge(QuUK::Element* e, DiagramElement* p) :
        Edge(e, p) {
}

AssociationEdge::AssociationEdge(const AssociationEdge& e) :
        Edge(e) {}

void AssociationEdge::paint(QPainter* p, 
        const QStyleOptionGraphicsItem* o, 
        QWidget* w) {
    Edge::paint(p, o, w);
    Shape* t = target();
    Direction entry = targetEntry();
    QuUK::AggregationKind aggregationKind = 
        static_cast<QuUK::Association*>(modelElement())->aggregation();
    QPointF origin = {t->pos().x() + t->width() / 2, 
            t->pos().y() + t->height() / 2};

    switch(aggregationKind) {
    case QuUK::AggregationKind::Shared:
        switch(entry) {
        case Up: {
            origin.ry() -= t->height() / 2;
            origin.rx() += 6;
            QPolygonF poly({ 
                {origin.x(), origin.y()},
                {origin.x()+5, origin.y()-10},
                {origin.x(), origin.y()-20},
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
                {origin.x(), origin.y()+20},
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
                {origin.x()-20, origin.y()},
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
                {origin.x()+10, origin.y()+5},
                {origin.x()+20, origin.y()},
                {origin.x()+10, origin.y()-5}
            });
            p->setBrush(Qt::white);
            p->drawPolygon(poly);
            break;
        }
        }
        break;
    case QuUK::AggregationKind::Composite:
        switch(entry) {
        case Up: {
            origin.ry() -= t->height() / 2;
            origin.rx() += 6;
            QPolygonF poly({ 
                {origin.x(), origin.y()},
                {origin.x()+5, origin.y()-10},
                {origin.x(), origin.y()-20},
                {origin.x()-5, origin.y()-10}
            });
            p->setBrush(Qt::black);
            p->drawPolygon(poly);
            break;
        }
        case Down: {
            origin.ry() += t->height() / 2;
            origin.rx() += 6;
            QPolygonF poly({ 
                {origin.x(), origin.y()},
                {origin.x()+5, origin.y()+10},
                {origin.x(), origin.y()+20},
                {origin.x()-5, origin.y()+10}
            });
            p->setBrush(Qt::black);
            p->drawPolygon(poly);
            break;
        }
        case Left: {
            origin.rx() -= t->width() / 2;
            origin.ry() += 6;
            QPolygonF poly({ 
                {origin.x(), origin.y()},
                {origin.x()-10, origin.y()+5},
                {origin.x()-20, origin.y()},
                {origin.x()-10, origin.y()-5}
            });
            p->setBrush(Qt::black);
            p->drawPolygon(poly);
            break;
        }
        case Right: {
            origin.rx() += t->width() / 2;
            origin.ry() += 6;
            QPolygonF poly({ 
                {origin.x(), origin.y()},
                {origin.x()+10, origin.y()+5},
                {origin.x()+20, origin.y()},
                {origin.x()+10, origin.y()-5}
            });
            p->setBrush(Qt::black);
            p->drawPolygon(poly);
            break;
        }
        }
        break;
    default:
        break;
    }
    }
QUML_END_NAMESPACE_GD

