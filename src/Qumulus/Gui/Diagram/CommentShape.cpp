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

#include "CommentShape.h"
#include <Uml/Kernel/Comment.h>
#include <QtCore/QXmlStreamWriter>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

CommentShape::CommentShape(QuUK::Element* e,
        DiagramElement* p) :
        SelectableShape(e, p) {
    updateSizeConstraints();
    resize(0,0);
}

CommentShape::CommentShape(const CommentShape& c) :
        SelectableShape(c) {

}

QuUK::Comment* CommentShape::modelElement() const {
    return dynamic_cast<QuUK::Comment*>(SelectableShape::modelElement());
}

void CommentShape::paint(QPainter* painter,
        const QStyleOptionGraphicsItem* option, QWidget* widget) {
    updateSizeConstraints();
    resize(size());

    painter->setBrush(Qt::white);
    QPolygonF poly( {
        {width() - 20, 0},
        {0, 0},
        {0, height()},
        {width(), height()},
        {width(), 20},
        {width() - 20, 0}});
    painter->drawPolygon(poly);

    painter->drawLine(width() - 20, 0, width() - 20, 20);
    painter->drawLine(width() - 20, 20, width(), 20);

    QFont font = sharedStyle()->font();
    painter->setFont(font);

    painter->drawText(5, 15, width()-10, height()-15,
            Qt::AlignLeft | Qt::AlignTop | Qt::TextWordWrap,
            dynamic_cast<QuUK::Comment*>(modelElement())->body());

    SelectableShape::paint(painter, option, widget);
}

void CommentShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    setSize({w, h});
}

void CommentShape::updateSizeConstraints() {
    setMinimumSize({100, 60});
}


void CommentShape::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Comment");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("x", QString::number(pos().x()));
    writer.writeAttribute("y", QString::number(pos().y()));
    writer.writeAttribute("width", QString::number(width()));
    writer.writeAttribute("height", QString::number(height()));
    writer.writeAttribute("modelelement", modelElement()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD
