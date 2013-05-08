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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

#include <QtGui/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GW

Popover::Popover(QWidget* parent, QPoint pos, Qt::Orientation orientation) : 
        QWidget(parent), mLayout(new QVBoxLayout()) {
    setWindowFlags(Qt::Popup | Qt::Window);

    int kWidth = 400;
    int kHeight = 200;

    QPoint mouse = pos;

    // Slightly shift the origin for looks.
    if(orientation == Qt::Horizontal) {
        pos.ry() -= 26;
    } else {
        pos.rx() -= 26;
    }

    // We need to find a suitable position for the window.
    auto location = findWindowLocation(pos, kWidth, kHeight, orientation, 
            QApplication::desktop()->availableGeometry(mouse)); 

    setGeometry(location.first.x(), location.first.y(), 0, 0);
    setFixedSize(kWidth, kHeight);
    setWindowOpacity(0.85);

    setLayout(mLayout);
    mLayout->setAlignment(Qt::AlignTop);
    mLayout->addWidget(new QPushButton("MANGO CHUTNEY!"));

    // Calculate offset of triangle tip.
    int offset;
    if(orientation == Qt::Horizontal) {
        offset = mouse.y() - location.first.y();
    } else {
        offset = mouse.x() - location.first.x();
    }

    generateMask(location.second, offset);
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
        offset = std::min(offset, mMask->width()-26);
    } else {
        offset = std::min(offset, mMask->height()-26);
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

        layout()->setContentsMargins(12, 32, 12, 12);

        break;

    case Right:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(0,0,mMask->width()-20,mMask->height(),5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(mMask->width(), offset),
                QPoint(mMask->width()-20, offset-20),
                QPoint(mMask->width()-20, offset+20)}));
        layout()->setContentsMargins(12, 12, 32, 12);

        break;

    case Bottom:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(0,0,mMask->width(),mMask->height()-20,5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(offset, mMask->height()),
                QPoint(offset-20, mMask->height()-20),
                QPoint(offset+20, mMask->height()-20)}));

        layout()->setContentsMargins(12, 12, 12, 32);

        break;

    case Left:
        //Add the rounded rect.
        maskPainter.drawRoundedRect(20,0,mMask->width()-20,mMask->height(),5,5);

        //Add the triangle.
        maskPainter.drawPolygon(QPolygon({
                QPoint(0, offset),
                QPoint(20, offset-20),
                QPoint(20, offset+20)}));

        layout()->setContentsMargins(32, 12, 12, 12);

        break;
    }

    setMask(*mMask);
}

QPair<QPoint, Popover::Direction> Popover::findWindowLocation(QPoint origin, 
        int width, int height, Qt::Orientation orientation, QRect available) {
    QPair<QPoint, Direction> ret = qMakePair(QPoint(0,0), Left);
    bool flipped = false;

    // Check if the origin is in bounds, otherwise move it in bounds.
    if(origin.x()+width > available.right()) {
        // If the orientation is vertical, just clip it, otherwise shift it left
        // by width.
        if(orientation == Qt::Vertical) {
            ret.first.rx() = available.right() - width;
        } else {
            ret.first.rx() = origin.x() - width;
            flipped = true;
        }
    } else {
        ret.first.rx() = origin.x();
    }

    if(origin.y()+height > available.bottom()) {
        // If the orientation is horizontal, just clip it, otherwise shift it up
        // by height.
        if(orientation == Qt::Horizontal) {
            ret.first.ry() = available.bottom() - height;
        } else {
            ret.first.ry() = origin.y() - height;
            flipped = true;
        }
    } else {
        ret.first.ry() = origin.y();
    }

    // Now set the arrow direction.
    if(orientation == Qt::Horizontal) {
        ret.second = flipped ? Right : Left;
    } else {
        ret.second = flipped ? Bottom : Top;
    }

    return ret;
}
QUML_END_NAMESPACE_GW

