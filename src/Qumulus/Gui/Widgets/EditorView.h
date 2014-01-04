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

#ifndef GUI_WIDGETS_EDITORVIEW_H_
#define GUI_WIDGETS_EDITORVIEW_H_

#include "internal_base.h"
#include <QtWidgets/QGraphicsView>
#include <QtGui/QMouseEvent>
#include <QtCore/QPointF>
#include <Gui/Diagram/Diagram.h>
#include <Gui/Widgets/MainWindow.h>
#include <Gui/Diagram/ClassShape.h>
#include <Gui/Diagram/CommentShape.h>

class QPushButton;
class QGraphicsProxyWidget;

QUML_BEGIN_NAMESPACE_GW

class Popover;

struct MouseState {
    QPointF startPos;
    CursorState startCursor;
};

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(MainWindow* parent, QuGD::Diagram* diagram);
    ~EditorView() noexcept;
    const QuGD::Diagram* diagram() const { return mDiagram; }

    void updateButtonsPosition();
    void resetSelection();

public slots:
    void zoom(double value);
    void selectionChanged();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    QGraphicsScene* mScene;
    QGraphicsRectItem* mSelectionRect;
    Popover* mPopover;
    QuGD::Diagram* mDiagram;
    bool mCursorOverride = false;

    QPushButton* mAttributeButton;
    QPushButton* mOperationButton;
    QPushButton* mLiteralButton;
    QGraphicsProxyWidget* mAttributeButtonItem;
    QGraphicsProxyWidget* mOperationButtonItem;
    QGraphicsProxyWidget* mLiteralButtonItem;

    MouseState mMouseState;
    QPointF mMousePosition;
    MainWindow* mMainWindow;
    bool mIsDragging = false;
    double mCurrentZoom = 1;
    bool mScrollable = true;
    QuGD::Shape* mSource = nullptr;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

