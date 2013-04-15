/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "MainWindow.h"
#include <QtWidgets/QTextEdit>

QUML_BEGIN_NAMESPACE_GW

MainWindow::MainWindow() : 
        mToolBar(new ToolBar(this)), 
        mSideBar(new SideBar(this)),
        mSplitter(new QSplitter(this)),
        mStatusBar(new QStatusBar(this)) {
    setMinimumSize(640, 480);

    // Add toolbar
    mToolBar->showInWindow(this);

    // Create main view.
    setCentralWidget(mSplitter);
    mSplitter->setHandleWidth(0);
    mSplitter->setChildrenCollapsible(false);

    // Add the treeview.
    mSideBar->setStyleSheet(
            "background-color: rgb(222, 228, 234);"
            "selection-color: white;"
            "selection-background-color:"
                "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                "stop: 0 rgb(110, 165, 218), stop: 1 rgb(33, 108, 183))");
    mSideBar->setAttribute(Qt::WA_MacShowFocusRect, false);
    mSideBar->setMinimumWidth(100);
    QSizePolicy sideBarSizePolicy = mSideBar->sizePolicy();
    sideBarSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    mSideBar->setSizePolicy(sideBarSizePolicy);
    mSplitter->addWidget(mSideBar);

    // Add the Editor view.
    QTextEdit* mEditorView = new QTextEdit();
    QSizePolicy editorViewPolicy = mEditorView->sizePolicy();
    editorViewPolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    mEditorView->setSizePolicy(editorViewPolicy);
    mSplitter->addWidget(mEditorView);

    // Force the treeview at minimum size.
    mSplitter->setSizes(QList<int>{0, 99999});

    // Add the status bar.
    setStatusBar(mStatusBar);
}

QUML_END_NAMESPACE_GW

