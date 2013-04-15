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
#include <QtWidgets/QStatusBar>
#include <Lib/Core/Ptr.h>

#include "ToolBar.h"
#include "SideBar.h"

QUML_BEGIN_NAMESPACE_GW

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
#ifdef Q_OS_MAC
    void setContentBorderOnMac();
#endif

private:
    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    QStatusBar* mStatusBar;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

