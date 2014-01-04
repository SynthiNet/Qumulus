/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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
        Primitive,
        Enumeration
    };

public:
    Popover(QWidget* parent = 0, QPoint pos = QPoint(0, 0),
            Qt::Orientation orientation = Qt::Horizontal);
    void setupUi(PopoverType);
    void bindModel(QuGD::Shape*);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void focusOutEvent(QFocusEvent*) override;

private:
    void generateMask(Direction direction, int offset);
    QPair<QPoint, Direction> findWindowLocation(QPoint mouse, int width,
            int height, Qt::Orientation orientation, QRect available);

signals:
    void lostFocus();

private:
    QBitmap* mMask;
    QVBoxLayout* mLayout;
    QPoint mMouse;
    QPoint mPos;
    Qt::Orientation mOrientation;
    PopoverForm* mForm = nullptr;
    PopoverType mType;
    constexpr static int kWidth = 400;
    constexpr static int kHeight = 400;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVER_H_ */

