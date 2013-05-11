/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"
#include <Gui/Widgets/Popover.h>

#include <Uml/Kernel/PrimitiveType.h>

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(QWidget* parent) : QGraphicsView(parent), 
        mScene(new QGraphicsScene(this)),
        mPopover(nullptr),
        mDiagram(new QuUD::Diagram()) {
    mScene->addEllipse(-5, -5, 10, 10, QPen(Qt::blue), QBrush(Qt::blue));
    setScene(mScene);
    setSceneRect(-20000.0, -20000.0, 40000.0, 40000.0);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // FIXME: this is temporary testing code!
    auto boolean = new QuUK::PrimitiveType("bool");
    boolean->updateDiagramElement(mDiagram);
    boolean->diagramElement()->setVisible(true);
    mDiagram->addToGroup(boolean->diagramElement());

    mScene->addItem(mDiagram);
}

EditorView::~EditorView() {
    delete mDiagram;    
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
            mPopover = new Popover(this, e->globalPos(), Qt::Horizontal);
            mPopover->show();
        }
    }
}

QUML_END_NAMESPACE_GW

