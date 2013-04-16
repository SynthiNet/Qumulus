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
        mStatusBar(new StatusBar(this)) {
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
    QTextEdit* mEditorView = new QTextEdit();
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

#ifdef Q_OS_MAC
    // Set border on OS X
    setContentBorderOnMac();
#endif
}

QUML_END_NAMESPACE_GW

