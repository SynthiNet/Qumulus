/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_EDITORVIEW_H_
#define GUI_WIDGETS_EDITORVIEW_H_

#include "internal_base.h"
#include <QtWidgets/QGraphicsView>

QUML_BEGIN_NAMESPACE_GW

class EditorView : public QGraphicsView {
    Q_OBJECT

public:
    EditorView(QWidget* parent = 0);

public slots:
    void zoom(int value);

private:
    QGraphicsScene* mScene;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_EDITORVIEW_H_ */

