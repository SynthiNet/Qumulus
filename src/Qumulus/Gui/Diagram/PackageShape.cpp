/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "PackageShape.h"
#include <QtGui/QBrush>
#include <QtGui/QPainter>

#include <Uml/Kernel/Package.h>

QUML_BEGIN_NAMESPACE_GD

PackageShape::PackageShape(QuUK::Element* e, 
        DiagramElement* p) :
        SelectableShape(e, p) {
    constexpr int kPackageZOrdering = -2;
    setZValue(kPackageZOrdering);
    setMinimumSize({100, 60});
    resize(0, 0);
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

    painter->drawRect(0, 0, 30, 10);
    painter->drawRect(0, 10, width(), height() - 10);

    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    int twidth = m.width(packageName());

    painter->setFont(font);
    painter->drawText((width() / 2) - (twidth / 2), 25, packageName());

    SelectableShape::paint(painter, option, widget);
}

QString PackageShape::packageName() const {
    return *(dynamic_cast<QuUK::Package*>(modelElement())->name());
}

QUML_END_NAMESPACE_GD

