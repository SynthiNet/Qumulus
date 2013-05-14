/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "PackageShape.h"
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_UD

PackageShape::PackageShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p),
        mTabItem(new QGraphicsRectItem(0, 0, 30, 10, this)),
        mBodyItem(new QGraphicsRectItem(0, 10, 100, 50, this)) {
    mTabItem->setBrush(QBrush(Qt::white));
    mBodyItem->setBrush(QBrush(Qt::white));
    addToGroup(mTabItem);
    addToGroup(mBodyItem);
}

PackageShape::PackageShape(const PackageShape& c) :
        SelectableShape(c) {

}

void PackageShape::resize(double w, double h) {
     if(minimumSize().isValid()) {
        w = std::max(w, minimumSize().width());
        h = std::max(h, minimumSize().height());
    }   

    mBodyItem->setRect(0, 10, w, h - 10);

    setSize({w, h});
}

QUML_END_NAMESPACE_UD

