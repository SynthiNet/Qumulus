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
#include <Uml/Diagram/Diagram.h>

QUML_BEGIN_NAMESPACE_GW

class Popover;

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(QWidget* parent = 0);
    ~EditorView() noexcept;

public slots:
    void zoom(double value);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QGraphicsScene* mScene;
    Popover* mPopover;
    QuUD::Diagram* mDiagram;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

