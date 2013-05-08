/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"
#include <Gui/Widgets/Popover.h>

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(QWidget* parent) : QGraphicsView(parent), 
    mScene(new QGraphicsScene(this)) {
    mPopover = nullptr;
    mScene->addRect(0, 0, 20, 20);
    setScene(mScene);
    setSceneRect(-20000.0, -20000.0, 40000.0, 40000.0);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void EditorView::zoom(double value) {
    resetMatrix();
    scale(value, value);
}

void EditorView::mousePressEvent(QMouseEvent* e) {
    if(e->buttons() == Qt::LeftButton) {
        if(mPopover) {
            delete mPopover;
            mPopover = nullptr;
        } else {
            mPopover = new Popover(this, e->globalPos());
            mPopover->show();
        }
    }
}

QUML_END_NAMESPACE_GW

