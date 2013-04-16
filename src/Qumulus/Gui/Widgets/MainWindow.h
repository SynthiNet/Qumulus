/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_MAINWINDOW_H_
#define GUI_WIDGETS_MAINWINDOW_H_

#include "internal_base.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSplitter>
#include <Lib/Core/Ptr.h>
#include <Gui/Widgets/SideBar.h>
#include <Gui/Widgets/ToolBar.h>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/StatusBar.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

    ToolBar* toolBar() const { return mToolBar; }
    StatusBar* statusBar() const { return mStatusBar; }
    SideBar* sideBar() const { return mSideBar; }

private:
#ifdef Q_OS_MAC
    void setContentBorderOnMac();
#endif

private:
    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    StatusBar* mStatusBar;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

