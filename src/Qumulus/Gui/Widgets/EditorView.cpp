/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "EditorView.h"

#include "Popover.h"

#include <QtCore/QDebug>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtWidgets/QPushButton>

#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Operation.h>
#include <Uml/Kernel/Parameter.h>
#include <Uml/Kernel/Property.h>
#include <Uml/Kernel/Association.h>

#include <Gui/Diagram/SelectableShape.h>
#include <Gui/Diagram/PackageShape.h>
#include <Gui/Diagram/CommentShape.h>
#include <Gui/Diagram/ClassShape.h>
#include <Gui/Diagram/EnumShape.h>
#include <Gui/Diagram/PrimitiveShape.h>

#include <Gui/Widgets/Popover.h>

#include <cmath>

#include <libavoid/connend.h>
#include <QtWidgets/QAction>

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(MainWindow* parent) : QGraphicsView(parent), 
        mScene(new QGraphicsScene(this)),
        mPopover(nullptr),
        mDiagram(new QuGD::Diagram()),
        mAttributeButton(new QPushButton(
                    QIcon(":/data/img/editor/add-attribute.png"), "")),
        mOperationButton(new QPushButton(
                    QIcon(":/data/img/editor/add-operation.png"), "")),
        mLiteralButton(new QPushButton(
                    QIcon(":/data/img/editor/add-literal.png"), "")),
        mMainWindow(parent) {
    setScene(mScene);
    mScene->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    setSceneRect(-20000.0, -20000.0, 40000.0, 40000.0);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setDragMode(QGraphicsView::RubberBandDrag);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    mDiagram->setScene(mScene);
    mSelectionRect = new QGraphicsRectItem();
    mSelectionRect->setZValue(9001);
    mSelectionRect->setVisible(false);
    mScene->addItem(mSelectionRect);

    connect(mScene, &QGraphicsScene::selectionChanged, 
            this, &EditorView::selectionChanged);

    // Setup buttons
    mAttributeButton->setIconSize({24, 24});
    mAttributeButton->setFixedSize({32, 32});
    mAttributeButton->setToolTip("Attribute [A]");
    mOperationButton->setIconSize({24, 24});
    mOperationButton->setFixedSize({32, 32});
    mOperationButton->setToolTip("Operation [O]");
    mLiteralButton->setIconSize({24, 24});
    mLiteralButton->setFixedSize({32, 32});
    mLiteralButton->setToolTip("Literal [L]");

    mAttributeButtonItem = mScene->addWidget(mAttributeButton);
    mAttributeButtonItem->setVisible(false);
    mAttributeButtonItem->setZValue(10);
    mOperationButtonItem = mScene->addWidget(mOperationButton);
    mOperationButtonItem->setVisible(false);
    mOperationButtonItem->setZValue(10);
    mLiteralButtonItem = mScene->addWidget(mLiteralButton);
    mLiteralButtonItem->setVisible(false);
    mLiteralButtonItem->setZValue(10);

    // FIXME: this is temporary testing code!
    auto package = new QuUK::Package("Uml");
    auto pshape = mDiagram->createShape(package);
    pshape->setVisible(true);
    pshape->setPos(-200, -100);

    // FIXME: this is temporary testing code!
    auto boolean = new QuUK::PrimitiveType("bool");
    auto ptshape = mDiagram->createShape(boolean);
    boolean->setPackage(package);
    ptshape->setPos(-200, 0);
    ptshape->setVisible(true);

    // FIXME: this is temporary testing code!
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
    auto clshape = mDiagram->createShape(classs);
    classs->setPackage(package);
    clshape->setPos(20, 0);
    clshape->setVisible(true);

    // FIXME: this is temporary testing code!
    auto visibilityKind = new QuUK::Enumeration("VisibilityKind");
    new QuUK::EnumerationLiteral("Public", visibilityKind);
    new QuUK::EnumerationLiteral("Protected", visibilityKind);
    new QuUK::EnumerationLiteral("Private", visibilityKind);
    new QuUK::EnumerationLiteral("FILE_NOT_FOUND", visibilityKind);
    auto eshape = mDiagram->createShape(visibilityKind);
    visibilityKind->setPackage(package);
    eshape->setPos(-200, 50);
    eshape->setVisible(true);

    // FIXME: this is temporary testing code!
    auto comment = new QuUK::Comment(
            "VisibilityKind is an enumeration type that defines literals to "
            "determine the visibility of elements in a model.");
    auto cshape = mDiagram->createShape(comment);
    cshape->setVisible(true);
    cshape->setPos(-200, 200);

    // FIXME: this is temporary testing code!
    auto assoc = new QuUK::Association(classs, visibilityKind);
    (void) assoc;

    // FIXME: this is temporary testing code!
    // Add a line between the comment and the class.
    // QAction* action = new QAction(this);
    // this->addAction(action);
    // action->setShortcuts({Qt::Key_0});
    // connect(action, &QAction::triggered, [&]{
    //     Avoid::ConnEnd src(cshape->shapeRef(), 1);
    //     Avoid::ConnEnd end(clshape->shapeRef(), 1);
    //     auto conn = new Avoid::ConnRef(
    //         mDiagram->router(), 
    //         src, 
    //         end);

    //     mDiagram->router()->processTransaction();
    //     auto route = conn->displayRoute();
    //     for (size_t i = 1; i < route.size(); ++i) {
    //         Avoid::Point point = route.at(i);
    //         mScene->addLine(route.at(i-1).x, route.at(i-1).y, point.x, point.y);
    //     }
    // });

    // mDiagram->saveToXml("test.uml");
}

EditorView::~EditorView() noexcept {
    delete mDiagram;    
}

void EditorView::zoom(double value) {
    resetMatrix();
    mCurrentZoom = value;
    scale(value, value);
}

void EditorView::selectionChanged() {
    if(scene()->selectedItems().size() != 1) {
        mAttributeButtonItem->setVisible(false);
        mOperationButtonItem->setVisible(false);
        mLiteralButtonItem->setVisible(false); 
    } else {
        auto p = scene()->selectedItems()[0];

        if(dynamic_cast<QuGD::ClassShape*>(p)) {
            mAttributeButtonItem->setVisible(true);
            mOperationButtonItem->setVisible(true);
            mLiteralButtonItem->setVisible(false); 

            mAttributeButtonItem->setPos(p->pos() - QPointF{36, 0});
            mOperationButtonItem->setPos(p->pos() - QPointF{36, -36});
        } else if(dynamic_cast<QuGD::EnumShape*>(p)) {
            mAttributeButtonItem->setVisible(false);
            mOperationButtonItem->setVisible(false);
            mLiteralButtonItem->setVisible(true); 

            mLiteralButtonItem->setPos(p->pos() - QPointF{36, 0});
        } else {
            mAttributeButtonItem->setVisible(false);
            mOperationButtonItem->setVisible(false);
            mLiteralButtonItem->setVisible(false); 
        }
    }
}

void EditorView::updateButtonsPosition() {
    if(scene()->selectedItems().size() == 1) {
        auto p = scene()->selectedItems()[0];

        if(dynamic_cast<QuGD::ClassShape*>(p)) {
            mAttributeButtonItem->setPos(p->pos() - QPointF{36, 0});
            mOperationButtonItem->setPos(p->pos() - QPointF{36, -36});
        } else if(dynamic_cast<QuGD::EnumShape*>(p)) {
            mLiteralButtonItem->setPos(p->pos() - QPointF{36, 0});
        } 
    }
}

void EditorView::mousePressEvent(QMouseEvent* e) {
    auto state = mMainWindow->cursorState();
    mMouseState = MouseState{mapToScene(e->pos()), state};

    if(state == CursorState::Normal) {
        QGraphicsView::mousePressEvent(e);
    } else {
        mIsDragging = true;
    }       
}

void EditorView::mouseReleaseEvent(QMouseEvent* e) {
    mIsDragging = false;
    mSelectionRect->setVisible(false);
    auto state = mMainWindow->cursorState();

    QPointF beginPoint;
    QPointF currentPos = mapToScene(e->pos());
    QSizeF delta;
    QRectF rect;
    if(mMouseState.startPos.x() < currentPos.x()) {
        if(mMouseState.startPos.y() < currentPos.y()) {
            rect.setTopLeft(mMouseState.startPos);
            rect.setBottomRight(currentPos);
        } else {
            rect.setBottomLeft(mMouseState.startPos);
            rect.setTopRight(currentPos);
        }
    } else {
        if(mMouseState.startPos.y() < currentPos.y()) {
            rect.setTopRight(mMouseState.startPos);
            rect.setBottomLeft(currentPos);
        } else {
            rect.setBottomRight(mMouseState.startPos);
            rect.setTopLeft(currentPos);
        }
    }
    beginPoint = rect.topLeft();
    auto sizePoint = rect.bottomRight() - rect.topLeft();
    delta = QSizeF(sizePoint.x(), sizePoint.y());
    

    switch(state) {
    case CursorState::Normal:
        QGraphicsView::mouseReleaseEvent(e);
        break;
    case CursorState::Aggregation:
        break;
    case CursorState::Class: {
        QString name = "Class" + QString::number(mDiagram->nextCounter());
        auto classElement = new QuUK::Class(name);
        auto classShape = mDiagram->createShape(classElement);
        classShape->setPos(beginPoint);
        classShape->resize(delta);
        classShape->setVisible(true);
        break;
    }
    case CursorState::Comment: {
        QString name = "Comment" + QString::number(mDiagram->nextCounter());
        auto commentElement = new QuUK::Comment(name);
        auto commentShape = mDiagram->createShape(commentElement);
        commentShape->setPos(beginPoint);
        commentShape->resize(delta);
        commentShape->setVisible(true);
        break;
    }
    case CursorState::Containment:
        break;
    case CursorState::Enum: {
        QString name = "Enumeration" + QString::number(mDiagram->nextCounter());
        auto enumElement = new QuUK::Enumeration(name);
        auto enumShape = mDiagram->createShape(enumElement);
        enumShape->setPos(beginPoint);
        enumShape->resize(delta);
        enumShape->setVisible(true);
        break;
    }
    case CursorState::Inheritance:
        break;
    case CursorState::Interface:
        break;
    case CursorState::PackageMembership:
        break;
    case CursorState::Package: {
        QString name = "Package" + QString::number(mDiagram->nextCounter());
        auto packageElement = new QuUK::Package(name);
        auto packageShape = mDiagram->createShape(packageElement);
        packageShape->setPos(beginPoint);
        packageShape->resize(delta);
        packageShape->setVisible(true);
        break;
    }
    case CursorState::Primitive: {
        QString name = "Primitive" + QString::number(mDiagram->nextCounter());
        auto primitiveElement = new QuUK::PrimitiveType(name);
        auto primitiveShape = mDiagram->createShape(primitiveElement);
        primitiveShape->setPos(beginPoint);
        primitiveShape->resize(delta);
        primitiveShape->setVisible(true);
        break;
    }
    case CursorState::Association:
        break;
    }

    mMainWindow->setCursorState(CursorState::Normal);
}

void EditorView::mouseMoveEvent(QMouseEvent* e) {
    mMousePosition = mapToScene(e->pos());

    if(mIsDragging) {
        QRectF rect;
        if(mMouseState.startPos.x() < mMousePosition.x()) {
            if(mMouseState.startPos.y() < mMousePosition.y()) {
                rect.setTopLeft(mMouseState.startPos);
                rect.setBottomRight(mMousePosition);
            } else {
                rect.setBottomLeft(mMouseState.startPos);
                rect.setTopRight(mMousePosition);
            }
        } else {
            if(mMouseState.startPos.y() < mMousePosition.y()) {
                rect.setTopRight(mMouseState.startPos);
                rect.setBottomLeft(mMousePosition);
            } else {
                rect.setBottomRight(mMouseState.startPos);
                rect.setTopLeft(mMousePosition);
            }
        }

        switch(mMouseState.startCursor) {
        case Class:
            mSelectionRect->setBrush(QBrush({0, 0, 255, 32}));
            mSelectionRect->setPen(QPen(Qt::blue, 2/mCurrentZoom, Qt::DashLine));
            break;
        case Enum:
            mSelectionRect->setBrush(QBrush({255, 0, 0, 32}));
            mSelectionRect->setPen(QPen(Qt::red, 2/mCurrentZoom, Qt::DashLine));
            break;
        case Comment:
            mSelectionRect->setBrush(QBrush({127, 127, 127, 32}));
            mSelectionRect->setPen(QPen(Qt::gray, 2/mCurrentZoom, Qt::DashLine));
            break;
        case Package:
            mSelectionRect->setBrush(QBrush({0, 127, 0, 32}));
            mSelectionRect->setPen(QPen(QColor{0, 127, 0}, 2/mCurrentZoom, Qt::DashLine));
            break;
        case Primitive:
            mSelectionRect->setBrush(QBrush({255, 255, 0, 32}));
            mSelectionRect->setPen(QPen(Qt::yellow, 2/mCurrentZoom, Qt::DashLine));
            break;
        default:
            mSelectionRect->setBrush(QBrush({0, 0, 0, 32}));
            mSelectionRect->setPen(QPen(Qt::black, 2/mCurrentZoom, Qt::DashLine));
            break;
        }

        mSelectionRect->setRect(rect);
        mSelectionRect->setVisible(true);
    }

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

void EditorView::wheelEvent(QWheelEvent* e) {
    if(mScrollable) QGraphicsView::wheelEvent(e);
}

void EditorView::mouseDoubleClickEvent(QMouseEvent* e) {
    mScrollable = false;
    auto popover = new Popover(this, e->globalPos());
    popover->setVisible(true);
    connect(popover, &Popover::lostFocus, [&]{mScrollable = true;});
    QGraphicsView::mouseDoubleClickEvent(e);
}

QUML_END_NAMESPACE_GW

