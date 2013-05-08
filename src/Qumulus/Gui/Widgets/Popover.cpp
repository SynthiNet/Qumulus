/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "Popover.h"
#include <algorithm>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtGui/QBitmap>
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_GW

Popover::Popover(QWidget* parent, QPoint pos, Qt::Orientation orientation) : 
        QWidget(parent) {
    setWindowFlags(Qt::Popup);
    setGeometry(pos.x(), pos.y(), 0, 0);
    setFixedSize(100, 200);
    setWindowOpacity(0.85);
    generateMask(Direction::Left, height()/2);
}

void Popover::resizeEvent(QResizeEvent*) {}

void Popover::generateMask(Direction direction, int offset) {
    mMask = new QBitmap(size());
    mMask->clear();

    QPainter maskPainter(mMask);
    QBrush brush(Qt::color1);
    maskPainter.setBrush(brush);

    // Clip to valid locations.
    offset = std::max(offset, 26);
    if(direction == Direction::Top || direction == Direction::Bottom) {
        offset = std::min(offset, mMask->height()-26);
    } else {
        offset = std::min(offset, mMask->width()-26);
    }

    switch(direction) {
    case Top:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(0,20,mMask->width(),mMask->height()-20,5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(offset, 0),
                QPoint(offset-20, 20),
                QPoint(offset+20, 20)}));

        break;

    case Right:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(0,0,mMask->width()-20,mMask->height(),5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(mMask->width(), offset),
                QPoint(mMask->width()-20, offset-20),
                QPoint(mMask->width()-20, offset+20)}));

        break;

    case Bottom:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(0,0,mMask->width(),mMask->height()-20,5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(offset, mMask->height()),
                QPoint(offset-20, mMask->height()-20),
                QPoint(offset+20, mMask->height()-20)}));

        break;

    case Left:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(20,0,mMask->width()-20,mMask->height(),5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(0, offset),
                QPoint(20, offset-20),
                QPoint(20, offset+20)}));

        break;
    }

    setMask(*mMask);
}

QUML_END_NAMESPACE_GW

