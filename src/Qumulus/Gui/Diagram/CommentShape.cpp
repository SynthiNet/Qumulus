/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "CommentShape.h"
#include <QtGui/QBrush>
#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

CommentShape::CommentShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p) {
}

CommentShape::CommentShape(const CommentShape& c) :
        SelectableShape(c) {

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
    // painter->drawText((width() / 2) - (twidth / 2), 25, packageName());

    SelectableShape::paint(painter, option, widget);
}

void CommentShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    setSize({w, h});
}

void CommentShape::updateSizeConstraints() {
    setMinimumSize({100, 40});
}

QUML_END_NAMESPACE_GD
