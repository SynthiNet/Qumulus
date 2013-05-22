/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "PackageShape.h"
#include <QtGui/QBrush>
#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

PackageShape::PackageShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p) {
    constexpr int kPackageZOrdering = -2;
    setZValue(kPackageZOrdering);
}

PackageShape::PackageShape(const PackageShape& c) :
        SelectableShape(c) {}



void PackageShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    setSize({w, h});
}

void PackageShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {
    painter->setBrush(Qt::white);

    SelectableShape::paint(painter, option, widget);
}

QUML_END_NAMESPACE_GD

