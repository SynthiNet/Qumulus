/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QFileDialog>
#include <QtSvg/QSvgGenerator>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <Gui/Widgets/SideBar.h>
#include <Gui/Widgets/ToolBar.h>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/StatusBar.h>
#include <Gui/Widgets/EditorView.h>
#include <Gui/Widgets/ElementItem.h>
#include <Gui/Widgets/ToolBarMenu.h>
#include <Gui/Widgets/MessageBox.h>
#include <Gui/Core/QumulusApplication.h>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QCursor>
#include <QtGui/QPixmap>
#include <QtGui/QPdfWriter>
#include <QtGui/QImage>
#include <QtCore/QTimer>

QUML_BEGIN_NAMESPACE_GW

MainWindow::MainWindow() :
        mDiagram(new QuGD::Diagram()),
        mToolBar(new ToolBar(this)),
        mSideBar(new SideBar(this, mDiagram)),
        mSplitter(new QSplitter(this)),
        mStatusBar(new StatusBar(this)),
        mEditorView(new EditorView(this, mDiagram)),
        mUndoStack(new QUndoStack(this)) {
    constexpr unsigned kWidth = 700, kHeight = 480, kSideWidth = 220;
    createCursors();

    // Size constraints
    setMinimumSize(400, 300);
    resize(kWidth, kHeight);

    // Title
    setWindowTitle("Qumulus");

    // Create and populate the toolbar.
    populateToolbar();

    // Create main view.
    setCentralWidget(mSplitter);

#ifdef Q_OS_MAC
    mSplitter->setHandleWidth(0);
#endif

    mSplitter->setChildrenCollapsible(false);

    // Add the treeview.
    mSplitter->addWidget(mSideBar);

    // Add the Editor view.
    QSizePolicy editorViewPolicy = mEditorView->sizePolicy();
    editorViewPolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    mEditorView->setSizePolicy(editorViewPolicy);
    mSplitter->addWidget(mEditorView);

    // Force the treeview an appropriate size.
    mSplitter->setSizes({kSideWidth, kWidth - kSideWidth});
    mSplitter->setStretchFactor(0, 0);
    mSplitter->setStretchFactor(1, 1);

    // Add the status bar.
    setStatusBar(mStatusBar);

    // Create the main menus.
    createMenus();

    // Cancel mode action.
    mCancelAction = new QAction(this);
    mCancelAction->setShortcuts({QKeySequence(tr("Esc"))});
    addAction(mCancelAction);
    connect(mCancelAction, &QAction::triggered,
            [&]{setCursorState(CursorState::Normal);});

    connect(mStatusBar->slider(), &ZoomSlider::zoomChanged,
            mEditorView, &EditorView::zoom);

    // Expand sidebar
    // mSideBar->expandAll();
}

MainWindow::~MainWindow() {
    delete mDiagram;
}

void MainWindow::populateToolbar() {
    mToolBar->showInWindow(this);


    // Class and submenu.
    mClassItem = new ToolBarItem(
            ElementItem("Class",
                    QIcon(":/data/img/toolbar/class.png"),
                    QKeySequence(tr("C")),
                    [&]{setCursorState(CursorState::Class);}));

    mClassMenu = new ToolBarMenu();
    mClassMenu->addItem(
            ElementItem("Enum",
                    QIcon(":/data/img/toolbar/enum.png"),
                    QKeySequence(tr("E")),
                    [&]{setCursorState(CursorState::Enum);}));
    mClassMenu->addItem(
            ElementItem("Primitive Datatype",
                    QIcon(":/data/img/toolbar/primitive.png"),
                    QKeySequence(tr("D")),
                    [&]{setCursorState(CursorState::Primitive);}));
    mClassItem->setMenu(mClassMenu);
    mToolBar->addWidget(mClassItem);


    // Package and submenu.
    mPackageItem = new ToolBarItem(
            ElementItem("Package",
                    QIcon(":/data/img/toolbar/package.png"),
                    QKeySequence(tr("P")),
                    [&]{setCursorState(CursorState::Package);}));

    mPackageMenu = new ToolBarMenu();
    mPackageMenu->addItem(
            ElementItem("Comment",
                    QIcon(":/data/img/toolbar/comment.png"),
                    QKeySequence(tr("H")),
                    [&]{setCursorState(CursorState::Comment);}));
    mPackageItem->setMenu(mPackageMenu);
    mToolBar->addWidget(mPackageItem);


    mToolBar->addSeparator();


    // Inheritance and submenu.
    mInheritanceItem = new ToolBarItem(
            ElementItem("Inheritance",
                    QIcon(":/data/img/toolbar/inheritance.png"),
                    QKeySequence(tr("I")),
                    [&]{setCursorState(CursorState::Inheritance);}));
    mToolBar->addWidget(mInheritanceItem);


    // Aggregation and submenu.
    mAggregationItem = new ToolBarItem(
            ElementItem("Composition",
                    QIcon(":/data/img/toolbar/containment.png"),
                    QKeySequence(tr("N")),
                    [&]{setCursorState(CursorState::Composition);}));

    mAggregationMenu = new ToolBarMenu();
    mAggregationMenu->addItem(
            ElementItem("Aggregation",
                    QIcon(":/data/img/toolbar/aggregation.png"),
                    QKeySequence(tr("G")),
                    [&]{setCursorState(CursorState::Aggregation);}));
    mAggregationItem->setMenu(mAggregationMenu);
    mToolBar->addWidget(mAggregationItem);


    // Relationship and submenu.
    mRelationshipItem = new ToolBarItem(
            ElementItem("Package Membership",
                    QIcon(":/data/img/toolbar/package-membership.png"),
                    QKeySequence(tr("M")),
                    [&]{setCursorState(CursorState::PackageMembership);}));

    mRelationshipMenu = new ToolBarMenu();
    mRelationshipMenu->addItem(
            ElementItem("Association",
                    QIcon(":/data/img/toolbar/association.png"),
                    QKeySequence(tr("R")),
                    [&]{setCursorState(CursorState::Association);}));
    mRelationshipItem->setMenu(mRelationshipMenu);
    mToolBar->addWidget(mRelationshipItem);
}

void MainWindow::createMenus() {
    mFileMenu = menuBar()->addMenu(tr("&File"));
    mEditMenu = menuBar()->addMenu(tr("&Edit"));
    // mInsertMenu = menuBar()->addMenu(tr("&Insert"));
    mViewMenu = menuBar()->addMenu(tr("&View"));
    mHelpMenu = menuBar()->addMenu(tr("&Help"));

    // File Menu
    mNewAction = new QAction(tr("&New"), this);
    mNewAction->setShortcuts(QKeySequence::New);
    // check mDiagram->isModified(); !

    mOpenAction = new QAction(tr("&Open..."), this);
    mOpenAction->setShortcuts(QKeySequence::Open);
    // check mDiagram->isModified(); !

    mSaveAction = new QAction(tr("&Save..."), this);
    mSaveAction->setShortcuts(QKeySequence::Save);
    connect(mSaveAction, &QAction::triggered, [&]{
            if(mFileName == "") {
                QString fName = QFileDialog::getSaveFileName(
                    this, tr("Save Diagram"), "",
                    tr("UML Diagram (*.uml)"));
                if(fName.isNull()) return; // No filename chosen.
                if(!fName.contains(QRegExp(R"(\.(uml)$)",
                        Qt::CaseInsensitive))) {
                    fName += ".uml";
                }
                mFileName = fName;
            }
            mDiagram->saveToXml(mFileName);
            mDiagram->clearModified();});

    mSaveAsAction = new QAction(tr("Save &As..."), this);
    mSaveAsAction->setShortcuts(QKeySequence::SaveAs);
    connect(mSaveAsAction, &QAction::triggered, [&]{
            QString fName = QFileDialog::getSaveFileName(
                this, tr("Save Diagram"), "",
                tr("UML Diagram (*.uml)"));
            if(fName.isNull()) return; // No filename chosen.
            if(!fName.contains(QRegExp(R"(\.(uml)$)",
                    Qt::CaseInsensitive))) {
                fName += ".uml";
            }
            mFileName = fName;
            mDiagram->saveToXml(fName);
            mDiagram->clearModified();});

    // mCloseAction = new QAction(tr("Close"), this);
    // mCloseAction->setShortcuts(QKeySequence::Close);

    mPrintAction = new QAction(tr("&Print..."), this);
    mPrintAction->setShortcuts(QKeySequence::Print);
    connect(mPrintAction, &QAction::triggered, [&]{
            QPrinter printer;
            if(QPrintDialog(&printer).exec() == QDialog::Accepted) {
                QPainter painter(&printer);
                painter.setRenderHint(QPainter::Antialiasing);
                mEditorView->scene()->clearSelection();
                mEditorView->scene()->render(&painter);
            }});

    mExportAction = new QAction(tr("&Export..."), this);
    connect(mExportAction, &QAction::triggered, [&]{
            QString fName = QFileDialog::getSaveFileName(
                this, tr("Export Diagram"), "",
                tr("PNG image (*.png);;"
                    "BMP image (*.bmp);;"
                    "JPG image (*.jpg);;"
                    "SVG file (*.svg);;"
                    "PDF file (*.pdf)"));
            if(fName.isNull()) return; // No filename chosen.
            mEditorView->scene()->clearSelection();
            if(!fName.contains(QRegExp(R"(\.(png|bmp|jpg|svg|pdf)$)",
                    Qt::CaseInsensitive))) {
                // Assume PNG
                fName += ".png";
            }

            QFile outFile(fName);
            if(!outFile.open(QIODevice::WriteOnly)) {
                MessageBox::warning(this, tr("Could not save file"),
                        tr("Unable to export to file %1").arg(fName));
                return;
            }

            if(fName.endsWith("svg")) {
                QSvgGenerator svg;
                svg.setOutputDevice(&outFile);
                svg.setSize(mEditorView->scene()->sceneRect().size().toSize());
                svg.setTitle(tr("UML Diagram"));
                svg.setDescription(tr("Generated by Qumulus UML Editor"));
                QPainter painter(&svg);
                mEditorView->scene()->render(&painter);
                painter.end();
            } else if(fName.endsWith("pdf")) {
                QPdfWriter pdf(&outFile);
                pdf.setTitle(tr("UML Diagram"));
                pdf.setCreator(tr("Qumulus UML Editor"));
                pdf.setMargins({0, 0, 0, 0});
                // Set page size to size * 72 dpi.
                pdf.setPageSizeMM(mEditorView->scene()->sceneRect().size() * 2.835);
                QPainter painter(&pdf);
                mEditorView->scene()->render(&painter);
                painter.end();
            } else {
                QImage img(mEditorView->scene()->sceneRect().width(),
                    mEditorView->scene()->sceneRect().height(),
                    QImage::Format_ARGB32_Premultiplied);
                QPainter painter(&img);
                mEditorView->scene()->render(&painter);
                painter.end();
                if(!img.save(&outFile)) {
                    MessageBox::warning(this, tr("Could not save file"),
                            tr("Unable to export to file %1").arg(fName));
                }
            }});

    // mPrefsAction = new QAction(tr("Settings"), this);
    // mPrefsAction->setShortcuts(QKeySequence::Preferences);

    mQuitAction = new QAction(tr("&Quit"), this);
    mQuitAction->setShortcuts(QKeySequence::Quit);
    connect(mQuitAction, &QAction::triggered, [&]{close();});

    mFileMenu->addAction(mNewAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mOpenAction);
    mFileMenu->addAction(mSaveAction);
    mFileMenu->addAction(mSaveAsAction);
    mFileMenu->addSeparator();
    // mFileMenu->addAction(mCloseAction);
    mFileMenu->addAction(mExportAction);
    mFileMenu->addAction(mPrintAction);
    mFileMenu->addSeparator();
    // mFileMenu->addAction(mPrefsAction);
    mFileMenu->addAction(mQuitAction);

    // Edit Menu
    mUndoAction = mUndoStack->createUndoAction(this);
    mUndoAction->setShortcuts(QKeySequence::Undo);

    mRedoAction = mUndoStack->createRedoAction(this);
    mRedoAction->setShortcuts(QKeySequence::Redo);

    // mCutAction = new QAction(tr("&Cut"), this);
    // mCutAction->setShortcuts(QKeySequence::Cut);

    // mCopyAction = new QAction(tr("C&opy"), this);
    // mCopyAction->setShortcuts(QKeySequence::Copy);

    // mPasteAction = new QAction(tr("&Paste"), this);
    // mPasteAction->setShortcuts(QKeySequence::Paste);

    mDeleteAction = new QAction(tr("&Delete"), this);
    mDeleteAction->setShortcuts({QKeySequence(Qt::Key_Backspace),
            QKeySequence(Qt::Key_Delete)});
    connect(mDeleteAction, &QAction::triggered, [&]{
            if(QApplication::focusWidget() == mEditorView) {
                for(auto i : mEditorView->scene()->selectedItems()) {
                    i->setVisible(false);
                }
            } else if(QApplication::focusWidget() == mSideBar) {
                for(auto i : mSideBar->selectionModel()->selectedIndexes()) {
                    // Do something with i here.
                    (void) i;
                }
            }});

    /*mDuplicateAction = new QAction(tr("D&uplicate"), this);
    mDuplicateAction->setShortcuts({QKeySequence(tr("Ctrl+D"))});*/

    mEditMenu->addAction(mUndoAction);
    mEditMenu->addAction(mRedoAction);
    // mEditMenu->addAction(mCutAction);
    // mEditMenu->addAction(mCopyAction);
    // mEditMenu->addAction(mPasteAction);
    mEditMenu->addAction(mDeleteAction);
    //mEditMenu->addAction(mDuplicateAction);

    // View Menu
    mCenterAction = new QAction(tr("&Center View"), this);
    mCenterAction->setShortcuts({QKeySequence(tr("Home"))});
    connect(mCenterAction, &QAction::triggered,
            [&]{mEditorView->centerOn(0, 0);});

    mUndoZoomAction = new QAction(tr("&Actual Size"), this);
    mUndoZoomAction->setShortcuts({QKeySequence(tr("Ctrl+0"))});
    connect(mUndoZoomAction, &QAction::triggered,
            [&]{mStatusBar->slider()->setValue(3);});

    mZoomInAction = new QAction(tr("Zoom &In"), this);
    mZoomInAction->setShortcuts(QKeySequence::ZoomIn);
    connect(mZoomInAction, &QAction::triggered,
            [&]{mStatusBar->slider()->setValue(
                        mStatusBar->slider()->value() + 1);});

    mZoomOutAction = new QAction(tr("Zoom &Out"), this);
    mZoomOutAction->setShortcuts(QKeySequence::ZoomOut);
    connect(mZoomOutAction, &QAction::triggered,
            [&]{mStatusBar->slider()->setValue(
                        mStatusBar->slider()->value() - 1);});

#ifdef Q_OS_MAC
    mFullScreenAction = new QAction(tr("Toggle &Full Screen"), this);
    mFullScreenAction->setShortcuts(QKeySequence::FullScreen);
    addAction(mFullScreenAction);
    connect(mFullScreenAction, &QAction::triggered,
            [&]{if(this->isFullScreen())
                this->showNormal();
            else
                this->showFullScreen();});
#endif

    mViewMenu->addAction(mCenterAction);
#ifdef Q_OS_MAC
    mViewMenu->addSeparator();
    mViewMenu->addAction(mFullScreenAction);
#endif
    mViewMenu->addSeparator();
    mViewMenu->addAction(mUndoZoomAction);
    mViewMenu->addAction(mZoomInAction);
    mViewMenu->addAction(mZoomOutAction);

    // Help Menu
    mAboutAction = new QAction(tr("&About Qumulus"), this);
    connect(mAboutAction, &QAction::triggered, [&]{
            this->setWindowIcon(QIcon(":/logo/qumulus-256.png"));
            QMessageBox::about(this,
                "About Qumulus",
                "Qumulus\n"
                "Version 0.1\n\n"
                "Authors: Frank Erens & Randy Thiemann");
            this->setWindowIcon(QIcon(""));});

    mHelpMenu->addAction(mAboutAction);
}

void MainWindow::setCursorState(CursorState c) {
    mCursorState = c;
    mEditorView->resetSelection();

    switch(c) {
    case Normal:
        unsetCursor();
        break;
    case Aggregation:
        setCursor(mCursors["aggregation"]);
        break;
    case Class:
        setCursor(mCursors["class"]);
        break;
    case Comment:
        setCursor(mCursors["comment"]);
        break;
    case Composition:
        setCursor(mCursors["containment"]);
        break;
    case Enum:
        setCursor(mCursors["enum"]);
        break;
    case Inheritance:
        setCursor(mCursors["inheritance"]);
        break;
    case Interface:
        setCursor(mCursors["interface"]);
        break;
    case PackageMembership:
        setCursor(mCursors["package-membership"]);
        break;
    case Package:
        setCursor(mCursors["package"]);
        break;
    case Primitive:
        setCursor(mCursors["primitive"]);
        break;
    case Association:
        setCursor(mCursors["association"]);
        break;
    }
}

void MainWindow::createCursors() {
    mCursors["aggregation"] =
        QCursor(QPixmap(":/data/img/cursor/aggregation.png"), -1, -1);
    mCursors["class"] =
        QCursor(QPixmap(":/data/img/cursor/class.png"), -1, -1);
    mCursors["comment"] =
        QCursor(QPixmap(":/data/img/cursor/comment.png"), -1, -1);
    mCursors["containment"] =
        QCursor(QPixmap(":/data/img/cursor/containment.png"), -1, -1);
    mCursors["enum"] =
        QCursor(QPixmap(":/data/img/cursor/enum.png"), -1, -1);
    mCursors["inheritance"] =
        QCursor(QPixmap(":/data/img/cursor/inheritance.png"), -1, -1);
    mCursors["interface"] =
        QCursor(QPixmap(":/data/img/cursor/interface.png"), -1, -1);
    mCursors["package-membership"] =
        QCursor(QPixmap(":/data/img/cursor/package-membership.png"), -1, -1);
    mCursors["package"] =
        QCursor(QPixmap(":/data/img/cursor/package.png"), -1, -1);
    mCursors["primitive"] =
        QCursor(QPixmap(":/data/img/cursor/primitive.png"), -1, -1);
    mCursors["association"] =
        QCursor(QPixmap(":/data/img/cursor/association.png"), -1, -1);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    if(mDiagram->isModified()) {
        if(QMessageBox::Yes ==
                QMessageBox::question(this, "Are you sure?",
                    "Your document contains unsaved changes, "
                    "are you sure you want to quit?",
                    QMessageBox::Yes|QMessageBox::No)){
            event->accept();
        } else {
            event->ignore();
#ifdef Q_OS_MAC
            // Ugly workaround for a Qt5 bug on OS X.
            QTimer::singleShot(0,this,SLOT(hide()));
            QTimer::singleShot(10,this,SLOT(show()));
#endif
        }
    } else {
        event->accept();
    }
}

QUML_END_NAMESPACE_GW

