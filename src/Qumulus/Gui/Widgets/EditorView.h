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

QUML_BEGIN_NAMESPACE_GW

class Popover;

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(QWidget* parent = 0);

public slots:
    void zoom(double value);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QGraphicsScene* mScene;
    Popover* mPopover;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

