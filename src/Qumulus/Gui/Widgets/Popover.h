/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVER_H_
#define GUI_WIDGETS_POPOVER_H_

#include "internal_base.h"
#include <Gui/Diagram/internal_base.h>
#include <QtWidgets/QWidget>
#include <QtCore/QPair>
#include <QtCore/QPoint>

#include <Gui/Diagram/ClassShape.h>

class QVBoxLayout;

QUML_BEGIN_NAMESPACE_GD

class Shape;

QUML_END_NAMESPACE_GD


QUML_BEGIN_NAMESPACE_GW

class PopoverForm;

class Popover : public QWidget {
    Q_OBJECT

public:
    enum Direction {
        Top,
        Right,
        Bottom,
        Left
    };

    enum PopoverType {
        Attribute,
        Class,
        Comment,
        Literal,
        Operation,
        Package,
        Primitive
    };

public:
    Popover(QWidget* parent = 0, QPoint pos = QPoint(0, 0),
            Qt::Orientation orientation = Qt::Horizontal);
    void setupUi(PopoverType);
    void bindModel(QuGD::Shape*);
    //Popover(QWidget* parent, QuGD::ClassShape* selected, QPoint pos, QPoint reversePos);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void focusOutEvent(QFocusEvent * event) override;

private:
    void generateMask(Direction direction, int offset);
    QPair<QPoint, Direction> findWindowLocation(QPoint mouse, int width,
            int height, Qt::Orientation orientation, QRect available);

signals:
    void lostFocus();

private:
    QBitmap* mMask;
    QVBoxLayout* mLayout;
    PopoverForm* mForm;
    PopoverType mType;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVER_H_ */

