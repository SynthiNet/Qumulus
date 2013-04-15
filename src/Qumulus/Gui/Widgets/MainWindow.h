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
#include <Gui/Widgets/ToolBar.h>
#include <Gui/Widgets/SideBar.h>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    ToolBar* mToolBar;
    SideBar* mSideBar;
    QSplitter* mSplitter;
    QStatusBar* mStatusBar;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

