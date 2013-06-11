/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
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

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD
