/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_EDITORVIEW_H_
#define GUI_WIDGETS_EDITORVIEW_H_

#include "internal_base.h"
#include <QtWidgets/QGraphicsView>
#include <QtGui/QMouseEvent>
#include <Gui/Diagram/Diagram.h>

QUML_BEGIN_NAMESPACE_GW

class Popover;

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(QWidget* parent = 0);
    ~EditorView() noexcept;
    const QuGD::Diagram* diagram() const { return mDiagram; }

public slots:
    void zoom(double value);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    QGraphicsScene* mScene;
    Popover* mPopover;
    QuGD::Diagram* mDiagram;
    bool mCursorOverride = false;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

