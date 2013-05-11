/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "CommentShape.h"

QUML_BEGIN_NAMESPACE_UD

CommentShape::CommentShape(QuUK::Element* e, 
        DiagramElement* p) :
        Shape(e, p),
        mPolygon(new QGraphicsPolygonItem(this)) {
    addToGroup(mPolygon);
}

CommentShape::CommentShape(const CommentShape& c) :
        Shape(c) {

}

void CommentShape::resize(double w, double h) {
     if(minimumSize().isValid()) {
        w = std::max(w, minimumSize().width());
        h = std::max(h, minimumSize().height());
    }   

    QPolygonF poly({
        {w-20, 0},
        {0, 0},
        {0, h},
        {w, h},
        {w, 20},
        {w-20, 20},
        {w-20, 0},
        {w, 20} });

    mPolygon->setPolygon(poly);

    setSize({w, h});
}

QUML_END_NAMESPACE_UD
