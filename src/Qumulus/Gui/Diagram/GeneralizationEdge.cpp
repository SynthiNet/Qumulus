/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "GeneralizationEdge.h"

#include <Uml/Kernel/Element.h>

#include <QtGui/QPainter>
#include <QtCore/QXmlStreamWriter>
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
            {origin.x()+10, origin.y()-20},
            {origin.x()-10, origin.y()-20}
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
            {origin.x()+10, origin.y()+20},
            {origin.x()-10, origin.y()+20}
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
            {origin.x()-20, origin.y()+10},
            {origin.x()-20, origin.y()-10}
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
            {origin.x()+20, origin.y()-10},
            {origin.x()+20, origin.y()+10}
        });
        p->setBrush(Qt::white);
        p->drawPolygon(poly);
        break;
    }
    }
}

void GeneralizationEdge::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Generalization");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("source", source()->uniqueId());
    writer.writeAttribute("target", target()->uniqueId());
    writer.writeAttribute("modelelement", modelElement()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD

