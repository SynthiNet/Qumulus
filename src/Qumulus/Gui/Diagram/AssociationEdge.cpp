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

#include "AssociationEdge.h"
#include <Uml/Kernel/Association.h>
#include <Uml/Kernel/Element.h>

#include <QtCore/QXmlStreamWriter>
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
    Shape* t = source();
    Direction entry = sourceExit();
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
            p->setBrush(isSelected() ? Qt::blue : Qt::black);
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
            p->setBrush(isSelected() ? Qt::blue : Qt::black);
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
            p->setBrush(isSelected() ? Qt::blue : Qt::black);
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
            p->setBrush(isSelected() ? Qt::blue : Qt::black);
            p->drawPolygon(poly);
            break;
        }
        }
        break;
    default:
        break;
    }
}

void AssociationEdge::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Association");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("source", source()->uniqueId());
    writer.writeAttribute("target", target()->uniqueId());
    writer.writeAttribute("modelelement", modelElement()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD

