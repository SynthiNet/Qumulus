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
#include <Gui/Diagram/AssociationEdge.h>
#include <Gui/Diagram/GeneralizationEdge.h>
#include <Gui/Diagram/ContainmentEdge.h>

#include <Gui/Core/XmlReader.h>

#include <Gui/Widgets/Popover.h>

#include <cmath>

#include <libavoid/connend.h>
#include <QtWidgets/QAction>

QUML_BEGIN_NAMESPACE_GW

EditorView::EditorView(MainWindow* parent, QuGD::Diagram* d) :
        QGraphicsView(parent),
        mScene(new QGraphicsScene(this)),
        mPopover(nullptr),
        mDiagram(d),
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
    mAttributeButton->setShortcut({Qt::Key_A});
    connect(mAttributeButton, &QPushButton::clicked, [&]{
            auto items = mScene->selectedItems();
            if(items.size() == 1 && dynamic_cast<QuGD::ClassShape*>(items[0])) {
                auto i = dynamic_cast<QuGD::ClassShape*>(items[0]);
                new QuUK::Property("attribute" +
                    QString::number(mDiagram->nextCounter()),
                    dynamic_cast<QuUK::Class*>(i->modelElement()));
                i->update();
            }});

    mOperationButton->setIconSize({24, 24});
    mOperationButton->setFixedSize({32, 32});
    mOperationButton->setToolTip("Operation [O]");
    mOperationButton->setShortcut({Qt::Key_O});
    connect(mOperationButton, &QPushButton::clicked, [&]{
            auto items = mScene->selectedItems();
            if(items.size() == 1 && dynamic_cast<QuGD::ClassShape*>(items[0])) {
                auto i = dynamic_cast<QuGD::ClassShape*>(items[0]);
                new QuUK::Operation("operation" +
                    QString::number(mDiagram->nextCounter()),
                    dynamic_cast<QuUK::Class*>(i->modelElement()));
                i->update();
            }});

    mLiteralButton->setIconSize({24, 24});
    mLiteralButton->setFixedSize({32, 32});
    mLiteralButton->setToolTip("Literal [L]");
    mLiteralButton->setShortcut({Qt::Key_L});
    connect(mLiteralButton, &QPushButton::clicked, [&]{
            auto items = mScene->selectedItems();
            if(items.size() == 1 && dynamic_cast<QuGD::EnumShape*>(items[0])) {
                auto i = dynamic_cast<QuGD::EnumShape*>(items[0]);
                new QuUK::EnumerationLiteral("Literal" +
                    QString::number(mDiagram->nextCounter()),
                    dynamic_cast<QuUK::Enumeration*>(i->modelElement()));
                i->update();
            }});


    mAttributeButtonItem = mScene->addWidget(mAttributeButton);
    mAttributeButtonItem->setVisible(false);
    mAttributeButtonItem->setZValue(10);
    mOperationButtonItem = mScene->addWidget(mOperationButton);
    mOperationButtonItem->setVisible(false);
    mOperationButtonItem->setZValue(10);
    mLiteralButtonItem = mScene->addWidget(mLiteralButton);
    mLiteralButtonItem->setVisible(false);
    mLiteralButtonItem->setZValue(10);

    QuGC::XmlReader r;
    r.loadFromXml(mDiagram, "test.uml");
}

EditorView::~EditorView() noexcept {
}

void EditorView::zoom(double value) {
    resetMatrix();
    mCurrentZoom = value;
    scale(value, value);
}

void EditorView::selectionChanged() {
    mDiagram->setModified();
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
    case CursorState::Aggregation: {
        auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());
        QuGD::Shape* shape = dynamic_cast<QuGD::Shape*>(selected);
        if(!mSource && shape && shape->acceptsAssociationSource()) {
            mSource = shape;
            return;
        } else if(mSource && shape && shape->acceptsAssociationTarget()) {
            auto assoc = new QuUK::Association(
                    dynamic_cast<QuUK::Classifier*>(mSource->modelElement()),
                    dynamic_cast<QuUK::Classifier*>(shape->modelElement()));
            assoc->setAggregation(QuUK::AggregationKind::Shared);
            auto ashape = mDiagram->createEdge(assoc, mSource, shape);
            ashape->setVisible(true);
            mSource = nullptr;
            break;
        } else {
            break;
        }
    }
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
    case CursorState::Composition: {
        auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());
        QuGD::Shape* shape = dynamic_cast<QuGD::Shape*>(selected);
        if(!mSource && shape && shape->acceptsAssociationSource()) {
            mSource = shape;
            return;
        } else if(mSource && shape && shape->acceptsAssociationTarget()) {
            auto assoc = new QuUK::Association(
                    dynamic_cast<QuUK::Classifier*>(mSource->modelElement()),
                    dynamic_cast<QuUK::Classifier*>(shape->modelElement()));
            assoc->setAggregation(QuUK::AggregationKind::Composite);
            auto ashape = mDiagram->createEdge(assoc, mSource, shape);
            ashape->setVisible(true);
            mSource = nullptr;
            break;
        } else {
            break;
        }
    }
    case CursorState::Enum: {
        QString name = "Enumeration" + QString::number(mDiagram->nextCounter());
        auto enumElement = new QuUK::Enumeration(name);
        auto enumShape = mDiagram->createShape(enumElement);
        enumShape->setPos(beginPoint);
        enumShape->resize(delta);
        enumShape->setVisible(true);
        break;
    }
    case CursorState::Inheritance: {
        auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());
        QuGD::Shape* shape = dynamic_cast<QuGD::Shape*>(selected);
        if(!mSource && shape && shape->acceptsGeneralizationSource()) {
            mSource = shape;
            return;
        } else if(mSource && shape && shape->acceptsGeneralizationTarget()) {
            auto gen = new QuUK::Generalization(
                    dynamic_cast<QuUK::Classifier*>(mSource->modelElement()),
                    dynamic_cast<QuUK::Classifier*>(shape->modelElement()));
            auto gshape = mDiagram->createEdge(gen, mSource, shape);
            gshape->setVisible(true);
            mSource = nullptr;
            break;
        } else {
            break;
        }
    }
    case CursorState::Interface:
        break;
    case CursorState::PackageMembership: {
        auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());
        QuGD::Shape* shape = dynamic_cast<QuGD::Shape*>(selected);
        if(!mSource && shape &&
                dynamic_cast<QuUK::PackageableElement*>(shape->modelElement())) {
            mSource = shape;
            return;
        } else if(mSource && dynamic_cast<QuGD::PackageShape*>(shape)) {
            dynamic_cast<QuUK::PackageableElement*>(mSource->modelElement())->
                setPackage(dynamic_cast<QuUK::Package*>(shape->modelElement()));
            auto pshape = mDiagram->createPackageContainment(mSource, shape);
            pshape->setVisible(true);
            mSource = nullptr;
            break;
        } else {
            break;
        }
    }
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
    case CursorState::Association: {
        auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());
        QuGD::Shape* shape = dynamic_cast<QuGD::Shape*>(selected);
        if(!mSource && shape && shape->acceptsAssociationSource()) {
            mSource = shape;
            return;
        } else if(mSource && shape && shape->acceptsAssociationTarget()) {
            auto assoc = new QuUK::Association(
                    dynamic_cast<QuUK::Classifier*>(mSource->modelElement()),
                    dynamic_cast<QuUK::Classifier*>(shape->modelElement()));
            auto ashape = mDiagram->createEdge(assoc, mSource, shape);
            ashape->setVisible(true);
            mSource = nullptr;
            break;
        } else {
            break;
        }
    }
    }

    mMainWindow->setCursorState(CursorState::Normal);
}

void EditorView::resetSelection() {
    mSource = nullptr;
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
                mDiagram->setModified();
                mCursorOverride = true;
            } else if(p->shouldShowFDiag(mapToScene(e->pos()))) {
                QApplication::setOverrideCursor(Qt::SizeFDiagCursor);
                mDiagram->setModified();
                mCursorOverride = true;
            } else {
                mCursorOverride = false;
                QApplication::restoreOverrideCursor();
                mDiagram->setModified();
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
    mDiagram->setModified();

    // Check what's selected.
    auto selected = mScene->itemAt(mapToScene(e->pos()), QTransform());

    Popover* popover = nullptr;
    if(dynamic_cast<QuGD::ClassShape*>(selected)) {
        auto operation =
            dynamic_cast<QuGD::ClassShape*>(selected)->highlightedOperation();
        auto attribute =
            dynamic_cast<QuGD::ClassShape*>(selected)->highlightedAttribute();

        if(operation) {
            popover = new Popover(this, e->globalPos());
            popover->setupUi(Popover::PopoverType::Operation);
            popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
        } else if(attribute) {
            popover = new Popover(this, e->globalPos());
            popover->setupUi(Popover::PopoverType::Attribute);
            popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
        } else {
            popover = new Popover(this, e->globalPos());
            popover->setupUi(Popover::PopoverType::Class);
            popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
        }
    } else if(dynamic_cast<QuGD::CommentShape*>(selected)) {
        popover = new Popover(this, e->globalPos());
        popover->setupUi(Popover::PopoverType::Comment);
        popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
    } else if(dynamic_cast<QuGD::PackageShape*>(selected)) {
        popover = new Popover(this, e->globalPos());
        popover->setupUi(Popover::PopoverType::Package);
        popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
    } else if(dynamic_cast<QuGD::PrimitiveShape*>(selected)) {
        popover = new Popover(this, e->globalPos());
        popover->setupUi(Popover::PopoverType::Primitive);
        popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
    } else if(dynamic_cast<QuGD::EnumShape*>(selected)) {
        auto literal =
            dynamic_cast<QuGD::EnumShape*>(selected)->highlightedLiteral();

        if(literal) {
            popover = new Popover(this, e->globalPos());
            popover->setupUi(Popover::PopoverType::Literal);
            popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
        } else {
            popover = new Popover(this, e->globalPos());
            popover->setupUi(Popover::PopoverType::Enumeration);
            popover->bindModel(dynamic_cast<QuGD::Shape*>(selected));
        }
    }

    if(popover) {
        popover->setVisible(true);
        connect(popover, &Popover::lostFocus, [&]{mScrollable = true;});
    }

    QGraphicsView::mouseDoubleClickEvent(e);
}

QUML_END_NAMESPACE_GW

