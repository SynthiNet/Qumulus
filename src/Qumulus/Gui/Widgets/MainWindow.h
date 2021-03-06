/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#ifndef GUI_WIDGETS_MAINWINDOW_H_
#define GUI_WIDGETS_MAINWINDOW_H_

#include "internal_base.h"
#include <QtWidgets/QMainWindow>
#include <QtCore/QHash>
#include <QtCore/QString>
#include <QtWidgets/QUndoStack>
#include <Gui/Diagram/Diagram.h>

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

enum CursorState {
    Normal,
    Aggregation,
    Class,
    Comment,
    Composition,
    Enum,
    Inheritance,
    Interface,
    PackageMembership,
    Package,
    Primitive,
    Association
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    ToolBar* toolBar() const { return mToolBar; }
    StatusBar* statusBar() const { return mStatusBar; }
    SideBar* sideBar() const { return mSideBar; }
    QUndoStack* undoStack() const { return mUndoStack; }
    CursorState cursorState() const { return mCursorState; }
    void setCursorState(CursorState cursorState);

protected:
    void closeEvent(QCloseEvent*);

private:
    void createMenus();
    void populateToolbar();
    void createCursors();

private:
    QuGD::Diagram* mDiagram;

    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    StatusBar* mStatusBar;
    EditorView* mEditorView;

    QUndoStack* mUndoStack;

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
    // QMenu* mInsertMenu;
    QMenu* mViewMenu;
    QMenu* mHelpMenu;

    // Application Menu
    // QAction* mPrefsAction;
    QAction* mQuitAction;

    // File Menu
    // QAction* mNewAction;
    QAction* mOpenAction;
    QAction* mSaveAction;
    QAction* mSaveAsAction;
    // QAction* mCloseAction;
    QAction* mPrintAction;
    QAction* mExportAction;

    // Edit Menu
    QAction* mUndoAction;
    QAction* mRedoAction;
    // QAction* mCutAction;
    // QAction* mCopyAction;
    // QAction* mPasteAction;
    QAction* mDeleteAction;
    // QAction* mDuplicateAction;

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
    CursorState mCursorState = CursorState::Normal;
    QString mFileName = "";
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

