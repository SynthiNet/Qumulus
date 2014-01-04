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

#include "ContainmentEdge.h"
#include <QtGui/QPainter>
#include <QtCore/QXmlStreamWriter>
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

    // if(target()->boundingRect().contains(source()->boundingRect()))
        // return;
    // This doesn't quite work...

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

void ContainmentEdge::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Containment");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("source", source()->uniqueId());
    writer.writeAttribute("target", target()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD

