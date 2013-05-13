/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "SelectableShape.h"
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UD

SelectableShape::SelectableShape(QuUK::Element* e, DiagramElement* p) : 
    Shape(e, p) {
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
}

SelectableShape::SelectableShape(const SelectableShape& c) : Shape(c) {}

QVariant SelectableShape::itemChange(GraphicsItemChange c, 
        const QVariant& v) {
    if(c == QGraphicsItem::ItemSelectedChange) {
        if(v.toBool()) {
            qDebug() << "Selected";
        } else {
            qDebug() << "Deselected";
        }
    }
    return Shape::itemChange(c, v); 
}

QUML_END_NAMESPACE_UD
