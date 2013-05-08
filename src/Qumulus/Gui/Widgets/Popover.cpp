/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "Popover.h"
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtGui/QBitmap>
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_GW

Popover::Popover(QWidget* parent, QPoint pos) : QWidget(parent) {
    setWindowFlags(Qt::Popup);
    setGeometry(pos.x(), pos.y(), 0, 0);
    setFixedSize(100, 200);
    setWindowOpacity(0.85);
    generateMask();
}

void Popover::resizeEvent(QResizeEvent*) {}

void Popover::generateMask() {
    mMask = new QBitmap(size());
    mMask->clear();

    QPainter maskPainter(mMask);
    QBrush brush(Qt::color1);
    maskPainter.setBrush(brush);
    maskPainter.drawLine(0,0,mMask->width(),mMask->height());

    setMask(*mMask);
}

QUML_END_NAMESPACE_GW

