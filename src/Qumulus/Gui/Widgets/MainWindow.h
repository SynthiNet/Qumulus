/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_MAINWINDOW_H_
#define GUI_WIDGETS_MAINWINDOW_H_

#include "internal_base.h"
#include <QtWidgets/QMainWindow>
#include <QtCore/QHash>
#include <QtCore/QString>

class QMenu;
class QSplitter;
class QAction;
class QCursor;

QUML_BEGIN_NAMESPACE_GW

class StatusBar;
class EditorView;
class ToolBar;
class SideBar;
class ToolBarMenu;
class ToolBarItem;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

    ToolBar* toolBar() const { return mToolBar; }
    StatusBar* statusBar() const { return mStatusBar; }
    SideBar* sideBar() const { return mSideBar; }

private:
    void createMenus();
    void populateToolbar();
    void createCursors();

private:
    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    StatusBar* mStatusBar;
    EditorView* mEditorView;

    // Toolbar members;
    ToolBarItem* mClassItem;
    ToolBarMenu* mClassMenu;
    ToolBarItem* mPackageItem;
    ToolBarMenu* mPackageMenu;
    ToolBarItem* mInheritanceItem;
    ToolBarMenu* mInheritanceMenu;
    ToolBarItem* mAggregationItem;
    ToolBarMenu* mAggregationMenu;
    ToolBarItem* mRelationshipItem;
    ToolBarMenu* mRelationshipMenu;

    // Main menu members
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
    QAction* mCenterAction;
    QAction* mZoomInAction;
    QAction* mZoomOutAction;
    QAction* mUndoZoomAction;
    
    // Help Menu
    QAction* mAboutAction;

    // Generic cancel action
    QAction* mCancelAction;

#ifdef Q_OS_MAC
    // OSX only fullscreen action
    QAction* mFullScreenAction;
#endif

    QHash<QString, QCursor> mCursors;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

