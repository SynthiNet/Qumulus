/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <Gui/Widgets/SideBar.h>
#include <Gui/Widgets/ToolBar.h>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/StatusBar.h>
#include <Gui/Widgets/EditorView.h>
#include <Gui/Core/QumulusApplication.h>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>

QUML_BEGIN_NAMESPACE_GW

MainWindow::MainWindow() : 
        mToolBar(new ToolBar(this)), 
        mSideBar(new SideBar(this)),
        mSplitter(new QSplitter(this)),
        mStatusBar(new StatusBar(this)),
        mEditorView(new EditorView(this)) {
    constexpr unsigned kWidth = 700, kHeight = 480, kSideWidth = 220;

    // Size constraints
    setMinimumSize(400, 300);
    resize(kWidth, kHeight);

    // Title
    setWindowTitle("Qumulus");

    // Add toolbar
    mToolBar->showInWindow(this);

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

    createMenus();

    connect(mStatusBar->slider(), &ZoomSlider::valueChanged,
            mEditorView, &EditorView::zoom);
}

void MainWindow::createMenus() {
    mFileMenu = menuBar()->addMenu(tr("&File"));
    mEditMenu = menuBar()->addMenu(tr("&Edit"));
    mInsertMenu = menuBar()->addMenu(tr("&Insert"));
    mViewMenu = menuBar()->addMenu(tr("&View"));
    mHelpMenu = menuBar()->addMenu(tr("&Help"));

    // File Menu
    mNewAction = new QAction(tr("&New"), this);
    mNewAction->setShortcuts(QKeySequence::New);

    mOpenAction = new QAction(tr("&Open..."), this);
    mOpenAction->setShortcuts(QKeySequence::Open);

    mCloseAction = new QAction(tr("Close"), this);
    mCloseAction->setShortcuts(QKeySequence::Close);
    
    mPrintAction = new QAction(tr("&Print..."), this);
    mPrintAction->setShortcuts(QKeySequence::Print);
    
    mPrefsAction = new QAction(tr("Settings"), this);
    mPrefsAction->setShortcuts(QKeySequence::Preferences);
    
    mQuitAction = new QAction(tr("&Quit"), this);
    mQuitAction->setShortcuts(QKeySequence::Quit);
    connect(mQuitAction, &QAction::triggered, &QApplication::exit);

    mFileMenu->addAction(mNewAction);
    mFileMenu->addAction(mOpenAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mCloseAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mPrintAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mPrefsAction);
    mFileMenu->addAction(mQuitAction);    
    
    // Edit Menu
    mUndoAction = new QAction(tr("&Undo"), this);
    mUndoAction->setShortcuts(QKeySequence::Undo);
    
    mRedoAction = new QAction(tr("&Redo"), this);
    mRedoAction->setShortcuts(QKeySequence::Redo);
    
    mCutAction = new QAction(tr("&Cut"), this);
    mCutAction->setShortcuts(QKeySequence::Cut);
    
    mCopyAction = new QAction(tr("C&opy"), this);
    mCopyAction->setShortcuts(QKeySequence::Copy);
    
    mPasteAction = new QAction(tr("&Paste"), this);
    mPasteAction->setShortcuts(QKeySequence::Paste);
    
    mDeleteAction = new QAction(tr("&Delete"), this);
    mDeleteAction->setShortcuts(QKeySequence::Delete);

    mDuplicateAction = new QAction(tr("D&uplicate"), this);
    mDuplicateAction->setShortcuts({QKeySequence(tr("Ctrl+D"))});

    mEditMenu->addAction(mUndoAction);
    mEditMenu->addAction(mRedoAction);
    mEditMenu->addAction(mCutAction);
    mEditMenu->addAction(mCopyAction);
    mEditMenu->addAction(mPasteAction);
    mEditMenu->addAction(mDeleteAction);
    mEditMenu->addAction(mDuplicateAction);

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

QUML_END_NAMESPACE_GW

