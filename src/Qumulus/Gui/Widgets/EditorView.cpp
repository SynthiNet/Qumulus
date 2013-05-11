/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"
#include <Gui/Widgets/Popover.h>

#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/Comment.h>

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
    boolean->diagramElement()->setPos(-200, 0);
    boolean->diagramElement()->setVisible(true);
    mDiagram->addToGroup(boolean->diagramElement());

    // FIXME: this is temporary testing code!
    auto visibilityKind = new QuUK::Enumeration("VisibilityKind");
    new QuUK::EnumerationLiteral("Public", visibilityKind);
    new QuUK::EnumerationLiteral("Protected", visibilityKind);
    new QuUK::EnumerationLiteral("Private", visibilityKind);
    visibilityKind->updateDiagramElement(mDiagram);
    visibilityKind->diagramElement()->setPos(-200, 50);
    visibilityKind->diagramElement()->setVisible(true);
    mDiagram->addToGroup(visibilityKind->diagramElement());

    // FIXME: this is temporary testing code!
    QSet<QuUK::Element*> tmpset;
    tmpset.insert(visibilityKind); // for some reason not initlist constructible
    auto comment = new QuUK::Comment(
            "VisibilityKind is an enumeration type that defines literals to "
            "determine the visibility of elements in a model.", 
            tmpset);
    comment->updateDiagramElement(mDiagram);
    comment->diagramElement()->resize(200,0);
    comment->updateDiagramElement(mDiagram);
    comment->diagramElement()->resize(200,0);
    comment->diagramElement()->setPos(-250, 150);
    comment->diagramElement()->setVisible(true);
    mDiagram->addToGroup(comment->diagramElement());

    mScene->addItem(mDiagram);
}

EditorView::~EditorView() noexcept {
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

