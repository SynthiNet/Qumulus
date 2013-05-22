/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "CommentShape.h"
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_UD

CommentShape::CommentShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p),
        mPolygon(new QGraphicsPolygonItem(this)),
        mLine1(new QGraphicsLineItem(this)),
        mLine2(new QGraphicsLineItem(this)) {
    mPolygon->setBrush(QBrush(Qt::white));
    addToGroup(mPolygon);
    addToGroup(mLine1);
    addToGroup(mLine2);
}

CommentShape::CommentShape(const CommentShape& c) :
        SelectableShape(c) {

}

void CommentShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    QPolygonF poly({
        {w-20, 0},
        {0, 0},
        {0, h},
        {w, h},
        {w, 20},
        {w-20, 0}});

    mLine1->setLine(w-20, 0, w-20, 20);
    mLine2->setLine(w-20, 20, w, 20);

    mPolygon->setPolygon(poly);

    setSize({w, h});
}

QUML_END_NAMESPACE_UD
