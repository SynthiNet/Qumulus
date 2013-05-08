/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVER_H_
#define GUI_WIDGETS_POPOVER_H_

#include "internal_base.h"
#include <QtWidgets/QWidget>
#include <QtCore/QPair>
#include <QtCore/QPoint>

class QVBoxLayout;

QUML_BEGIN_NAMESPACE_GW

class Popover : public QWidget {
    Q_OBJECT

public:
    enum Direction {
        Top,
        Right,
        Bottom,
        Left
    };

public:
    Popover(QWidget* parent = 0, QPoint pos = QPoint(0, 0), 
            Qt::Orientation orientation = Qt::Horizontal);

protected:
    void resizeEvent(QResizeEvent* event) override;
    
private:
    void generateMask(Direction direction, int offset);
    QPair<QPoint, Direction> findWindowLocation(QPoint mouse, int width, 
            int height, Qt::Orientation orientation, QRect available);

private:
    QBitmap* mMask;
    QVBoxLayout* mLayout;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVER_H_ */

