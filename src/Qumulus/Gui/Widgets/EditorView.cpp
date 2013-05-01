/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(QWidget* parent) : QGraphicsView(parent), 
    mScene(new QGraphicsScene(this)) {
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

QUML_END_NAMESPACE_GW

