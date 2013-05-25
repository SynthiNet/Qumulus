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

class QPushButton;
class QGraphicsProxyWidget;

QUML_BEGIN_NAMESPACE_GW

class Popover;

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(QWidget* parent = 0);
    ~EditorView() noexcept;
    const QuGD::Diagram* diagram() const { return mDiagram; }

    void updateButtonsPosition();

public slots:
    void zoom(double value);
    void selectionChanged();

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

    QPushButton* mAttributeButton;
    QPushButton* mOperationButton;
    QPushButton* mLiteralButton;
    QGraphicsProxyWidget* mAttributeButtonItem;
    QGraphicsProxyWidget* mOperationButtonItem;
    QGraphicsProxyWidget* mLiteralButtonItem;

};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

