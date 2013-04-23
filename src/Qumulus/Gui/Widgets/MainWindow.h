/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_MAINWINDOW_H_
#define GUI_WIDGETS_MAINWINDOW_H_

#include "internal_base.h"
#include <QtWidgets/QMainWindow>

class QMenu;
class QSplitter;
class QAction;

QUML_BEGIN_NAMESPACE_GW

class StatusBar;
class EditorView;
class ToolBar;
class SideBar;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

    ToolBar* toolBar() const { return mToolBar; }
    StatusBar* statusBar() const { return mStatusBar; }
    SideBar* sideBar() const { return mSideBar; }

private:
    void createMenus();

private:
    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    StatusBar* mStatusBar;
    EditorView* mEditorView;

    QMenu* mFileMenu;
    QMenu* mEditMenu;
    QMenu* mInsertMenu;
    QMenu* mViewMenu;
    QMenu* mHelpMenu;

    // Application Menu
    QAction* mPrefsAction;
    QAction* mQuitAction;

    // File Menu
    QAction* mNewAction;
    QAction* mOpenAction;
    QAction* mCloseAction;
    QAction* mPrintAction;
    
    // Edit Menu
    QAction* mUndoAction;
    QAction* mRedoAction;
    QAction* mCutAction;
    QAction* mCopyAction;
    QAction* mPasteAction;
    QAction* mDeleteAction;
    QAction* mDuplicateAction;

    // Insert Menu
     
    // View Menu
    
    // Help Menu
    QAction* mAboutAction;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

