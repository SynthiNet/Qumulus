/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"
#include <QtCore/QDebug>
#include <QtWidgets/QGraphicsRectItem>
#include <Gui/Widgets/Popover.h>
#include <QtWidgets/QApplication>

#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Operation.h>
#include <Uml/Kernel/Parameter.h>
#include <Uml/Kernel/Property.h>
#include <Gui/Diagram/SelectableShape.h>
#include <Gui/Diagram/PackageShape.h>

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(QWidget* parent) : QGraphicsView(parent), 
        mScene(new QGraphicsScene(this)),
        mPopover(nullptr),
        mDiagram(new QuGD::Diagram()) {
    setScene(mScene);
    mScene->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    setSceneRect(-20000.0, -20000.0, 40000.0, 40000.0);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setDragMode(QGraphicsView::RubberBandDrag);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    mDiagram->setScene(mScene);

#if 0
    // FIXME: this is temporary testing code!
    auto boolean = new QuUK::PrimitiveType("bool");
    boolean->updateDiagramElement(mDiagram);
    boolean->diagramElement()->setPos(-200, 0);
    boolean->diagramElement()->setVisible(true);
    mDiagram->addElement(boolean->diagramElement());

    // FIXME: look at me, different comment.
    auto classs = new QuUK::Class("Classy");
    auto oper = new QuUK::Operation("naam", classs);
    oper->setStatic(true);
    oper->setVisiblity(QuUK::VisibilityKind::Public);
    auto ret = new QuUK::Parameter("", oper);
    ret->setDirection(QuUK::ParameterDirectionKind::Return);
    ret->setType(boolean);
    (new QuUK::Parameter("par1", oper))->setDirection(QuUK::ParameterDirectionKind::Out);
    (new QuUK::Parameter("par2", oper))->setType(boolean);
    new QuUK::Property("naamGeinspireerdDoorHetWerkVanMarxVanTweeEeuwenTerug", classs);
    classs->updateDiagramElement(mDiagram);
    classs->diagramElement()->setPos(20, 0);
    classs->diagramElement()->setVisible(true);
    mDiagram->addElement(classs->diagramElement());

    // FIXME: this is temporary testing code!
    auto visibilityKind = new QuUK::Enumeration("VisibilityKind");
    new QuUK::EnumerationLiteral("Public", visibilityKind);
    new QuUK::EnumerationLiteral("Protected", visibilityKind);
    new QuUK::EnumerationLiteral("Private", visibilityKind);
    visibilityKind->updateDiagramElement(mDiagram);
    visibilityKind->diagramElement()->setPos(-200, 50);
    visibilityKind->diagramElement()->setVisible(true);
    mDiagram->addElement(visibilityKind->diagramElement());

    // FIXME: this is temporary testing code!
    auto comment = new QuUK::Comment(
            "VisibilityKind is an enumeration type that defines literals to "
            "determine the visibility of elements in a model.", 
            visibilityKind);
    comment->updateDiagramElement(mDiagram, {200, 0});
    comment->diagramElement()->setPos(-250, 150);
    comment->diagramElement()->setVisible(true);
    mDiagram->addElement(comment->diagramElement());
#endif

    // FIXME: this is temporary testing code!
    auto package = new QuUK::Package("Uml");
    auto pshape = mDiagram->createShape(package);
    pshape->setVisible(true);
    pshape->setPos(-200, -100);
}

EditorView::~EditorView() noexcept {
    delete mDiagram;    
}

void EditorView::zoom(double value) {
    resetMatrix();
    scale(value, value);
}

void EditorView::mousePressEvent(QMouseEvent* e) {
    /*if(e->buttons() == Qt::LeftButton) {
          if(mPopover) {
            delete mPopover;
            mPopover = nullptr;
        } else {
            mPopover = new Popover(this, e->globalPos(), Qt::Horizontal);
            mPopover->show();
        }
    }*/

    QGraphicsView::mousePressEvent(e);
}

void EditorView::mouseMoveEvent(QMouseEvent* e) {
    for(auto i : scene()->selectedItems()) {
        if(auto p = dynamic_cast<QuGD::SelectableShape*>(i)) {
            if(p->shouldShowBDiag(mapToScene(e->pos()))) {
                QApplication::setOverrideCursor(Qt::SizeBDiagCursor);
                mCursorOverride = true;
            } else if(p->shouldShowFDiag(mapToScene(e->pos()))) {
                QApplication::setOverrideCursor(Qt::SizeFDiagCursor);
                mCursorOverride = true;
            } else {
                mCursorOverride = false;
                QApplication::restoreOverrideCursor();
            }
        }
    }

    QGraphicsView::mouseMoveEvent(e);
}

void EditorView::keyPressEvent(QKeyEvent* e) {
    if(e->key() == Qt::Key_Shift) {
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

    QGraphicsView::keyPressEvent(e);
}

void EditorView::keyReleaseEvent(QKeyEvent* e) {
    if(e->key() == Qt::Key_Shift) {
        setDragMode(QGraphicsView::RubberBandDrag);
    }

    QGraphicsView::keyReleaseEvent(e);
}

QUML_END_NAMESPACE_GW

